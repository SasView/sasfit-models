r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by sphere_with_3_shells

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "sphere_with_3_shells"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R_CORE", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "T_SH1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "T_SH2", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "T_SH3", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SH1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SH2", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SH3", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_sphere_with_3_shells.c" ]

demo = dict(
	R_CORE = 10.0,
	T_SH1 = 0.0,
	T_SH2 = 0.0,
	T_SH3 = 1.0,
	ETA_CORE = 0.0,
	ETA_SH1 = 0.0,
	ETA_SH2 = 0.0,
	ETA_SH3 = 0.0,
	ETA_SOL = 0.0)
