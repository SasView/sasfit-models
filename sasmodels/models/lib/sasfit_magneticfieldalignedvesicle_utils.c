///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iqxy( double qx, double qy, double RSH0, double THETA1, double THETA2, double T_SH, double T_C, double DETA_SH, double DETA_CE, double SIGMA, double PSI_DEG, double KAPPA, double Q, double RKERNEL, double GAMA, double _THETA, double PHI, double PSI, double RSH);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
#define Power pow
#define Cos cos
#define Sin sin
#define Pi M_PI
#define Sec 1./cos
#define Csc 1./sin
double mKernelreal(double z, sasfit_param *param)
{
double res, tmp;
res = cos(Q*z*cos(GAMA))*Pi*(RKERNEL*RKERNEL-z*z);
tmp =Q*sqrt(RKERNEL*RKERNEL-z*z)*sin(GAMA);
if (fabs(tmp) > 0.0) {
return res*2.0*sas_J1(tmp)/tmp;
} else {
return res;
}
}
double mKernelimag(double z, sasfit_param *param)
{
double res, tmp;
res = sin(Q*z*cos(GAMA))*Pi*(RKERNEL*RKERNEL-z*z);
tmp =Q*sqrt(RKERNEL*RKERNEL-z*z)*sin(GAMA);
if (fabs(tmp) > 0.0) {
return res*2.0*sas_J1(tmp)/tmp;
} else {
return res;
}
}
void sasfit_cappedSphere(double q,
sasfit_param *param,
double R,
double theta1,
double theta2,
double *Freal,
double *Fimag)
{
RKERNEL = R;
Q = q;
if (R == 0) {
*Freal = 0.0;
*Fimag = 0.0;
} else {
*Freal = sasfit_integrate(-RKERNEL*cos(theta2), RKERNEL*cos(theta1), mKernelreal, param);
if (theta1 == theta2) {
*Fimag = 0.0;
} else {
*Fimag = sasfit_integrate(-RKERNEL*cos(theta2), RKERNEL*cos(theta1), mKernelimag, param);
}
}
return;
}
void sasfit_Cylinder4cappedSphere(double q,
double R,
double a,
double b,
double alpha,
double *Freal,
double *Fimag)
{
if (q==0.0) {
*Freal = (b-a)*Pi*R*R;
*Fimag = 0.0;
} else if (alpha == 0.0) {
*Freal = -((Pi*Power(R,2)*(Sin(a*q) - Sin(b*q)))/q);
*Fimag =   (Pi*Power(R,2)*(Cos(a*q) - Cos(b*q)))/q;
} else {
*Freal = (-8*Pi*R*sas_J1(q*R*Sin(alpha))
* Cos(((a + b)*q*Cos(alpha))/2.)
* Csc(2*alpha)
* Sin(((a - b)*q*Cos(alpha))/2.)
)/Power(q,2);
*Fimag = ( 4*Pi*R*sas_J1(q*R*Sin(alpha))
*(Cos(a*q*Cos(alpha)) - Cos(b*q*Cos(alpha)))
* Csc(2*alpha)
)/Power(q,2);
}
return;
}
double sasfit_ff_magneticfieldalignedvesicle_util_psi(double q, sasfit_param * param)
{
double R,t,
lc1, lc2,tdisc1, tdisc2,
Rc1, Rc2,
theta1P, theta2P,
Deta_sh, Deta_c;
double Fsphreal, Fsphimag;
double Freal , Fimag;
double tmpFreal , tmpFimag;
double FD1real, FD1imag;
double FD2real, FD2imag, IQ;
int i,imax;
// insert your code here
R = RSH;
t = T_SH;
if (R*10 < t) {
return sas_pow_2(Dsld_SH*4.0*M_PI*(sin(Q*t)-Q*t*cos(Q*t))/(Q*Q*Q));
}
Deta_sh = Dsld_SH;
Deta_c  = Dsld_CE;
lc1 = RSH*cos(THsld1);
lc2 = RSH*cos(THsld2);
Rc1 = RSH*sin(THsld1);
Rc2 = RSH*sin(THsld2);
if (fabs(RSH+T_SH)>0) {
theta1P = asin(Rc1/(RSH+T_SH));
theta2P = asin(Rc2/(RSH+T_SH));
} else {
theta1P = 0.0;
theta2P = 0.0;
}
tdisc1 = sqrt((R+t)*(R+t)-Rc1*Rc1)-sqrt(R*R-Rc1*Rc1);
tdisc2 = sqrt((R+t)*(R+t)-Rc2*Rc2)-sqrt(R*R-Rc2*Rc2);
IQ = 0.0;
imax = 0;
for (i=1;i<=1;i++) {
imax++;
if (fabs(q) > 0) {
sasfit_cappedSphere(q * (1+0.0*sas_pow_int(-1,i+1)),param,R+T_SH,theta1P,theta2P,&tmpFreal,&tmpFimag);
sasfit_cappedSphere(q * (1+0.0*sas_pow_int(-1,i+1)),param,R     ,THsld1 ,THsld2 ,&Fsphreal,&Fsphimag);
Fsphreal = Deta_sh*(tmpFreal-Fsphreal);
Fsphimag = Deta_sh*(tmpFimag-Fsphimag);
sasfit_Cylinder4cappedSphere(q,Rc1,lc1,lc1+tdisc1,GAMA,&tmpFreal,&tmpFimag);
FD1real = - Deta_sh * tmpFreal;
FD1imag = - Deta_sh * tmpFimag;
sasfit_Cylinder4cappedSphere(q,Rc2,-(lc2+tdisc2),-lc2,GAMA,&tmpFreal,&tmpFimag);
FD2real = - Deta_sh * tmpFreal;
FD2imag = - Deta_sh * tmpFimag;
sasfit_Cylinder4cappedSphere(q,Rc1,lc1,lc1+T_C,GAMA,&tmpFreal,&tmpFimag);
FD1real = FD1real + Deta_c * tmpFreal;
FD1imag = FD1imag + Deta_c * tmpFimag;
sasfit_Cylinder4cappedSphere(q,Rc2,-(lc2+T_C),-lc2,GAMA,&tmpFreal,&tmpFimag);
FD2real =  FD2real + Deta_c * tmpFreal;
FD2imag =  FD2imag + Deta_c * tmpFimag;
} else {
Fsphreal = Deta_sh*
(Pi*Power(R,3)*(- 9*Cos(THsld1)
+   Cos(3*THsld1)
- 9*Cos(THsld2)
+   Cos(3*THsld2)
)
)/12.;
FD1real  = -Deta_sh*Pi*pow(Rc1,2)*tdisc1;
FD2real  = -Deta_sh*Pi*pow(Rc2,2)*tdisc2;
FD1real = FD1real + Deta_c*Pi*pow(Rc1,2)*T_C;
FD2real = FD2real + Deta_c*Pi*pow(Rc2,2)*T_C;
Fsphimag = 0.0;
FD1imag = 0.0;
FD2imag = 0.0;
}
Freal = FD1real + FD2real + Fsphreal;
Fimag = FD1imag + FD2imag + Fsphimag;
IQ = IQ + Freal*Freal+Fimag*Fimag;
}
return IQ/imax;
}
double Iqxy( double qx, double qy, double RSH0, double THETA1, double THETA2, double T_SH, double T_C, double DETA_SH, double DETA_CE, double SIGMA, double PSI_DEG, double KAPPA, double Q, double RKERNEL, double GAMA, double _THETA, double PHI, double PSI, double RSH)
{
	double q = sqrt(qx*qx + qy*qy);
	return Iq( q, RSH0, THETA1, THETA2, T_SH, T_C, DETA_SH, DETA_CE, SIGMA, PSI_DEG, KAPPA, Q, RKERNEL, GAMA, _THETA, PHI, PSI, RSH);
}
