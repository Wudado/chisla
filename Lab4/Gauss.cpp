#include "Gauss.h"

void fillMatrix(QVector<QVector<double>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void fillMatrix(QVector<double>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
}

void resizeMatrix(QVector<QVector<double>>& matrix, int newSize) {
    matrix.resize(newSize);
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        matrix[i].resize(newSize);
    }
}

void resizeMatrix(QVector<double>& matrix, int newSize) {
    matrix.resize(newSize);
}

QVector<double> calculate(QVector<QVector<double>> matrixA, QVector<double> matrixB) {
    int n = matrixA.size();

    for (int i = 0; i < n; ++i) {
        matrixA[i].push_back(matrixB[i]);
    }

    for (int i = 0; i < n; ++i) {
        int max_row = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(matrixA[j][i]) > abs(matrixA[max_row][i])) {
                max_row = j;
            }
        }
        swap(matrixA[i], matrixA[max_row]);

        double pivot = matrixA[i][i];

        for (int j = n; j >= i; --j) {
            matrixA[i][j] /= pivot;
        }

        for (int j = 0; j < n; ++j) {
            if (j != i) {
                double factor = matrixA[j][i];
                for (int k = i; k <= n; ++k) {
                    matrixA[j][k] -= factor * matrixA[i][k];
                }
            }
        }
    }

    QVector<double> solution;
    for (int i = 0; i < n; ++i) {
        solution.push_back(matrixA[i][n]);
    }

    return solution;
}

void printMatrix(const QVector<QVector<double>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(11) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void printMatrix(const QVector<double>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        cout << setw(13) << matrix[i];
    }
    cout << endl;
}

QVector<double> calculateNeviazku(const QVector<QVector<double>>& matrixA, const QVector<double>& matrixB, const QVector<double>& solution) {
    QVector<double> neviazka;

    int n = matrixA.size();
    for (int i = 0; i < n; i++) {
        neviazka.push_back(0);
        for (int j = 0; j < n; j++) {
            neviazka[i] += matrixA[i][j] * solution[j];
        }
        neviazka[i] -= matrixB[i];
    }

    return neviazka;
}

pair<double, int> maximum(const QVector<double>& matrix) {
    double max = 0.0f;
    int n = matrix.size();
    int line = 0;
    pair<double, int> res;

    for (int i = 0; i < n; i++) {
        if (abs(max < matrix[i])) { max = matrix[i]; line = i; }
    }

    res.first = max;
    res.second = line;
    return res;
}

double relative_fault(const QVector<QVector<double>> matrixA, const QVector<double>& solution) {
    int n = matrixA.size();
    QVector<double> matrixB(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrixB[i] += matrixA[i][j] * solution[j];
        }
    }

    QVector<double> new_solution = calculate(matrixA, matrixB);

    QVector<double> delta;
    for (int i = 0; i < n; i++) {
        delta.push_back(abs(new_solution[i] - solution[i]));
    }

    return maximum(delta).first / maximum(solution).first;
}
