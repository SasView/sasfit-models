r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by MassFractExp

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "MassFractExp"
title = " "
description = "F^2(Q,Rg,D,I0) = I0 sin((D-1)atan(Q*xi)) / ((D-1) Q xi (1+Q^2xi^2)^((D-1)/2))\nwith xi^2 = 2Rg^2/(D(D+1))"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "RG", 	"", 	10.0, 	[-inf, inf], 	"", 	"Rg: radius of gyration (xi^2=2Rg^2/(D(D+1)))"],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	"D: fractal dimensio"],
 [ "I0", 	"", 	0.0, 	[-inf, inf], 	"", 	"I0: forward scattering"],
 [ "Q", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["sasfit_MassFractExp.c" ]

demo = dict(
	RG = 10.0,
	D = 0.0,
	I0 = 0.0,
	Q = 1.0)
