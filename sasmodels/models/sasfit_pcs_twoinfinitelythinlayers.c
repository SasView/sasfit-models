///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double T,  double SIGMA_T,  double Q,  double P0,
           double LB,  double B,  double L,  double EXVOL,  double CLB);
double Fq( double q,  double T,  double SIGMA_T,  double Q,  double P0,
           double LB,  double B,  double L,  double EXVOL,  double CLB);
double form_volume(  double T,  double SIGMA_T,  double Q,  double P0,
                     double LB,  double B,  double L,  double EXVOL,  double CLB);
double Iqxy( double qx, double qy, double T, double SIGMA_T, double Q,
             double P0, double LB, double B, double L, double EXVOL, double CLB);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local T, SIGMA_T, Q, P0, LB, B, L, EXVOL, CLBeters/variables
double thincentrosymmetriclayers_core(double x,  double T,  double SIGMA_T,
                                      double Q,  double P0,  double LB,  double B,  double L,  double EXVOL,
                                      double CLB)
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
double thincentrosymmetriclayers(double q,  double T,  double SIGMA_T,
                                 double Q,  double P0,  double LB,  double B,  double L,  double EXVOL,
                                 double CLB)
{
    double tstart = 0.0, tend = 0.0;
    static double Q_old = -1.;
    static double T0_old = -1.;
    static double sigma_T_old = -1.;
    static double Pcs = 1.;
    Q = q;
    if ((Q != Q_old) || (T != T0_old) || (SIGMA_T != sigma_T_old))
    {
        if (SIGMA_T == 0.0)
        {
            Pcs = sas_pow_2(cos(q*T/2));
        }
        else
        {
            find_LogNorm_int_range(2,T,SIGMA_T,&tstart,&tend,T, SIGMA_T, Q, P0, LB, B, L,
                                   EXVOL, CLB);
            Pcs 	= sasfit_integrate(tstart, tend, &thincentrosymmetriclayers_core, T,
                                       SIGMA_T, Q, P0, LB, B, L, EXVOL, CLB);
        }
        Q_old	= Q;
        T0_old	= T;
        sigma_T_old = SIGMA_T;
    }
    return Pcs;
}
double Iq( double q, double T,  double SIGMA_T,  double Q,  double P0,
           double LB,  double B,  double L,  double EXVOL,  double CLB)
{
// insert your code here
    if (SIGMA_T == 0)
    {
        return sas_pow_2(cos(q*T));
    }
    else
    {
        return thincentrosymmetriclayers(q,T, SIGMA_T, Q, P0, LB, B, L, EXVOL, CLB);
    }
}
double Fq( double q,  double T,  double SIGMA_T,  double Q,  double P0,
           double LB,  double B,  double L,  double EXVOL,  double CLB)
{
// insert your code here
    return 0.0;
}
double form_volume(  double T,  double SIGMA_T,  double Q,  double P0,
                     double LB,  double B,  double L,  double EXVOL,  double CLB)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double T, double SIGMA_T, double Q,
             double P0, double LB, double B, double L, double EXVOL, double CLB)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, T, SIGMA_T, Q, P0, LB, B, L, EXVOL, CLB);
}
