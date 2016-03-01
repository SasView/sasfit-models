r"""
This model calculates an empirical functional form for SAS data for
spinodal decomposing systems

Definition
----------

The scattering intensity $I(q)$ is calculated as

.. math::

    I(q) = I_max \frac{(1+\gamma/2) x^2} {\gamma/2 + x^{2+\gamma}}

where $x = q/g_max$ and $q_max$ - The position of the correlation peak at
containing information about the size of the structures, which scatter
$I_max$ - The scattering intensity at peak position I max,
$\gamma = D + 1$ for off-critical mixtures and $\gamma=2D$ for critical concentration
mixtures, whereby $D$ is the dimensionality of the system

For 2D data the scattering intensity is calculated in the same way as 1D,
where the $q$ vector is defined as

.. math::

    q = \sqrt{q_x^2 + q_y^2}


.. figure::

    None

References
----------

H. Furukawa. Dynamics-scaling theory for phase-separating unmixing mixtures: Growth rates of
droplets and scaling properties of autocorrelation functions. Physica A, 123:497, 1984.

"""

from numpy import power
from numpy import sqrt
from numpy import inf
from numpy import concatenate

name = "spinodal"
title = "Spinodal form factor calculation"
description = """
            I(q) = I_max * (1 + gamma/2) *x**2 / (gamma/2 +x**(2+gamma)
            I_max =  The scattering intensity at peak position [1/cm]
            q_max = The position of the correlation peak [1/A]
            ganmna = The decomposition epxonent
            background = Incoherent background [1/cm]
        """
category = "shape-independent"

# pylint: disable=bad-whitespace, line-too-long
#            ["name", "units", default, [lower, upper], "type", "description"],
parameters = [["I_max",  "",         1.0, [-inf, inf], "", "Scattering intensity at peak position"],
              ["qmax",     "1/Ang",    0.04,[-inf, inf],    "", "Croleation peak position"],
              ["gamma",       "",         2.0, [-inf, inf],    "", "Decomposition exponent"],
             ]
# pylint: enable=bad-whitespace, line-too-long


def Iq(q,
       I_max=1.0,
       q_max=0.1,
       gamma=1.0,
       ):

    """
    :param q:               Input q-value (float or [float, float])
    :param I_max:           Scattering intensity at peak position
    :param q_max:           Croleation peak position
    :param gamma:           Decomposition exponent
    :return:                Calculated intensity
    """
    x = q/q_max
    intensity = I_max*(1+0.5*gamma)*x**2/(0.5*gamma+x**(2+gamma))

    return intensity

Iq.vectorized = True  # Iq accepts an array of q values

def Iqxy(qx, qy, *args):
    """
    :param qx:   Input q_x-value
    :param qy:   Input q_y-value
    :param args: Remaining arguments
    :return:     2D-Intensity
    """

    return Iq(sqrt(qx**2 + qy**2), *args)

Iqxy.vectorized = True  # Iqxy accepts an array of qx, qy values

demo = dict(scale=1, background=0.0,
            I_max=1.0,
            q_max=0.1,
            ganna=2.0)

#TODO: This is only used to see if model works - will have to be removed
oldname = "TwoPowerLawModel"
oldpars = dict(coefficent_1='I_max',
               crossover='q_max',
               power_1='gamma',
               power_2='gamma',
               background='background')
tests = [
    # Accuracy tests based on content in test/utest_extra_models.py
    [{'I_max':    1.0,
      'q_max':    0.1,
      'gamma':    2.0,
      }, 0.001, 1000],
]
