#pragma once
#include <cmath>

double trapezoid_method(double(&function)(const double&), const double& A, const double& B, const unsigned long& n);

double calculate_trapezoid(double(&function)(const double&), const double& A, const double& B, const double& epsilon);