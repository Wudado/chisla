#include "func.h"

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
    std::cout << "\n"<<"------------------------------------------------------------------\n";
    for (int i = 0; i < result.size(); i++) {
        cout << setw(11) << result[i];
    }

  ///*  std::cout << "\n";
  //  vector<float> residuals = calculateResiduals(coefficientsMatrix, solutionsVector, result);
  //  for (int i = 0; i < residuals.size(); i++) {
  //      cout << setw(11) << residuals[i];
  //  }*/

  //  float relativeError = calculateRelativeError(residuals, result);
  //  std::cout << "\n" << relativeError;

    vector<float> Nev = calculateNev(coefficientsMatrix, solutionsVector, result);
    std::cout << "\n" << "------------------------------------------------------------------\n";
    cout << "Вектор невязки:\n";
    printVector(Nev);

    pair<float, int> fault = maximum(Nev);

    std::cout << "\n" << "------------------------------------------------------------------\n";
    cout << "Норма: " << fault.first << endl;
    cout << "Относительная погрешность: " << fault.first / result[fault.second] << endl;
}
