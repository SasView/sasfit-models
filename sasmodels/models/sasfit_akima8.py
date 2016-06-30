r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by akima8

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "akima8"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "XMIN", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "XMAX", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Y1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Y2", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "Y3", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Y4", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Y5", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Y6", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Y7", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Y8", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_akima8.c" ]

demo = dict(
	XMIN = 10.0,
	XMAX = 0.0,
	Y1 = 0.0,
	Y2 = 1.0,
	Y3 = 0.0,
	Y4 = 0.0,
	Y5 = 0.0,
	Y6 = 0.0,
	Y7 = 0.0,
	Y8 = 0.0,
	P0 = 0.0)
