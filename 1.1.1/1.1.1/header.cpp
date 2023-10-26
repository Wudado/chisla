#include "Header.h"

void fillMatrix(vector<vector<float>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cin >> matrix[i][j];
        }
    }
}

void fillMatrix(vector<float>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        cin >> matrix[i];
    }
}

void resizeMatrix(vector<vector<float>>& matrix, int newSize) {
    matrix.resize(newSize);
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i].resize(newSize);
    }
}

void resizeMatrix(vector<float>& matrix, int newSize) {
    matrix.resize(newSize);
}

//vector<float> solveSystem(vector<vector<float>>& coefficientsMatrix, vector<float>& solutionsVector) {
//    int n = coefficientsMatrix[0].size();
//
//    #pragma omp for
//    for (int i = 0; i < n; ++i) {
//        coefficientsMatrix[i].push_back(solutionsVector[i]);
//    }
//
//    for (int i = 0; i < n; ++i) {
//        int max_row = i;
//        for (int j = i + 1; j < n; ++j) {
//            if (abs(coefficientsMatrix[j][i]) > abs(coefficientsMatrix[max_row][i])) {
//                max_row = j;
//            }
//        }
//
//        swap(coefficientsMatrix[i], coefficientsMatrix[max_row]);
//        printMatrix(coefficientsMatrix);
//
//        float main = coefficientsMatrix[i][i];
//        for (int j = i; j <= n; ++j) {
//            coefficientsMatrix[i][j] /= main;
//        }
//        printMatrix(coefficientsMatrix);
//
//        float factor = 1;
//
//        for (int j = 0; j < n; ++j) {
//            if (j != i) {
//                factor = coefficientsMatrix[j][i];
//                for (int k = i; k <= n; ++k) {
//                    coefficientsMatrix[j][k] -= factor * coefficientsMatrix[i][k];
//                }
//            }
//        }
//        printMatrix(coefficientsMatrix);
//    }
//
//    vector<float> solution;
//
//    for (int i = 0; i < n; ++i) {
//        solution.push_back(coefficientsMatrix[i][n]);
//    }
//
//    return solution;
//}

vector<float> solveSystem(vector<vector<float>> matrixA, vector<float> matrixB) {
    int n = matrixA.size();
    printMatrix(matrixA);

    for (int i = 0; i < n; ++i) {
        matrixA[i].push_back(matrixB[i]);
    }
    printMatrix(matrixA);

    for (int i = 0; i < n; ++i) {
        int max_row = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(matrixA[j][i]) > abs(matrixA[max_row][i])) {
                max_row = j;
            }
        }

        swap(matrixA[i], matrixA[max_row]);
        printMatrix(matrixA);

        float pivot = matrixA[i][i];
        if (pivot == 0) {
            cout << "���������� ������ ������� (���� �� ������������� ����� 0)";
            return {};
        }
        for (int j = i; j <= n; ++j) {
            matrixA[i][j] /= pivot;
        }
        printMatrix(matrixA);

        for (int j = 0; j < n; ++j) {
            if (j != i) {
                float factor = matrixA[j][i];
                for (int k = i; k <= n; ++k) {
                    matrixA[j][k] -= factor * matrixA[i][k];
                }
            }
        }
        printMatrix(matrixA);
    }

    vector<float> solution;
    for (int i = 0; i < n; ++i) {
        solution.push_back(matrixA[i][n]);
    }

    return solution;
}

void printMatrix(vector<vector<float>> matrix) {
    int size = matrix.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(11) << matrix[i][j];
        }
        cout << endl;
    }
}

vector<float> calculateResiduals(vector<vector<float>>& coefficientsMatrix, vector<float>& solutionsVector, vector<float>& solution) {
    int n = coefficientsMatrix.size();
    vector<float> residuals(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            residuals[i] += coefficientsMatrix[i][j] * solution[j];
        }
        residuals[i] -= solutionsVector[i];
    }

    return residuals;
}

float calculateRelativeError(const vector<float>& residuals, const vector<float>& solution) {
    int n = residuals.size();
    float residualNorm = 0.0;
    float solutionNorm = 0.0;

    for (int i = 0; i < n; ++i) {
        residualNorm += residuals[i] * residuals[i];
        solutionNorm += solution[i] * solution[i];
    }

    residualNorm = sqrt(residualNorm);
    solutionNorm = sqrt(solutionNorm);

    float relativeError = residualNorm / solutionNorm;

    return relativeError;
}