r"""
This model provides the form factor, $P(q)$, for a multi-shell sphere where
the scattering length density (SLD) of the each shell is described by an
exponential, linear, or constant function. The form factor is normalized by
the volume of the sphere where the SLD is not identical to the SLD of the
solvent. We currently provide up to 9 shells with this model.

NB: *radius* represents the core radius $r_0$ and
*thickness[k]* represents the thickness of the shell, $r_{k+1} - r_k$.

Definition
----------

The 1D scattering intensity is calculated in the following way

.. math::

    P(q) &= [f]^2 / V_\text{particle}

where

.. math::

    f    &= f_\text{core}
            + \left(\sum_{\text{shell}=1}^N f_\text{shell}\right)
            + f_\text{solvent}


The shells are spherically symmetric with particle density $\rho(r)$ and
constant SLD within the core and solvent, so

.. math::

    f_\text{core}
        &= 4\pi\int_0^{r_\text{core}} \rho_\text{core}
            \frac{\sin(qr)}{qr}\, r^2\,\mathrm{d}r
        &= 3\rho_\text{core} V(r_\text{core})
            \frac{j_1(qr_\text{core})}{qr_\text{core}} \\
    f_\text{shell}
        &= 4\pi\int_{r_{\text{shell}-1}}^{r_\text{shell}}
            \rho_\text{shell}(r)\frac{\sin(qr)}{qr}\,r^2\,\mathrm{d}r \\
    f_\text{solvent}
        &= 4\pi\int_{r_N}^\infty
            \rho_\text{solvent}\frac{\sin(qr)}{qr}\,r^2\,\mathrm{d}r
        &= -3\rho_\text{solvent}V(r_N)\frac{j_1(q r_N)}{q r_N}

where the spherical bessel function $j_1$ is

.. math::

    j_1(x) = \frac{\sin(x)}{x^2} - \frac{\cos(x)}{x}

and the volume is $V(r) = \frac{4\pi}{3}r^3$. The volume of the particle
is determined by the radius of the outer shell, so $V_\text{particle} = V(r_N)$.

Now lets consider the SLD of a shell defined by

.. math::

    \rho_\text{shell}(r) = \begin{cases}
        B\exp\left(A(r-r_{\text{shell}-1})/\Delta t_\text{shell}\right)
            + C & \mbox{for } A \neq 0 \\
        \rho_\text{in} = \text{constant} & \mbox{for } A = 0
    \end{cases}

An example of a possible SLD profile is shown below where
$\rho_\text{in}$ and $\Delta t_\text{shell}$ stand for the
SLD of the inner side of the $k^\text{th}$ shell and the
thickness of the $k^\text{th}$ shell in the equation above, respectively.

For $A \gt 0$,

.. math::

    f_\text{shell} &= 4 \pi \int_{r_{\text{shell}-1}}^{r_\text{shell}}
        \left[ B\exp
            \left(A (r - r_{\text{shell}-1}) / \Delta t_\text{shell} \right) + C
        \right] \frac{\sin(qr)}{qr}\,r^2\,\mathrm{d}r \\
    &= 3BV(r_\text{shell}) e^A h(\alpha_\text{out},\beta_\text{out})
        - 3BV(r_{\text{shell}-1}) h(\alpha_\text{in},\beta_\text{in})
        + 3CV(r_{\text{shell}}) \frac{j_1(\beta_\text{out})}{\beta_\text{out}}
        - 3CV(r_{\text{shell}-1}) \frac{j_1(\beta_\text{in})}{\beta_\text{in}}

for

.. math::
    :nowrap:

    \begin{align*}
    B&=\frac{\rho_\text{out} - \rho_\text{in}}{e^A-1}
         &C &= \frac{\rho_\text{in}e^A - \rho_\text{out}}{e^A-1} \\
    \alpha_\text{in} &= A\frac{r_{\text{shell}-1}}{\Delta t_\text{shell}}
         &\alpha_\text{out} &= A\frac{r_\text{shell}}{\Delta t_\text{shell}} \\
    \beta_\text{in} &= qr_{\text{shell}-1}
        &\beta_\text{out} &= qr_\text{shell}
    \end{align*}

where $h$ is

 .. math::

    h(x,y) = \frac{x \sin(y) - y\cos(y)}{(x^2+y^2)y}
               - \frac{(x^2-y^2)\sin(y) - 2xy\cos(y)}{(x^2+y^2)^2y}


For $A \sim 0$, e.g., $A = -0.0001$, this function converges to that of the
linear SLD profile with
$\rho_\text{shell}(r) \approx A(r-r_{\text{shell}-1})/\Delta t_\text{shell})+B$,
so this case is equivalent to

.. math::


    f_\text{shell}
    &=
      3 V(r_\text{shell}) \frac{\Delta\rho_\text{shell}}{\Delta t_\text{shell}}
        \left[\frac{
                2 \cos(qr_\text{out})
                    + qr_\text{out} \sin(qr_\text{out})
            }{
                (qr_\text{out})^4
            }\right] \\
     &{}
      -3 V(r_\text{shell}) \frac{\Delta\rho_\text{shell}}{\Delta t_\text{shell}}
        \left[\frac{
                    2\cos(qr_\text{in})
                +qr_\text{in}\sin(qr_\text{in})
            }{
                (qr_\text{in})^4
            }\right] \\
    &{}
      +3\rho_\text{out}V(r_\text{shell}) \frac{j_1(qr_\text{out})}{qr_\text{out}}
      -3\rho_\text{in}V(r_{\text{shell}-1}) \frac{j_1(qr_\text{in})}{qr_\text{in}}

For $A = 0$, the exponential function has no dependence on the radius (so that
$\rho_\text{out}$ is ignored this case) and becomes flat. We set the constant
to $\rho_\text{in}$ for convenience, and thus the form factor contributed by
the shells is

.. math::

    f_\text{shell} =
        3\rho_\text{in}V(r_\text{shell})
           \frac{j_1(qr_\text{out})}{qr_\text{out}}
        - 3\rho_\text{in}V(r_{\text{shell}-1})
            \frac{j_1(qr_\text{in})}{qr_\text{in}}

.. figure:: img/onion_geometry.png

    Example of an onion model profile.

The 2D scattering intensity is the same as $P(q)$ above, regardless of the
orientation of the $q$ vector which is defined as

.. math::

    q = \sqrt{q_x^2 + q_y^2}

NB: The outer most radius is used as the effective radius for $S(q)$
when $P(q) S(q)$ is applied.

References
----------

L A Feigin and D I Svergun,
*Structure Analysis by Small-Angle X-Ray and Neutron Scattering*,
Plenum Press, New York, 1987.
"""

