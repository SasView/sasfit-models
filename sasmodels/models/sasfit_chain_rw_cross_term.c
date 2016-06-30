///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL,  double P0,  double R_TOT,  double T_SHELL,  double SNAGG,
           double VBRUSH,  double ETA_CORE,  double ETA_SHELL,  double ETA_BRUSH,
           double ETA_SOLV,  double ETA_MAG_CORE,  double ETA_MAG_SHELL,  double R_AV,
           double ALPHA,  double RG,  double PSIDEG,  double POL,  double PEP,
           double YAWPEP,  double SIGYAW,  double P,  double A,  double TAU,
           double T_BRUSH_CONST,  double SIGMA_BRUSH_GAUSSIAN,  double L_B,  double TPLUS,
           double TMINUS,  double PSI,  double NAGG,  double RW_SAW,  double RADAVG,
           double R_CORE,  double T_SH,  double I,  double C,  double LAMBDA,  double R02,
           double ALPHA_SH,  double ZMAX,  double Q,  double DTHETA);
double Fq( double q,  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL,  double P0,  double R_TOT,  double T_SHELL,  double SNAGG,
           double VBRUSH,  double ETA_CORE,  double ETA_SHELL,  double ETA_BRUSH,
           double ETA_SOLV,  double ETA_MAG_CORE,  double ETA_MAG_SHELL,  double R_AV,
           double ALPHA,  double RG,  double PSIDEG,  double POL,  double PEP,
           double YAWPEP,  double SIGYAW,  double P,  double A,  double TAU,
           double T_BRUSH_CONST,  double SIGMA_BRUSH_GAUSSIAN,  double L_B,  double TPLUS,
           double TMINUS,  double PSI,  double NAGG,  double RW_SAW,  double RADAVG,
           double R_CORE,  double T_SH,  double I,  double C,  double LAMBDA,  double R02,
           double ALPHA_SH,  double ZMAX,  double Q,  double DTHETA);
double form_volume(  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
                     double POL,  double P0,  double R_TOT,  double T_SHELL,  double SNAGG,
                     double VBRUSH,  double ETA_CORE,  double ETA_SHELL,  double ETA_BRUSH,
                     double ETA_SOLV,  double ETA_MAG_CORE,  double ETA_MAG_SHELL,  double R_AV,
                     double ALPHA,  double RG,  double PSIDEG,  double POL,  double PEP,
                     double YAWPEP,  double SIGYAW,  double P,  double A,  double TAU,
                     double T_BRUSH_CONST,  double SIGMA_BRUSH_GAUSSIAN,  double L_B,  double TPLUS,
                     double TMINUS,  double PSI,  double NAGG,  double RW_SAW,  double RADAVG,
                     double R_CORE,  double T_SH,  double I,  double C,  double LAMBDA,  double R02,
                     double ALPHA_SH,  double ZMAX,  double Q,  double DTHETA);
double Iqxy( double qx, double qy, double R_CORE, double SNAGG, double VBRUSH,
             double RG, double POL, double P0, double R_TOT, double T_SHELL, double SNAGG,
             double VBRUSH, double ETA_CORE, double ETA_SHELL, double ETA_BRUSH,
             double ETA_SOLV, double ETA_MAG_CORE, double ETA_MAG_SHELL, double R_AV,
             double ALPHA, double RG, double PSIDEG, double POL, double PEP, double YAWPEP,
             double SIGYAW, double P, double A, double TAU, double T_BRUSH_CONST,
             double SIGMA_BRUSH_GAUSSIAN, double L_B, double TPLUS, double TMINUS,
             double PSI, double NAGG, double RW_SAW, double RADAVG, double R_CORE,
             double T_SH, double I, double C, double LAMBDA, double R02, double ALPHA_SH,
             double ZMAX, double Q, double DTHETA);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local R_CORE, SNAGG, VBRUSH, RG, POL, P0, R_TOT, T_SHELL, SNAGG, VBRUSH, ETA_CORE, ETA_SHELL, ETA_BRUSH, ETA_SOLV, ETA_MAG_CORE, ETA_MAG_SHELL, R_AV, ALPHA, RG, PSIDEG, POL, PEP, YAWPEP, SIGYAW, P, A, TAU, T_BRUSH_CONST, SIGMA_BRUSH_GAUSSIAN, L_B, TPLUS, TMINUS, PSI, NAGG, RW_SAW, RADAVG, R_CORE, T_SH, I, C, LAMBDA, R02, ALPHA_SH, ZMAX, Q, DTHETAeters/variables
