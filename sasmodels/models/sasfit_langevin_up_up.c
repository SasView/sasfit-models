///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double NU);
double Fq( double q,  double NU);
double form_volume(  double NU);
double Iqxy( double qx, double qy, double NU);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
double Iq( double q, double NU)
{
    PSI = PSI_DEG*M_PI/180.0;
    AD = 1.0;
    R=1.0;
    R_AV=R;
    TEMPERATURE = 273.0;
    DAMP_ALPHA = 1.0;
    STATIC = 0.0;
    P_POL = -fabs(P_POL);
    EPSILON_FLIPPER = 1.0;
    T_PLUS = 1.0;
    T_MINUS = 0.0;
    return i_measured(t,param);
}
double Fq( double q,  double NU)
{
// insert your code here
    return 0.0;
}
double form_volume(  double NU)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double NU)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, NU);
}
