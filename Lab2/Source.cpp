#include "Source.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double f1(double x1, double x2) {
    return cos(0.4 * x2 + x1 * x1) + x2 * x2 + x1 * x1 - 1.6;
}

double f2(double x1, double x2) {
    return 1.5 * x1 * x1 - ((x2 * x2) / 0.36) - 1;
}

double df1_dx1(double x1, double x2) {
    return -sin(x1 * x1) * 2 * x1 + 2 * x1;
}

double df1_dx2(double x1, double x2) {
    return -sin(0.4 * x2) * 0.4 + 2 * x2;
}

double df2_dx1(double x1, double x2) {
    return 3 * x1;
}

double df2_dx2(double x1, double x2) {
    return -((2 * x2) / 0.36);
}


void newtonMethod(double x1, double x2, double E1, double E2, int NIT) {
    int k = 1;
    double res1, res2;

    cout << "Номер итерации\t\tЗначение x1\t\tЗначение x2" << endl;

    while (true) {
        res1 = f1(x1, x2);
        res2 = f2(x1, x2);

        cout << k << "\t\t\t" << x1 << "\t\t\t" << x2 << endl;

        if (abs(res1) < E1 && abs(res2) < E2) {
            cout << "Решение найдено: x1 = " << x1 << ", x2 = " << x2 << endl;
            break;
        }

        if (k >= NIT) {
            cout << "Превышено предельное число итераций." << endl;
            break;
        }

        vector<vector<double>> jacobian = {
            {df1_dx1(x1, x2), df1_dx2(x1, x2)},
            {df2_dx1(x1, x2), df2_dx2(x1, x2)}
        };

        vector<double> residuals = { -res1, -res2 };

        vector<double> delta = {
            (jacobian[0][0] * residuals[0] + jacobian[0][1] * residuals[1]) / (jacobian[0][0] * jacobian[1][1] - jacobian[0][1] * jacobian[1][0]),
            (jacobian[1][0] * residuals[0] + jacobian[1][1] * residuals[1]) / (jacobian[0][0] * jacobian[1][1] - jacobian[0][1] * jacobian[1][0])
        };

        x1 += delta[0];
        x2 += delta[1];

        k++;
    }
}
