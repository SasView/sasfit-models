r"""
This file has been automatically gereated by sasfit_plugin_convert
The model calculates an empirical functional form for SAS data characterized
by coreshellmicrogel

Definition:
some scattering from spherical particles with a fuzzy interface function
 Default (Size) Distribution: \ref delta
-----------

References:
-----------

"""
from numpy import inf

name = "coreshellmicrogel"
title = " "
description = "some scattering from spherical particles with a fuzzy interface function"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "W_core", 	"", 	10.0, 	[-inf, inf], 	"", 	"radius of center parts of core  with homogeneous scattering length density"],
 [ "sigma_core", 	"", 	0.0, 	[-inf, inf], 	"", 	"interface half width of the core"],
 [ "W_sh", 	"", 	0.0, 	[-inf, inf], 	"", 	"width of center parts of shell  with homogeneous scattering length density"],
 [ "sigma_sh,in", 	"", 	1.0, 	[-inf, inf], 	"", 	"half width of the inner interface of shell"],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	"distance between interface of core and in interface of shell"],
 [ "sigma_out", 	"", 	0.0, 	[-inf, inf], 	"", 	"half width of the outer surface profile"],
 [ "eta_core", 	"", 	0.0, 	[-inf, inf], 	"", 	"scattering length density of homogeneous core part"],
 [ "eta_shell", 	"", 	0.0, 	[-inf, inf], 	"", 	"scattering length density of homogeneous shell part"],
 [ "eta_sol", 	"", 	0.0, 	[-inf, inf], 	"", 	"scattering length density of solvent"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_coreshellmicrogel_plugin.c" ]

demo = dict(
	W_core = 10.0,
	sigma_core = 0.0,
	W_sh = 0.0,
	sigma_sh,in = 1.0,
	D = 0.0,
	sigma_out = 0.0,
	eta_core = 0.0,
	eta_shell = 0.0,
	eta_sol = 0.0,
)
