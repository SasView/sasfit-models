/*                                                     hyperg.c
 *
 *     Confluent hypergeometric function
 *
 *
 *
 * SYNOPSIS:
 *
 * double a, b, x, y, hyperg();
 *
 * y = hyperg( a, b, x );
 *
 *
 *
 * DESCRIPTION:
 *
 * Computes the confluent hypergeometric function
 *
 *                          1           2
 *                       a x    a(a+1) x
 *   F ( a,b;x )  =  1 + ---- + --------- + ...
 *  1 1                  b 1!   b(b+1) 2!
 *
 * Many higher transcendental functions are special cases of
 * this power series.
 *
 * As is evident from the formula, b must not be a negative
 * integer or zero unless a is an integer with 0 >= a > b.
 *
 * The routine attempts both a direct summation of the series
 * and an asymptotic expansion.  In each case error due to
 * roundoff, cancellation, and nonconvergence is estimated.
 * The result with smaller estimated error is returned.
 *
 *
 *
 * ACCURACY:
 *
 * Tested at random points (a, b, x), all three variables
 * ranging from 0 to 30.
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      0,30        30000       1.8e-14     1.1e-15
 *
 * Larger errors can be observed when b is near a negative
 * integer or zero.  Certain combinations of arguments yield
 * serious cancellation error in the power series summation
 * and also are not in the region of near convergence of the
 * asymptotic series.  An error message is printed if the
 * self-estimated relative error is greater than 1.0e-12.
 *
 */

/*                                                     hyperg.c */


/*
 * Cephes Math Library Release 2.8:  June, 2000
 * Copyright 1984, 1987, 1988, 2000 by Stephen L. Moshier
 */

static double sas_hyp2f0(double a, double b, double x, int type);

static double sas_hyp2f0(double a, double b, double x, int type)
{
#if FLOAT_SIZE > 4
    double err;
    const double MACHEP = 1.11022302462515654042E-16; /* 2**-53 */
    const double MAXNUM =  1.79769313486231570815E308;
    double a0, alast, t, tlast, maxt;
    double n, an, bn, u, sum, temp;

    an = a;
    bn = b;
    a0 = 1.0;
    alast = 1.0;
    sum = 0.0;
    n = 1.0;
    t = 1.0;
    tlast = 1.0e9;
    maxt = 0.0;

    while (t > MACHEP) {

	    if (an == 0 || bn == 0) {
	        err = fabs(MACHEP * (n + maxt));
            alast = a0;
            sum += alast;
            return (sum);
        }

	    u = an * (bn * x / n);

	    /* check for blowup */
	    temp = fabs(u);
	    if ((temp > 1.0) && (maxt > (MAXNUM / temp))) {
	        err = MAXNUM;
            //mtherr("hyperg", TLOSS);
            return (sum);
        }

	    a0 *= u;
	    t = fabs(a0);

	    /* terminating condition for asymptotic series:
	    * the series is divergent (if a or b is not a negative integer),
	    * but its leading part can be used as an asymptotic expansion
	    */
	    if (t > tlast) {
	        /* The following "Converging factors" are supposed to improve accuracy,
            * but do not actually seem to accomplish very much. */

            n -= 1.0;
            x = 1.0 / x;
            if (type == 1) {
	            alast *=
	            (0.5 + (0.125 + 0.25 * b - 0.5 * a + 0.25 * x - 0.25 * n) / x);
	        }

            if (type == 2) {
	            alast *= 2.0 / 3.0 - b + 2.0 * a + x - n;
	        }

	        err = MACHEP * (n + maxt)  +  fabs ( a0 );
            sum += alast;
            return( sum );
        }

	    tlast = t;
	    sum += alast;		/* the sum is one term behind */
	    alast = a0;

	    if (n > 200) {
	        n -= 1.0;
            x = 1.0 / x;

            if (type == 1) {
	            alast *=
	            (0.5 + (0.125 + 0.25 * b - 0.5 * a + 0.25 * x - 0.25 * n) / x);
	        }

            if (type == 2) {
	            alast *= 2.0 / 3.0 - b + 2.0 * a + x - n;
	        }

	        err = MACHEP * (n + maxt)  +  fabs ( a0 );
            sum += alast;
            return( sum );
	    }
	    an += 1.0;
	    bn += 1.0;
	    n += 1.0;
	    if (t > maxt)
	        maxt = t;
    }

    /* estimate error due to roundoff and cancellation */
    err = fabs(  MACHEP * (n + maxt)  );
    alast = a0;
    sum += alast;
    return( sum );

#else
    double err;
    const double MACHEPF =5.9604644775390625E-8;
    const double MAXNUMF =3.4028234663852885981170418348451692544e38;
    double a0, alast, t, tlast, maxt;
    double n, an, bn, u, sum, temp;

    an = a;
    bn = b;
    a0 = 1.0;
    alast = 1.0;
    sum = 0.0;
    n = 1.0;
    t = 1.0;
    tlast = 1.0e9;
    maxt = 0.0;

    while( t > MACHEPF ) {

	    if( an == 0 || bn == 0 ) {
	         /* estimate error due to roundoff and cancellation */
            err = fabs(  MACHEPF * (n + maxt)  );

            alast = a0;
            sum += alast;
            return( sum );
	    }

	    u = an * (bn * x / n);

	    /* check for blowup */
	    temp = fabs(u);
	    if( (temp > 1.0 ) && (maxt > (MAXNUMF/temp)) ) {
		    err = MAXNUMF;
            return( sum );
        }
	    a0 *= u;
	    t = fabs(a0);

	    /* terminating condition for asymptotic series */
	    if( t > tlast ) {
	        /* The following "Converging factors" are supposed to improve accuracy,
             * but do not actually seem to accomplish very much. */

            n -= 1.0;
            x = 1.0/x;

            if (type == 1) {
	            alast *= ( 0.5 + (0.125 + 0.25*b - 0.5*a + 0.25*x - 0.25*n)/x );
            }

            if (type == 2) {
	            alast *= 2.0/3.0 - b + 2.0*a + x - n;
            }

            /* estimate error due to roundoff, cancellation, and nonconvergence */
            err = MACHEPF * (n + maxt)  +  fabs( a0 );

            sum += alast;
            return( sum );
	    }

	    tlast = t;
	    sum += alast;	/* the sum is one term behind */
	    alast = a0;

	    if( n > 200 ) {
	         /* The following "Converging factors" are supposed to improve accuracy,
             * but do not actually seem to accomplish very much. */

            n -= 1.0;
            x = 1.0/x;

            if (type == 1) {
	            alast *= ( 0.5 + (0.125 + 0.25*b - 0.5*a + 0.25*x - 0.25*n)/x );
            }

            if (type == 2) {
	            alast *= 2.0/3.0 - b + 2.0*a + x - n;
            }

            /* estimate error due to roundoff, cancellation, and nonconvergence */
            err = MACHEPF * (n + maxt)  +  fabs( a0 );

            sum += alast;
            return( sum );
	    }

	    an += 1.0;
	    bn += 1.0;
	    n += 1.0;
	    if( t > maxt )
		    maxt = t;
    }

    err = fabs(  MACHEPF * (n + maxt)  );
    alast = a0;
    sum += alast;
    return( sum );
#endif
}

/* Power series summation for confluent hypergeometric function                */

