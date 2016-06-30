///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R,  double EPSILON,  double L,  double T,
           double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
           double HOW,  double Q,  double ALPHA,  double THETA,  double P0);
double Fq( double q,  double R,  double EPSILON,  double L,  double T,
           double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
           double HOW,  double Q,  double ALPHA,  double THETA,  double P0);
double form_volume(  double R,  double EPSILON,  double L,  double T,
                     double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
                     double HOW,  double Q,  double ALPHA,  double THETA,  double P0);
double Iqxy( double qx, double qy, double R, double EPSILON, double L, double T,
             double ETA_CORE, double ETA_SH, double ETA_SOL, double PHI, double PAR,
             double HOW, double Q, double ALPHA, double THETA, double P0);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (<joachim.kohlbrecher@psi.ch>)
*   17.5.2009
*/
// define shortcuts for local R, EPSILON, L, T, ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR, HOW, Q, ALPHA, THETA, P0eters/variables
double beta_cq(double q,  double R,  double EPSILON,  double L,  double T,
               double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
               double HOW,  double Q,  double ALPHA,  double THETA,  double P0)
{
    double cq,beta,u,S0, B,C,D,n,r;
    double B2, B3,  Vp, Ap, Rp;
    r=sqrt((R+T)*(R*EPSILON+T));
    u=q*2.0*r;
    cq=3*(sin(u)-u*cos(u))/sas_pow_3(u);
    n = PHI/form_volume(q,R, EPSILON, L, T, ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR,
                        HOW, Q, ALPHA, THETA, P0,0);
    B = M_PI*r*r*(L+2.0*T)*n;
    C = 4./3.*M_PI*r*r*r*n;
    D = 0.5 * M_PI*r*(L+2.0*T)*(L+2.0*T)*n;
    S0 = -1;
    if ( (int) (fabs(fmod(HOW,10))+0.5) == 1)
    {
        S0 = sas_pow_4(1.0-B-C)/(sas_pow_2(1.0+2.0*(B+C))+2.0*D*(1.0+B+5./4.*C));
    }
    if ( (int) (fabs(fmod(HOW,10))+0.5) == 2)
    {
        S0 = sas_pow_4(1.0-B-C)/((1.0+2.0*sas_pow_2(B+C))+2.0*D*(1.0+B+5./4.*C));
    }
    if ( (int) (fmod(HOW,10)+0.5) == 3)
    {
        Rp = M_PI*r/4.0+(L+2*T)/4.0;
        Vp = form_volume(q,R, EPSILON, L, T, ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR, HOW,
                         Q, ALPHA, THETA, P0,0);
        if (EPSILON == 1)
        {
            Ap = 2.0*M_PI*R;
        }
        else if (EPSILON < 1)
        {
            Ap = 4.0*R*gsl_sf_ellint_Ecomp(EPSILON,0);
        }
        else if (EPSILON > 1)
        {
            Ap = 4.0*R*EPSILON*gsl_sf_ellint_Ecomp(1./EPSILON,0);
        }
        B2 = (Vp+Ap*Rp)/Vp;
        B3 = (sas_pow_2(Vp)+2.0*Rp*Ap*Vp+1.0/3.0*sas_pow_2(Rp*Ap))/sas_pow_2(Vp);
        S0 = sas_pow_4(1.0-PHI)/(1.0+2.0*(B2-2.0)*PHI+(3.0*B3-8.0*B2+6.0)*sas_pow_2(
                                     PHI));
    }
    if ( (int) (fabs(fmod(HOW,10))+0.5) == 4)
    {
        Rp = M_PI*r/4.0+(L+2*T)/4.0;
        Vp = form_volume(q,R, EPSILON, L, T, ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR, HOW,
                         Q, ALPHA, THETA, P0,0);
        if (EPSILON == 1)
        {
            Ap = 2.0*M_PI*R;
        }
        else if (EPSILON < 1)
        {
            Ap = 4.0*R*gsl_sf_ellint_Ecomp(EPSILON,0);
        }
        else if (EPSILON > 1)
        {
            Ap = 4.0*R*EPSILON*gsl_sf_ellint_Ecomp(1./EPSILON,0);
        }
        B3 = (sas_pow_2(Vp)+2.0*Rp*Ap*Vp+1.0/(12.0*M_PI)*sas_pow_3(Ap))/sas_pow_2(Vp);
        S0 = sas_pow_4(1.0-PHI)/(1.0+2.0*(B2-2.0)*PHI+(3.0*B3-8.0*B2+6.0)*sas_pow_2(
                                     PHI));
    }
    if ( (int) (fabs(fmod(HOW,10))+0.5) == 5)
    {
        S0 = 1.0/(1.0+2.0*PAR*PHI);
    }
    beta = (1.0-S0)/S0;
    return beta*cq;
}
double P_Rod(double q, double length)
{
    double u,u2;
    u = fabs(q*length);
    u2 = u/2.0;
//	if (u < 1.0e-2) return exp(-u*u/12.0/3.0);
    return 2.0*Si(u)/u-sas_pow_2(sin(u2)/u2);
}
double P_L(double q,  double R,  double EPSILON,  double L,  double T,
           double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
           double HOW,  double Q,  double ALPHA,  double THETA,  double P0)
{
    return L*L*P_Rod(q,L);
}
double r(double radius, double epsilo, double theta)
{
    return radius*sqrt(sin(theta)*sin(theta)+epsilo*epsilo*cos(theta)*cos(theta));
}
double AcylSHell(double x,  double R,  double EPSILON,  double L,  double T,
                 double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
                 double HOW,  double Q,  double ALPHA,  double THETA,  double P0)
{
    double Ain, Aout,A,u1,u2,v1,v2,b1,b2;
    u1 = Q*r(R,EPSILON,THETA)*sin(ALPHA);
    v1 = Q*L*0.5*cos(ALPHA);
    u2 = Q*(r(R,EPSILON,THETA)+T)*sin(ALPHA);
    v2 = Q*(L*0.5+T)*cos(ALPHA);
    b1 = M_PI*R*R*EPSILON*L*(ETA_CORE-ETA_SH);
    b2 = M_PI*(R+T)*(R+T)*EPSILON*(L+2.0*T)*(ETA_SH-ETA_SOL);
    if (v1==0)
    {
        Ain = 1;
    }
    else
    {
        Ain = sin(v1)/v1;
    }
    if (u1!=0)
    {
        Ain = Ain*2.0*sas_J1(u1)/u1;
    }
    if (v2==0)
    {
        Aout = 1;
    }
    else
    {
        Aout = sin(v2)/v2;
    }
    if (u2!=0)
    {
        Aout = Aout*2.0*sas_J1(u2)/u2;
    }
    A = b1*Ain+b2*Aout;
    return A;
}
double PcylSHell( double R,  double EPSILON,  double L,  double T,
                  double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
                  double HOW,  double Q,  double ALPHA,  double THETA,  double P0)
{
    double Ain, Aout,A,u1,u2,v1,v2,b1,b2, J1;
    u1 = Q*r(R,EPSILON,THETA)*sin(ALPHA);
    v1 = Q*L*0.5*cos(ALPHA);
    u2 = Q*(r(R,EPSILON,THETA)+T)*sin(ALPHA);
    v2 = Q*(L*0.5+T)*cos(ALPHA);
    b1 = M_PI*R*R*EPSILON*L*(ETA_CORE-ETA_SH);
    b2 = M_PI*(R+T)*(R+T)*EPSILON*(L+2*T)*(ETA_SH-ETA_SOL);
    if (v1==0)
    {
        Ain = 1;
    }
    else
    {
        Ain = sin(v1)/v1;
    }
    if (u1!=0)
    {
        J1 = sasfit_bessj1(u1);
//		J1 = sas_J1(u1);
        Ain = Ain*2.0*J1/u1;
    }
    if (v2==0)
    {
        Aout = 1;
    }
    else
    {
        Aout = sin(v2)/v2;
    }
    if (u2!=0)
    {
        J1 = sasfit_bessj1(u2);
//		J1 = sas_J1(u2);
        Aout = Aout*2.0*J1/u2;
    }
    A = b1*Ain+b2*Aout;
    return A*A;
}
double PcylSHellCS(double x, double R,  double EPSILON,  double L,  double T,
                   double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
                   double HOW,  double Q,  double ALPHA,  double THETA,  double P0)
{
    double Ain, Aout,A,u1,u2,b1,b2, J1;
    u1 = Q*r(R,EPSILON,x);
    u2 = Q*(r(R,EPSILON,x)+T);
    b1 = M_PI*R*R*EPSILON*(ETA_CORE-ETA_SH);
    b2 = M_PI*(R+T)*(R+T)*EPSILON*(ETA_SH-ETA_SOL);
    if (u1 == 0.0)
    {
        Ain = 1.0;
    }
    else
    {
//		J1 = sasfit_bessj1(u1);
        J1 = sas_J1(u1);
        Ain = 2.0*J1/u1;
    }
    if (u2 == 0.0)
    {
        Aout = 1.0;
    }
    else
    {
//		J1 = sasfit_bessj1(u2);
        J1 = sas_J1(u2);
        Aout = 2.0*J1/u2;
    }
    A = b1*Ain+b2*Aout;
    return A*A;
}
double P_cs(double q,  double R,  double EPSILON,  double L,  double T,
            double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
            double HOW,  double Q,  double ALPHA,  double THETA,  double P0)
{
    Q = q;
    if (EPSILON == 1.0)
    {
        return PcylSHellCS(1.0,R, EPSILON, L, T, ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR,
                           HOW, Q, ALPHA, THETA, P0);
    }
    else
    {
        return 2.0/M_PI*sasfit_integrate(0.0,M_PI/2.0,&PcylSHellCS,R, EPSILON, L, T,
                                         ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR, HOW, Q, ALPHA, THETA, P0);
    }
}
double RM_PRISM_theta(double x, double R,  double EPSILON,  double L,  double T,
                      double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
                      double HOW,  double Q,  double ALPHA,  double THETA,  double P0)
{
    THETA = x;
    return PcylSHell(R, EPSILON, L, T, ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR, HOW, Q,
                     ALPHA, THETA, P0);
}
double RM_PRISM_alpha(double x, double R,  double EPSILON,  double L,  double T,
                      double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
                      double HOW,  double Q,  double ALPHA,  double THETA,  double P0)
{
    ALPHA = x;
    if (EPSILON == 1.0)
    {
        return RM_PRISM_theta(1.0,R, EPSILON, L, T, ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR,
                              HOW, Q, ALPHA, THETA, P0)*sin(ALPHA);
    }
    else
    {
        return sasfit_integrate(0.0,M_PI/2.0,&RM_PRISM_theta,R, EPSILON, L, T, ETA_CORE,
                                ETA_SH, ETA_SOL, PHI, PAR, HOW, Q, ALPHA, THETA, P0)*2.0/M_PI*sin(ALPHA);
    }
}
double Iq( double q, double R,  double EPSILON,  double L,  double T,
           double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
           double HOW,  double Q,  double ALPHA,  double THETA,  double P0)
{
    double P_RODSH,ProdSQ,  SQ;
    Q = q;
    if (sasfit_eps_get_iter_4_mc() <= 0.0)
    {
        P_RODSH = 1.0;
    }
    else
    {
        if (((int) floor(HOW/10)) == 1)
        {
            P_RODSH = P_L(q,R, EPSILON, L, T, ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR, HOW, Q,
                          ALPHA, THETA, P0)*P_cs(q,R, EPSILON, L, T, ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR,
                                                 HOW, Q, ALPHA, THETA, P0);
        }
        else
        {
            P_RODSH = sasfit_integrate(0.0,M_PI/2.0,&RM_PRISM_alpha,R, EPSILON, L, T,
                                       ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR, HOW, Q, ALPHA, THETA, P0);
        }
    }
    ProdSQ = P_Rod(q,L-2.0*R);
    SQ=1.0/(1.0+beta_cq(q,R, EPSILON, L, T, ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR,
                        HOW, Q, ALPHA, THETA, P0)*ProdSQ);
    /*
    Bapp =   2.0/3.0*M_PI*sas_pow_3(DEFF)/form_volume(q,R, EPSILON, L, T, ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR, HOW, Q, ALPHA, THETA, P0,0)
    *(1.0-sas_pow_2(DEFF*q)/10.0);
    if (Bapp < 0) {
    SQ = 1;
    } else {
    SQ=1.0/(1.0+2.0*Bapp*PHI);
    }
    */
    return P_RODSH*SQ;
}
double Fq( double q,  double R,  double EPSILON,  double L,  double T,
           double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
           double HOW,  double Q,  double ALPHA,  double THETA,  double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R,  double EPSILON,  double L,  double T,
                     double ETA_CORE,  double ETA_SH,  double ETA_SOL,  double PHI,  double PAR,
                     double HOW,  double Q,  double ALPHA,  double THETA,  double P0)
{
// insert your code here
    return M_PI*(R+T)*(R*EPSILON+T)*L;
}
double Iqxy( double qx, double qy, double R, double EPSILON, double L, double T,
             double ETA_CORE, double ETA_SH, double ETA_SOL, double PHI, double PAR,
             double HOW, double Q, double ALPHA, double THETA, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R, EPSILON, L, T, ETA_CORE, ETA_SH, ETA_SOL, PHI, PAR, HOW, Q,
               ALPHA, THETA, P0);
}
