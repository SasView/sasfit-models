///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double I0, double XI);
double Fq( double q,  double I0, double XI);
double form_volume(  double I0, double XI);
double Iqxy( double qx, double qy, double I0, double XI);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double I0, double XI)
{
// insert your code here
    return I0/pow(q*q * XI*XI+1.0,2.0);;
}
double Fq( double q,  double I0, double XI)
{
// insert your code here
    return 0.0;
}
double form_volume(  double I0, double XI)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double I0, double XI)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, I0, XI);
}