#
# Give a polynomial $\rho(r) = Ar^3 + Br^2 + Cr + D$ for density,
#
# .. math::
#
#    f = 4 \pi \int_a^b \rho(r) \sin(qr)/(qr) \mathrm{d}r  = h(b) - h(a)
#
# where
#
# .. math::
#
#    h(r) = \frac{4 \pi}{q^6}\left[
#        (q^3(4Ar^3 + 3Br^2 + 2Cr + D) - q(24Ar + 6B)) \sin(qr)
#      - (q^4(Ar^4 + Br^3 + Cr^2 + Dr) - q^2(12Ar^2 + 6Br + 2C) + 24A) \cos(qr)
#    \right]
#
# Use the monotonic spline to get the polynomial coefficients for each shell.
#
# Order 0
#
# .. math::
#
#    h(r) = \frac{4 \pi}{q^3} \left[
#       - \cos(qr) (Ar) q
#       + \sin(qr) (A)
#    \right]
#
# Order 1
#
# .. math::
#
#   h(r) = \frac{4 \pi}{q^4} \left[
#       - \cos(qr) ( Ar^2 + Br) q^2
#       + \sin(qr) ( Ar   + B ) q
#       + \cos(qr) (2A        )
#   \right]
#
# Order 2
#
# .. math::
#  h(r) = \frac{4 \pi}{q^5} \left[
#        - \cos(qr) ( Ar^3 +  Br^2 + Cr) q^3
#        + \sin(qr) (3Ar^2 + 2Br   + C ) q^2
#        + \cos(qr) (6Ar   + 2B        ) q
#        - \sin(qr) (6A                )
#
# Order 3
#
#    h(r) = \frac{4 \pi}{q^6}\left[
#      - \cos(qr) (  Ar^4 +  Br^3 +  Cr^2 + Dr) q^4
#      + \sin(qr) ( 4Ar^3 + 3Br^2 + 2Cr   + D ) q^3
#      + \cos(qr) (12Ar^2 + 6Br   + 2C        ) q^2
#      - \sin(qr) (24Ar   + 6B                ) q
#      - \cos(qr) (24A                        )
#    \right]
#
# Order p
#
#    h(r) = \frac{4 \pi}{q^{2}}
#      \sum_{k=0}^p -\frac{d^k\cos(qr)}{dr^k} \frac{d^k r\rho(r)}{dr^k} (qr)^{-k}
#
# Given the equation
#
#    f = sum_(k=0)^(n-1) h_k(r_(k+1)) - h_k(r_k)
#
# we can rearrange the terms so that
#
#    f = sum_0^(n-1) h_k(r_(k+1)) - sum_0^(n-1) h_k(r_k)
#      = sum_1^n h_(k-1)(r_k) - sum_0^(n-1) h_k(r_k)
#      = h_(n-1)(r_n) - h_0(r_0) + sum_1^(n-1) [h_(k-1)(r_k) - h_k(r_k)]
#      = h_(n-1)(r_n) - h_0(r_0) - sum_1^(n-1) h_(Delta k)(r_k)
#
# where
#
#    h_(Delta k)(r) = h(Delta rho_k, r)
#
# for
#
#    Delta rho_k = (A_k-A_(k-1)) r^p + (B_k-B_(k-1)) r^(p-1) + ...
#
# Using l'H\^opital's Rule 6 times on the order 3 polynomial,
#
#   lim_(q->0) h(r) = (140D r^3 + 180C r^4 + 144B r^5 + 120A r^6)/720
#


