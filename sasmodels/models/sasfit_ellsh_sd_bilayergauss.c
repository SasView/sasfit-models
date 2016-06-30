///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double T,  double P0,  double LB,  double B,  double L,
           double EXVOL,  double CLB);
double Fq( double q,  double T,  double P0,  double LB,  double B,  double L,
           double EXVOL,  double CLB);
double form_volume(  double T,  double P0,  double LB,  double B,  double L,
                     double EXVOL,  double CLB);
double Iqxy( double qx, double qy, double T, double P0, double LB, double B,
             double L, double EXVOL, double CLB);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local T, P0, LB, B, L, EXVOL, CLBeters/variables
double Iq( double q, double T,  double P0,  double LB,  double B,  double L,
           double EXVOL,  double CLB)
{
// insert your code here
    return 0.0;
}
double Fq( double q,  double T,  double P0,  double LB,  double B,  double L,
           double EXVOL,  double CLB)
{
// insert your code here
    return 0.0;
}
double form_volume(  double T,  double P0,  double LB,  double B,  double L,
                     double EXVOL,  double CLB)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double T, double P0, double LB, double B,
             double L, double EXVOL, double CLB)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, T, P0, LB, B, L, EXVOL, CLB);
}
