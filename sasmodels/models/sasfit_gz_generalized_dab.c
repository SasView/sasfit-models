///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf.h>

double Iq( double q, double A,  double H,  double DUMMY,  double ETA,
           double P0);
double Fq( double q,  double A,  double H,  double DUMMY,  double ETA,
           double P0);
double form_volume(  double A,  double H,  double DUMMY,  double ETA,
                     double P0);
double Iqxy( double qx, double qy, double A, double H, double DUMMY, double ETA,
             double P0);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
double dgamma(double x)
{
    int k, n;
    double w, y;
    n = x < 1.5 ? -((int) (2.5 - x)) : (int) (x - 1.5);
    w = x - (n + 2);
    y = ((((((((((((-1.99542863674e-7 * w + 1.337767384067e-6) * w -
                   2.591225267689e-6) * w - 1.7545539395205e-5) * w +
                 1.45596568617526e-4) * w - 3.60837876648255e-4) * w -
               8.04329819255744e-4) * w + 0.008023273027855346) * w -
             0.017645244547851414) * w - 0.024552490005641278) * w +
           0.19109110138763841) * w - 0.233093736421782878) * w -
         0.422784335098466784) * w + 0.99999999999999999;
    if (n > 0) {
        w = x - 1;
        for (k = 2; k <= n; k++) {
            w *= x - k;
        }
    } else {
        w = 1;
        for (k = 0; k > n; k--) {
            y *= x - k;
        }
    }
    return w / y;
}
// define shortcuts for local A, H, DUMMY, ETA, P0eters/variables
double Iq( double q, double A,  double H,  double DUMMY,  double ETA,
           double P0)
{
    double z=q;
    double Gz, G0, V,u,KH,z2_4,nu;
// insert your code here
    if (z==0) return 0;
    gsl_set_error_handler_off();
    V = sas_pow_3(2*A)*sqrt(M_PI)*exp(gsl_sf_lngamma(1.5+H)-gsl_sf_lngamma(H));
    u=z/A;
    G0 = V*2*A*sqrt(M_PI)*exp(gsl_sf_lngamma(0.5+H)-gsl_sf_lngamma(H));
    if ( ((0.5+H) - (int) (0.5+H)) != 0) {
        KH = gsl_sf_bessel_Kn((int) (H+0.5),u);
    } else {
        KH = sqrt(M_PI)*pow(2*u,(H+0.5))*exp(-u)*gsl_sf_hyperg_U((H+1),2*H+2,2*u);
    }
    Gz = KH*V*pow(2,1.5-H)*sqrt(M_PI)*pow(u,H)*sqrt(z*A)/sas_gamma(H);
    return Gz-G0;
}
double Fq( double q,  double A,  double H,  double DUMMY,  double ETA,
           double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double A,  double H,  double DUMMY,  double ETA,
                     double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double A, double H, double DUMMY, double ETA,
             double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, A, H, DUMMY, ETA, P0);
}
