///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double xi, double d, double eta);
double Fq( double q,  double xi, double d, double eta);
double form_volume(  double xi, double d, double eta);
double Iqxy( double qx, double qy, double xi, double d, double eta);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double xi, double d, double eta)
{
    double a, b, k, c, xi, d, eta;
// insert your code here
    k = 2.*M_PI/D;
    a = k*k + 1./(XI*XI);
    b = k*k - 1./(XI*XI);
    c = a*a - 2.*b*q*q + q*q*q*q;
    return eta*eta*8*M_PI/xi/c;
}
double Fq( double q,  double xi, double d, double eta)
{
// insert your code here
    return 0.0;
}
double form_volume(  double xi, double d, double eta)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double xi, double d, double eta)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, xi, d, eta);
}
