///////////////////////////////////////////////////
//    This is automatically generated file       //
//    by sasfit_convert.py                       //
//    Some editting may still be required        //
///////////////////////////////////////////////////

#include <sasfit_common.h>
#include <sasfit_coreshellmicrogel.h>

#define R_CORE		W_CORE+SIGMA_CORE
#define R_OUT		R_CORE+D+SIGMA_SHIN+W_SH+SIGMA_OUT
#define R_SHIN		R_CORE+D


double Fq( double q, double W_core,  double sigma_core,  double W_sh,  double sigma_sh,in,  double D,  double sigma_out,  double eta_core,  double eta_shell,  double eta_sol);
double Iq( double q, double W_core,  double sigma_core,  double W_sh,  double sigma_sh,in,  double D,  double sigma_out,  double eta_core,  double eta_shell,  double eta_sol);
double Iqxy( double qx, double qy, double W_core,  double sigma_core,  double W_sh,  double sigma_sh,in,  double D,  double sigma_out,  double eta_core,  double eta_shell,  double eta_sol);
double Fq( double q, double W_core,  double sigma_core,  double W_sh,  double sigma_sh,in,  double D,  double sigma_out,  double eta_core,  double eta_shell,  double eta_sol) {
sasfit_param param;
param.p[0] = W_core;
param.p[1] = sigma_core;
param.p[2] = W_sh;
param.p[3] = sigma_sh,in;
param.p[4] = D;
param.p[5] = sigma_out;
param.p[6] = eta_core;
param.p[7] = eta_shell;
param.p[8] = eta_sol;
return sasfit_ff_coreshellmicrogel_f(q, &param);
}

double Iq( double q, double W_core,  double sigma_core,  double W_sh,  double sigma_sh,in,  double D,  double sigma_out,  double eta_core,  double eta_shell,  double eta_sol) {
sasfit_param param;
param.p[0] = W_core;
param.p[1] = sigma_core;
param.p[2] = W_sh;
param.p[3] = sigma_sh,in;
param.p[4] = D;
param.p[5] = sigma_out;
param.p[6] = eta_core;
param.p[7] = eta_shell;
param.p[8] = eta_sol;
return sasfit_ff_coreshellmicrogel(q, &param);
}

double Iqxy( double qx, double qy, double W_core,  double sigma_core,  double W_sh,  double sigma_sh,in,  double D,  double sigma_out,  double eta_core,  double eta_shell,  double eta_sol){
	double q = sqrt(qx*qx + qy*qy);
	return Iq( q, W_core, sigma_core, W_sh, sigma_sh,in, D, sigma_out, eta_core, eta_shell, eta_sol);
}

double form_volume(  {
double q;
sasfit_param param;
int dist;
return sasfit_ff_coreshellmicrogel_v(q, &param, dist);
}

