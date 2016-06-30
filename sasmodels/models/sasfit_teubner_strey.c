///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double xi,  double d,  double eta,  double P0);
double Fq( double q,  double xi,  double d,  double eta,  double P0);
double form_volume(  double xi,  double d,  double eta,  double P0);
double Iqxy( double qx, double qy, double xi, double d, double eta, double P0);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local xi, d, eta, P0eters/variables
double Iq( double q, double xi,  double d,  double eta,  double P0)
{
    double a, b, k, c, xi, d, eta;
// insert your code here
    k = 2.*M_PI/D;
    a = k*k + 1./(XI*XI);
    b = k*k - 1./(XI*XI);
    c = a*a - 2.*b*q*q + q*q*q*q;
    return eta*eta*8*M_PI/xi/c;
}
double Fq( double q,  double xi,  double d,  double eta,  double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double xi,  double d,  double eta,  double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double xi, double d, double eta, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, xi, d, eta, P0);
}
