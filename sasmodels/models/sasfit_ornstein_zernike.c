///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double I0,  double XI,  double P0);
double Fq( double q,  double I0,  double XI,  double P0);
double form_volume(  double I0,  double XI,  double P0);
double Iqxy( double qx, double qy, double I0, double XI, double P0);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local I0, XI, P0eters/variables
double Iq( double q, double I0,  double XI,  double P0)
{
// insert your code here
    return  I0/(q*q * XI*XI+ 1.0);;
}
double Fq( double q,  double I0,  double XI,  double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double I0,  double XI,  double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double I0, double XI, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, I0, XI, P0);
}
