///////////////////////////////////////////////////
//    This is automatically generated file       //
//    by sasfit_convert.py                       //
//    Some editting may still be required        //
///////////////////////////////////////////////////

#include <sasfit_common.h>
#include <sasfit_fuzzysphere.h>

#define R	param->p[0]
#define SIGMA	param->p[1]
#define ETA_SPH	param->p[2]
#define ETA_SOL	param->p[3]
double Fq( double q, double R,  double sigma,  double eta_sph,  double eta_sol);
double Iq( double q, double R,  double sigma,  double eta_sph,  double eta_sol);
double Iqxy( double qx, double qy, double R,  double sigma,  double eta_sph,  double eta_sol);
double form_volume(  double R);

double Fq( double q, double R,  double sigma,  double eta_sph,  double eta_sol) {
sasfit_param param;
param.p[0] = R;
param.p[1] = sigma;
param.p[2] = eta_sph;
param.p[3] = eta_sol;
return sasfit_ff_fuzzysphere_f(q, &param);
}

double Iq( double q, double R,  double sigma,  double eta_sph,  double eta_sol) {
sasfit_param param;
param.p[0] = R;
param.p[1] = sigma;
param.p[2] = eta_sph;
param.p[3] = eta_sol;
return sasfit_ff_fuzzysphere(q, &param);
}

double Iqxy( double qx, double qy, double R,  double sigma,  double eta_sph,  double eta_sol){
	double q = sqrt(qx*qx + qy*qy);
	return Iq( q, R, sigma, eta_sph, eta_sol);
}

double form_volume(  double R) {
double q;
sasfit_param param;
int dist;
param.p[0] = R;
return sasfit_ff_fuzzysphere_v(q, &param, dist);
}

