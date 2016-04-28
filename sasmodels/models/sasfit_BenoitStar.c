///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* src/sasfit_ff/sasfit_ff_BenoitStar.c
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
/*
float BenoitStar(Tcl_Interp *interp,
float q,
float Rg,
float f,
float I0,
bool  *error)
*/
/**
* form factor of a star polymer with Gaussian statistics
* scattering length density:  eta
* Rg^2 is the assemble average radius of gyration squared of an arm
* f is the number of arm
*/
double Iq( double q,
	double Rg,
	double f,
	double EMPTY,
	double I0)
{
double u,v;
//double Rg, f, I0;
if (q  == 0.0) return I0;
if (Rg == 0.0) return 0.0;
u = q*q*Rg*Rg;
v = u*f/(3.0*f-2.0);
return I0*(2.0/(f*v*v)*(-1.0+v+exp(-v)+(f-1.0)*pow(1.0-exp(-v),2.0)/2.0));
}
double Iqxy( double qx, double qy,
	double Rg,
	double f,
	double EMPTY,
	double I0)
{
	double q = sqrt(qx*qx + qy*qy);
	return Iq( q, Rg, f, EMPTY, I0);
}
