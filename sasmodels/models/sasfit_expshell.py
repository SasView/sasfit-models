r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by expshell

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "expshell"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R1", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "dR", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "eta_c", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "eta_sh", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "x_in", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "x_out", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "alpha", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "eta_sol", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_expshell.c" ]

demo = dict(
	R1 = 10.0,
	dR = 0.0,
	eta_c = 0.0,
	eta_sh = 1.0,
	x_in = 0.0,
	x_out = 0.0,
	alpha = 0.0,
	eta_sol = 0.0,
	P0 = 0.0)
