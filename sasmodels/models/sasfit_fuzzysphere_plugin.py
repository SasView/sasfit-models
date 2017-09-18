r"""
This file has been automatically gereated by sasfit_plugin_convert
The model calculates an empirical functional form for SAS data characterized
by fuzzysphere

Definition:
some scattering from spherical particles with a fuzzy interface function
 Default (Size) Distribution: \ref delta
-----------

References:
-----------

"""
from numpy import inf

name = "fuzzysphere"
title = " "
description = "some scattering from spherical particles with a fuzzy interface function"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R", 	"", 	-10, 	[-inf, inf], 	"volume", 	"radius of the fuzzy sphere"],
 [ "sigma", 	"", 	0.1, 	[-inf, inf], 	"", 	"thickness of the fuzzy shell"],
 [ "eta_sph", 	"", 	0.1, 	[-inf, inf], 	"", 	"scattering length density of sphere"],
 [ "eta_sol", 	"", 	1.0, 	[-inf, inf], 	"", 	"scattering length density of the solvent"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_fuzzysphere_plugin.c" ]

# demo = dict(
# 	R = 10.0,
# 	sigma = 0.0,
# 	eta_sph = 0.0,
# 	eta_sol = 1.0,
# )
