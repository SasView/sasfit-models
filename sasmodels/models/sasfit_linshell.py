r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by linshell

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "linshell"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "EMPTY", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "DR", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "eta_core", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "eta_shell", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "x_in_solvent", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "x_out_solvent", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "eta_solvent", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_linshell.c" ]

demo = dict(
	EMPTY = 10.0,
	DR = 0.0,
	eta_core = 0.0,
	eta_shell = 1.0,
	x_in_solvent = 0.0,
	x_out_solvent = 0.0,
	eta_solvent = 0.0,
	P0 = 0.0)
