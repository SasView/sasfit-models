///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double NU,  double B0,  double B1,  double NU,
           double RHO_0,  double PHASE_PAR,  double PSI_DEG,  double SQ_AMPL,
           double SQ_PHASE,  double SQ_STATIC,  double FNUC_FMAG,  double MU_KT,
           double LAM_CENTER,  double D_LAM_LAM,  double SD,  double P_POL,
           double EPSILON_FLIPPER,  double T_PLUS,  double T_MINUS,  double B_STATIC,
           double B_STAT_PHI_DEG,  double DELTA_T_BOTTOM,  double DELTA_T_TOP,
           double ALPHA_PHASE,  double LAMBDA,  double MU,  double DAMP_ALPHA,
           double SQ_TIME,  double TEMPERATURE,  double AD,  double AD_FUNC,
           double NONAD_FUNC,  double FNUC,  double FMAG,  double S1,  double S2,
           double R,  double R_AV,  double TIME,  double STATIC,  double PSI);
double Fq( double q,  double NU,  double B0,  double B1,  double NU,
           double RHO_0,  double PHASE_PAR,  double PSI_DEG,  double SQ_AMPL,
           double SQ_PHASE,  double SQ_STATIC,  double FNUC_FMAG,  double MU_KT,
           double LAM_CENTER,  double D_LAM_LAM,  double SD,  double P_POL,
           double EPSILON_FLIPPER,  double T_PLUS,  double T_MINUS,  double B_STATIC,
           double B_STAT_PHI_DEG,  double DELTA_T_BOTTOM,  double DELTA_T_TOP,
           double ALPHA_PHASE,  double LAMBDA,  double MU,  double DAMP_ALPHA,
           double SQ_TIME,  double TEMPERATURE,  double AD,  double AD_FUNC,
           double NONAD_FUNC,  double FNUC,  double FMAG,  double S1,  double S2,
           double R,  double R_AV,  double TIME,  double STATIC,  double PSI);
double form_volume(  double NU,  double B0,  double B1,  double NU,
                     double RHO_0,  double PHASE_PAR,  double PSI_DEG,  double SQ_AMPL,
                     double SQ_PHASE,  double SQ_STATIC,  double FNUC_FMAG,  double MU_KT,
                     double LAM_CENTER,  double D_LAM_LAM,  double SD,  double P_POL,
                     double EPSILON_FLIPPER,  double T_PLUS,  double T_MINUS,  double B_STATIC,
                     double B_STAT_PHI_DEG,  double DELTA_T_BOTTOM,  double DELTA_T_TOP,
                     double ALPHA_PHASE,  double LAMBDA,  double MU,  double DAMP_ALPHA,
                     double SQ_TIME,  double TEMPERATURE,  double AD,  double AD_FUNC,
                     double NONAD_FUNC,  double FNUC,  double FMAG,  double S1,  double S2,
                     double R,  double R_AV,  double TIME,  double STATIC,  double PSI);
double Iqxy( double qx, double qy, double NU, double B0, double B1, double NU,
             double RHO_0, double PHASE_PAR, double PSI_DEG, double SQ_AMPL, double SQ_PHASE,
             double SQ_STATIC, double FNUC_FMAG, double MU_KT, double LAM_CENTER,
             double D_LAM_LAM, double SD, double P_POL, double EPSILON_FLIPPER,
             double T_PLUS, double T_MINUS, double B_STATIC, double B_STAT_PHI_DEG,
             double DELTA_T_BOTTOM, double DELTA_T_TOP, double ALPHA_PHASE, double LAMBDA,
             double MU, double DAMP_ALPHA, double SQ_TIME, double TEMPERATURE, double AD,
             double AD_FUNC, double NONAD_FUNC, double FNUC, double FMAG, double S1,
             double S2, double R, double R_AV, double TIME, double STATIC, double PSI);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
