///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* src/sasfit_ff/sasfit_ff_MassFractExp.c
*
* Copyright (c) 2008-2009, Paul Scherrer Institute (PSI)
*
* This file is part of SASfit.
*
* SASfit is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* SASfit is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with SASfit.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*   Ingo Bressler (ingo@cs.tu-berlin.de)
*/
double Iq( double q,
	double RG,
	double D,
	double I0,
	double Q)
{
double xi;
if (RG == 0) return 0.0;
xi = sqrt(2.0*RG*RG/(D*(D+1.0)));
return I0*(sin((D-1.0)*atan(q*xi))) / ((D-1.)*q*xi*pow(1.0+q*q*xi*xi,(D-1.0)/2.0));
}
double Iqxy( double qx, double qy,
	double RG,
	double D,
	double I0,
	double Q)
{
	double q = sqrt(qx*qx + qy*qy);
	return Iq( q, RG, D, I0, Q);
}
