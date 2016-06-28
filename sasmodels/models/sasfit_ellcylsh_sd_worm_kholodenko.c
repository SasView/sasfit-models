///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R0,  double SIGMA_R0,  double EPSILON,  double T,
           double LLB,  double LL,  double LEXV,  double ETA_CORE,  double ETA_SHELL,
           double ETA_SOLV,  double R,  double Q);
double Fq( double q,  double R0,  double SIGMA_R0,  double EPSILON,  double T,
           double LLB,  double LL,  double LEXV,  double ETA_CORE,  double ETA_SHELL,
           double ETA_SOLV,  double R,  double Q);
double form_volume(  double R0,  double SIGMA_R0,  double EPSILON,  double T,
                     double LLB,  double LL,  double LEXV,  double ETA_CORE,  double ETA_SHELL,
                     double ETA_SOLV,  double R,  double Q);
double Iqxy( double qx, double qy, double R0, double SIGMA_R0, double EPSILON,
             double T, double LLB, double LL, double LEXV, double ETA_CORE, double ETA_SHELL,
             double ETA_SOLV, double R, double Q);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double R0,  double SIGMA_R0,  double EPSILON,  double T,
           double LLB,  double LL,  double LEXV,  double ETA_CORE,  double ETA_SHELL,
           double ETA_SOLV,  double R,  double Q)
{
    double Pcs,Pprime;
    sasfit_param subParam;
// insert your code here
    Pcs=sasfit_ff_pcs_ellcylsh(q,param);
    sasfit_init_param( &subParam );
    subParam.p[0] = LLB;
    subParam.p[1] = LL;
    Pprime = sasfit_sq_p__q___kholodenko_worm(q,&subParam);
    return Pcs*Pprime;
}
double Fq( double q,  double R0,  double SIGMA_R0,  double EPSILON,  double T,
           double LLB,  double LL,  double LEXV,  double ETA_CORE,  double ETA_SHELL,
           double ETA_SOLV,  double R,  double Q)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R0,  double SIGMA_R0,  double EPSILON,  double T,
                     double LLB,  double LL,  double LEXV,  double ETA_CORE,  double ETA_SHELL,
                     double ETA_SOLV,  double R,  double Q)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R0, double SIGMA_R0, double EPSILON,
             double T, double LLB, double LL, double LEXV, double ETA_CORE, double ETA_SHELL,
             double ETA_SOLV, double R, double Q)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R0, SIGMA_R0, EPSILON, T, LLB, LL, LEXV, ETA_CORE, ETA_SHELL,
               ETA_SOLV, R, Q);
}
