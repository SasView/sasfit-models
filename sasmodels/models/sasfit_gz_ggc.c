///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf.h>

double Iq( double q, double RG,  double NU,  double DUMMY2,  double I0,
           double P0);
double Fq( double q,  double RG,  double NU,  double DUMMY2,  double I0,
           double P0);
double form_volume(  double RG,  double NU,  double DUMMY2,  double I0,
                     double P0);
double Iqxy( double qx, double qy, double RG, double NU, double DUMMY2,
             double I0, double P0);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local RG, NU, DUMMY2, I0, P0eters/variables
double Iq( double q, double RG,  double NU,  double DUMMY2,  double I0,
           double P0)
{
    double z = q;
    double w,Gz,G0;
// insert your code here
    gsl_set_error_handler_off();
    w = z*z/((1 + 3*NU + 2*NU*NU)*RG*RG);
    G0 =  I0*(3*M_PI)/((1 - 5*sas_pow_2(NU) + 4*sas_pow_4(NU))*sas_pow_2(RG));
    if (z==0) return 0;
    Gz = -((pow(3,1/NU)*pow(4,1 - 1/NU)*M_PI*pow(w,
            -1 + 1/NU)*gsl_sf_gamma_inc(1 - 1/NU,(3*w)/4.))/
           (NU*(1 + NU)*(1 + 2*NU)*pow(RG,2))) +
         (pow(3,1/(2.*NU))*pow(4,1 - 1/(2.*NU))*M_PI*pow(w,-1 + 1/(2.*NU))*
          gsl_sf_gamma_inc(1 - 1/(2.*NU),(3*w)/4.))/(NU*(1 + NU)*(1 + 2*NU)*pow(RG,2));
    return Gz-G0;
}
double Fq( double q,  double RG,  double NU,  double DUMMY2,  double I0,
           double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double RG,  double NU,  double DUMMY2,  double I0,
                     double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double RG, double NU, double DUMMY2,
             double I0, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, RG, NU, DUMMY2, I0, P0);
}
