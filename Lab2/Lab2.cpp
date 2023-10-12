#include <iostream>
#include <cmath>
#include <vector>
#include "Source.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    double x1, x2, E1, E2;
    int NIT;

    cout << "Введите начальное приближение x1: ";
    cin >> x1;

    cout << "Введите начальное приближение x2: ";
    cin >> x2;

    cout << "Введите параметр E1: ";
    cin >> E1;

    cout << "Введите параметр E2: ";
    cin >> E2;

    cout << "Введите предельное число итераций NIT: ";
    cin >> NIT;

    newtonMethod(x1, x2, E1, E2, NIT);

    return 0;
}