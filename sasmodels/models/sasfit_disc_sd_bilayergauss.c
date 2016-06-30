///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double T,  double SIGMA_T,  double D,  double SIGMA_D,
           double DUMMY,  double DUMMY,  double SIGMA_OUT,  double B_OUT,
           double SIGMA_CORE,  double B_CORE,  double P0,  double LB,  double B,  double L,
           double EXVOL,  double CLB);
double Fq( double q,  double T,  double SIGMA_T,  double D,  double SIGMA_D,
           double DUMMY,  double DUMMY,  double SIGMA_OUT,  double B_OUT,
           double SIGMA_CORE,  double B_CORE,  double P0,  double LB,  double B,  double L,
           double EXVOL,  double CLB);
double form_volume(  double T,  double SIGMA_T,  double D,  double SIGMA_D,
                     double DUMMY,  double DUMMY,  double SIGMA_OUT,  double B_OUT,
                     double SIGMA_CORE,  double B_CORE,  double P0,  double LB,  double B,  double L,
                     double EXVOL,  double CLB);
double Iqxy( double qx, double qy, double T, double SIGMA_T, double D,
             double SIGMA_D, double DUMMY, double DUMMY, double SIGMA_OUT, double B_OUT,
             double SIGMA_CORE, double B_CORE, double P0, double LB, double B, double L,
             double EXVOL, double CLB);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local T, SIGMA_T, D, SIGMA_D, DUMMY, DUMMY, SIGMA_OUT, B_OUT, SIGMA_CORE, B_CORE, P0, LB, B, L, EXVOL, CLBeters/variables
double Iq( double q, double T,  double SIGMA_T,  double D,  double SIGMA_D,
           double DUMMY,  double DUMMY,  double SIGMA_OUT,  double B_OUT,
           double SIGMA_CORE,  double B_CORE,  double P0,  double LB,  double B,  double L,
           double EXVOL,  double CLB)
{
// insert your code here
    return 0.0;
}
double Fq( double q,  double T,  double SIGMA_T,  double D,  double SIGMA_D,
           double DUMMY,  double DUMMY,  double SIGMA_OUT,  double B_OUT,
           double SIGMA_CORE,  double B_CORE,  double P0,  double LB,  double B,  double L,
           double EXVOL,  double CLB)
{
// insert your code here
    return 0.0;
}
double form_volume(  double T,  double SIGMA_T,  double D,  double SIGMA_D,
                     double DUMMY,  double DUMMY,  double SIGMA_OUT,  double B_OUT,
                     double SIGMA_CORE,  double B_CORE,  double P0,  double LB,  double B,  double L,
                     double EXVOL,  double CLB)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double T, double SIGMA_T, double D,
             double SIGMA_D, double DUMMY, double DUMMY, double SIGMA_OUT, double B_OUT,
             double SIGMA_CORE, double B_CORE, double P0, double LB, double B, double L,
             double EXVOL, double CLB)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, T, SIGMA_T, D, SIGMA_D, DUMMY, DUMMY, SIGMA_OUT, B_OUT,
               SIGMA_CORE, B_CORE, P0, LB, B, L, EXVOL, CLB);
}
