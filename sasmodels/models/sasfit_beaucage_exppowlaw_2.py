r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by beaucage_exppowlaw_2

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "beaucage_exppowlaw_2"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "G", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "R_I", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "R_Ip1", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "K", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c", "lib/polevl.c", "lib/sas_erf.c",  "sasfit_beaucage_exppowlaw_2.c" ]

demo = dict(
	G = 10.0,
	B = 0.0,
	R_I = 0.0,
	R_Ip1 = 1.0,
	K = 0.0,
	P = 0.0,
	P0 = 0.0)
