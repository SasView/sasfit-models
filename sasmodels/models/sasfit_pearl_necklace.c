///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R,  double l,  double NU,  double B,  double NP);
double Fq( double q,  double R,  double l,  double NU,  double B,  double NP);
double form_volume(  double R,  double l,  double NU,  double B,  double NP);
double Iqxy( double qx, double qy, double R, double l, double NU, double B,
             double NP);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*   8.12.2014
*/
// define shortcuts for local parameters/variables
double Iq( double q, double R,  double l,  double NU,  double B,  double NP)
{
    double  qR,ql,qA,Psi,L,Mr,mr,ms,beta,Sr,Sp,Sm,sinqA_qA,sinql2_ql2,A;
// insert your code here
    A=l+2.*R;
    qR = q*R;
    ql = q*l;
    qA = q*A;
    mr=l/B; // number of monomers in rod-like segment
    ms=4.0*M_PI*sas_pow_3(R)/(3.*NU);
    Mr=NP-1.0;
    if (qR==0.0)
    {
        Psi = 1;
    }
    else
    {
        Psi=3.*(sin(qR)-qR*cos(qR))/sas_pow_3(qR);
    }
    if (ql == 0.0)
    {
        L=1.0;
        sinql2_ql2= 1.0;
    }
    else
    {
        L=Si(ql)/(ql);
        sinql2_ql2 = sin(ql/2.0)*2/ql;
    }
    if (qA == 0.0)
    {
        sinqA_qA=1.;
    }
    else
    {
        sinqA_qA=sin(qA)/(qA);
    }
    if (q==0)
    {
        beta = 1.0;
    }
    else if (A==2*R)
    {
        if (R==0)
        {
            beta = 1;
        }
        else
        {
            beta = sin(q*R)/(q*R);
        }
    }
    else
    {
        beta=(Si(q*(A-R))-Si(qR))/(ql);
    }
    Sp=2*pow(ms,2)*pow(Psi,2)*((NP/(1-sinqA_qA))-(NP/2)-((1-pow(fabs(sinqA_qA),
                               NP))/pow(1-sinqA_qA,2))*sinqA_qA);
    Sr=pow(mr,2)*(Mr*(2*L-pow(sinql2_ql2,2))+(2*Mr*pow(beta,
                  2)/(1-sinqA_qA))- 2*pow(beta,2)*(1-pow(fabs(sinqA_qA),Mr))/pow(1-sinqA_qA,2));
    Sm=mr*beta*ms*Psi*4*(((NP-1)/(1-sinqA_qA))-((1-pow(fabs(sinqA_qA),
                         NP-1))/pow(1-sinqA_qA,2))*sinqA_qA);
    return (Sp+Sr+Sm)/pow(Mr*mr+NP*ms,2);
}
double Fq( double q,  double R,  double l,  double NU,  double B,  double NP)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R,  double l,  double NU,  double B,  double NP)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R, double l, double NU, double B,
             double NP)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R, l, NU, B, NP);
}
