function rebuild_model_jakstat_adjoint_o2()
modelName = 'model_jakstat_adjoint_o2';
amimodel.compileAndLinkModel(modelName, '', [], [], [], []);
amimodel.generateMatlabWrapper(162, 54, 17, 2, 0,  , [], ['simulate_' modelName '.m'], 'model_jakstat_adjoint_o2', 'log10', 1, 1);
end
