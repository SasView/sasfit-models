r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by boucher_sphere

Definition:
-----------

References:
-----------

"""
from numpy import inf
opencl=False
name = "boucher_sphere"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "ALPHA", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "DELTA_ETA", 	"", 	2.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c", "lib/sas_gamma.c",  "sasfit_boucher_sphere.c" ]

demo = dict(
	R = 10.0,
	ALPHA = 1.0,
	DELTA_ETA = 2.0,
	P0 = 1.0)
