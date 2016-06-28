r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by pcs_homogeneouscyl

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "pcs_homogeneouscyl"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA_R", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY2", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY3", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY4", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY5", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY6", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/polevl.c", "lib/sas_J1.c", "lib/sas_pow.c",  "sasfit_pcs_homogeneouscyl.c" ]

demo = dict(
	R = 10.0,
	SIGMA_R = 0.0,
	DUMMY1 = 0.0,
	DUMMY2 = 1.0,
	DUMMY3 = 0.0,
	DUMMY4 = 0.0,
	DUMMY5 = 0.0,
	ETA_CORE = 0.0,
	DUMMY6 = 0.0,
	ETA_SOL = 0.0,
	Q = 0.0)
