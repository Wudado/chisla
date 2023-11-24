#include "functions.h"
#include "simpson.h"
#include "trapezoid.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	system("cls");

	cout << "Метод трапеций" << endl;
	cout << "Вариант 1: " << calculate_trapezoid(function1, 0.8, 1.762, 1e-5) << endl;
	cout << "Вариант 2: " << calculate_trapezoid(function2, 1.3, 2.621, 1e-5) << endl;
	cout << "Вариант 3: " << calculate_trapezoid(function3, 0.6, 1.724, 1e-5) << endl;
	cout << "Вариант 4: " << calculate_trapezoid(function4, 3.0, 4.254, 1e-5) << endl;
	cout << "Вариант 5: " << calculate_trapezoid(function5, 0.0, 1.234, 1e-5) << endl;
	cout << "Вариант 6: " << calculate_trapezoid(function6, 0.0, 1.047, 1e-5) << endl;
	cout << "Вариант 7: " << calculate_trapezoid(function7, 1.2, 2.471, 1e-5) << endl;
	cout << "Вариант 8: " << calculate_trapezoid(function8, 1.0, 2.835, 1e-5) << endl;

	cout << "Метод Симпсона" << endl;
	cout << "Вариант 1: " << calculate_simpson(function1, 0.8, 1.762, 1e-5) << endl;
	cout << "Вариант 2: " << calculate_simpson(function2, 1.3, 2.621, 1e-5) << endl;
	cout << "Вариант 3: " << calculate_simpson(function3, 0.6, 1.724, 1e-5) << endl;
	cout << "Вариант 4: " << calculate_simpson(function4, 3.0, 4.254, 1e-5) << endl;
	cout << "Вариант 5: " << calculate_simpson(function5, 0.0, 1.234, 1e-5) << endl;
	cout << "Вариант 6: " << calculate_simpson(function6, 0.0, 1.047, 1e-5) << endl;
	cout << "Вариант 7: " << calculate_simpson(function7, 1.2, 2.471, 1e-5) << endl;
	cout << "Вариант 8: " << calculate_simpson(function8, 1.0, 2.835, 1e-5) << endl;
	cout << endl;

	cout << "Кубатурная функция Симпсона" << endl;
	cout << "Вариант 29: " << calculate_simpson(function29, 0.0, 4.0, 1.0, 2.0, 1e-5) << endl;
	cout << "Вариант 30: " << calculate_simpson(function30, 3.0, 4.0, 1.0, 2.0, 1e-5) << endl;
	cout << "Вариант 31: " << calculate_simpson(function31, 0.0, 2.0, 0.0, 1.0, 1e-5) << endl;
	cout << "Вариант 32: " << calculate_simpson(function32, -1.0, 1.0, -1.0, 1.0, 1e-5) << endl;
	cout << "Вариант 33: " << calculate_simpson(function33, 0.0, 1.57, 0.0, 0.7535, 1e-5) << endl;
	cout << endl;
}