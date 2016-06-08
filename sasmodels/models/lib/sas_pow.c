// integral of sin(x)/x Taylor series approximated to w/i 0.1%
double sas_pow_2(double x);
double sas_pow_3(double x);
double sas_pow_4(double x);
double sas_pow_5(double x);
double sas_pow_6(double x);
double sas_pow_7(double x);
double sas_pow_8(double x);
double sas_pow_9(double x);
double sas_pow_int(double x, int n);


double sas_pow_2(double x) {
    return pow(x,2);
}

double sas_pow_3(double x) {
    return pow(x,3);
}

double sas_pow_4(double x) {
    return pow(x,4);
}

double sas_pow_5(double x) {
    return pow(x,5);
}

double sas_pow_6(double x) {
    return pow(x,6);
}

double sas_pow_7(double x) {
    return pow(x,7);
}

double sas_pow_8(double x) {
    return pow(x,8);
}

double sas_pow_9(double x) {
    return pow(x,9);
}

double sas_pow_int(double x, int n) {
    return pow(x,n);
}