double Iq( double q, double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL,  double P0,  double R_TOT,  double T_SHELL,  double SNAGG,
           double VBRUSH,  double ETA_CORE,  double ETA_SHELL,  double ETA_BRUSH,
           double ETA_SOLV,  double ETA_MAG_CORE,  double ETA_MAG_SHELL,  double R_AV,
           double ALPHA,  double RG,  double PSIDEG,  double POL,  double PEP,
           double YAWPEP,  double SIGYAW,  double P,  double A,  double TAU,
           double T_BRUSH_CONST,  double SIGMA_BRUSH_GAUSSIAN,  double L_B,  double TPLUS,
           double TMINUS,  double PSI,  double NAGG,  double RW_SAW,  double RADAVG,
           double R_CORE,  double T_SH,  double I,  double C,  double LAMBDA,  double R02,
           double ALPHA_SH,  double ZMAX,  double Q,  double DTHETA)
{
// insert your code here
    RW_SAW = 1.0;
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
    return POL*(FFmicelle_pp(q,R_CORE, SNAGG, VBRUSH, RG, POL, P0, R_TOT, T_SHELL,
                             SNAGG, VBRUSH, ETA_CORE, ETA_SHELL, ETA_BRUSH, ETA_SOLV, ETA_MAG_CORE,
                             ETA_MAG_SHELL, R_AV, ALPHA, RG, PSIDEG, POL, PEP, YAWPEP, SIGYAW, P, A, TAU,
                             T_BRUSH_CONST, SIGMA_BRUSH_GAUSSIAN, L_B, TPLUS, TMINUS, PSI, NAGG, RW_SAW,
                             RADAVG, R_CORE, T_SH, I, C, LAMBDA, R02, ALPHA_SH, ZMAX, Q,
                             DTHETA)-FFmicelle_mm(q,R_CORE, SNAGG, VBRUSH, RG, POL, P0, R_TOT, T_SHELL,
                                     SNAGG, VBRUSH, ETA_CORE, ETA_SHELL, ETA_BRUSH, ETA_SOLV, ETA_MAG_CORE,
                                     ETA_MAG_SHELL, R_AV, ALPHA, RG, PSIDEG, POL, PEP, YAWPEP, SIGYAW, P, A, TAU,
                                     T_BRUSH_CONST, SIGMA_BRUSH_GAUSSIAN, L_B, TPLUS, TMINUS, PSI, NAGG, RW_SAW,
                                     RADAVG, R_CORE, T_SH, I, C, LAMBDA, R02, ALPHA_SH, ZMAX, Q, DTHETA));
}
double Fq( double q,  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL,  double P0,  double R_TOT,  double T_SHELL,  double SNAGG,
           double VBRUSH,  double ETA_CORE,  double ETA_SHELL,  double ETA_BRUSH,
           double ETA_SOLV,  double ETA_MAG_CORE,  double ETA_MAG_SHELL,  double R_AV,
           double ALPHA,  double RG,  double PSIDEG,  double POL,  double PEP,
           double YAWPEP,  double SIGYAW,  double P,  double A,  double TAU,
           double T_BRUSH_CONST,  double SIGMA_BRUSH_GAUSSIAN,  double L_B,  double TPLUS,
           double TMINUS,  double PSI,  double NAGG,  double RW_SAW,  double RADAVG,
           double R_CORE,  double T_SH,  double I,  double C,  double LAMBDA,  double R02,
           double ALPHA_SH,  double ZMAX,  double Q,  double DTHETA)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
                     double POL,  double P0,  double R_TOT,  double T_SHELL,  double SNAGG,
                     double VBRUSH,  double ETA_CORE,  double ETA_SHELL,  double ETA_BRUSH,
                     double ETA_SOLV,  double ETA_MAG_CORE,  double ETA_MAG_SHELL,  double R_AV,
                     double ALPHA,  double RG,  double PSIDEG,  double POL,  double PEP,
                     double YAWPEP,  double SIGYAW,  double P,  double A,  double TAU,
                     double T_BRUSH_CONST,  double SIGMA_BRUSH_GAUSSIAN,  double L_B,  double TPLUS,
                     double TMINUS,  double PSI,  double NAGG,  double RW_SAW,  double RADAVG,
                     double R_CORE,  double T_SH,  double I,  double C,  double LAMBDA,  double R02,
                     double ALPHA_SH,  double ZMAX,  double Q,  double DTHETA)
{
// insert your code here
    return V(R_CORE+T_SH+2.*sqrt(5./3.)*RG,R_CORE, SNAGG, VBRUSH, RG, POL, P0,
             R_TOT, T_SHELL, SNAGG, VBRUSH, ETA_CORE, ETA_SHELL, ETA_BRUSH, ETA_SOLV,
             ETA_MAG_CORE, ETA_MAG_SHELL, R_AV, ALPHA, RG, PSIDEG, POL, PEP, YAWPEP, SIGYAW,
             P, A, TAU, T_BRUSH_CONST, SIGMA_BRUSH_GAUSSIAN, L_B, TPLUS, TMINUS, PSI, NAGG,
             RW_SAW, RADAVG, R_CORE, T_SH, I, C, LAMBDA, R02, ALPHA_SH, ZMAX, Q, DTHETA);
}
double Iqxy( double qx, double qy, double R_CORE, double SNAGG, double VBRUSH,
             double RG, double POL, double P0, double R_TOT, double T_SHELL, double SNAGG,
             double VBRUSH, double ETA_CORE, double ETA_SHELL, double ETA_BRUSH,
             double ETA_SOLV, double ETA_MAG_CORE, double ETA_MAG_SHELL, double R_AV,
             double ALPHA, double RG, double PSIDEG, double POL, double PEP, double YAWPEP,
             double SIGYAW, double P, double A, double TAU, double T_BRUSH_CONST,
             double SIGMA_BRUSH_GAUSSIAN, double L_B, double TPLUS, double TMINUS,
             double PSI, double NAGG, double RW_SAW, double RADAVG, double R_CORE,
             double T_SH, double I, double C, double LAMBDA, double R02, double ALPHA_SH,
             double ZMAX, double Q, double DTHETA)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R_CORE, SNAGG, VBRUSH, RG, POL, P0, R_TOT, T_SHELL, SNAGG, VBRUSH,
               ETA_CORE, ETA_SHELL, ETA_BRUSH, ETA_SOLV, ETA_MAG_CORE, ETA_MAG_SHELL, R_AV,
               ALPHA, RG, PSIDEG, POL, PEP, YAWPEP, SIGYAW, P, A, TAU, T_BRUSH_CONST,
               SIGMA_BRUSH_GAUSSIAN, L_B, TPLUS, TMINUS, PSI, NAGG, RW_SAW, RADAVG, R_CORE,
               T_SH, I, C, LAMBDA, R02, ALPHA_SH, ZMAX, Q, DTHETA);
}
