///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double homoXS_core(double x, sasfit_param *param)
{
    double Pcs, u, LNdistr;
    sasfit_param subParam;
    u = Q*x*0.5;
    if (u  == 0.0)
    {
        Pcs = sas_pow_2((ETA_L-ETA_SOL)*x);
    } else {
        Pcs = sas_pow_2((ETA_L-ETA_SOL)*x*sin(u)/u);
    }
    sasfit_init_param( &subParam );
    subParam.p[0] = 1.0;
    subParam.p[1] = SIGMA_T;
    subParam.p[2] = 1.0;
    subParam.p[3] = T;
    LNdistr = sasfit_sd_LogNorm(x, &subParam);
    return LNdistr*Pcs;
}
double homogeneousXS(double q, sasfit_param * param)
{
    double Pcs, u;
    double tstart = 0.0, tend = 0.0;
    Q = q;
    if (SIGMA_T == 0.0) {
        u = q*T*0.5;
        if (u  == 0.0) {
            Pcs = sas_pow_2(T);
        } else {
            Pcs = sas_pow_2(T*sin(u)/u);
        }
    } else {
        find_LogNorm_int_range(2,T,SIGMA_T,&tstart,&tend,param);
        Pcs 	= sasfit_integrate(tstart, tend, &homoXS_core, param);
    }
    return Pcs;
}
double sasfit_ff_pcs_homogeneousplate(double q, sasfit_param * param)
{
// insert your code here
    return homogeneousXS(q,param)*sas_pow_2(ETA_L-ETA_SOL);
}
double sasfit_ff_pcs_homogeneousplate_f(double q, sasfit_param * param)
{
// insert your code here
    return 0.0;
}
double sasfit_ff_pcs_homogeneousplate_v(double q, sasfit_param * param,
                                        int dist)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double T, double SIGMA_T, double DUMMY1,
             double DUMMY2, double ETA_L, double ETA_SOL, double Q)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, T, SIGMA_T, DUMMY1, DUMMY2, ETA_L, ETA_SOL, Q);
}
