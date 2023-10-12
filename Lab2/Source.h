#pragma once
#include <iostream>
#include <cmath>
#include <vector>

double f1(double x1, double x2);
double f2(double x1, double x2);
double df1_dx1(double x1, double x2);
double df1_dx2(double x1, double x2);
double df2_dx1(double x1, double x2);
double df2_dx2(double x1, double x2);
void newtonMethod(double x1, double x2, double E1, double E2, int NIT);