r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by pcs_bilayergaus

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "pcs_bilayergaus"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "SIGMA_CORE", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "B_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA_OUT", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "B_OUT", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "LB", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "L", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "EXVOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "CLB", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_pcs_bilayergaus.c" ]

demo = dict(
	SIGMA_CORE = 10.0,
	B_CORE = 0.0,
	SIGMA_OUT = 0.0,
	B_OUT = 1.0,
	D = 0.0,
	P0 = 0.0,
	LB = 0.0,
	B = 0.0,
	L = 0.0,
	EXVOL = 0.0,
	CLB = 0.0)
