r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by Rod

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "Rod"
title = " "
description = "Formfactor of very long cylindrical block copolymer micelles"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "L", 	"", 	10.0, 	[-inf, inf], 	"", 	"Vpolym_core: molecular volume of the block in the core \nin nm\^3 if Q in nm\^-1, in A\^3 if Q in A\^-1"],
 [ "eta", 	"", 	1.0, 	[-inf, inf], 	"", 	"eta_brsh: (bulk) scattering length density of block unit in shell"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["lib/Si.c","sasfit_Rod.c" ]

demo = dict(
	L = 10.0,
	eta = 1.0)
