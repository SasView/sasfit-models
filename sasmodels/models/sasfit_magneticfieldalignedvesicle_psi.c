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
#define Csc 1./sin
double Iq( double q, double RSH0,  double THETA1,  double THETA2,  double T_SH,
           double T_C,  double DETA_SH,  double DETA_CE,  double SIGMA,  double PSI_DEG,
           double KAPPA,  double Q,  double RKERNEL,  double GAMA,  double _THETA,
           double PHI,  double PSI,  double RSH)
{
    PSI = PSI_DEG*M_PI/180.0;
    GAMA = PSI;
    return sasfit_ff_magneticfieldalignedvesicle_util_psi(q,RSH0, THETA1, THETA2,
            T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG, KAPPA, Q, RKERNEL, GAMA, _THETA,
            PHI, PSI, RSH);
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
