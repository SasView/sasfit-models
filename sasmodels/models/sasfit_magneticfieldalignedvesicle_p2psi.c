///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double RSH0,  double THETA1,  double THETA2,  double T_SH,
           double T_C,  double DETA_SH,  double DETA_CE,  double SIGMA,  double PSI_DEG,
           double KAPPA,  double Q,  double RKERNEL,  double GAMA,  double _THETA,
           double PHI,  double PSI,  double RSH);
double Fq( double q,  double RSH0,  double THETA1,  double THETA2,  double T_SH,
           double T_C,  double DETA_SH,  double DETA_CE,  double SIGMA,  double PSI_DEG,
           double KAPPA,  double Q,  double RKERNEL,  double GAMA,  double _THETA,
           double PHI,  double PSI,  double RSH);
double form_volume(  double RSH0,  double THETA1,  double THETA2,  double T_SH,
                     double T_C,  double DETA_SH,  double DETA_CE,  double SIGMA,  double PSI_DEG,
                     double KAPPA,  double Q,  double RKERNEL,  double GAMA,  double _THETA,
                     double PHI,  double PSI,  double RSH);
double Iqxy( double qx, double qy, double RSH0, double THETA1, double THETA2,
             double T_SH, double T_C, double DETA_SH, double DETA_CE, double SIGMA,
             double PSI_DEG, double KAPPA, double Q, double RKERNEL, double GAMA,
             double _THETA, double PHI, double PSI, double RSH);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local RSH0, THETA1, THETA2, T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG, KAPPA, Q, RKERNEL, GAMA, _THETA, PHI, PSI, RSHeters/variables
