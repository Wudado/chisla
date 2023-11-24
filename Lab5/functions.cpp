#include "functions.h"

double function1(const double& x) { return sqrt(1 + pow(x, 3)); }
double function2(const double& x) { return 1 / (pow(log10(x), 2) + 1); }
double function3(const double& x) { return sqrt(x + pow(x, 3)); }
double function4(const double& x) { return (1 + pow(x, 2)) / (1 + pow(x, 3)); }
double function5(const double& x) { return sqrt(pow(sin(x), 2) / (1 + pow(x, 3))); }
double function6(const double& x) { return exp(x / 2) / sqrt(x + 1); }
double function7(const double& x) { return sqrt(1 + 2 * pow(x, 3)); }
double function8(const double& x) { return 1 / (pow(log10(x), 2) + 1); }

double function29(const double& x, const double& y) { return pow(x, 2) / (1 + pow(y, 2)); }
double function30(const double& x, const double& y) { return 1 / pow(x + y, 2); }
double function31(const double& x, const double& y) { return pow(x, 2) + 2 * y; }
double function32(const double& x, const double& y) { return 4 - pow(x, 2) - pow(y, 2); }
double function33(const double& x, const double& y) { return sin(x + y); }