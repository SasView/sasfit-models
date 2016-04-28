r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by BiLayerGauss

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "BiLayerGauss"
title = " "
description = "P(Q,...) = "
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "sigma_out", 	"", 	10.0, 	[-inf, inf], 	"", 	"sigma_out: "],
 [ "b_out", 	"", 	0.0, 	[-inf, inf], 	"", 	"b_out:"],
 [ "sigma_core", 	"", 	0.0, 	[-inf, inf], 	"", 	"sigma_core:"],
 [ "b_core", 	"", 	1.0, 	[-inf, inf], 	"", 	"b_core:"],
 [ "t", 	"", 	0.0, 	[-inf, inf], 	"", 	"t: distance between bilayer centres"],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	"D: diameter of planar object"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["lib/polevl.c","lib/sas_J1.c", "sasfit_BiLayerGauss.c" ]

demo = dict(
	sigma_out = 10.0,
	b_out = 0.0,
	sigma_core = 0.0,
	b_core = 1.0,
	t = 0.0,
	D = 0.0)
