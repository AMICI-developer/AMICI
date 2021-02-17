function generateC(this)
% generateC generates the c files which will be used in the compilation.
%
% Return values:
%  void

% different signatures for cvodes / idas
if(strcmp(this.wtype,'iw'))
    dxvec = 'dx,';
    rtcj = 'cj,';
else
    dxvec = 'NULL,';
    rtcj = '0.0,';
end


% write fun ccode

for ifun = this.funs
    cppFunctionName = strrep(ifun{1}, 'sigma_', 'sigma');
    if(isfield(this.fun,ifun{1}))
        bodyNotEmpty = any(this.fun.(ifun{1}).sym(:)~=0);
        if(strcmp(ifun{1},'JSparse'))
            bodyNotEmpty = any(this.fun.J.sym(:)~=0);
        end

        if(bodyNotEmpty)
            fprintf([ifun{1} ' | ']);
            fid = fopen(fullfile(this.wrap_path,'models',this.modelname,[this.modelname '_' cppFunctionName '.cpp']),'w');
            fprintf(fid,'\n');
            fprintf(fid,'#include "amici/symbolic_functions.h"\n');
            fprintf(fid,'#include "amici/defines.h" //realtype definition\n');

            if(ismember(ifun{1},{'JSparse'}))
                fprintf(fid,'#include <sunmatrix/sunmatrix_sparse.h> //SUNMatrixContent_Sparse definition\n');
            end

            fprintf(fid,'typedef amici::realtype realtype;\n');
            fprintf(fid,'#include <cmath> \n');
            fprintf(fid,'\n');
            fprintf(fid,'using namespace amici;\n');
            fprintf(fid,'\n');
            fprintf(fid,'namespace amici {\n\n');
            fprintf(fid,['namespace model_' this.modelname '{\n\n']);

            % function definition
            fprintf(fid,['void ' cppFunctionName '_' this.modelname '' this.fun.(ifun{1}).argstr ' {\n']);
            if(strcmp(ifun{1},'JSparse'))
                for i = 1:length(this.rowvals)
                    fprintf(fid,['  JSparse->indexvals[' num2str(i-1) '] = ' num2str(this.rowvals(i)) ';\n']);
                end
                for i = 1:length(this.colptrs)
                    fprintf(fid,['  JSparse->indexptrs[' num2str(i-1) '] = ' num2str(this.colptrs(i)) ';\n']);
                end
            end

            if(strcmp(ifun{1},'JBand'))
                fprintf(fid,['return(J_' this.modelname removeTypes(this.fun.J.argstr) ');']);
            elseif(strcmp(ifun{1},'JBandB'))
                fprintf(fid,['return(JB_' this.modelname removeTypes(this.fun.JB.argstr) ');']);
            else
                if( strcmp(ifun{1},'qBdot') )
                    fprintf(fid,'switch (ip) {\n');
                    this.fun.(ifun{1}).writeCcode_sensi(this,fid);
                    fprintf(fid,'}\n');
                elseif(this.fun.(ifun{1}).sensiflag)
                    fprintf(fid,'switch (ip) {\n');
                    this.fun.(ifun{1}).writeCcode_sensi(this,fid);
                    fprintf(fid,'}\n');
                else
                    this.fun.(ifun{1}).writeCcode(this,fid);
                end
            end
            fprintf(fid,'}\n');
            fprintf(fid,'\n');
            fprintf(fid,['} // namespace model_' this.modelname '\n\n']);
            fprintf(fid,'} // namespace amici\n\n');

            fclose(fid);
        end
    end
end

% wrapfunctions.h

fid = fopen(fullfile(this.wrap_path,'models',this.modelname,'wrapfunctions.h'),'w');
fprintf(fid,'#ifndef _amici_wrapfunctions_h\n');
fprintf(fid,'#define _amici_wrapfunctions_h\n');
fprintf(fid,'\n');
fprintf(fid,['#include "' this.modelname '.h"\n']);
fprintf(fid,'\n');
fprintf(fid,'namespace amici {\n\n');
fprintf(fid,'namespace generic_model {\n\n');
fprintf(fid,'std::unique_ptr<amici::Model> getModel();\n');
fprintf(fid,'\n');
fprintf(fid,'} // namespace generic_model\n\n');
fprintf(fid,'} // namespace amici \n\n');
fprintf(fid,'#endif /* _amici_wrapfunctions_h */\n');
fclose(fid);

%
%----------------------------------------------------------------
% modelname.h
% model specific function declarations
%----------------------------------------------------------------
%
matVer = ver('MATLAB');
fid = fopen(fullfile(this.wrap_path,'models',this.modelname,[this.modelname '.h']),'w');
fprintf(fid,['#ifndef _amici_' this.modelname '_h\n']);
fprintf(fid,['#define _amici_' this.modelname '_h\n']);
fprintf(fid,['/* Generated by amiwrap ' matVer.Release ' ' getCommitHash(fileparts(fileparts(mfilename('fullpath')))) ' */\n']);
fprintf(fid,'#include <cmath>\n');
fprintf(fid,'#include <memory>\n');
fprintf(fid,'#include "amici/defines.h"\n');
fprintf(fid,'#include <sunmatrix/sunmatrix_sparse.h> //SUNMatrixContent_Sparse definition\n');
if(~strcmp(this.wtype,'iw'))
    fprintf(fid,'#include "amici/solver_cvodes.h"\n');
    fprintf(fid,'#include "amici/model_ode.h"\n');
