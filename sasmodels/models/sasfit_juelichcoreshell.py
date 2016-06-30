r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by juelichcoreshell

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "juelichcoreshell"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "C", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "MCORE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "MBRUSH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "RHO_CORE", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "RHO_BRUSH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "B_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "B_BRUSH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "NAGG", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "D1_PLUS", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "PART23", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "D2_PLUS", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "D3_PLUS", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "SIGMA1", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "SIGMA2", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "SIGMA3", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "PARTSTAR", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "GAMMA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "LPARABOL", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "F_BRUSH", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "F_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "RHOSOLV", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_juelichcoreshell.c" ]

demo = dict(
	C = 10.0,
	MCORE = 0.0,
	MBRUSH = 0.0,
	RHO_CORE = 1.0,
	RHO_BRUSH = 0.0,
	B_CORE = 0.0,
	B_BRUSH = 0.0,
	NAGG = 0.0,
	D1_PLUS = 0.0,
	PART23 = 0.0,
	D2_PLUS = 0.0,
	D3_PLUS = 0.0,
	SIGMA1 = 0.0,
	SIGMA2 = 0.0,
	SIGMA3 = 0.0,
	PARTSTAR = 0.0,
	GAMMA = 0.0,
	LPARABOL = 0.0,
	F_BRUSH = 0.0,
	F_CORE = 0.0,
	RHOSOLV = 0.0,
	Q = 0.0,
	P0 = 0.0)
