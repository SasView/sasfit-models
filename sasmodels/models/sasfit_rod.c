///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* src/plugins/rod/sasfit_ff_rod.c
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
// define shortcuts for local parameters/variables
double Iq( double q, double LENGTH, double ETA)
{
    if (q*LENGTH == 0.0) return ETA*ETA*LENGTH*LENGTH;
    return ETA*ETA * LENGTH *
           (2.0*LENGTH*Si(q*LENGTH)/q - pow(sin(q*LENGTH*0.5)/(q*0.5),2.0));
}
double Fq( double q,  double LENGTH, double ETA)
{
// insert your code here
    if (q*LENGTH == 0.0) return ETA*LENGTH;
    return ETA *2.*Si(q*LENGTH/2.0)/q;
}
double form_volume(  double LENGTH, double ETA)
{
// insert your code here
    return LENGTH;
}
double Iqxy( double qx, double qy, double LENGTH, double ETA)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, LENGTH, ETA);
}
