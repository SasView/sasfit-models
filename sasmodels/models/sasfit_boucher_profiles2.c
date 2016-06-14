///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R, double ALPHA, double DELTA_ETA);
double Fq( double q,  double R, double ALPHA, double DELTA_ETA);
double form_volume(  double R, double ALPHA, double DELTA_ETA);
double Iqxy( double qx, double qy, double R, double ALPHA, double DELTA_ETA);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double R, double ALPHA, double DELTA_ETA)
{
// insert your code here
    if (fabs(r)>fabs(R)) {
        return 0;
    } else {
        return DELTA_ETA*pow((1-sas_pow_2(r/R)),ALPHA/2.-2)*4./3.*M_PI/
               (sas_pow_3(sqrt(M_PI))*sas_gamma(ALPHA/2.-1)/sas_gamma(ALPHA/2.+0.5));
    }
}
double Fq( double q,  double R, double ALPHA, double DELTA_ETA)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R, double ALPHA, double DELTA_ETA)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R, double ALPHA, double DELTA_ETA)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R, ALPHA, DELTA_ETA);
}
