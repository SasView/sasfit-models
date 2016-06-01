r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by generalized_guinier_porod_law

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "generalized_guinier_porod_law"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "G2", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "S2", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "RG2", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "S1", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "RG1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "M", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["sasfit_generalized_guinier_porod_law.c" ]

demo = dict(
	G2 = 10.0,
	S2 = 0.0,
	RG2 = 0.0,
	S1 = 1.0,
	RG1 = 0.0,
	M = 0.0)
