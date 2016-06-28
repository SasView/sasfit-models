r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by i_q__for_spin_misalignment

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "i_q__for_spin_misalignment"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "K", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "HI", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "L_H", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "R", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "lR", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c", "lib/s", "lib/p", "lib/h", "lib/_", "lib/j", "lib/1", "lib/c", "lib/.",  "sasfit_i_q__for_spin_misalignment.c" ]

demo = dict(
	K = 10.0,
	HI = 0.0,
	L_H = 0.0,
	R = 1.0,
	Q = 0.0,
	lR = 0.0)
