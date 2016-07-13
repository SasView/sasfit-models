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

double sas_hyp2f0(double a, double b, double x, int type, double *err);
double sas_hy1f1p(double a, double b, double x, double *err);
double sas_hy1f1a(double a, double b, double x, double *err);
double sas_hyperg(double a, double b, double x);

double sas_hyp2f0(double a, double b, double x, int type, double *err)
{
#if FLOAT_SIZE > 4
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
    *err = 1.0;

    while (t > MACHEP) {

	    if (an == 0 || bn == 0) {
	        *err = fabs(MACHEP * (n + maxt));
            alast = a0;
            sum += alast;
            return (sum);
        }

	    u = an * (bn * x / n);

	    /* check for blowup */
	    temp = fabs(u);
	    if ((temp > 1.0) && (maxt > (MAXNUM / temp))) {
	        *err = MAXNUM;
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

	        *err = MACHEP * (n + maxt)  +  fabs ( a0 );
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

	        *err = MACHEP * (n + maxt)  +  fabs ( a0 );
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
    *err = fabs(  MACHEP * (n + maxt)  );
    alast = a0;
    sum += alast;
    return( sum );

#else
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
    *err = 1.0;

    while( t > MACHEPF ) {

	    if( an == 0 || bn == 0 ) {
	         /* estimate error due to roundoff and cancellation */
            *err = fabs(  MACHEPF * (n + maxt)  );

            alast = a0;
            sum += alast;
            return( sum );
	    }

	    u = an * (bn * x / n);

	    /* check for blowup */
	    temp = fabs(u);
	    if( (temp > 1.0 ) && (maxt > (MAXNUMF/temp)) ) {
		    *err = MAXNUMF;
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
            *err = MACHEPF * (n + maxt)  +  fabs( a0 );

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
            *err = MACHEPF * (n + maxt)  +  fabs( a0 );

            sum += alast;
            return( sum );
	    }

	    an += 1.0;
	    bn += 1.0;
	    n += 1.0;
	    if( t > maxt )
		    maxt = t;
    }

    *err = fabs(  MACHEPF * (n + maxt)  );
    alast = a0;
    sum += alast;
    return( sum );
#endif
}

/* Power series summation for confluent hypergeometric function                */


double sas_hy1f1p(double a, double b, double x, double *err)
{
#if FLOAT_SIZE > 4
    const double MACHEP = 1.11022302462515654042E-16; /* 2**-53 */
    const double MAXNUM =  1.79769313486231570815E308;

    double n, a0, sum, t, u, temp, maxn;
    double an, bn, maxt;
    double y, c, sumc;


    /* set up for power series summation */
    an = a;
    bn = b;
    a0 = 1.0;
    sum = 1.0;
    c = 0.0;
    n = 1.0;
    t = 1.0;
    maxt = 0.0;
    *err = 1.0;

    maxn = 200.0 + 2 * fabs(a) + 2 * fabs(b);

    while (t > MACHEP) {
	    if (bn == 0) {		/* check bn first since if both   */
	        return (MAXNUM);	/* an and bn are zero it is     */
	    }
	    if (an == 0)		/* a singularity            */
	        return (sum);
	    if (n > maxn) {
	        /* too many terms; take the last one as error estimate */
	        c = fabs(c) + fabs(t) * 50.0;
	        if (sum != 0.0) {
	            *err = fabs(c / sum);
            }
            else {
	            *err = fabs(c);
            }

            if (*err != *err) {
	            /* nan */
	         *err = 1.0;
            }

            return (sum);
	    }
	    u = x * (an / (bn * n));

	    /* check for blowup */
	    temp = fabs(u);
	    if ((temp > 1.0) && (maxt > (MAXNUM / temp))) {
	        *err = 1.0;		/* blowup: estimate 100% error */
	        return sum;
	    }

	    a0 *= u;

	    y = a0 - c;
	    sumc = sum + y;
	    c = (sumc - sum) - y;
	    sum = sumc;

	    t = fabs(a0);

	    an += 1.0;
	    bn += 1.0;
	    n += 1.0;
    }

    /* estimate error due to roundoff and cancellation */
    if (sum != 0.0) {
	    *err = fabs(c / sum);
    }
    else {
	    *err = fabs(c);
    }

    if (*err != *err) {
	    /* nan */
	    *err = 1.0;
    }


    return (sum);
#else
    const double  MACHEPF =5.9604644775390625E-8;
    const double MAXNUMF = 3.4028234663852885981170418348451692544e38;
    double n, a0, sum, t, u, temp;
    double an, bn, maxt, pcanc;

    /* set up for power series summation */
    an = a;
    bn = b;
    a0 = 1.0;
    sum = 1.0;
    n = 1.0;
    t = 1.0;
    maxt = 0.0;


    while( t > MACHEPF ) {
	    if( bn == 0 ) {			/* check bn first since if both	*/
		    return( MAXNUMF );	/* an and bn are zero it is	*/
	    }
	    if( an == 0 )			/* a singularity		*/
		    return( sum );
	    if( n > 200 ) {
	        if( sum != 0.0 )
	            maxt /= fabs(sum);
            maxt *= MACHEPF; 	/* this way avoids multiply overflow */
            pcanc = fabs( MACHEPF * n  +  maxt );
            *err = pcanc;
            return( sum );
	    }
	    u = x * ( an / (bn * n) );

	    /* check for blowup */
	    temp = fabs(u);
	    if( (temp > 1.0 ) && (maxt > (MAXNUMF/temp)) ) {
		    pcanc = 1.0;	/* estimate 100% error */
            *err = pcanc;
            return( sum );
	    }

	    a0 *= u;
	    sum += a0;
	    t = fabs(a0);
	    if( t > maxt )
		    maxt = t;

        an += 1.0;
	    bn += 1.0;
	    n += 1.0;
	}

    /* estimate error due to roundoff and cancellation */
    if( sum != 0.0 )
	    maxt /= fabs(sum);
    maxt *= MACHEPF; 	/* this way avoids multiply overflow */
    pcanc = fabs( MACHEPF * n  +  maxt );

    *err = pcanc;
    return( sum );

#endif
}


/*                                                     hy1f1a()        */
/* asymptotic formula for hypergeometric function:
 *
 *        (    -a
 *  --    ( |z|
 * |  (b) ( -------- 2f0( a, 1+a-b, -1/x )
 *        (  --
 *        ( |  (b-a)
 *
 *
 *                                x    a-b                     )
 *                               e  |x|                        )
 *                             + -------- 2f0( b-a, 1-a, 1/x ) )
 *                                --                           )
 *                               |  (a)                        )
 */


double sas_hy1f1a(double a, double b, double x, double *err)
{
#if FLOAT_SIZE > 4
    const double MAXNUM =  1.79769313486231570815E308;

    double h1, h2, t, u, temp, acanc, asum, err1, err2;

    if (x == 0) {
	    acanc = 1.0;
	    asum = MAXNUM;
	    *err = acanc;
        return (asum);
    }
    temp = log(fabs(x));
    t = x + temp * (a - b);
    u = -temp * a;

    if (b > 0) {
	    temp = sas_lgamma(b);
	    t += temp;
	    u += temp;
    }

    h1 = sas_hyp2f0(a, a - b + 1, -1.0 / x, 1, &err1);

    temp = exp(u) / sas_gamma(b - a);
    h1 *= temp;
    err1 *= temp;

    h2 = sas_hyp2f0(b - a, 1.0 - a, 1.0 / x, 2, &err2);

    if (a < 0)
	    temp = exp(t) / sas_gamma(a);
    else
	    temp = exp(t - sas_lgamma(a));

    h2 *= temp;
    err2 *= temp;

    if (x < 0.0)
	    asum = h1;
    else
	    asum = h2;

    acanc = fabs(err1) + fabs(err2);

    if (b < 0) {
	    temp = sas_gamma(b);
	    asum *= temp;
	    acanc *= fabs(temp);
    }


    if (asum != 0.0)
	    acanc /= fabs(asum);

    if (acanc != acanc)
	    /* nan */
	    acanc = 1.0;

    if (asum == MAXNUM || asum == -MAXNUM)
	    /* infinity */
	    acanc = 0;

    acanc *= 30.0;		/* fudge factor, since error of asymptotic formula
				 * often seems this much larger than advertised */

    *err = acanc;
    return (asum);
#else
    const double MAXNUMF = 3.4028234663852885981170418348451692544e38;
    double h1, h2, t, u, temp, acanc, asum, err1, err2;

    if( x == 0 ) {
	    acanc = 1.0;
	    asum = MAXNUMF;
	    *err = acanc;
        return( asum );
	}

    temp = log( fabs(x) );
    t = x + temp * (a-b);
    u = -temp * a;

    if( b > 0 ) {
	    temp = sas_lgamma(b);
	    t += temp;
	    u += temp;
	}

    h1 = sas_hyp2f0( a, a-b+1, -1.0/x, 1, &err1 );

    temp = exp(u) / sas_gamma(b-a);
    h1 *= temp;
    err1 *= temp;

    h2 = sas_hyp2f0( b-a, 1.0-a, 1.0/x, 2, &err2 );

    if( a < 0 )
	    temp = exp(t) / sas_gamma(a);
    else
	    temp = exp( t - sas_lgamma(a) );

    h2 *= temp;
    err2 *= temp;

    if( x < 0.0 )
	    asum = h1;
    else
	    asum = h2;

    acanc = fabs(err1) + fabs(err2);


    if( b < 0 ) {
	    temp = sas_gamma(b);
	    asum *= temp;
	    acanc *= fabs(temp);
	}


    if( asum != 0.0 )
	    acanc /= fabs(asum);

    acanc *= 30.0;	/* fudge factor, since error of asymptotic formula
		 * often seems this much larger than advertised */

    *err = acanc;
    return( asum );
#endif
}


/*                                                     hyp2f0()        */


double sas_hyperg(double a, double b, double x)
{
#if FLOAT_SIZE > 4
    double asum, psum, acanc, pcanc, temp;

    /* See if a Kummer transformation will help */
    temp = b - a;
    if (fabs(temp) < 0.001 * fabs(a))
	    return (exp(x) * sas_hyperg(temp, b, -x));

    psum = sas_hy1f1p( a, b, x, &pcanc );

    if( pcanc < 1.0e-15 ) {
        //This is from original code but it doesn't make sense 1.0e-15 < 1.0e-12
        //if( pcanc > 1.0e-12 )
	    //    return 0;

        return( psum );
    }


    /* try asymptotic series */

    asum = sas_hy1f1a( a, b, x, &acanc );


    /* Pick the result with less estimated error */

    if( acanc < pcanc ) {
	    pcanc = acanc;
	    psum = asum;
	}

    if( pcanc > 1.0e-12 )
	    return 0;

    return( psum );
#else
    double  asum, psum, acanc, pcanc, temp;
    /* See if a Kummer transformation will help */
    temp = b - a;
    if( fabs(temp) < 0.001 * fabs(a) )
	    return( exp(x) * sas_hyperg( temp, b, -x )  );

    psum = sas_hy1f1p( a, b, x, &pcanc );
    if( pcanc < 1.0e-6 )
	    return( psum );

    /* try asymptotic series */

    asum = sas_hy1f1a( a, b, x, &acanc );


    /* Pick the result with less estimated error */

    if( acanc < pcanc ) {
	    pcanc = acanc;
	    psum = asum;
	}

    //TODO: It would be good to have some error handling
    if( pcanc > 1.0e-3 )
	    return 0;

    return( psum );
#endif
}
