///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double K,  double HI,  double L_H,  double R,  double Q,
           double lR);
double Fq( double q,  double K,  double HI,  double L_H,  double R,  double Q,
           double lR);
double form_volume(  double K,  double HI,  double L_H,  double R,  double Q,
                     double lR);
double Iqxy( double qx, double qy, double K, double HI, double L_H, double R,
             double Q, double lR);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double Iq_kernel(double r, sasfit_param * param)
{
    if (fabs(Q*r)<=1e-3)
    {
        return 4*M_PI*r*r
               *(1-sas_pow_2(Q*r)/6.0+sas_pow_4(Q*r)/120.0-sas_pow_6(Q*r)/5040.0)
               *sasfit_ff_c_r__for_spin_misalignment(r,param);
    }
    else
    {
        return 4*M_PI*r*r
               *sin(Q*r)/(Q*r)
               *sasfit_ff_c_r__for_spin_misalignment(r,param);
    }
}
double Iq( double q, double K,  double HI,  double L_H,  double R,  double Q,
           double lR)
{
// insert your code here
    if (R==0) return 0;
//	if (R>0) {
    if (fabs(q*R)< 1e-3)
    {
        return K*sas_pow_6(R)/sas_pow_2(HI)*
               (2*M_PI*M_PI)*
               (1./9.-sas_pow_2(q*R)/45.+sas_pow_4(q*R)/525.-4*sas_pow_6(q*R)/42525.)
               /sas_pow_2(1.0+sas_pow_2(L_H*q));
    }
    else
    {
        return K*sas_pow_6(R)/sas_pow_2(HI)*
               (2*M_PI*M_PI)*
               1.0/sas_pow_2(q*R)*
               sas_pow_2(sph_j1(q*fabs(R)))
               /sas_pow_2(1.0+sas_pow_2(L_H*q));
    }
//	} else {
//       Q = q;
// GSL_POSINF
//        R = fabs(R);
//        return sasfit_integrate(0,GSL_POSINF,&Iq_kernel, param);
//	}
}
double Fq( double q,  double K,  double HI,  double L_H,  double R,  double Q,
           double lR)
{
// insert your code here
    return 0.0;
}
double form_volume(  double K,  double HI,  double L_H,  double R,  double Q,
                     double lR)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double K, double HI, double L_H, double R,
             double Q, double lR)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, K, HI, L_H, R, Q, lR);
}
