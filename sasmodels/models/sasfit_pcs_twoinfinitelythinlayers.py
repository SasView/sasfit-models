r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by pcs_twoinfinitelythinlayers

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "pcs_twoinfinitelythinlayers"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "T", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA_T", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "LB", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "L", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "EXVOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "CLB", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_pcs_twoinfinitelythinlayers.c" ]

demo = dict(
	T = 10.0,
	SIGMA_T = 0.0,
	Q = 0.0,
	P0 = 1.0,
	LB = 0.0,
	B = 0.0,
	L = 0.0,
	EXVOL = 0.0,
	CLB = 0.0)
