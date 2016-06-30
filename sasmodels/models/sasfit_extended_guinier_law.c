///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double I0,  double A,  double RA,  double P0);
double Fq( double q,  double I0,  double A,  double RA,  double P0);
double form_volume(  double I0,  double A,  double RA,  double P0);
double Iqxy( double qx, double qy, double I0, double A, double RA, double P0);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local I0, A, RA, P0eters/variables
double Iq( double q, double I0,  double A,  double RA,  double P0)
{
    return ((A == 0.0) ? I0*exp(-RA*RA*q*q/3.0): A*M_PI*pow(q,
            -A)*I0*exp(-RA*RA*q*q/(3.0-A)) );
}
double Fq( double q,  double I0,  double A,  double RA,  double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double I0,  double A,  double RA,  double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double I0, double A, double RA, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, I0, A, RA, P0);
}
