r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by DLCAggregation

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "DLCAggregation"
title = " "
description = "F^2(Q,Rg,D,I0) = I0 (sum\[C_i (Q^2Rg^2)^2i\])^-D/8\nC_1=0, C_1=8/(3D), C_2=2.5, C_3=-1.52, C_4=1.02"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "RG", 	"", 	10.0, 	[-inf, inf], 	"", 	"Rg: radius of gyratio"],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	"D: fractal dimensio"],
 [ "I0", 	"", 	0.0, 	[-inf, inf], 	"", 	"I0: forward scattering"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["sasfit_DLCAggregation.c" ]

demo = dict(
	RG = 10.0,
	D = 0.0,
	I0 = 0.0)
