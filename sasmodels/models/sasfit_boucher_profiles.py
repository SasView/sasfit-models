r"""
This file has been automatically gereated by sasfit_convert script
The model calculates an empirical functional form for SAS data characterized
by boucher_profiles

Definition:
-----------
Boucher has described in [24] a simple analytical radial profile for which also
the form factor can be calculated analytically. The radial profile is
parameterized in a way that any potential law in the Porod regime can be obtained.
The radial profile is defined by

.. math::
 	if (fabs(q)>fabs(R))
    {
        return 0;
    }
    else
    {
        return DELTA_ETA*pow((1-sas_pow_2(q/R)),ALPHA/2.-2);
    }

References:
-----------
B Boucher, P Chieux, P Convert, and M Tournarie. Small-angle neutron scattering
determination of medium and long range order in the amorphous metallic alloy
tbcu 3.54. Journal of Physics F: Metal Physics, 13(7):1339, 1983.
"""
from numpy import inf

name = "boucher_profiles"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "ALPHA", 	"", 	2, 	[-inf, inf], 	"", 	""],
 [ "DELTA_ETA", 	"", 	0.1, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_boucher_profiles.c" ]

demo = dict(
	R = 10.0,
	ALPHA = 0.0,
	DELTA_ETA = 0.0
	)
