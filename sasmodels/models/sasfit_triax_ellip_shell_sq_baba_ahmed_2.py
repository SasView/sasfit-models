r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by triax_ellip_shell_sq_baba_ahmed_2

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "triax_ellip_shell_sq_baba_ahmed_2"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "A", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "DELTA_B", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DELTA_C", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "T", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_C", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SH_DRY", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "PHI", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "V_POL_AP", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ALPHA", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Z_P", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "EPSILON_R", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "MB", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ZB", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "TEMP", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_triax_ellip_shell_sq_baba_ahmed_2.c" ]

demo = dict(
	A = 10.0,
	DELTA_B = 0.0,
	DELTA_C = 0.0,
	T = 1.0,
	ETA_C = 0.0,
	ETA_SH_DRY = 0.0,
	ETA_SOL = 0.0,
	PHI = 0.0,
	V_POL_AP = 0.0,
	ALPHA = 0.0,
	Z_P = 0.0,
	EPSILON_R = 0.0,
	MB = 0.0,
	ZB = 0.0,
	TEMP = 0.0)
