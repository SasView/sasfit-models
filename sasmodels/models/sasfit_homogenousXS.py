r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by homogenousXS

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "homogenousXS"
title = " "
description = "P(Q,L,eta) = "
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "L", 	"", 	10.0, 	[-inf, inf], 	"", 	"L: layer thickness"],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	"D: diameter of planar object"],
 [ "eta", 	"", 	0.0, 	[-inf, inf], 	"", 	"eta: scattering contrast"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["lib/polevl.c", "lib/sas_J1.c","sasfit_homogenousXS.c" ]

demo = dict(
	L = 10.0,
	D = 0.0,
	eta = 0.0)
