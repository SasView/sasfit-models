r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by rod

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "rod"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "LENGTH", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "ETA", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/Si.c",  "sasfit_rod.c" ]

demo = dict(
	LENGTH = 10.0,
	ETA = 0.0)
