///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double G2, double S2, double RG2, double S1, double RG1,
           double M)
{
    double Q1, Q2, G1,D;
// insert your code here
    Q2 = sqrt((S1-S2)/(2./(3.-S2)*RG2*RG2-2./(3.-S1)*RG1*RG1));
    G1 = G2*exp(Q2*Q2*(RG1*RG1/(3.-S1)-RG2*RG2/(3.-S2)))*pow(Q2,S1-S2);
    Q1 = 1./RG1*sqrt((M-S1)*(3.-S1)/2.);
    D=G1*exp(-Q1*Q1*RG1*RG1/(3.-S1))*pow(Q1,M-S1);
    if (q<=Q2) {
        return G2/pow(q,S2)*exp(-q*q*RG2*RG2/(3.-S2));
    } else if ((Q2<q) && (q<Q1)) {
        return G1/pow(q,S1)*exp(-q*q*RG1*RG1/(3.-S1));
    } else {
        return D/pow(q,M);
    }
}
double Fq( double q,  double G2, double S2, double RG2, double S1, double RG1,
           double M)
{
// insert your code here
    return 0.0;
}
double form_volume(  double G2, double S2, double RG2, double S1, double RG1,
                     double M)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double G2, double S2, double RG2, double S1,
             double RG1, double M)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, G2, S2, RG2, S1, RG1, M);
}