#define Power pow
#define Cos cos
#define Sin sin
#define Pi M_PI
#define Sec 1./cos
double probability(double *x, sasfit_param * param)
{
    double p, norm, u, c, LNf, theta, phi, radius;
    theta	= x[0];
    phi		= x[1];
    radius	= x[2];
    if (KAPPA < 0)
    {
        u = sqrt(-KAPPA);
        norm = sqrt(M_PI)*sas_erf(u)/u;
    }
    else if (KAPPA == 0.0)
    {
        norm = 2;
    }
    else
    {
        u = sqrt(KAPPA);
        norm = 2.0*exp(KAPPA)*gsl_sf_dawson(
                   u)/u; // maple: `assuming`([convert(int(exp(kappa*cos(theta)^2)*sin(theta), theta = 0 .. Pi), dawson)], [kappa > 0])
    }
    if (radius == 0.0)
    {
        LNf = 0.0;
    }
    else
    {
        c = 1.0/(sqrt(M_PI*2.0)*fabs(SIGMA));
        LNf = c/radius * exp(-0.5*pow(log(radius/RSH0)/SIGMA,2.0));
    }
    p = LNf*exp(KAPPA*sas_pow_2(cos(theta)))/(norm*2.0*M_PI);
    return p;
}
double sasfit_ff_magneticfieldalignedvesicle_p2psi_kernel(double *x, size_t dim,
        sasfit_param * param)
{
    double res,p;
    _THETA	= x[0];
    PHI		= x[1];
    RSH		= x[2];
    p = probability(x,RSH0, THETA1, THETA2, T_SH, T_C, DETA_SH, DETA_CE, SIGMA,
                    PSI_DEG, KAPPA, Q, RKERNEL, GAMA, _THETA, PHI, PSI, RSH);
    GAMA = acos( sin(_THETA) * cos(PHI) * sin(PSI) + cos(_THETA) * cos(PSI) );
    res = sin(_THETA)*p*sasfit_ff_magneticfieldalignedvesicle_util_psi(Q,RSH0,
            THETA1, THETA2, T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG, KAPPA, Q, RKERNEL,
            GAMA, _THETA, PHI, PSI, RSH);
    return res;
}
int sasfit_integrate_plugin_P2Psi(sasfit_func_monte_t intKern_fct,
                                  double *xl,
                                  double *xu,
                                  size_t dim,
                                  sasfit_param * param,
                                  size_t calls,
                                  double *res,
                                  double *err)
{
    int status;
    static gsl_rng * r;
    static int rng_init=-1;
    gsl_monte_function F;
    gsl_monte_miser_state *s;
    if (rng_init < 0)
    {
        r = gsl_rng_alloc (gsl_rng_default);
        rng_init = 1;
    }
    s = gsl_monte_miser_alloc(dim);
    gsl_set_error_handler_off ();
    F.f = (double (*) (double*, size_t, void*)) intKern_fct;
    F.dim = dim;
    F.RSH0, THETA1, THETA2, T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG, KAPPA, Q,
            RKERNEL, GAMA, _THETA, PHI, PSI, RSHs = RSH0, THETA1, THETA2, T_SH, T_C,
                                             DETA_SH, DETA_CE, SIGMA, PSI_DEG, KAPPA, Q, RKERNEL, GAMA, _THETA, PHI, PSI,
                                             RSH;
    status = gsl_monte_miser_integrate(&F,xl,xu,dim,calls,r,s,res, err);
    gsl_monte_miser_free(s);
    return status;
}
double sasfit_ff_magneticfieldalignedvesicle_p2psi_kernel_theta(double x,
        sasfit_param * param)
{
    double res,p;
    _THETA = x;
    p = 1;
    GAMA = acos( sin(_THETA) * cos(PHI) * sin(PSI) + cos(_THETA) * cos(PSI) );
    res = sin(_THETA)*p*sasfit_ff_magneticfieldalignedvesicle_util_psi(Q,RSH0,
            THETA1, THETA2, T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG, KAPPA, Q, RKERNEL,
            GAMA, _THETA, PHI, PSI, RSH);
    return res;
}
double sasfit_ff_magneticfieldalignedvesicle_p2psi_kernel_phi(double x,
        sasfit_param * param)
{
    double res;
    PHI = x;
    res = 2.0*sasfit_integrate(0.0, M_PI/2.0,
                               &sasfit_ff_magneticfieldalignedvesicle_p2psi_kernel_theta, RSH0, THETA1, THETA2,
                               T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG, KAPPA, Q, RKERNEL, GAMA, _THETA,
                               PHI, PSI, RSH);
    return res;
}
double Iq( double q, double RSH0,  double THETA1,  double THETA2,  double T_SH,
           double T_C,  double DETA_SH,  double DETA_CE,  double SIGMA,  double PSI_DEG,
           double KAPPA,  double Q,  double RKERNEL,  double GAMA,  double _THETA,
           double PHI,  double PSI,  double RSH)
{
    double res,err;
    double xl[3], xu[3];
    int status;
    Q=q;
    gsl_set_error_handler_off ();
    if (KAPPA == 0.0)
    {
        PSI = 0.0;
        PHI=0.0;
//		if (RSH == 0.0) {
//			res = sasfit_ff_magneticfieldalignedvesicle_util_Psi(Q,RSH0, THETA1, THETA2, T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG, KAPPA, Q, RKERNEL, GAMA, _THETA, PHI, PSI, RSH);
//		} else {
        res = 2.0*sasfit_integrate(0.0, M_PI/2.0,
                                   &sasfit_ff_magneticfieldalignedvesicle_p2psi_kernel_theta, RSH0, THETA1, THETA2,
                                   T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG, KAPPA, Q, RKERNEL, GAMA, _THETA,
                                   PHI, PSI, RSH);
//		}
    }
    else
    {
        PSI = PSI_DEG*M_PI/180.0;
        xl[0]=0.0;
        xl[1]=0.0;
        xl[2]=0.0;
        xu[0]=Pi;
        xu[1]=2.0*Pi;
        xu[2]=RSH0*exp(-SIGMA*SIGMA*(1.0-6.0)+sqrt(2.0*SIGMA*SIGMA*log(100.0/0.1)));
//		if (RSH0 == 0.0) {
//			res = sasfit_ff_magneticfieldalignedvesicle_util_Psi(Q,RSH0, THETA1, THETA2, T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG, KAPPA, Q, RKERNEL, GAMA, _THETA, PHI, PSI, RSH);
//		} else {
        status = sasfit_integrate_plugin_P2Psi(
                     &sasfit_ff_magneticfieldalignedvesicle_p2psi_kernel,
                     xl,xu,3,RSH0, THETA1, THETA2, T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG,
                     KAPPA, Q, RKERNEL, GAMA, _THETA, PHI, PSI, RSH,sasfit_eps_get_iter_4_mc(),&res,
                     &err);
        sasfit_out("Q=%lf, Int=%lf, Err/Int=%lf Rmax=%lf\n",Q,res,err/res,xu[2]);
        return res;
//			res = sasfit_integrate(0.0, 2.0*M_PI, &sasfit_ff_magneticfieldalignedvesicleP2Psi_kernel_Phi, RSH0, THETA1, THETA2, T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG, KAPPA, Q, RKERNEL, GAMA, _THETA, PHI, PSI, RSH);
//		}
    }
    return res;
}
double Fq( double q,  double RSH0,  double THETA1,  double THETA2,  double T_SH,
           double T_C,  double DETA_SH,  double DETA_CE,  double SIGMA,  double PSI_DEG,
           double KAPPA,  double Q,  double RKERNEL,  double GAMA,  double _THETA,
           double PHI,  double PSI,  double RSH)
{
// insert your code here
    return 0.0;
}
double form_volume(  double RSH0,  double THETA1,  double THETA2,  double T_SH,
                     double T_C,  double DETA_SH,  double DETA_CE,  double SIGMA,  double PSI_DEG,
                     double KAPPA,  double Q,  double RKERNEL,  double GAMA,  double _THETA,
                     double PHI,  double PSI,  double RSH)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double RSH0, double THETA1, double THETA2,
             double T_SH, double T_C, double DETA_SH, double DETA_CE, double SIGMA,
             double PSI_DEG, double KAPPA, double Q, double RKERNEL, double GAMA,
             double _THETA, double PHI, double PSI, double RSH)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, RSH0, THETA1, THETA2, T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG,
               KAPPA, Q, RKERNEL, GAMA, _THETA, PHI, PSI, RSH);
}
