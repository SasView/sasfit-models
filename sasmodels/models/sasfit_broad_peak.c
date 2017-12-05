///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double I0,  double XI,  double Q0,  double M,  double P);
double Fq( double q,  double I0,  double XI,  double Q0,  double M,  double P);
double form_volume(  double I0,  double XI,  double Q0,  double M,  double P);
double Iqxy( double qx, double qy, double I0, double XI, double Q0, double M,
             double P);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local I0, XI, Q0, M, P, P0eters/variables
double Iq( double q, double I0,  double XI,  double Q0,  double M,  double P)
{
// insert your code here
    return I0/pow(1.0+pow(fabs(q-Q0)*XI,M),P);
}
double Fq( double q,  double I0,  double XI,  double Q0,  double M,  double P)
{
// insert your code here
    return 0.0;
}
double form_volume(  double I0,  double XI,  double Q0,  double M,  double P)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double I0, double XI, double Q0, double M,
             double P)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, I0, XI, Q0, M, P);
}
