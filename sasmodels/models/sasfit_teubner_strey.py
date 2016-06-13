r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by teubner_strey

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "teubner_strey"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "xi", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "d", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "eta", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_teubner_strey.c" ]

demo = dict(
	xi = 10.0,
	d = 0.0,
	eta = 0.0)
