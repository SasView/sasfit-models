r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by ellcylsh_sd_worm_kholodenko

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "ellcylsh_sd_worm_kholodenko"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R0", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA_R0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "EPSILON", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "T", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "LLB", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "LL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "LEXV", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SHELL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOLV", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "R", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "LB", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "L", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "EXVOL", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "CLB", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_ellcylsh_sd_worm_kholodenko.c" ]

demo = dict(
	R0 = 10.0,
	SIGMA_R0 = 0.0,
	EPSILON = 0.0,
	T = 1.0,
	LLB = 0.0,
	LL = 0.0,
	LEXV = 0.0,
	ETA_CORE = 0.0,
	ETA_SHELL = 0.0,
	ETA_SOLV = 0.0,
	R = 0.0,
	Q = 0.0,
	P0 = 0.0,
	LB = 0.0,
	B = 0.0,
	L = 0.0,
	EXVOL = 0.0,
	CLB = 0.0)
