
double sas_spline_eval (double *x, double *f,  int n, double t )

/*
     PURPOSE:
          evaluate a cubic spline at a single value of 
          the independent variable given the coefficients of
          the cubic spline interpolant


     CALLING SEQUENCE:
          y = spline_eval ( n, x, f, b, c, d, t );
          spline_eval ( n, x, f, b, c, d, t );


     INPUTS:
          n		number of interpolating points
          x		array containing interpolating points
          f		array containing the constant terms from 
			the cubic spline (obtained from 'cubic_nak'
			or 'cubic_clamped')
          t		value of independent variable at which
			the interpolating polynomial is to be
			evaluated


     OUTPUTS:
          y		value of cubic spline at the specified 
			value of the independent variable
*/

{
    //From the AKIMA model there are 10 elements
    double b[10], c[10], d[10];
    double h[10], dl[10], dd[10], du[10];
    int i, found;

    for ( i = 0; i < n-1; i++ )
        h[i] = x[i+1] - x[i];
    for ( i = 0; i < n-3; i++ )
        dl[i] = du[i] = h[i+1];

    for ( i = 0; i < n-2; i++ ) {
        dd[i] = 2.0 * ( h[i] + h[i+1] );
        c[i]  = ( 3.0 / h[i+1] ) * ( f[i+2] - f[i+1] ) -
                 ( 3.0 / h[i] ) * ( f[i+1] - f[i] );
     }
     dd[0] += ( h[0] + h[0]*h[0] / h[1] );
     dd[n-3] += ( h[n-2] + h[n-2]*h[n-2] / h[n-3] );
     du[0] -= ( h[0]*h[0] / h[1] );
     dl[n-4] -= ( h[n-2]*h[n-2] / h[n-3] );


     for ( i = 0; i < n-3; i++ ) {
         du[i] /= dd[i];
         dd[i+1] -= dl[i]*b[i];
     }

     c[0] /= dd[0];
     for ( i = 1; i < n; i++ )
         c[i] = ( c[i] - dl[i-1] * c[i-1] ) / dd[i];

     for ( i = n-4; i >= 0; i-- )
         c[i] -= c[i+1] * du[i];

     for ( i = n-3; i >= 0; i-- )
         c[i+1] = c[i];
     c[0] = ( 1.0 + h[0] / h[1] ) * c[1] - h[0] / h[1] * c[2];
     c[n-1] = ( 1.0 + h[n-2] / h[n-3] ) * c[n-2] - h[n-2] / h[n-3] * c[n-3];
     for ( i = 0; i < n-1; i++ ) {
         d[i] = ( c[i+1] - c[i] ) / ( 3.0 * h[i] );
         b[i] = ( f[i+1] - f[i] ) / h[i] - h[i] * ( c[i+1] + 2.0*c[i] ) / 3.0;
     }

     i = 1;
     found = 0;
     while ( !found && ( i < n-1 ) ) {
           if ( t < x[i] )
              found = 1;
           else
              i++;
     }
     t = f[i-1] + ( t - x[i-1] ) * ( b[i-1] + ( t - x[i-1] ) * ( c[i-1] +
                  ( t - x[i-1] ) * d[i-1] ) );
     return ( t );
}
