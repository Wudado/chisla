#include "simpson.h"

double simpson_method(double(&function)(const double&), const double& A, const double& B, const unsigned long& n) {
	unsigned int m = n / 2;	
	double h = (B - A) / n; 
	double f1 = 0;
	double f2 = 0;

	for (int i = 1; i <= m; ++i) {
		f1 += function(A + (double(i) * 2 - 1) * h);
	}

	for (int i = 1; i <= m - 1; ++i) {
		f2 += function(A + (double(i) * 2) * h);
	}

	return h * (function(A) + 4 * f1 + 2 * f2 + function(B)) / 3;
}

double calculate_simpson(double(&function)(const double&), const double& A, const double& B, const double& epsilon) {
	long n = 10;
	double intg1 = 0;
	double intg2 = simpson_method(function, A, B, n);

	while (abs(intg1 - intg2) > 15 * epsilon) {
		n *= 2;
		intg1 = intg2;
		intg2 = simpson_method(function, A, B, n);
	}

	return intg2;
}

double simpson_method(double(&function)(const double&, const double&), const double& A, const double& B, const double& C, const double& D, const unsigned long& n) {
	double hx = (B - A) / (double(2) * n);
	double hy = (D - C) / (double(2) * n);

	double result = 0.0;

	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= n - 1; ++j) {
			result += function(A + (double(i) * 2) * hx, C + (double(j) * 2) * hy) +
				4 * function(A + (double(i) * 2 + 1) * hx, C + (double(j) * 2) * hy) +
				function(A + (double(i) * 2 + 2) * hx, C + (double(j) * 2) * hy) +
				4 * function(A + (double(i) * 2) * hx, C + (double(j) * 2 + 1) * hy) +
				16 * function(A + (double(i) * 2 + 1) * hx, C + (double(j) * 2 + 1) * hy) +
				4 * function(A + (double(i) * 2 + 2) * hx, C + (double(j) * 2 + 1) * hy) +
				function(A + (double(i) * 2) * hx, C + (double(j) * 2 + 2) * hy) +
				4 * function(A + (double(i) * 2 + 1) * hx, C + (double(j) * 2 + 2) * hy) +
				function(A + (double(i) * 2 + 2) * hx, C + (double(j) * 2 + 2) * hy);
		}
	}
	return hx * hy * result / 9;
}

double calculate_simpson(double(&function)(const double&, const double&), const double& A, const double& B, const double& C, const double& D, const double& epsilon) {
	long n = 10;
	double intg1 = 0;
	double intg2 = simpson_method(function, A, B, C, D, n);

	while (abs(intg1 - intg2) > 15 * epsilon) {
		n *= 2;
		intg1 = intg2;
		intg2 = simpson_method(function, A, B, C, D, n);
	}

	return intg2;
}
