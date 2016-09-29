///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf.h>

double Iq( double q, double R,  double DUMMY1,  double DUMMY2,  double ETA,
           double P0);
double Fq( double q,  double R,  double DUMMY1,  double DUMMY2,  double ETA,
           double P0);
double form_volume(  double R,  double DUMMY1,  double DUMMY2,  double ETA,
                     double P0);
double Iqxy( double qx, double qy, double R, double DUMMY1, double DUMMY2,
             double ETA, double P0);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local R, DUMMY1, DUMMY2, ETA, P0eters/variables
double Iq( double q, double R,  double DUMMY1,  double DUMMY2,  double ETA,
           double P0)
{
    double z = q;
    double xi,xi2,Gz,G0;
// insert your code here
    G0 =  2*M_PI*sas_pow_4(R)*ETA*ETA;
    if (z>2*R)return -G0;
    if (z==0) return 0;
    xi=z/(2*R);
    xi2=xi*xi;
    Gz = M_PI*sas_pow_4(R)*ETA*ETA*(sqrt(1-xi2)*(2+xi2)+xi2*(4-xi2)*log(xi/(1+sqrt(
                                        1-xi2))));
    return Gz-G0;
}
double Fq( double q,  double R,  double DUMMY1,  double DUMMY2,  double ETA,
           double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R,  double DUMMY1,  double DUMMY2,  double ETA,
                     double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R, double DUMMY1, double DUMMY2,
             double ETA, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R, DUMMY1, DUMMY2, ETA, P0);
}
