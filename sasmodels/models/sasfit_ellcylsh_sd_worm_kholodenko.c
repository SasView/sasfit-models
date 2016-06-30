///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R0,  double SIGMA_R0,  double EPSILON,  double T,
           double LLB,  double LL,  double LEXV,  double ETA_CORE,  double ETA_SHELL,
           double ETA_SOLV,  double R,  double Q,  double P0,  double LB,  double B,
           double L,  double EXVOL,  double CLB);
double Fq( double q,  double R0,  double SIGMA_R0,  double EPSILON,  double T,
           double LLB,  double LL,  double LEXV,  double ETA_CORE,  double ETA_SHELL,
           double ETA_SOLV,  double R,  double Q,  double P0,  double LB,  double B,
           double L,  double EXVOL,  double CLB);
double form_volume(  double R0,  double SIGMA_R0,  double EPSILON,  double T,
                     double LLB,  double LL,  double LEXV,  double ETA_CORE,  double ETA_SHELL,
                     double ETA_SOLV,  double R,  double Q,  double P0,  double LB,  double B,
                     double L,  double EXVOL,  double CLB);
double Iqxy( double qx, double qy, double R0, double SIGMA_R0, double EPSILON,
             double T, double LLB, double LL, double LEXV, double ETA_CORE, double ETA_SHELL,
             double ETA_SOLV, double R, double Q, double P0, double LB, double B, double L,
             double EXVOL, double CLB);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local R0, SIGMA_R0, EPSILON, T, LLB, LL, LEXV, ETA_CORE, ETA_SHELL, ETA_SOLV, R, Q, P0, LB, B, L, EXVOL, CLBeters/variables
double Iq( double q, double R0,  double SIGMA_R0,  double EPSILON,  double T,
           double LLB,  double LL,  double LEXV,  double ETA_CORE,  double ETA_SHELL,
           double ETA_SOLV,  double R,  double Q,  double P0,  double LB,  double B,
           double L,  double EXVOL,  double CLB)
{
    double Pcs,Pprime;
    sasfit_param subParam;
// insert your code here
    Pcs=sasfit_ff_pcs_ellcylsh(q,R0, SIGMA_R0, EPSILON, T, LLB, LL, LEXV, ETA_CORE,
                               ETA_SHELL, ETA_SOLV, R, Q, P0, LB, B, L, EXVOL, CLB);
    sasfit_init_param( &subParam );
    subParam.p[0] = LLB;
    subParam.p[1] = LL;
    Pprime = sasfit_sq_p__q___kholodenko_worm(q,&subParam);
    return Pcs*Pprime;
}
double Fq( double q,  double R0,  double SIGMA_R0,  double EPSILON,  double T,
           double LLB,  double LL,  double LEXV,  double ETA_CORE,  double ETA_SHELL,
           double ETA_SOLV,  double R,  double Q,  double P0,  double LB,  double B,
           double L,  double EXVOL,  double CLB)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R0,  double SIGMA_R0,  double EPSILON,  double T,
                     double LLB,  double LL,  double LEXV,  double ETA_CORE,  double ETA_SHELL,
                     double ETA_SOLV,  double R,  double Q,  double P0,  double LB,  double B,
                     double L,  double EXVOL,  double CLB)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R0, double SIGMA_R0, double EPSILON,
             double T, double LLB, double LL, double LEXV, double ETA_CORE, double ETA_SHELL,
             double ETA_SOLV, double R, double Q, double P0, double LB, double B, double L,
             double EXVOL, double CLB)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R0, SIGMA_R0, EPSILON, T, LLB, LL, LEXV, ETA_CORE, ETA_SHELL,
               ETA_SOLV, R, Q, P0, LB, B, L, EXVOL, CLB);
}
