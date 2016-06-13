///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double I0, double A, double RA)
{
    return ((A == 0.0) ? I0*exp(-RA*RA*q*q/3.0): A*M_PI*pow(q,
            -A)*I0*exp(-RA*RA*q*q/(3.0-A)) );
}
double Fq( double q,  double I0, double A, double RA)
{
// insert your code here
    return 0.0;
}
double form_volume(  double I0, double A, double RA)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double I0, double A, double RA)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, I0, A, RA);
}
