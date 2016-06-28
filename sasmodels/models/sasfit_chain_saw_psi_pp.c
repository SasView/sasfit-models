///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double T_BRUSH_CONST,  double SIGMA_BRUSH_GAUSSIAN,  double POL,  double L_B);
double Fq( double q,  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double T_BRUSH_CONST,  double SIGMA_BRUSH_GAUSSIAN,  double POL,  double L_B);
double form_volume(  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
                     double T_BRUSH_CONST,  double SIGMA_BRUSH_GAUSSIAN,  double POL,  double L_B);
double Iqxy( double qx, double qy, double R_CORE, double SNAGG, double VBRUSH,
             double RG, double T_BRUSH_CONST, double SIGMA_BRUSH_GAUSSIAN, double POL,
             double L_B);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double T_BRUSH_CONST,  double SIGMA_BRUSH_GAUSSIAN,  double POL,  double L_B)
{
// insert your code here
    RW_SAW = 0.0;
    RADAVG = 0.0;
    PEP    = 0.0;
    R_CORE = 0.0;
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
    PSI = sasfit_param_override_get_psi(PSIDEG*M_PI/180.);
    return	FFmicelle_pp(q,param);
}
double Fq( double q,  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double T_BRUSH_CONST,  double SIGMA_BRUSH_GAUSSIAN,  double POL,  double L_B)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
                     double T_BRUSH_CONST,  double SIGMA_BRUSH_GAUSSIAN,  double POL,  double L_B)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R_CORE, double SNAGG, double VBRUSH,
             double RG, double T_BRUSH_CONST, double SIGMA_BRUSH_GAUSSIAN, double POL,
             double L_B)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R_CORE, SNAGG, VBRUSH, RG, T_BRUSH_CONST, SIGMA_BRUSH_GAUSSIAN,
               POL, L_B);
}
