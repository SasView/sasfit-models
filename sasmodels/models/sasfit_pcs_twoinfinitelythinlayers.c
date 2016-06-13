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
double thincentrosymmetriclayers_core(double x, sasfit_param *param)
{
    double Pcs, LNdistr;
    sasfit_param subParam;
    Pcs = sas_pow_2(cos(Q*x/2));
    sasfit_init_param( &subParam );
    subParam.p[0] = 1.0;
    subParam.p[1] = SIGMA_T;
    subParam.p[2] = 1.0;
    subParam.p[3] = T;
    LNdistr = sasfit_sd_LogNorm(x, &subParam);
    return LNdistr*Pcs;
}
double thincentrosymmetriclayers(double q, sasfit_param * param)
{
    double tstart = 0.0, tend = 0.0;
    static double Q_old = -1.;
    static double T0_old = -1.;
    static double sigma_T_old = -1.;
    static double Pcs = 1.;
    Q = q;
    if ((Q != Q_old) || (T != T0_old) || (SIGMA_T != sigma_T_old)) {
        if (SIGMA_T == 0.0) {
            Pcs = sas_pow_2(cos(q*T/2));
        } else {
            find_LogNorm_int_range(2,T,SIGMA_T,&tstart,&tend,param);
            Pcs 	= sasfit_integrate(tstart, tend, &thincentrosymmetriclayers_core, param);
        }
        Q_old	= Q;
        T0_old	= T;
        sigma_T_old = SIGMA_T;
    }
    return Pcs;
}
double Iq( double q, double T, double SIGMA_T, double Q)
{
// insert your code here
    if (SIGMA_T == 0) {
        return sas_pow_2(cos(q*T));
    } else {
        return thincentrosymmetriclayers(q,param);
    }
}
double Fq( double q,  double T, double SIGMA_T, double Q)
{
// insert your code here
    return 0.0;
}
double form_volume(  double T, double SIGMA_T, double Q)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double T, double SIGMA_T, double Q)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, T, SIGMA_T, Q);
}
