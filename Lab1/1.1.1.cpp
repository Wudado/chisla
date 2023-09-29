#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    vector<vector<float>> coefficientsMatrix;
    vector<float> solutionsVector;
    int matrixSize;

    cout << "Введите размерность матрицы: ";
    cin >> matrixSize;

    resizeMatrix(coefficientsMatrix, matrixSize);
    resizeMatrix(solutionsVector, matrixSize);

    cout << "Введите матрицу коэффициентов:" << endl;
    fillMatrix(coefficientsMatrix);
    cout << "Введите дополнение матрицы:" << endl;
    fillMatrix(solutionsVector);

    vector<float> result = solveSystem(coefficientsMatrix, solutionsVector);
    for (int i = 0; i < result.size(); i++) {
        cout << setw(11) << result[i];
    }
}
