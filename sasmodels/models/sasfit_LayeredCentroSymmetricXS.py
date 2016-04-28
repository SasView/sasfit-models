r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by LayeredCentroSymmetricXS

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "LayeredCentroSymmetricXS"
title = " "
description = "P(Q,...) = "
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "t_out", 	"", 	10.0, 	[-inf, inf], 	"", 	"L_out: "],
 [ "t_core", 	"", 	0.0, 	[-inf, inf], 	"", 	"L_core:"],
 [ "b_out", 	"", 	0.0, 	[-inf, inf], 	"", 	"b_out"],
 [ "b_core", 	"", 	1.0, 	[-inf, inf], 	"", 	"b_core:"],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	"D: diameter of planar object"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["lib/polevl.c","lib/sas_J1.c","sasfit_LayeredCentroSymmetricXS.c" ]

demo = dict(
	t_out = 10.0,
	t_core = 0.0,
	b_out = 0.0,
	b_core = 1.0,
	D = 0.0)
