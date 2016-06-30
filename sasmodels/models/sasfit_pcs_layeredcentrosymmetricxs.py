r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by pcs_layeredcentrosymmetricxs

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "pcs_layeredcentrosymmetricxs"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "LC", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA_LC", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "LSH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA_LSH", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_C", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "SH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "LL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "LB", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "L", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "EXVOL", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "CLB", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_pcs_layeredcentrosymmetricxs.c" ]

demo = dict(
	LC = 10.0,
	SIGMA_LC = 0.0,
	LSH = 0.0,
	SIGMA_LSH = 1.0,
	ETA_C = 0.0,
	ETA_SH = 0.0,
	ETA_SOL = 0.0,
	SH = 0.0,
	LL = 0.0,
	Q = 0.0,
	P0 = 0.0,
	LB = 0.0,
	B = 0.0,
	L = 0.0,
	EXVOL = 0.0,
	CLB = 0.0)