from __future__ import division

import numpy as np
from numpy import inf, nan
from math import fabs, exp, expm1

name = "onion"
title = "Onion shell model with constant, linear or exponential density"

description = """\
Form factor of mutishells normalized by the volume. Here each shell is
described by an exponential function;

	I) For A_shell != 0,
		f(r) = B*exp(A_shell*(r-r_in)/thick_shell)+C
	where
		B=(sld_out-sld_in)/(exp(A_shell)-1)
		C=sld_in-B.
	Note that in the above case, the function becomes a linear function
	as A_shell --> 0+ or 0-.

	II) For the exact point of A_shell == 0,
		f(r) = sld_in ,i.e., it crosses over flat function
	Note that the 'sld_out' becaomes NULL in this case.

	background:background,
	rad_core0: radius of sphere(core)
	thick_shell#:the thickness of the shell#
	sld_core0: the SLD of the sphere
	sld_solv: the SLD of the solvent
	sld_shell: the SLD of the shell#
	A_shell#: the coefficient in the exponential function
"""

category = "shape:sphere"

# TODO: n is a volume parameter that is not polydisperse

#             ["name", "units", default, [lower, upper], "type","description"],
parameters = [["core_sld", "1e-6/Ang^2", 1.0, [-inf, inf], "",
               "Core scattering length density"],
              ["core_radius", "Ang", 200., [0, inf], "volume",
               "Radius of the core"],
              ["solvent_sld", "1e-6/Ang^2", 6.4, [-inf, inf], "",
               "Solvent scattering length density"],
              ["n", "", 1, [0, 10], "volume",
               "number of shells"],
              ["in_sld[n]", "1e-6/Ang^2", 1.7, [-inf, inf], "",
               "scattering length density at the inner radius of shell k"],
              ["out_sld[n]", "1e-6/Ang^2", 2.0, [-inf, inf], "",
               "scattering length density at the outer radius of shell k"],
              ["thickness[n]", "Ang", 40., [0, inf], "volume",
               "Thickness of shell k"],
              ["A[n]", "", 1.0, [-inf, inf], "",
               "Decay rate of shell k"],
              ]

#source = ["lib/sph_j1c.c", "onion.c"]

def Iq(q, *args, **kw):
    return q

def Iqxy(qx, *args, **kw):
    return qx


def shape(core_sld, core_radius, solvent_sld, n, in_sld, out_sld, thickness, A):
    """
    SLD profile
    """

    total_radius = 1.25*(sum(thickness[:n]) + core_radius + 1)
    dr = total_radius/400  # 400 points for a smooth plot

    r = []
    beta = []

    # add in the core
    r.append(0)
    beta.append(core_sld)
    r.append(core_radius)
    beta.append(core_sld)

    # add in the shells
    for k in range(n):
        # Left side of each shells
        r0 = r[-1]
        r.append(r0)
        beta.append(in_sld[k])

        if fabs(A[k]) < 1.0e-16:
            # flat shell
            r.append(r0 + thickness[k])
            beta.append(out_sld[k])
        else:
            # exponential shell
            # num_steps must be at least 1, so use floor()+1 rather than ceil
            # to protect against a thickness0.
            num_steps = np.floor(thickness[k]/dr) + 1
            slope = (out_sld[k] - in_sld[k])/expm1(A[k])
            const = (in_sld[k] - slope)
            for rk in np.linspace(0, thickness[k], num_steps+1):
                r.append(r0+rk)
                beta.append(slope*exp(A[k]*rk/thickness[k]) + const)

    # add in the solvent
    r.append(r[-1])
    beta.append(solvent_sld)
    r.append(total_radius)
    beta.append(solvent_sld)

    return np.asarray(r), np.asarray(beta)

def ER(core_radius, n, thickness):
    return np.sum(thickness[:n[0]], axis=0) + core_radius

def VR(core_radius, n, thickness):
    return 1.0, 1.0

demo = {
    "solvent_sld": 2.2,
    "core_sld": 1.0,
    "core_radius": 100,
    "n": 4,
    "in_sld": [0.5, 1.5, 0.9, 2.0],
    "out_sld": [nan, 0.9, 1.2, 1.6],
    "thickness": [50, 75, 150, 75],
    "A": [0, -1, 1e-4, 1],
    # Could also specify them individually as
    # "A[1]": 0, "A[2]": -1, "A[3]": 1e-4, "A[4]": 1,
    }

