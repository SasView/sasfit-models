///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf.h>

double Iq( double q, double XI,  double DUMMY1,  double DUMMY2,  double ETA,
           double P0);
double Fq( double q,  double XI,  double DUMMY1,  double DUMMY2,  double ETA,
           double P0);
double form_volume(  double XI,  double DUMMY1,  double DUMMY2,  double ETA,
                     double P0);
double Iqxy( double qx, double qy, double XI, double DUMMY1, double DUMMY2,
             double ETA, double P0);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local XI, DUMMY1, DUMMY2, ETA, P0eters/variables
double Iq( double q, double XI,  double DUMMY1,  double DUMMY2,  double ETA,
           double P0)
{
    double u,Gz,G0;
    double z = q;
// insert your code here
    u=z/XI;
    G0=16*M_PI*sas_pow_4(XI)*ETA*ETA;
    if (fabs(u)<1e-6) {
        if (u*u==0) {
            Gz=G0;
        } else {
            Gz=G0*(1+u*u/4.*(2*M_EULER)-1+log(u*u/4.));
        }
    } else {
        Gz=G0*u*gsl_sf_bessel_K1(u);
    }
    return Gz-G0;
}
double Fq( double q,  double XI,  double DUMMY1,  double DUMMY2,  double ETA,
           double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double XI,  double DUMMY1,  double DUMMY2,  double ETA,
                     double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double XI, double DUMMY1, double DUMMY2,
             double ETA, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, XI, DUMMY1, DUMMY2, ETA, P0);
}
