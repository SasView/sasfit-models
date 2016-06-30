r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by chain_parabolic_psi_mm

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "chain_parabolic_psi_mm"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R_CORE", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "SNAGG", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "VBRUSH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "RG", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "POL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "R_TOT", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "T_SHELL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "SNAGG", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "VBRUSH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ETA_SHELL", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ETA_BRUSH", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ETA_SOLV", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ETA_MAG_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ETA_MAG_SHELL", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "R_AV", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ALPHA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "RG", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "PSIDEG", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "POL", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "PEP", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "YAWPEP", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "SIGYAW", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "P", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "A", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "TAU", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "T_BRUSH_CONST", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "SIGMA_BRUSH_GAUSSIAN", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "L_B", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "TPLUS", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "TMINUS", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "PSI", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "NAGG", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "RW_SAW", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "RADAVG", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "R_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "T_SH", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "I", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "C", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "LAMBDA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "R02", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ALPHA_SH", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ZMAX", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "DTHETA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_chain_parabolic_psi_mm.c" ]

demo = dict(
	R_CORE = 10.0,
	SNAGG = 0.0,
	VBRUSH = 0.0,
	RG = 1.0,
	POL = 0.0,
	P0 = 0.0,
	R_TOT = 0.0,
	T_SHELL = 0.0,
	SNAGG = 0.0,
	VBRUSH = 0.0,
	ETA_CORE = 0.0,
	ETA_SHELL = 0.0,
	ETA_BRUSH = 0.0,
	ETA_SOLV = 0.0,
	ETA_MAG_CORE = 0.0,
	ETA_MAG_SHELL = 0.0,
	R_AV = 0.0,
	ALPHA = 0.0,
	RG = 0.0,
	PSIDEG = 0.0,
	POL = 0.0,
	PEP = 0.0,
	YAWPEP = 0.0,
	SIGYAW = 0.0,
	P = 0.0,
	A = 0.0,
	TAU = 0.0,
	T_BRUSH_CONST = 0.0,
	SIGMA_BRUSH_GAUSSIAN = 0.0,
	L_B = 0.0,
	TPLUS = 0.0,
	TMINUS = 0.0,
	PSI = 0.0,
	NAGG = 0.0,
	RW_SAW = 0.0,
	RADAVG = 0.0,
	R_CORE = 0.0,
	T_SH = 0.0,
	I = 0.0,
	C = 0.0,
	LAMBDA = 0.0,
	R02 = 0.0,
	ALPHA_SH = 0.0,
	ZMAX = 0.0,
	Q = 0.0,
	DTHETA = 0.0)
