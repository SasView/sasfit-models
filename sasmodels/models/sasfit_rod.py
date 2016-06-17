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
description = "Formfactor of very long cylindrical block copolymer micelles"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "LENGTH", 	"", 	10.0, 	[-inf, inf], 	"", 	"Vpolym_core: molecular volume of the block in the core \nin nm\^3 if Q in nm\^-1, in A\^3 if Q in A\^-1"],
 [ "ETA", 	"", 	0.0, 	[-inf, inf], 	"", 	"Vpolym_brsh: molecular volume of the block bilding the shell \nin nm\^3 if Q in nm\^-1, in A\^3 if Q in A\^-1"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/Si.c",  "sasfit_rod.c" ]

demo = dict(
	LENGTH = 10.0,
	ETA = 0.0)
