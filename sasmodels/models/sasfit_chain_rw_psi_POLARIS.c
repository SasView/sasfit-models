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
    double avgT,origyaw,q;
    double siga, da;
    int i;
// insert your code here
    RW_SAW = 1.0;
    RADAVG = 0.0;
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
    if (PSIDEG >= 0)
    {
        q = x;
        PSI = sasfit_param_override_get_psi(PSIDEG*M_PI/180.);
    }
    else
    {
        q = -PSIDEG;
        PSI = sasfit_param_override_get_psi(x*M_PI/180.);
    }
    if  (lround(PEP) == 0)
    {
        return	(1.0+POL)/2.0*(TPLUS *FFmicelle_pp(q,param)+TMINUS*FFmicelle_pm(q,param))
                +	(1.0-POL)/2.0*(TMINUS*FFmicelle_mm(q,param)+TPLUS *FFmicelle_mp(q,param));
    }
    else
    {
        avgT = 0;
        siga = SIGYAW*M_PI/180.;
        origyaw = YAWPEP*M_PI/180.;
        for (i=-6; i<=6; i++)
        {
            da = i*siga/(3.0);
            YAWPEP = origyaw+da;
            avgT = avgT+exp(-0.5*sas_pow_2(da/siga))/(siga*sqrt(2.0*M_PI))
                   *siga/3.0*
                   (    (1.0+POL)/2.0*( TPLUS *FFmicelle_pp(q,param)
                                        +TMINUS*FFmicelle_pm(q,param))
                        +	(1.0-POL)/2.0*( TMINUS*FFmicelle_mm(q,param)
                                            +TPLUS *FFmicelle_mp(q,param))
                   );
        }
        YAWPEP = origyaw*180/M_PI;
        return avgT;
    }
}
double Fq( double q,  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL)
{
    double avgT,origyaw,q;
    double siga, da;
    int i;
// insert your code here
    RW_SAW = 1.0;
    RADAVG = 0.0;
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
    if (PSIDEG >= 0)
    {
        q = x;
        PSI = sasfit_param_override_get_psi(PSIDEG*M_PI/180.);
    }
    else
    {
        q = -PSIDEG;
        PSI = sasfit_param_override_get_psi(x*M_PI/180.);
    }
//	return	(1.0+POL)/2.0*(TPLUS *Amicelle_pp(q,param)+TMINUS*Amicelle_pm(q,param))
//		+	(1.0-POL)/2.0*(TMINUS*Amicelle_mm(q,param)+TPLUS *Amicelle_mp(q,param));
    if  (lround(PEP) == 0)
    {
        return	(1.0+POL)/2.0*(TPLUS *Amicelle_pp(q,param)+TMINUS*Amicelle_pm(q,param))
                +	(1.0-POL)/2.0*(TMINUS*Amicelle_mm(q,param)+TPLUS *Amicelle_mp(q,param));
    }
    else
    {
        avgT = 0;
        siga = SIGYAW*M_PI/180.;
        origyaw = YAWPEP*M_PI/180.;
        for (i=-6; i<=6; i++)
        {
            da = i*siga/(3.0);
            YAWPEP = origyaw+da;
            avgT = avgT+exp(-0.5*sas_pow_2(da/siga))/(siga*sqrt(2.0*M_PI))
                   *siga/3.0*
                   (    (1.0+POL)/2.0*( TPLUS *Amicelle_pp(q,param)
                                        +TMINUS*Amicelle_pm(q,param))
                        +	(1.0-POL)/2.0*( TMINUS*Amicelle_mm(q,param)
                                            +TPLUS *Amicelle_mp(q,param))
                   );
        }
        YAWPEP = origyaw*180/M_PI;
        return avgT;
    }
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
