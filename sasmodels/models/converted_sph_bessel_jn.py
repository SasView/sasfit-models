r"""
This file has been automatically gereated by conversion script
The model calculates an empirical functional form for SAS data characterized
by sph_bessel_jn

Definition:
-----------

References:
-----------

"""
from numpy import inf
import scipy.special            ##CHANGE THIS LINE WITH CAUTION!!!
name = "sph_bessel_jn"
title = " "
description = "            Spherical Bessel Function: C*sph_jn(n, Ax+B)+D"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "A", 	"", 	1.0, 	[-inf, inf], 	"", 	" "],
 [ "C", 	"", 	1.0, 	[-inf, inf], 	"", 	" "],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "n", 	"", 	1.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

def Iq(x , A, C, B, D, n):
        """ 
        Evaluate the model
        
        :param x: input x
        
        :return: function value
        
        """
        ## ADD YOUR FUNCTION HERE.
        ## REUSE THE PARAMETERS DEFINED PREVIOUSLY TO WRITE YOUR FUNCTION.
        
        ## IN THIS EXAMPLE THE FUNTION IS:
        ## C*sph_jn(Ax+B)+D
         
        ## NOTE: pow IS A FUNCTION IMPORTED FROM PYTHON MATH LIBRARY
        ## FOR MORE INFORMATION CHECK http://docs.python.org/library/html      
        ## OTHER FUNCTIONS ARE ALSO 
        ###  AVAILABLE http://www.scipy.org/Numpy_Functions_by_Category
        ## numpy FUNCTIONS ARE FOR EXPERT USER
        
        ## YOU CAN ERASE EVERYTHING BELLOW FOR YOUR OWN FUNCTION
        #Redefine parameters as local parameters
        a  = A
        b  = B
        c  = C
        d  = D
        # Take integer value only
        n  = n

        ##THIS OUR FUNCTION TEMPLATE
        #Remove a singular point (lim poly --> 0) for sin(poly)/poly
        #(Just note: In Python, indentation defines the belongings of 'if', 'for', and so on..)
        input = a * x + b
        # sph_out and _ are in array types from scipy upto n'th order
        # where _ is not used for this function.
        sph_out, _ = scipy.special.sph_jn(n, input)
        # Take only n'th value
        result = c * sph_out[n] + d      ## <-----                

        return result ## MODIFY ONLY RESULT. DON'T DELETE RETURN!!!!
