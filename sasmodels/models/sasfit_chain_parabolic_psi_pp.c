///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL);
double Fq( double q,  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL);
double form_volume(  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
                     double POL);
double Iqxy( double qx, double qy, double R_CORE, double SNAGG, double VBRUSH,
             double RG, double POL);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL)
{
    double nn;
// insert your code here
    RW_SAW = 2.0;
    RADAVG = 0.0;
    PEP    = 0.0;
    if ((R_TOT-T_SHELL) > 0)
    {
        R_CORE=R_TOT-T_SHELL;
        T_SH = T_SHELL;
    }
    else
    {
        R_CORE = 0.0;
        T_SH = R_TOT;
    }
    if (R_TOT == 0.0) return 0.0;
    ALPHA_SH = 2.0/(3*M_PI);
    nn = 4*M_PI*sas_pow_2(R_TOT)/SIGMA;
    I = nn*N*sas_pow_3(A)/(4*M_PI);
    nn = SNAGG*4*M_PI*sas_pow_2(R_TOT);
    I = VBRUSH * nn /(4*M_PI);
    C=ALPHA_SH/(P*sas_pow_2(A*N));
//	sasfit_out("q:%lf\n",q);
    LAMBDA = find_LAMBDA(param);
//	sasfit_out("LAMBDA: %f   zmax: %f\n",LAMBDA,sqrt(LAMBDA/C));
    PSI = sasfit_param_override_get_psi(PSIDEG*M_PI/180.);
    return	FFmicelle_pp(q,param);
}
double Fq( double q,  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
                     double POL)
{
// insert your code here
    return V(R_CORE+T_SH+2.*sqrt(5./3.)*RG,param);
}
double Iqxy( double qx, double qy, double R_CORE, double SNAGG, double VBRUSH,
             double RG, double POL)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R_CORE, SNAGG, VBRUSH, RG, POL);
}