else
    fprintf(fid,'#include "amici/solver_idas.h"\n');
    fprintf(fid,'#include "amici/model_dae.h"\n');
end
fprintf(fid,'\n');
fprintf(fid,'namespace amici {\n\n');
fprintf(fid,'class Solver;\n\n');
fprintf(fid,['namespace model_' this.modelname '{\n\n']);

for ifun = this.funs
    if(~isfield(this.fun,ifun{1}))

        this.fun(1).(ifun{1}) = amifun(ifun{1},this); % don't use getfun here
        % as we do not want symbolics to be generated, we only want to be able
        % access argstr
    end
    if(checkIfFunctionBodyIsNonEmpty(this,ifun{1}))
        cppFunctionName = strrep(ifun{1}, 'sigma_', 'sigma');
        fprintf(fid,['extern void ' cppFunctionName '_' this.modelname this.fun.(ifun{1}).argstr ';\n']);
    end
end

% Subclass Model
fprintf(fid,'\n');
if(strcmp(this.wtype,'iw'))
    baseclass = 'Model_DAE';
else
    baseclass = 'Model_ODE';
end

fprintf(fid,['class Model_' this.modelname ' : public amici::' baseclass ' {\n']);
fprintf(fid,'public:\n');
fprintf(fid,['    Model_' this.modelname '()\n']);
fprintf(fid,['        : amici::' baseclass '(\n']);
fprintf(fid,['              amici::ModelDimensions(\n']);
fprintf(fid,['                  ' num2str(this.nx) ',\n']);
fprintf(fid,['                  ' num2str(this.nxtrue) ',\n']);
fprintf(fid,['                  ' num2str(this.nx) ',\n']);
fprintf(fid,['                  ' num2str(this.nxtrue) ',\n']);
fprintf(fid,['                  0,\n']);
fprintf(fid,['                  ' num2str(this.np) ',\n']);
fprintf(fid,['                  ' num2str(this.nk) ',\n']);
fprintf(fid,['                  ' num2str(this.ny) ',\n']);
fprintf(fid,['                  ' num2str(this.nytrue) ',\n']);
fprintf(fid,['                  ' num2str(this.nz) ',\n']);
fprintf(fid,['                  ' num2str(this.nztrue) ',\n']);
fprintf(fid,['                  ' num2str(this.nevent) ',\n']);
fprintf(fid,['                  ' num2str(this.ng) ',\n']);
fprintf(fid,['                  ' num2str(this.nw) ',\n']);
fprintf(fid,['                  ' num2str(this.ndwdx) ',\n']);
fprintf(fid,['                  ' num2str(this.ndwdp) ',\n']);
fprintf(fid,['                  0,\n']);
fprintf(fid,['                  0,\n']);
fprintf(fid,['                  {},\n']);
fprintf(fid,['                  ' num2str(this.nnz) ',\n']);
fprintf(fid,['                  ' num2str(this.ubw) ',\n']);
fprintf(fid,['                  ' num2str(this.lbw) '\n']);
fprintf(fid,['              ),\n']);
fprintf(fid,['              amici::SimulationParameters(\n']);
fprintf(fid,['                  std::vector<realtype>(' num2str(this.nk) ', 1.0),\n']);
fprintf(fid,['                  std::vector<realtype>(' num2str(this.np) ', 1.0)\n']);
fprintf(fid,['              ),\n']);
switch(this.o2flag)
    case 1
        fprintf(fid,'              amici::SecondOrderMode::full,\n');
    case 2
        fprintf(fid,'              amici::SecondOrderMode::directional,\n');
    otherwise
        fprintf(fid,'              amici::SecondOrderMode::none,\n');
end
initstr = num2str(this.id, '%d, ');
fprintf(fid,['              std::vector<realtype>{' initstr(1:end-1) '},\n']);
initstr = num2str(transpose(this.z2event), '%d, ');
fprintf(fid,['              std::vector<int>{' initstr(1:end-1) '})\n']);
fprintf(fid,['              {};\n\n']);
fprintf(fid,['    virtual amici::Model* clone() const override { return new Model_' this.modelname '(*this); };\n\n']);
fprintf(fid,['    const  std::string getAmiciCommit() const override { return "' getCommitHash(fileparts(fileparts(mfilename('fullpath')))) '"; };\n\n']);

for ifun = this.funs
    cppFunctionName = strrep(ifun{1}, 'sigma_', 'sigma');
    fprintf(fid,['    virtual void f' cppFunctionName this.fun.(ifun{1}).argstr ' override {\n']);
    if(checkIfFunctionBodyIsNonEmpty(this,ifun{1}))
        fprintf(fid,['        ' cppFunctionName '_' this.modelname '' removeTypes(this.fun.(ifun{1}).argstr) ';\n']);
    end
    fprintf(fid,'    }\n\n');
