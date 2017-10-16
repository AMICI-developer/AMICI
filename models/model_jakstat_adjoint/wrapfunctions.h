#ifndef _amici_wrapfunctions_h
#define _amici_wrapfunctions_h
#include <math.h>
#include <include/amici_model.h>
#include "model_jakstat_adjoint.h"
#include <include/amici_solver_cvodes.h>

class UserData;
class Solver;


#define pi M_PI

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

UserData getUserData();
Solver *getSolver();
Model *getModel();
int fx0(N_Vector x0, void *user_data);
int fdx0(N_Vector x0, N_Vector dx0, void *user_data);
int fsx0(N_Vector *sx0, N_Vector x, N_Vector dx, void *user_data);
int fsdx0(N_Vector *sdx0, N_Vector x, N_Vector dx, void *user_data);
int fJ(long int N, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fJB(long int NeqBdot, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B);
int fJDiag(realtype t, N_Vector JDiag, N_Vector x, void *user_data);
int fJv(N_Vector v, N_Vector Jv, realtype t, N_Vector x, N_Vector xdot, void *user_data, N_Vector tmp);
int froot(realtype t, N_Vector x, N_Vector dx, realtype *root, void *user_data);
int frz(realtype t, int ie, N_Vector x, TempData *tdata, ReturnData *rdata);
int fsrz(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata, ReturnData *rdata);
int fstau(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata);
int fy(realtype t, int it, N_Vector x, void *user_data, ReturnData *rdata);
int fdydp(realtype t, int it, N_Vector x, TempData *tdata);
int fdydx(realtype t, int it, N_Vector x, TempData *tdata);
int fz(realtype t, int ie, N_Vector x, TempData *tdata, ReturnData *rdata);
int fsz(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata, ReturnData *rdata);
int fdzdp(realtype t, int ie, N_Vector x, TempData *tdata);
int fdzdx(realtype t, int ie, N_Vector x, TempData *tdata);
int fdrzdp(realtype t, int ie, N_Vector x, TempData *tdata);
int fdrzdx(realtype t, int ie, N_Vector x, TempData *tdata);
int fsxdot(int Ns, realtype t, N_Vector x, N_Vector xdot,int ip,  N_Vector sx, N_Vector sxdot, void *user_data, N_Vector tmp1, N_Vector tmp2);
int fxdot(realtype t, N_Vector x, N_Vector dx, N_Vector xdot, void *user_data);
int fxBdot(realtype t, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, void *user_data);
int fqBdot(realtype t, N_Vector x, N_Vector xB, N_Vector qBdot, void *user_data);
int fdxdotdp(realtype t, N_Vector x, N_Vector dx, void *user_data);
int fdeltax(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, TempData *tdata);
int fdeltasx(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, N_Vector *sx, TempData *tdata);
int fdeltaxB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector xdot, N_Vector xdot_old, TempData *tdata);
int fdeltaqB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector qBdot, N_Vector xdot, N_Vector xdot_old, TempData *tdata);
int fsigma_y(realtype t, TempData *tdata);
int fdsigma_ydp(realtype t, TempData *tdata);
int fsigma_z(realtype t, int ie, TempData *tdata);
int fdsigma_zdp(realtype t, int ie, TempData *tdata);
int fJSparse(realtype t, N_Vector x, N_Vector xdot, SlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fJBand(long int N, long int mupper, long int mlower, realtype t, N_Vector x, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fJSparseB(realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, SlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B);
int fJBandB(long int NeqBdot, long int mupper, long int mlower, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B);
int fJvB(N_Vector vB, N_Vector JvB, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, void *user_data, N_Vector tmpB);
int fJy(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fJz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fJrz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJydy(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJydsigma(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJzdz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJzdsigma(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJrzdz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJrzdsigma(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fddydpdp(realtype t, int it, N_Vector x, TempData *tdata);
int fddydpdx(realtype t, int it, N_Vector x, TempData *tdata);
int fddydxdx(realtype t, int it, N_Vector x, TempData *tdata);
int fs2x0(realtype *s2x0, N_Vector x, N_Vector dx, void *user_data);
int fddJydsigmady(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fddJydsigmadsigma(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fddJy_s2sigma(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fddJydydy(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);

class Model_model_jakstat_adjoint : public Model {
public:
    Model_model_jakstat_adjoint() : Model(17,
                    9,
                    9,
                    2,
                    3,
                    3,
                    0,
                    0,
                    0,
                    1,
                    2,
                    1,
                    5,
                    18,
                    8,
                    1,
                    AMICI_O2MODE_NONE)
    {
        z2event = new int[0] {};
        idlist = new realtype[9] {0, 0, 0, 0, 0, 0, 0, 0, 0,};
    }

    Solver *getSolver() override {
        return new CVodeSolver();
    }

    int fxdot(realtype t, N_Vector x, N_Vector dx, N_Vector xdot, void *user_data) override {
        return xdot_model_jakstat_adjoint(t, x, xdot, user_data);
    }

    int fw(realtype t, N_Vector x, N_Vector dx, void *user_data) override {
        return w_model_jakstat_adjoint(t, x, dx, user_data);
    }

    int fdwdx(realtype t, N_Vector x, N_Vector dx, void *user_data) override {
        return dwdx_model_jakstat_adjoint(t, x, dx, user_data);
    }

    int fJ(long int N, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) override {
        return J_model_jakstat_adjoint(N, t, x, xdot, J, user_data, tmp1, tmp2, tmp3);
    }

    int fx0(N_Vector x0, void *user_data) override {
        return x0_model_jakstat_adjoint(x0, user_data);
    }

    int fJv(N_Vector v, N_Vector Jv, realtype t, N_Vector x, N_Vector xdot, void *user_data, N_Vector tmp) override {
        return Jv_model_jakstat_adjoint(v, Jv, t, x, xdot, user_data, tmp);
    }

    int fJBand(long int N, long int mupper, long int mlower, realtype t, N_Vector x, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) override {
        return JBand_model_jakstat_adjoint(N, mupper, mlower, t, x, xdot, J, user_data, tmp1, tmp2, tmp3);
    }

    int fJSparse(realtype t, N_Vector x, N_Vector xdot, SlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) override {
        return JSparse_model_jakstat_adjoint(t, x, xdot, J, user_data, tmp1, tmp2, tmp3);
    }

    int fJDiag(realtype t, N_Vector JDiag, N_Vector x, void *user_data) override {
        return JDiag_model_jakstat_adjoint(t, JDiag, x, user_data);
    }

    int fy(realtype t, int it, N_Vector x, void *user_data, ReturnData *rdata) override {
        return y_model_jakstat_adjoint(t, it, x, user_data, rdata);
    }

    int fz(realtype t, int ie, N_Vector x, TempData *tdata, ReturnData *rdata) override {
        return z_model_jakstat_adjoint(t, ie, x, tdata, rdata);
    }

    int frz(realtype t, int ie, N_Vector x, TempData *tdata, ReturnData *rdata) override {
        return rz_model_jakstat_adjoint(t, ie, x, tdata, rdata);
    }

    int fdeltax(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, TempData *tdata) override {
        return deltax_model_jakstat_adjoint(t, ie, x, xdot, xdot_old, tdata);
    }

    int froot(realtype t, N_Vector x, N_Vector dx, realtype *root, void *user_data) override {
        return root_model_jakstat_adjoint(t, x, root, user_data);
    }

    int fJy(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return Jy_model_jakstat_adjoint(t, it, x, tdata, edata, rdata);
    }

    int fJz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return Jz_model_jakstat_adjoint(t, ie, x, tdata, edata, rdata);
    }

    int fJrz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return Jrz_model_jakstat_adjoint(t, ie, x, tdata, edata, rdata);
    }

    int fsigma_y(realtype t, TempData *tdata) override {
        return sigma_y_model_jakstat_adjoint(t, tdata);
    }

    int fsigma_z(realtype t, int ie, TempData *tdata) override {
        return sigma_z_model_jakstat_adjoint(t, ie, tdata);
    }

    int fsxdot(int Ns, realtype t, N_Vector x, N_Vector xdot,int ip,  N_Vector sx, N_Vector sxdot, void *user_data, N_Vector tmp1, N_Vector tmp2) override {
        return sxdot_model_jakstat_adjoint(Ns, t, x, xdot, ip, sx, sxdot, user_data, tmp1, tmp2);
    }

    int fsx0(N_Vector *sx0, N_Vector x, N_Vector dx, void *user_data) override {
        return sx0_model_jakstat_adjoint(sx0, x, dx, user_data);
    }

    int fsz(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata, ReturnData *rdata) override {
        return sz_model_jakstat_adjoint(t, ie, x, sx, tdata, rdata);
    }

    int fdeltasx(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, N_Vector *sx, TempData *tdata) override {
        return deltasx_model_jakstat_adjoint(t, ie, x, xdot, xdot_old, sx, tdata);
    }

    int fstau(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata) override {
        return stau_model_jakstat_adjoint(t, ie, x, sx, tdata);
    }

    int fsrz(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata, ReturnData *rdata) override {
        return srz_model_jakstat_adjoint(t, ie, x, sx, tdata, rdata);
    }

    int fdJydy(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return dJydy_model_jakstat_adjoint(t, it, x, tdata, edata, rdata);
    }

    int fdJydsigma(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return dJydsigma_model_jakstat_adjoint(t, it, x, tdata, edata, rdata);
    }

    int fdJzdz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return dJzdz_model_jakstat_adjoint(t, ie, x, tdata, edata, rdata);
    }

    int fdJzdsigma(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return dJzdsigma_model_jakstat_adjoint(t, ie, x, tdata, edata, rdata);
    }

    int fdJrzdz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return dJrzdz_model_jakstat_adjoint(t, ie, x, tdata, edata, rdata);
    }

    int fdJrzdsigma(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return dJrzdsigma_model_jakstat_adjoint(t, ie, x, tdata, edata, rdata);
    }

    int fdwdp(realtype t, N_Vector x, N_Vector dx, void *user_data) override {
        return dwdp_model_jakstat_adjoint(t, x, dx, user_data);
    }

    int fdxdotdp(realtype t, N_Vector x, N_Vector dx, void *user_data) override {
        return dxdotdp_model_jakstat_adjoint(t, x, dx, user_data);
    }

    int fdydp(realtype t, int it, N_Vector x, TempData *tdata) override {
        return dydp_model_jakstat_adjoint(t, it, x, tdata);
    }

    int fdsigma_ydp(realtype t, TempData *tdata) override {
        return dsigma_ydp_model_jakstat_adjoint(t, tdata);
    }

    int fdsigma_zdp(realtype t, int ie, TempData *tdata) override {
        return dsigma_zdp_model_jakstat_adjoint(t, ie, tdata);
    }

    int fdydx(realtype t, int it, N_Vector x, TempData *tdata) override {
        return dydx_model_jakstat_adjoint(t, it, x, tdata);
    }

    int fdzdx(realtype t, int ie, N_Vector x, TempData *tdata) override {
        return dzdx_model_jakstat_adjoint(t, ie, x, tdata);
    }

    int fdzdp(realtype t, int ie, N_Vector x, TempData *tdata) override {
        return dzdp_model_jakstat_adjoint(t, ie, x, tdata);
    }

    int fdrzdx(realtype t, int ie, N_Vector x, TempData *tdata) override {
        return drzdx_model_jakstat_adjoint(t, ie, x, tdata);
    }

    int fdrzdp(realtype t, int ie, N_Vector x, TempData *tdata) override {
        return drzdp_model_jakstat_adjoint(t, ie, x, tdata);
    }

    int fxBdot(realtype t, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, void *user_data) override {
        return xBdot_model_jakstat_adjoint(t, x, xB, xBdot, user_data);
    }

    int fqBdot(realtype t, N_Vector x, N_Vector xB, N_Vector qBdot, void *user_data) override {
        return qBdot_model_jakstat_adjoint(t, x, xB, qBdot, user_data);
    }

    int fJB(long int NeqBdot, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B) override {
        return JB_model_jakstat_adjoint(NeqBdot, t, x, xB, xBdot, JB, user_data, tmp1B, tmp2B, tmp3B);
    }

    int fJvB(N_Vector vB, N_Vector JvB, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, void *user_data, N_Vector tmpB) override {
        return JvB_model_jakstat_adjoint(vB, JvB, t, x, xB, xBdot, user_data, tmpB);
    }

    int fJBandB(long int NeqBdot, long int mupper, long int mlower, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B) override {
        return JBandB_model_jakstat_adjoint(NeqBdot, mupper, mlower, t, x, xB, xBdot, JB, user_data, tmp1B, tmp2B, tmp3B);
    }

    int fJSparseB(realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, SlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B) override {
        return JSparseB_model_jakstat_adjoint(t, x, xB, xBdot, JB, user_data, tmp1B, tmp2B, tmp3B);
    }

    int fdeltaxB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector xdot, N_Vector xdot_old, TempData *tdata) override {
        return deltaxB_model_jakstat_adjoint(t, ie, x, xB, xdot, xdot_old, tdata);
    }

    int fdeltaqB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector qBdot, N_Vector xdot, N_Vector xdot_old, TempData *tdata) override {
        return deltaqB_model_jakstat_adjoint(t, ie, x, xB, qBdot, xdot, xdot_old, tdata);
    }

    int fddydpdp(realtype t, int it, N_Vector x, TempData *tdata) override {
        return ddydpdp_model_jakstat_adjoint(t, it, x, tdata);
    }

    int fddydpdx(realtype t, int it, N_Vector x, TempData *tdata) override {
        return ddydpdx_model_jakstat_adjoint(t, it, x, tdata);
    }

    int fddydxdx(realtype t, int it, N_Vector x, TempData *tdata) override {
        return ddydxdx_model_jakstat_adjoint(t, it, x, tdata);
    }

    int fs2x0(realtype *s2x0, N_Vector x, N_Vector dx, void *user_data) override {
        return s2x0_model_jakstat_adjoint(s2x0, x, dx, user_data);
    }

    int fddJydsigmady(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return ddJydsigmady_model_jakstat_adjoint(t, it, x, tdata, edata, rdata);
    }

    int fddJydsigmadsigma(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return ddJydsigmadsigma_model_jakstat_adjoint(t, it, x, tdata, edata, rdata);
    }

    int fddJy_s2sigma(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return ddJy_s2sigma_model_jakstat_adjoint(t, it, x, tdata, edata, rdata);
    }

    int fddJydydy(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) override {
        return ddJydydy_model_jakstat_adjoint(t, it, x, tdata, edata, rdata);
    }

};

#endif /* _amici_wrapfunctions_h */
