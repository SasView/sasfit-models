///////////////////////////////////////////////////
//    This is automatically generated file       //
//    by sasfit_convert.py                       //
//    Some editting may still be required        //
///////////////////////////////////////////////////

#include <sasfit_common.h>
#include <sasfit_fuzzysphere.h>

double Fq( double q, double R,  double sigma,  double eta_sph,  double eta_sol);
double Iq( double q, double R,  double sigma,  double eta_sph,  double eta_sol);
double Iqxy( double qx, double qy, double R,  double sigma,  double eta_sph,  double eta_sol);
double form_volume(  double R);

double Fq( double q, double R,  double sigma,  double eta_sph,  double eta_sol) {
sasfit_param param;
sasfit_init_param( &param );
param.p[0] = R;
param.p[1] = sigma;
param.p[2] = eta_sph;
param.p[3] = eta_sol;
scalar results = sasfit_ff_fuzzysphere_f(q, &param);
return results;
}

double Iq( double q, double R,  double sigma,  double eta_sph,  double eta_sol) {
sasfit_param param;
sasfit_init_param( &param );

param.p[0] = R;
param.p[1] = sigma;
param.p[2] = eta_sph;
param.p[3] = eta_sol;
scalar results = sasfit_ff_fuzzysphere(q, &param);

//bool errStatus = param.errStatus;
//int errLen = param.errLen;
//char errMessage[errLen];
//for (int i=0; i<errLen; i++){
//    errMessage[i] = param.errStr[i];
//}
if (param.errStatus!=FALSE) {
    //sasfit_err("#Error occured: >%s<\n",&param.errStr);
    printf("Error occurs : %s\n",param.errStr);
}

return results;
}

double Iqxy( double qx, double qy, double R,  double sigma,  double eta_sph,  double eta_sol){
	double q = sqrt(qx*qx + qy*qy);
	return Iq( q, R, sigma, eta_sph, eta_sol);
}

double form_volume(  double R) {
double q;
sasfit_param param;
sasfit_init_param( &param );
int dist;
param.p[0] = R;
scalar results = sasfit_ff_fuzzysphere_v(q, &param, dist);
return results;
}

