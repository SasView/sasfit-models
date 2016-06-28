///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iqxy( double qx, double qy, double RSH0, double THETA1, double THETA2,
             double T_SH, double T_C, double DETA_SH, double DETA_CE, double SIGMA,
             double PSI_DEG, double KAPPA, double Q, double RKERNEL, double GAMA,
             double _THETA, double PHI, double PSI, double RSH);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
#define Power pow
#define Cos cos
#define Sin sin
#define Pi M_PI
#define Sec 1./cos
#define Csc 1./sin
double sasfit_ff_magneticfieldalignedvesicle_psi(double q, sasfit_param * param)
{
    PSI = PSI_DEG*M_PI/180.0;
    GAMA = PSI;
    return sasfit_ff_magneticfieldalignedvesicle_util_psi(q,param);
}
double sasfit_ff_magneticfieldalignedvesicle_psi_f(double q,
        sasfit_param * param)
{
// insert your code here
    return 0.0;
}
double sasfit_ff_magneticfieldalignedvesicle_psi_v(double q,
        sasfit_param * param, int dist)
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
