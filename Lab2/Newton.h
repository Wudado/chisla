#pragma once
#include "Gauss.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Функции, для которых мы решаем систему уравнений
double f1(vector<double> solution);
double f2(vector<double> solution);

// Частные производные для исходных функций
double df1_dx1(vector<double> solution);
double df2_dx1(vector<double> solution);
double df1_dx2(vector<double> solution);
double df2_dx2(vector<double> solution);

vector<double> calculateNewton(vector<double> currentSolution, const double& epsilon1, const double& epsilon2, const int& maxIterations, const double& M, const bool& print, const int& statsEvery);