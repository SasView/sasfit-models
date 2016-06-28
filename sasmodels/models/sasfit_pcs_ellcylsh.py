r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by pcs_ellcylsh

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "pcs_ellcylsh"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R0", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA_R0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "EPSILON", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "T", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY2", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY3", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SHELL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOLV", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "R", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c", "lib/polevl.c", "lib/sas_J1.c",  "sasfit_pcs_ellcylsh.c" ]

demo = dict(
	R0 = 10.0,
	SIGMA_R0 = 0.0,
	EPSILON = 0.0,
	T = 1.0,
	DUMMY1 = 0.0,
	DUMMY2 = 0.0,
	DUMMY3 = 0.0,
	ETA_CORE = 0.0,
	ETA_SHELL = 0.0,
	ETA_SOLV = 0.0,
	R = 0.0,
	Q = 0.0)
