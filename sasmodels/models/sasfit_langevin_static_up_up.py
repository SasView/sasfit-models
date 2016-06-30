r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by langevin_static_up_up

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "langevin_static_up_up"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "NU", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "B0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "B1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "NU", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "RHO_0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "PHASE_PAR", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "PSI_DEG", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "SQ_AMPL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "SQ_PHASE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "SQ_STATIC", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "FNUC_FMAG", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "MU_KT", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "LAM_CENTER", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "D_LAM_LAM", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "SD", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "P_POL", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "EPSILON_FLIPPER", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "T_PLUS", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "T_MINUS", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "B_STATIC", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "B_STAT_PHI_DEG", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "DELTA_T_BOTTOM", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "DELTA_T_TOP", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ALPHA_PHASE", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "LAMBDA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "MU", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "DAMP_ALPHA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "SQ_TIME", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "TEMPERATURE", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "AD", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "AD_FUNC", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "NONAD_FUNC", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "FNUC", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "FMAG", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "S1", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "S2", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "R", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "R_AV", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "TIME", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "STATIC", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "PSI", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_langevin_static_up_up.c" ]

demo = dict(
	NU = 10.0,
	B0 = 0.0,
	B1 = 0.0,
	NU = 1.0,
	RHO_0 = 0.0,
	PHASE_PAR = 0.0,
	PSI_DEG = 0.0,
	SQ_AMPL = 0.0,
	SQ_PHASE = 0.0,
	SQ_STATIC = 0.0,
	FNUC_FMAG = 0.0,
	MU_KT = 0.0,
	LAM_CENTER = 0.0,
	D_LAM_LAM = 0.0,
	SD = 0.0,
	P_POL = 0.0,
	EPSILON_FLIPPER = 0.0,
	T_PLUS = 0.0,
	T_MINUS = 0.0,
	B_STATIC = 0.0,
	B_STAT_PHI_DEG = 0.0,
	DELTA_T_BOTTOM = 0.0,
	DELTA_T_TOP = 0.0,
	ALPHA_PHASE = 0.0,
	LAMBDA = 0.0,
	MU = 0.0,
	DAMP_ALPHA = 0.0,
	SQ_TIME = 0.0,
	TEMPERATURE = 0.0,
	AD = 0.0,
	AD_FUNC = 0.0,
	NONAD_FUNC = 0.0,
	FNUC = 0.0,
	FMAG = 0.0,
	S1 = 0.0,
	S2 = 0.0,
	R = 0.0,
	R_AV = 0.0,
	TIME = 0.0,
	STATIC = 0.0,
	PSI = 0.0)
