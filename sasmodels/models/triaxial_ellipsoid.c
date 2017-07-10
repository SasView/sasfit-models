double form_volume(double radius_equat_minor, double radius_equat_major, double radius_polar);
double Iq(double q, double sld, double sld_solvent,
    double radius_equat_minor, double radius_equat_major, double radius_polar);
double Iqxy(double qx, double qy, double sld, double sld_solvent,
    double radius_equat_minor, double radius_equat_major, double radius_polar, double theta, double phi, double psi);

//#define INVALID(v) (v.radius_equat_minor > v.radius_equat_major || v.radius_equat_major > v.radius_polar)


double form_volume(double radius_equat_minor, double radius_equat_major, double radius_polar)
{
    return M_4PI_3*radius_equat_minor*radius_equat_major*radius_polar;
}

double Iq(double q,
    double sld,
    double sld_solvent,
    double radius_equat_minor,
    double radius_equat_major,
    double radius_polar)
{
    const double pa = square(radius_equat_minor/radius_equat_major) - 1.0;
    const double pc = square(radius_polar/radius_equat_major) - 1.0;
    // translate a point in [-1,1] to a point in [0, pi/2]
    const double zm = M_PI_4;
    const double zb = M_PI_4;
    double outer = 0.0;
    for (int i=0;i<76;i++) {
        //const double u = Gauss76Z[i]*(upper-lower)/2 + (upper + lower)/2;
        const double phi = Gauss76Z[i]*zm + zb;
        const double pa_sinsq_phi = pa*square(sin(phi));

        double inner = 0.0;
        const double um = 0.5;
        const double ub = 0.5;
        for (int j=0;j<76;j++) {
            // translate a point in [-1,1] to a point in [0, 1]
            const double usq = square(Gauss76Z[j]*um + ub);
            const double r = radius_equat_major*sqrt(pa_sinsq_phi*(1.0-usq) + 1.0 + pc*usq);
            const double fq = sas_3j1x_x(q*r);
            inner += Gauss76Wt[j] * fq * fq;
        }
        outer += Gauss76Wt[i] * inner;  // correcting for dx later
    }
    // translate integration ranges from [-1,1] to [lower,upper] and normalize by 4 pi
    const double fqsq = outer/4.0;  // = outer*um*zm*8.0/(4.0*M_PI);
    const double s = (sld - sld_solvent) * form_volume(radius_equat_minor, radius_equat_major, radius_polar);
    return 1.0e-4 * s * s * fqsq;
}

double Iqxy(double qx, double qy,
    double sld,
    double sld_solvent,
    double radius_equat_minor,
    double radius_equat_major,
    double radius_polar,
    double theta,
    double phi,
    double psi)
{
    double q, xhat, yhat, zhat;
    ORIENT_ASYMMETRIC(qx, qy, theta, phi, psi, q, xhat, yhat, zhat);

    const double r = sqrt(square(radius_equat_minor*xhat)
                          + square(radius_equat_major*yhat)
                          + square(radius_polar*zhat));
    const double fq = sas_3j1x_x(q*r);
    const double s = (sld - sld_solvent) * form_volume(radius_equat_minor, radius_equat_major, radius_polar);

    return 1.0e-4 * square(s * fq);
}