end
fprintf(fid,'};\n\n');
fprintf(fid,['} // namespace model_' this.modelname '\n\n']);
fprintf(fid,'} // namespace amici \n\n');
fprintf(fid,['#endif /* _amici_' this.modelname '_h */\n']);
fclose(fid);

% wrapfunctions.cpp
fid = fopen(fullfile(this.wrap_path,'models',this.modelname,'wrapfunctions.cpp'),'w');
fprintf(fid,'#include "amici/model.h"\n');
fprintf(fid,'#include "wrapfunctions.h"\n\n');
fprintf(fid,'namespace amici {\n\n');
fprintf(fid,'namespace generic_model {\n\n');
fprintf(fid,'std::unique_ptr<amici::Model> getModel() {\n');
fprintf(fid,'    return std::unique_ptr<amici::Model>(\n');
fprintf(fid,['        new amici::model_' this.modelname '::Model_' this.modelname '());\n']);
fprintf(fid,'}\n\n');
fprintf(fid,'} // namespace generic_model\n\n');
fprintf(fid,'} // namespace amici \n\n');
fclose(fid);

fprintf('CMakeLists | ');
generateCMakeFile(this);

fprintf('swig | ');
generateSwigInterfaceFiles(this)

fprintf('main | ');
generateMainC(this);

fprintf('\r')
end


function argstr = removeTypes(argstr)
% removeTypes transforms an argument string from a string with variable
% types (for function definition) to a string without variable types
% (for function calling)
%
% Parameters:
%  argstr: function definition argument string @type *char
%
% Return values:
%  argstr: function call argument string @type *char

argstr = strrep(argstr,'realtype','');
argstr = strrep(argstr,'int','');
argstr = strrep(argstr,'const','');
argstr = strrep(argstr,'double','');
argstr = strrep(argstr,'SUNMatrixContent_Sparse','');
argstr = strrep(argstr,'*','');
argstr = strrep(argstr,' ','');
argstr = strrep(argstr,',',', ');

end


function generateCMakeFile(this)
    sourceStr = '';
    for j=1:length(this.funs)
        funcName = this.funs{j};
        if(checkIfFunctionBodyIsNonEmpty(this,funcName))
            cppFunctionName = strrep(funcName, 'sigma_', 'sigma');
            sourceStr = [ sourceStr, sprintf('${MODEL_DIR}/%s_%s.cpp\n', this.modelname, cppFunctionName) ];
        end
    end

    t = template();
    t.add('TPL_MODELNAME', this.modelname);
    t.add('TPL_SOURCES', sourceStr);
    t.add('TPL_AMICI_VERSION', '');
    CMakeFileName = fullfile(this.wrap_path,'models',this.modelname,'CMakeLists.txt');
    CMakeTemplateFileName = fullfile(fileparts(fileparts(fileparts(mfilename('fullpath')))), 'src' , 'CMakeLists.template.cmake');
    t.replace(CMakeTemplateFileName, CMakeFileName);
end

function generateSwigInterfaceFiles(this)

    modelSwigDir = fullfile(this.wrap_path,'models',this.modelname,'swig');
    amiciSwigDir = fullfile(fileparts(fileparts(fileparts(mfilename('fullpath')))),'swig');
    if(~exist(modelSwigDir,'dir'))
        mkdir(modelSwigDir)
    end

    %interface file
    t = template();
    t.add('TPL_MODELNAME', this.modelname);
    SwigInterfaceFile = fullfile(modelSwigDir,[this.modelname '.i']);
    SwigInterfaceTemplateFileName = fullfile(amiciSwigDir, 'modelname.template.i');
    t.replace(SwigInterfaceTemplateFileName, SwigInterfaceFile);

    %CMakeLists.txt
    if(~exist(fullfile(this.wrap_path,'models',this.modelname,'swig'),'dir'))
        mkdir(fullfile(this.wrap_path,'models',this.modelname),'swig');
    end
    copyfile(fullfile(amiciSwigDir,'CMakeLists_model.cmake'),fullfile(modelSwigDir,'CMakeLists.txt'));

end



function generateMainC(this)
    mainFileSource = fullfile(fileparts(fileparts(fileparts(mfilename('fullpath')))), 'src/main.template.cpp');
    mainFileDestination = fullfile(this.wrap_path,'models',this.modelname,'main.cpp');
    copyfile(mainFileSource, mainFileDestination);
end

function nonempty = checkIfFunctionBodyIsNonEmpty(this,ifun)
    % if we don't have symbolic variables, it might have been generated before and symbolic expressions were simply not
    % regenerated. any() for empty (no generated) variables is always false.
    cppFunctionName = strrep(ifun, 'sigma_', 'sigma');
    nonempty = or(exist(fullfile(this.wrap_path,'models',this.modelname,[this.modelname '_' cppFunctionName '.cpp']),'file'),any(this.fun.(ifun).sym(:)~=0));
end
