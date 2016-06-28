///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double LC,  double N_AGG,  double V_BRUSH,
           double ETA_CORE,  double ETA_BRUSH,  double ETA_SOLV,  double XSOLV_CORE,
           double RG,  double D,  double PCHAIN,  double NAGG,  double V_CORE);
double Fq( double q,  double LC,  double N_AGG,  double V_BRUSH,
           double ETA_CORE,  double ETA_BRUSH,  double ETA_SOLV,  double XSOLV_CORE,
           double RG,  double D,  double PCHAIN,  double NAGG,  double V_CORE);
double form_volume(  double LC,  double N_AGG,  double V_BRUSH,
                     double ETA_CORE,  double ETA_BRUSH,  double ETA_SOLV,  double XSOLV_CORE,
                     double RG,  double D,  double PCHAIN,  double NAGG,  double V_CORE);
double Iqxy( double qx, double qy, double LC, double N_AGG, double V_BRUSH,
             double ETA_CORE, double ETA_BRUSH, double ETA_SOLV, double XSOLV_CORE,
             double RG, double D, double PCHAIN, double NAGG, double V_CORE);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
#define SURF M_PI*sas_pow_2(100*LC) // surface area is not really known for this cross section form factor and is guessed to be the one of a disc with a radius 100 times larger than the thickjness of the core layer
double Iq( double q, double LC,  double N_AGG,  double V_BRUSH,
           double ETA_CORE,  double ETA_BRUSH,  double ETA_SOLV,  double XSOLV_CORE,
           double RG,  double D,  double PCHAIN,  double NAGG,  double V_CORE)
{
    double Fc, Fs, Fcs, Scc, Ssc, w, I, rc, rs;
// insert your code here
    V_CORE = LC * (1.0-XSOLV_CORE)/N_AGG;
    NAGG = SURF * N_AGG;
    rs = V_CORE * (ETA_CORE - ETA_SOLV);
    rc = V_BRUSH * (ETA_BRUSH - ETA_SOLV);
    Fc = sasfit_gauss_fc(q, RG);
    w = sasfit_rwbrush_w(q, RG);
    if (q * LC/2. == 0)
    {
        Fs = 1.0;
    }
    else
    {
        Fs = sin(q * LC/2.) / (q * LC/2.);
    }
    Fcs = Fs*Fs;
    Scc = sas_pow_2(w*cos(q*(LC/2.+D*RG)));
    Ssc = w * Fs *cos(q*(LC/2.+D*RG));
    PCHAIN = NAGG*rc*rc*Fc;
    I =   NAGG*NAGG*rs*rs*Fcs
          + 0*NAGG*rc*rc*Fc
          + NAGG*(NAGG-1.)*((NAGG < 1.) ?  0 : 1)*rc*rc*Scc
          + 2.*NAGG*NAGG*rs*rc*Ssc;
    return I/sas_pow_2(SURF);
}
double Fq( double q,  double LC,  double N_AGG,  double V_BRUSH,
           double ETA_CORE,  double ETA_BRUSH,  double ETA_SOLV,  double XSOLV_CORE,
           double RG,  double D,  double PCHAIN,  double NAGG,  double V_CORE)
{
// insert your code here
    return 0.0;
}
double form_volume(  double LC,  double N_AGG,  double V_BRUSH,
                     double ETA_CORE,  double ETA_BRUSH,  double ETA_SOLV,  double XSOLV_CORE,
                     double RG,  double D,  double PCHAIN,  double NAGG,  double V_CORE)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double LC, double N_AGG, double V_BRUSH,
             double ETA_CORE, double ETA_BRUSH, double ETA_SOLV, double XSOLV_CORE,
             double RG, double D, double PCHAIN, double NAGG, double V_CORE)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, LC, N_AGG, V_BRUSH, ETA_CORE, ETA_BRUSH, ETA_SOLV, XSOLV_CORE, RG,
               D, PCHAIN, NAGG, V_CORE);
}
