///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double W_CORE, double SIGMA_CORE, double W_SH,
           double SIGMA_SHIN, double D, double SIGMA_OUT, double sld_CORE,
           double sld_SHELL, double sld_SOL);
double Fq( double q,  double W_CORE, double SIGMA_CORE, double W_SH,
           double SIGMA_SHIN, double D, double SIGMA_OUT, double sld_CORE,
           double sld_SHELL, double sld_SOL);
double form_volume(  double W_CORE, double SIGMA_CORE, double W_SH,
                     double SIGMA_SHIN, double D, double SIGMA_OUT);
double Iqxy( double qx, double qy, double W_CORE, double SIGMA_CORE,
             double W_SH, double SIGMA_SHIN, double D, double SIGMA_OUT, double sld_CORE,
             double sld_SHELL, double sld_SOL);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
#define R_CORE		W_CORE+SIGMA_CORE
#define R_OUT		R_CORE+D+SIGMA_SHIN+W_SH+SIGMA_OUT
#define R_SHIN		R_CORE+D
double ampl(double q, double rad, double sigma, double contrast)
{
    double u,v,w,t,s,Vol;
    u = q*fabs(rad);
    v=q*(fabs(rad)+fabs(sigma));
    w=q*(fabs(rad)-fabs(sigma));
    t=sas_pow_5(q)*sas_pow_2(sigma);
    s=sas_pow_4(q)*sas_pow_2(sigma);
    Vol=4.*M_PI*(sas_pow_3(rad)/3.+rad*sas_pow_2(sigma)/6.0);
// insert your code here
    if (Vol==0) return 0;
    if (sigma*q<1e-3) {
        if (q==0) {
            return Vol * contrast;
        } else {
            return Vol
                   * contrast / (sas_pow_3(rad)/3.+rad*sas_pow_2(sigma)/6.0) *
                   (					 (sin(u)-u*cos(u))/sas_pow_3(q)
                                        + sas_pow_2(sigma) * (sin(u)+u*cos(u))/(12.*q)
                                        - sas_pow_4(sigma) * ((1./360.)*q*u*cos(u)+1./120.*q*sin(u))
                   );
        }
    } else {
        if (q==0) {
            return Vol * contrast;
        } else {
            return Vol
                   * contrast / (sas_pow_3(rad)/3.+rad*sas_pow_2(sigma)/6.0)
                   * ( (rad/sas_pow_2(sigma)+1/sigma) * cos(v)/sas_pow_4(q)
                       +(rad/sas_pow_2(sigma)-1/sigma) * cos(w)/sas_pow_4(q)
                       -3*sin(v)/t
                       -3*sin(w)/t
                       -2*rad*cos(u)/s
                       +6*sin(u)/t
                     );
        }
    }
}
double Iq( double q, double W_CORE, double SIGMA_CORE, double W_SH,
           double SIGMA_SHIN, double D, double SIGMA_OUT, double sld_CORE,
           double sld_SHELL, double sld_SOL)
{
// insert your code here
    return sas_pow_2(Fq(q, W_CORE,SIGMA_CORE,W_SH,SIGMA_SHIN,D,SIGMA_OUT,sld_CORE,
                        sld_SHELL,sld_SOL));
}
double Fq( double q,  double W_CORE, double SIGMA_CORE, double W_SH,
           double SIGMA_SHIN, double D, double SIGMA_OUT, double sld_CORE,
           double sld_SHELL, double sld_SOL)
{
    double u,v,w,t,s;
    return		ampl(q,R_OUT,SIGMA_OUT,(sld_SHELL-sld_SOL))
                -	ampl(q,R_SHIN,SIGMA_SHIN,(sld_SHELL-sld_SOL))
                +	ampl(q,R_CORE,SIGMA_CORE,(sld_CORE -sld_SOL));
}
double form_volume(  double W_CORE, double SIGMA_CORE, double W_SH,
                     double SIGMA_SHIN, double D, double SIGMA_OUT)
{
// insert your code here
    return 4.*M_PI*sas_pow_3(R_OUT+SIGMA_OUT)/3.;
}
double Iqxy( double qx, double qy, double W_CORE, double SIGMA_CORE,
             double W_SH, double SIGMA_SHIN, double D, double SIGMA_OUT, double sld_CORE,
             double sld_SHELL, double sld_SOL)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, W_CORE, SIGMA_CORE, W_SH, SIGMA_SHIN, D, SIGMA_OUT, sld_CORE,
               sld_SHELL, sld_SOL);
}
