r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by BroadPeak

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "BroadPeak"
title = " "
description = "F^2(q,I0,xi,m,q0) = I0/(1+(|q-q0|*xi)^m)^p"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "I0", 	"", 	10.0, 	[-inf, inf], 	"", 	"I0: forward scattering"],
 [ "XI", 	"", 	0.0, 	[-inf, inf], 	"", 	"xi: correlation length"],
 [ "Q0", 	"", 	0.0, 	[-inf, inf], 	"", 	"q0:peak position which is related to the d-spacing as q0 = 2pi/d"],
 [ "M", 	"", 	1.0, 	[-inf, inf], 	"", 	"m:"],
 [ "P", 	"", 	0.0, 	[-inf, inf], 	"", 	"p:"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["sasfit_BroadPeak.c" ]

demo = dict(
	I0 = 10.0,
	XI = 0.0,
	Q0 = 0.0,
	M = 1.0,
	P = 0.0)
