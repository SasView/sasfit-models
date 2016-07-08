r"""
This file has been automatically gereated by conversion script
The model calculates an empirical functional form for SAS data characterized
by polynomial5

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "polynomial5"
title = " "
description = "            a + b * x + c * math.pow(x,2) + d * math.pow(x,3) \n"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "A", 	"", 	0.1, 	[-inf, inf], 	"", 	" "],
 [ "C", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "B", 	"", 	10.0, 	[-inf, inf], 	"", 	" "],
 [ "E", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "F", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

def Iq(x , A, C, B, E, D, F):
        """ 
        Evaluate the model
        :param x: input x
        :return: function value
        """
        ## DEFINE YOUR FUNCTION HERE.
        ## YOU CAN ERASE EVERYTHING BELLOW FOR YOUR OWN FUNCTION
        #Redefine parameters as local parameters, or skip and use long name
        a  = A
        b  = B
        c  = C
        d  = D
        e  = E
        f  = F
 
        ##THIS OUR FUNCTION TEMPLATE
        poly = a + b * x + c * pow(x,2) + d * pow(x,3) \
                + e * pow(x,4) + f * pow(x,5)              ## <-----                
        
        #(Just note: In Python, indentation defines the belongings 
        # of 'if', 'for', and so on..)
        #(lim x --> 0) 
        if x == 0:                          ## <-----   
            result = a                      ## <-----   
        else:                               ## <-----   
            result = poly                   ## <-----    

        return result       ## MODIFY ONLY RESULT. DON'T DELETE RETURN!!!!
