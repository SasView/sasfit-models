r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by ellulv_chain_rw__nagg

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "ellulv_chain_rw__nagg"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "N", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_ellulv_chain_rw__nagg.c" ]

demo = dict(
	N = 10.0,
	P0 = 0.0)
