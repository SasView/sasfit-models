r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by RLCAggregation

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "RLCAggregation"
title = " "
description = "F^2(Q,Rg,D,I0) = I0 (sum\[C_i (Q^2Rg^2)^2i\])^-D/8\nC_1=0, C_1=8/(3D), C_2=3.13, C_3=-2.58, C_4=0.95"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "RG", 	"", 	10.0, 	[-inf, inf], 	"", 	"Rg: radius of gyratio"],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	"D: fractal dimensio"],
 [ "I0", 	"", 	0.0, 	[-inf, inf], 	"", 	"I0: forward scattering"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["sasfit_RLCAggregation.c" ]

demo = dict(
	RG = 10.0,
	D = 0.0,
	I0 = 0.0)
