///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

#include <sasfit_common.h>
#include <sasfit_fuzzysphere.h>

double Iq( double q, double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL);
//double Fq( double q,  double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL);
double form_volume(  double R );
double Iqxy( double qx, double qy, double R, double SIGMA, double ETA_SPH,
    double ETA_SOL);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local R, SIGMA, ETA_SPH, ETA_SOL, P0eters/variables
//double Iq( double q, double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL)
//{
// insert your code here
//    return sas_pow_2(Fq(q,R, SIGMA, ETA_SPH, ETA_SOL));
//}
double Iq( double q,  double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL)
{


    sasfit_param param;     // configure parameters
    param.p[0] = R;       // R
    param.p[1] = SIGMA;       // sigma
    param.p[2] = ETA_SPH;       // eta_sph
    param.p[3] = ETA_SOL;       // eta_sol

    return sasfit_ff_fuzzysphere(q, &param);
}
double form_volume( double R )
{
// insert your code here
    return 4./3.*M_PI*sas_pow_3(R);
}
double Iqxy( double qx, double qy, double R, double SIGMA, double ETA_SPH,
             double ETA_SOL)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R, SIGMA, ETA_SPH, ETA_SOL);
}