double Iq( double q, double NU,  double B0,  double B1,  double NU,
           double RHO_0,  double PHASE_PAR,  double PSI_DEG,  double SQ_AMPL,
           double SQ_PHASE,  double SQ_STATIC,  double FNUC_FMAG,  double MU_KT,
           double LAM_CENTER,  double D_LAM_LAM,  double SD,  double P_POL,
           double EPSILON_FLIPPER,  double T_PLUS,  double T_MINUS,  double B_STATIC,
           double B_STAT_PHI_DEG,  double DELTA_T_BOTTOM,  double DELTA_T_TOP,
           double ALPHA_PHASE,  double LAMBDA,  double MU,  double DAMP_ALPHA,
           double SQ_TIME,  double TEMPERATURE,  double AD,  double AD_FUNC,
           double NONAD_FUNC,  double FNUC,  double FMAG,  double S1,  double S2,
           double R,  double R_AV,  double TIME,  double STATIC,  double PSI)
{
    PSI = PSI_DEG*M_PI/180.0;
    AD = 1.0;
    R=1.0;
    R_AV=R;
    TEMPERATURE = 273.0;
    DAMP_ALPHA = 1.0;
    STATIC = 1.0;
    P_POL = -fabs(P_POL);
    EPSILON_FLIPPER = 1.0;
    T_PLUS = 1.0;
    T_MINUS = 0.0;
    return i_measured(t,NU, B0, B1, NU, RHO_0, PHASE_PAR, PSI_DEG, SQ_AMPL,
                      SQ_PHASE, SQ_STATIC, FNUC_FMAG, MU_KT, LAM_CENTER, D_LAM_LAM, SD, P_POL,
                      EPSILON_FLIPPER, T_PLUS, T_MINUS, B_STATIC, B_STAT_PHI_DEG, DELTA_T_BOTTOM,
                      DELTA_T_TOP, ALPHA_PHASE, LAMBDA, MU, DAMP_ALPHA, SQ_TIME, TEMPERATURE, AD,
                      AD_FUNC, NONAD_FUNC, FNUC, FMAG, S1, S2, R, R_AV, TIME, STATIC, PSI);
}
double Fq( double q,  double NU,  double B0,  double B1,  double NU,
           double RHO_0,  double PHASE_PAR,  double PSI_DEG,  double SQ_AMPL,
           double SQ_PHASE,  double SQ_STATIC,  double FNUC_FMAG,  double MU_KT,
           double LAM_CENTER,  double D_LAM_LAM,  double SD,  double P_POL,
           double EPSILON_FLIPPER,  double T_PLUS,  double T_MINUS,  double B_STATIC,
           double B_STAT_PHI_DEG,  double DELTA_T_BOTTOM,  double DELTA_T_TOP,
           double ALPHA_PHASE,  double LAMBDA,  double MU,  double DAMP_ALPHA,
           double SQ_TIME,  double TEMPERATURE,  double AD,  double AD_FUNC,
           double NONAD_FUNC,  double FNUC,  double FMAG,  double S1,  double S2,
           double R,  double R_AV,  double TIME,  double STATIC,  double PSI)
{
// insert your code here
    return 0.0;
}
double form_volume(  double NU,  double B0,  double B1,  double NU,
                     double RHO_0,  double PHASE_PAR,  double PSI_DEG,  double SQ_AMPL,
                     double SQ_PHASE,  double SQ_STATIC,  double FNUC_FMAG,  double MU_KT,
                     double LAM_CENTER,  double D_LAM_LAM,  double SD,  double P_POL,
                     double EPSILON_FLIPPER,  double T_PLUS,  double T_MINUS,  double B_STATIC,
                     double B_STAT_PHI_DEG,  double DELTA_T_BOTTOM,  double DELTA_T_TOP,
                     double ALPHA_PHASE,  double LAMBDA,  double MU,  double DAMP_ALPHA,
                     double SQ_TIME,  double TEMPERATURE,  double AD,  double AD_FUNC,
                     double NONAD_FUNC,  double FNUC,  double FMAG,  double S1,  double S2,
                     double R,  double R_AV,  double TIME,  double STATIC,  double PSI)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double NU, double B0, double B1, double NU,
             double RHO_0, double PHASE_PAR, double PSI_DEG, double SQ_AMPL, double SQ_PHASE,
             double SQ_STATIC, double FNUC_FMAG, double MU_KT, double LAM_CENTER,
             double D_LAM_LAM, double SD, double P_POL, double EPSILON_FLIPPER,
             double T_PLUS, double T_MINUS, double B_STATIC, double B_STAT_PHI_DEG,
             double DELTA_T_BOTTOM, double DELTA_T_TOP, double ALPHA_PHASE, double LAMBDA,
             double MU, double DAMP_ALPHA, double SQ_TIME, double TEMPERATURE, double AD,
             double AD_FUNC, double NONAD_FUNC, double FNUC, double FMAG, double S1,
             double S2, double R, double R_AV, double TIME, double STATIC, double PSI)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, NU, B0, B1, NU, RHO_0, PHASE_PAR, PSI_DEG, SQ_AMPL, SQ_PHASE,
               SQ_STATIC, FNUC_FMAG, MU_KT, LAM_CENTER, D_LAM_LAM, SD, P_POL, EPSILON_FLIPPER,
               T_PLUS, T_MINUS, B_STATIC, B_STAT_PHI_DEG, DELTA_T_BOTTOM, DELTA_T_TOP,
               ALPHA_PHASE, LAMBDA, MU, DAMP_ALPHA, SQ_TIME, TEMPERATURE, AD, AD_FUNC,
               NONAD_FUNC, FNUC, FMAG, S1, S2, R, R_AV, TIME, STATIC, PSI);
}
