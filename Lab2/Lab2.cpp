#include "Newton.h"
#include "Gauss.h"
#include <windows.h>

int main() {
    setlocale(LC_ALL, "rus");
    system("cls");

    vector<vector<double>> answers1;
    vector<vector<double>> answers2;
    int size, size1;
    bool same;
    int statsEvery = 5;
    double epsilon1 = 1e-9;
    double epsilon2 = 1e-6;
    int NIT = 100;

    answers1.push_back(calculateNewton({ 3, 2 }, epsilon1, epsilon2, NIT, 0, true, statsEvery));
    answers1.push_back(calculateNewton({ 3, 2 }, epsilon1, epsilon2, NIT, 0.5, true, statsEvery));
    answers1.push_back(calculateNewton({ 3, 2 }, epsilon1, epsilon2, NIT, 0.1, true, statsEvery));
    answers1.push_back(calculateNewton({ 3, 2 }, epsilon1, epsilon2, NIT, 0.01, true, statsEvery));

    size = answers1.size();
    size1 = answers1[0].size();
    same = true;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size1; ++j) {
            if (abs(answers1[i][j] - answers1[i + 1][j]) > 1e-6) {
                same = false;
                break;
            }
        }
    }
    if (same) { cout << "Ответы совпадают.\n\n\n\n\n"; }
    else { cout << "Ответы не совпадают.\n\n\n\n\n"; }


    answers2.push_back(calculateNewton({ 3, -2 }, epsilon1, 1e-6, NIT, 0, true, statsEvery));
    answers2.push_back(calculateNewton({ 3, -2 }, epsilon1, 1e-6, NIT, 0.5, true, statsEvery));
    answers2.push_back(calculateNewton({ 3, -2 }, epsilon1, 1e-6, NIT, 0.1, true, statsEvery));
    answers2.push_back(calculateNewton({ 3, -2 }, epsilon1, 1e-6, NIT, 0.01, true, statsEvery));

    size = answers2.size();
    size1 = answers2[0].size();
    same = true;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size1; ++j) {
            if (abs(answers2[i][j] - answers2[i + 1][j]) > 1e-6) {
                same = false;
                break;
            }
        }
    }
    if (same) { cout << "Ответы совпадают.\n\n\n\n\n"; }
    else { cout << "Ответы не совпадают.\n\n\n\n\n"; }
}
