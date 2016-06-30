///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Fq( double q,  double C,  double MCORE,  double MBRUSH,  double RHO_CORE,
           double RHO_BRUSH,  double B_CORE,  double B_BRUSH,  double NAGG,
           double D1_PLUS,  double PART23,  double D2_PLUS,  double D3_PLUS,
           double SIGMA1,  double SIGMA2,  double SIGMA3,  double PARTSTAR,  double GAMMA,
           double LPARABOL,  double F_BRUSH,  double F_CORE,  double RHOSOLV,  double Q,
           double P0);
double form_volume(  double C,  double MCORE,  double MBRUSH,  double RHO_CORE,
                     double RHO_BRUSH,  double B_CORE,  double B_BRUSH,  double NAGG,
                     double D1_PLUS,  double PART23,  double D2_PLUS,  double D3_PLUS,
                     double SIGMA1,  double SIGMA2,  double SIGMA3,  double PARTSTAR,  double GAMMA,
                     double LPARABOL,  double F_BRUSH,  double F_CORE,  double RHOSOLV,  double Q,
                     double P0);
double Iq( double q, double C,  double MCORE,  double MBRUSH,  double RHO_CORE,
           double RHO_BRUSH,  double B_CORE,  double B_BRUSH,  double NAGG,
           double D1_PLUS,  double PART23,  double D2_PLUS,  double D3_PLUS,
           double SIGMA1,  double SIGMA2,  double SIGMA3,  double PARTSTAR,  double GAMMA,
           double LPARABOL,  double F_BRUSH,  double F_CORE,  double RHOSOLV,  double Q,
           double P0);
double Iqxy( double qx, double qy, double C, double MCORE, double MBRUSH,
             double RHO_CORE, double RHO_BRUSH, double B_CORE, double B_BRUSH, double NAGG,
             double D1_PLUS, double PART23, double D2_PLUS, double D3_PLUS, double SIGMA1,
             double SIGMA2, double SIGMA3, double PARTSTAR, double GAMMA, double LPARABOL,
             double F_BRUSH, double F_CORE, double RHOSOLV, double Q, double P0);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0eters/variables
