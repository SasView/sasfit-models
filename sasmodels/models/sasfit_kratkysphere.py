r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by kratkysphere

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "kratkysphere"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "DELTA_Q_PERP", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "R0", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "XI", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "SCALE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c", "lib/sas_gamma.c",  "sasfit_kratkysphere.c" ]

demo = dict(
	R = 10.0,
	DELTA_Q_PERP = 0.0,
	ETA = 0.0,
	R0 = 1.0,
	XI = 0.0,
	D = 0.0,
	SCALE = 0.0,
	Q = 0.0,
	P0 = 0.0)
