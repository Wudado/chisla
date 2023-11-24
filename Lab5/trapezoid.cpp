#include "trapezoid.h"

double trapezoid_method(double(&function)(const double&), const double& A, const double& B, const unsigned long& n) {
	double h = (B - A) / n; //шаг(step)(خطوة)(βήμα)(Schritt)(ステップ)(שלב)(ნაბიჯი)
	double f = 0;
	for (int i = 1; i < n - 1; ++i) {
		f += function(A + h * i);
	}

	return h * (function(A) + 2 * f + function(B)) / 2;
}

double calculate_trapezoid(double(&function)(const double&), const double& A, const double& B, const double& epsilon) {
	long n = 10;
	double intg1 = 0;
	double intg2 = trapezoid_method(function, A, B, n);

	while (abs(intg1 - intg2) > 3 * epsilon) {
		n *= 2;
		intg1 = intg2;
		intg2 = trapezoid_method(function, A, B, n);
	}

	return intg2;
}