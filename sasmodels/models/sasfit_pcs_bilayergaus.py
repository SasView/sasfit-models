r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by pcs_bilayergaus

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "pcs_bilayergaus"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "SIGMA_CORE", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "B_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA_OUT", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "B_OUT", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_pcs_bilayergaus.c" ]

demo = dict(
	SIGMA_CORE = 10.0,
	B_CORE = 0.0,
	SIGMA_OUT = 0.0,
	B_OUT = 1.0,
	D = 0.0)