double sasfit_ff_jjuelichcoreshell(double q, sasfit_param * param)
{
// insert your code here
    return 0.0;
}
double Fq( double q,  double C,  double MCORE,  double MBRUSH,  double RHO_CORE,
           double RHO_BRUSH,  double B_CORE,  double B_BRUSH,  double NAGG,
           double D1_PLUS,  double PART23,  double D2_PLUS,  double D3_PLUS,
           double SIGMA1,  double SIGMA2,  double SIGMA3,  double PARTSTAR,  double GAMMA,
           double LPARABOL,  double F_BRUSH,  double F_CORE,  double RHOSOLV,  double Q,
           double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double C,  double MCORE,  double MBRUSH,  double RHO_CORE,
                     double RHO_BRUSH,  double B_CORE,  double B_BRUSH,  double NAGG,
                     double D1_PLUS,  double PART23,  double D2_PLUS,  double D3_PLUS,
                     double SIGMA1,  double SIGMA2,  double SIGMA3,  double PARTSTAR,  double GAMMA,
                     double LPARABOL,  double F_BRUSH,  double F_CORE,  double RHOSOLV,  double Q,
                     double P0)
{
// insert your code here
    return 0.0;
}
// JuelichCoreShell (JCS) subParam layout:
typedef enum
{
    JCS_Q		= 0,
    JCS_R1		= 1,
    JCS_R1_OLD	= 2,
    JCS_SIGMA1	= 3,
    JCS_SIGMA1_OLD	= 4,
    JCS_TOT_SWELL1	= 5,
    JCS_V1I		= 6,
    JCS_PHI01	= 7,
    JCS_R2		= 8,
    JCS_R2_OLD	= 9,
    JCS_SIGMA2	= 10,
    JCS_SIGMA2_OLD	= 11,
    JCS_TOT_SWELL2	= 12,
    JCS_V2I		= 13,
    JCS_PHI02	= 14,
    JCS_R3		= 15,
    JCS_R3_OLD	= 16,
    JCS_SIGMA3	= 17,
    JCS_SIGMA3_OLD	= 18,
    JCS_TOT_SWELL3	= 19,
    JCS_V3I		= 20,
    JCS_PHI03	= 21,
    JCS_GAMMA	= 22,
    JCS_FSTAR	= 23,
    JCS_LPARABOL	= 24
} jcs_param_layout_t;
static const double jcs_xunit = 1e-8;
/*
* ---> fermi Funkktion 1/(1+exp(x/sigma)  ROBUST
*
*  implicit none
*  double precision x, sigma, arg
*/
double fermi(double x, double sigma)
{
    double argu;
    if (sigma > 0.0)
    {
        argu = x/sigma;
        if (argu < -100.0)
        {
            return 1.0;
        }
        if (argu > 100.0)
        {
            return 0.0;
        }
        return 1.0/(1.0+exp(argu));
    }
    else
    {
        if (x < 0.0)
        {
            return 1.0;
        }
        else
        {
            return 0.0;
        }
    }
}
double parabol_brush(double x, double l)
{
    double yl;
    if (l < 1e-4*jcs_xunit)
    {
        yl = 1e-4*jcs_xunit;
    }
    else
    {
        yl = l;
    }
    if (x < 0.0)
    {
        return 1.0;
    }
    if (x > yl)
    {
        return 0.0;
    }
    return 1.0 - (x/yl)*(x/yl);
}
// for the first shot I do this with switches, may be improved later ..
double plugin_vol_ker(double r, sasfit_param * param)
{
    double phi, r_para;
    int idx_dist;
    idx_dist = (JCS_R2 - JCS_R1) * (C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE,
                                    B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3,
                                    PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0->kernelSelector-1);
    switch( C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS,
            PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL,
            F_BRUSH, F_CORE, RHOSOLV, Q,
            P0->kernelSelector )	// represent the shell to calculate
    {
    case 1:
        break;
    case 2:
// Volumefraction 2.Schale
// Modellierung 2.Schale : hier einfache Fermi-Fktn
        break;
    case 3:
// Modellierung 3.Schale :  Fermi-Fktn * Parabol oder star
    {
        r_para = r;
    }
    else
    {
    }
    break;
    default:
        SASFIT_ERR_UNKNOWN_KERNEL(C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE,
                                  B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3,
                                  PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0, "shell number");
        break;
    }
    {
        return 4.0*M_PI * phi * r*r;	// former vol_kerX() function
    }
    {
// Streuintegration Schale X
    }
    else
    {
        SASFIT_ERR_UNKNOWN_KERNEL(C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE,
                                  B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3,
                                  PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0,
                                  "integration method");
    }
}
double jcs_integrate(sasfit_param *param, int shellNr, int intType)
{
    const double VerrorVal = 1.007;
    double res, R, sigma;
    int idx_dist;
    C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23,
    D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH,
    F_CORE, RHOSOLV, Q, P0->kernelSelector = shellNr;
    C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23,
    D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH,
    F_CORE, RHOSOLV, Q, P0->kernelSubSelector = intType;
// used to add to array indices to get the correct entry
// JCS_R1+distance = JCS_R2 ..
    idx_dist = (JCS_R2 - JCS_R1) * (C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE,
                                    B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3,
                                    PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0->kernelSelector-1);
    res = sasfit_integrate(0.0, R+sigma*10.0, plugin_vol_ker, C, MCORE, MBRUSH,
                           RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS,
                           SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q,
                           P0);
    if ( C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS,
            PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL,
            F_BRUSH, F_CORE, RHOSOLV, Q, P0->errStatus != FALSE )
    {
        if ( C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS,
                PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL,
                F_BRUSH, F_CORE, RHOSOLV, Q,
                P0->kernelSubSelector == JCS_INT_V )	return VerrorVal;
        else 						return 0.0;	// t == JCS_INT_FF
    }
    return res;
}
/*
'amplitu'	concentration factor
'mcore'		molecular weight core (g/mol)
'mbrush'	molecular weight brush (g/mol)
'rhocore'	density core matter (g/cm**3)
'rhobrsh'	density brush matter (g/cm**3)
'bcore'		scattering length density core mat. (cm**-2)
'bbrush'	scattering length density brush mat.(cm**-2)
'naggr'		aggregation number real to be fitted
'd1+'		extra radius of shell1=core (compared to compact)
'part23'	relative distribution of shell amount in shell2:shell3 (0..inf)
'd2+'		extra radius of shell2 (compared to compact)
'd3+'		extra radius of shell3 (compared to compact)
'sigma1'	core smearing
'sigma2'	shell2 smearing
'sigma3'	shell3 smearing
'partstar'	relative distribution of parbolic:starlike profile in shell3;
I usually put a very high value in order to consider only a star-like profile.
'gamma'		star-like exponent is 4/3, const=0
'lparabol'	thickness of parabolic brush (must fit in shell3!) I put it = 0
'f_brush'	scattering length density correction factor brush
'f_core'	scattering length density correction factor core
'rhosolv'   scattering length density of solvent
dbc = bcore-rhosolv*(1-f_core)
dbb = bbrush - rhosolv*(1-f_brush)
dSigma/dOmega = amplitu/(VC+VB)*(dbc*F1+dbb*(F1+F2))^2
*/
double Iq( double q, double C,  double MCORE,  double MBRUSH,  double RHO_CORE,
           double RHO_BRUSH,  double B_CORE,  double B_BRUSH,  double NAGG,
           double D1_PLUS,  double PART23,  double D2_PLUS,  double D3_PLUS,
           double SIGMA1,  double SIGMA2,  double SIGMA3,  double PARTSTAR,  double GAMMA,
           double LPARABOL,  double F_BRUSH,  double F_CORE,  double RHOSOLV,  double Q,
           double P0)
{
    double amplitu, mcore, mbrush,
           rhocore, rhobrsh, bcore, bbrush,
           naggr, d1p, part23, d2p, d3p, sigma1, sigma2, sigma3, partstar, gamma, lparabol,
           f_brush, f_core, rhosolv;
    double dbc, dbb,Nav,VC,RC0,R1,VCS,swellC,VB,fshell2,fshell3;
    double VS2, RC2, R2, VS2S, swellS2;
    double VS3, RC3, R3, VS3S, swellS3;
    double fstar;
    static double V_1, V_2, V_3;
    double f_1, f_2, f_3;
    double delta, alpha, a1,a2,a3,afactor;
//	const double unit = 1e-7;
    static double first=-1;
    sasfit_param subParam;
    /*
    */
    Q			= q/jcs_xunit;
    sasfit_init_param( &subParam );
    if (first != 1.123779053423241)
    {
        first = 1.123779053423241;
        /*
        C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.R1_old = -1.0;
        C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.sigma1_old = -1.0;
        C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.R2_old = -1.0;
        C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.sigma2_old = -1.0;
        C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.R3_old = -1.0;
        C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.sigma3_old = -1.0;
        */
        subParam.p[JCS_R1_OLD] 		= -1.0;
        subParam.p[JCS_SIGMA1_OLD] 	= -1.0;
        subParam.p[JCS_R2_OLD] 		= -1.0;
        subParam.p[JCS_SIGMA2_OLD] 	= -1.0;
        subParam.p[JCS_R3_OLD] 		= -1.0;
        subParam.p[JCS_SIGMA3_OLD] 	= -1.0;
    }
    dbc = bcore-rhosolv*(1.-f_core);
    dbb = bbrush-rhosolv*(1.-f_brush);
    Nav = 6.022045E23;
    VC = naggr*mcore/(rhocore*Nav);
    RC0 = pow(3.0/(4.0*M_PI)*VC, 1.0/3.0);
    R1 = RC0 + d1p;
    VCS = 4.0/3.0 * M_PI * R1*R1*R1;
    swellC = ((VC == 0.0) ?  1.0 : VCS/VC);
    VB = naggr*mbrush/(rhobrsh*Nav);
    fshell2 = part23/(1.0+part23)+1e-5;
    fshell3 = 1.0-fshell2;
    VS2 = fshell2*VB;
    RC2 = pow(3.0/(4.0*M_PI)*(VCS+VS2), 1.0/3.0);
    R2 = RC2+d2p;
    VS2S = 4.0/3.0 * M_PI *R2*R2*R2;
    swellS2 = ((VS2 == 0.0) ?  1.0 : (VS2S-VCS)/VS2);
    VS3 = fshell3*VB;
    RC3 = pow(3.0/(4.0*M_PI)*(VS3+VS2S), 1.0/3.0);
    R3 = RC3+d3p;
    VS3S = 4.0/3.0 * M_PI *R3*R3*R3;
    swellS3 = ((VS3 == 0.0) ?  1.0 : (VS3S-VS2S)/VS3) ;
    fstar = 2.0*atan(fabs(partstar))/M_PI;
    subParam.p[JCS_R1]	= R1;
    subParam.p[JCS_R2] 	= R2;
    subParam.p[JCS_R3] 	= R3;
    subParam.p[JCS_SIGMA1] 	= sigma1;
    subParam.p[JCS_SIGMA2] 	= sigma2;
    subParam.p[JCS_SIGMA3] 	= sigma3;
    subParam.p[JCS_Q]	= Q;
// as phi01, phi02, phi03 are anyway canceld due to the normalization F_i/V_i
// they could be set here to 1, but I will leave it as in the original
// fortran version from IFF
//   C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.phi01 = 1.;
//   C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.phi02 = 1.;
//   C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.phi03 = 1.;
    subParam.p[JCS_TOT_SWELL1] = swellC;
    subParam.p[JCS_TOT_SWELL2] = swellS2;
    subParam.p[JCS_TOT_SWELL3] = swellS3;
    if (swellC  == 0.0)
    {
        subParam.p[JCS_PHI01] = 0.0;
    }
    else
    {
        subParam.p[JCS_PHI01] = 1.0/swellC;
    }
    if (swellS2 == 0.0)
    {
        subParam.p[JCS_PHI02] = 0.0;
    }
    else
    {
        subParam.p[JCS_PHI02] = 1.0/swellS2;
    }
    if (swellS3 == 0.0)
    {
        subParam.p[JCS_PHI03] = 0.0;
    }
    else
    {
        subParam.p[JCS_PHI03] = 1.0/swellS3;
    }
    subParam.p[JCS_GAMMA] 		= gamma;
    subParam.p[JCS_FSTAR] 		= fstar;
    subParam.p[JCS_LPARABOL] 	= lparabol;
    if ((subParam.p[JCS_R1] 	!= subParam.p[JCS_R1_OLD]) ||
            (subParam.p[JCS_SIGMA1] 	!= subParam.p[JCS_SIGMA1_OLD]))
    {
        V_1 = jcs_integrate( &subParam, 1, JCS_INT_V );
        V_2 = jcs_integrate( &subParam, 2, JCS_INT_V );
        subParam.p[JCS_R1_OLD] 		= subParam.p[JCS_R1];
        subParam.p[JCS_SIGMA1_OLD] 	= subParam.p[JCS_SIGMA1];
        subParam.p[JCS_R2_OLD] 		= subParam.p[JCS_R2];
        subParam.p[JCS_SIGMA2_OLD] 	= subParam.p[JCS_SIGMA2];
    }
    if ((subParam.p[JCS_R2] 	!= subParam.p[JCS_R2_OLD]) ||
            (subParam.p[JCS_SIGMA2] 	!= subParam.p[JCS_SIGMA2_OLD]))
    {
        V_2 = jcs_integrate( &subParam, 2, JCS_INT_V );
        V_3 = jcs_integrate( &subParam, 3, JCS_INT_V );
        subParam.p[JCS_R2_OLD] 		= subParam.p[JCS_R2];
        subParam.p[JCS_SIGMA2_OLD] 	= subParam.p[JCS_SIGMA2];
        subParam.p[JCS_R3_OLD] 		= subParam.p[JCS_R3];
        subParam.p[JCS_SIGMA3_OLD] 	= subParam.p[JCS_SIGMA3];
    }
    if ((subParam.p[JCS_R3] 	!= subParam.p[JCS_R3_OLD]) ||
            (subParam.p[JCS_SIGMA3] 	!= subParam.p[JCS_SIGMA3_OLD]))
    {
        V_3 = jcs_integrate( &subParam, 3, JCS_INT_V );
        subParam.p[JCS_R3_OLD] 		= subParam.p[JCS_R3];
        subParam.p[JCS_SIGMA3_OLD] 	= subParam.p[JCS_SIGMA3];
    }
    subParam.p[JCS_V1I] = V_1;
    subParam.p[JCS_V2I] = V_2;
    subParam.p[JCS_V3I] = V_3;
//! erstens: erzwinge Kompaktvolumenvehaeltnis 2te/3te Schale
    if (V_2 > 0.0)
    {
        delta = part23 * V_3 / V_2;
    }
    else
    {
        delta = 0.0;
    }
//! zweitens: erzwinge Kompaktvolumen der gesamten Schale
    alpha = VB / (V_3 * (1. + part23) );
//! reskaliere die Schalen, so dass die Volumina konserviert sind
    a1 = VC / V_1;
    a2 = delta * alpha;
    a3 = alpha;
    dbc = bcore-rhosolv * (1.0 - f_core);
    dbb = bbrush - rhosolv * (1.0 - f_brush);
    f_1 = a1 * jcs_integrate( &subParam, 1, JCS_INT_FF );
    f_2 = a2 * jcs_integrate( &subParam, 2, JCS_INT_FF );
    f_3 = a3 * jcs_integrate( &subParam, 3, JCS_INT_FF );
    afactor = amplitu / (VC + VB);
    /*
    if ((C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.R1 != C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.R1_old) || (C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.sigma1 != C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.sigma1_old))  {
    IFFprint(C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s);
    C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.R1_old = C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.R1;
    C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.sigma1_old = C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.sigma1;
    C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.R2_old = C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.R2;
    C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.sigma2_old = C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG, D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA, LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0s.sigma2;
    }
    */
    return afactor*pow(dbc*f_1+dbb*(f_2+f_3),2.0);
}
double Iqxy( double qx, double qy, double C, double MCORE, double MBRUSH,
             double RHO_CORE, double RHO_BRUSH, double B_CORE, double B_BRUSH, double NAGG,
             double D1_PLUS, double PART23, double D2_PLUS, double D3_PLUS, double SIGMA1,
             double SIGMA2, double SIGMA3, double PARTSTAR, double GAMMA, double LPARABOL,
             double F_BRUSH, double F_CORE, double RHOSOLV, double Q, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, C, MCORE, MBRUSH, RHO_CORE, RHO_BRUSH, B_CORE, B_BRUSH, NAGG,
               D1_PLUS, PART23, D2_PLUS, D3_PLUS, SIGMA1, SIGMA2, SIGMA3, PARTSTAR, GAMMA,
               LPARABOL, F_BRUSH, F_CORE, RHOSOLV, Q, P0);
}
