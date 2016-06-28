///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double T,  double SIGMA_T,  double R0,  double SIGMA_R0,
           double EPSILON,  double DUMMY,  double ETA_L,  double ETA_SOL);
double Fq( double q,  double T,  double SIGMA_T,  double R0,  double SIGMA_R0,
           double EPSILON,  double DUMMY,  double ETA_L,  double ETA_SOL);
double form_volume(  double T,  double SIGMA_T,  double R0,  double SIGMA_R0,
                     double EPSILON,  double DUMMY,  double ETA_L,  double ETA_SOL);
double Iqxy( double qx, double qy, double T, double SIGMA_T, double R0,
             double SIGMA_R0, double EPSILON, double DUMMY, double ETA_L, double ETA_SOL);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double T,  double SIGMA_T,  double R0,  double SIGMA_R0,
           double EPSILON,  double DUMMY,  double ETA_L,  double ETA_SOL)
{
    double Pcs, Pprime;
    sasfit_param subParam;
// insert your code here
    Pcs = sasfit_ff_pcs_homogeneousplate(q,param);
    sasfit_init_param( &subParam );
    subParam.p[0] = R0;
    subParam.p[1] = EPSILON;
    subParam.p[2] = SIGMA_R0;
    Pprime = sasfit_sq_p__q___thin_ellipsoidal_shell(q,&subParam);
    return Pcs*Pprime;
}
double Fq( double q,  double T,  double SIGMA_T,  double R0,  double SIGMA_R0,
           double EPSILON,  double DUMMY,  double ETA_L,  double ETA_SOL)
{
// insert your code here
    return 0.0;
}
double form_volume(  double T,  double SIGMA_T,  double R0,  double SIGMA_R0,
                     double EPSILON,  double DUMMY,  double ETA_L,  double ETA_SOL)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double T, double SIGMA_T, double R0,
             double SIGMA_R0, double EPSILON, double DUMMY, double ETA_L, double ETA_SOL)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, T, SIGMA_T, R0, SIGMA_R0, EPSILON, DUMMY, ETA_L, ETA_SOL);
}
