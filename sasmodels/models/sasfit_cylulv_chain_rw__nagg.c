///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double N,  double P0);
double Fq( double q,  double N,  double P0);
double form_volume(  double N,  double P0);
double Iqxy( double qx, double qy, double N, double P0);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local N, P0eters/variables
double Iq( double q, double N,  double P0)
{
// insert your code here
    return 0.0;
}
double Fq( double q,  double N,  double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double N,  double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double N, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, N, P0);
}
