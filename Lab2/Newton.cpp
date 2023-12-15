#include "Newton.h"

// Ôóíêöèè, äëÿ êîòîðûõ ìû ðåøàåì ñèñòåìó óðàâíåíèé
double f1(vector<double> X) {
    return 2 * pow(X[0], 2) - X[0] * X[1] - 5 * X[0] + 1.0;
}
double f2(vector<double> X) {
    return X[0] + 3 * log10(X[0]) - pow(X[1], 2);
}

// ×àñòíûå ïðîèçâîäíûå äëÿ èñõîäíûõ ôóíêöèé
double df1_dx1(vector<double> X) {
    return 4.0 * X[0] - X[1] - 5.0;
}
double df2_dx1(vector<double> X) {
    return 1.0 + 3.0 / (X[0] * log(10));
}
double df1_dx2(vector<double> X) {
    return -X[0];
}
double df2_dx2(vector<double> X) {
    return -2.0 * X[1];
}

vector<vector<double>> jacobian(vector<double> X) {
    vector<vector<double>> J(2, vector<double>(2));
    J[0][0] = df1_dx1(X);
    J[0][1] = df1_dx2(X);
    J[1][0] = df2_dx1(X);
    J[1][1] = df2_dx2(X);
    return J;
}
vector<vector<double>> jacobian(vector<double> X, const double& M) {
    vector<vector<double>> J(2, vector<double>(2));
    double F1 = f1(X);
    double F2 = f2(X);

    vector<double> dx(X);

    for (int i = 0; i < X.size(); i++) {
        dx[i] *= M;
    }

    J[0][0] = (f1({ X[0] + dx[0], X[1] }) - F1) / dx[0];
    J[0][1] = (f1({ X[0], X[1] + dx[1] }) - F1) / dx[1];
    J[1][0] = (f2({ X[0] + dx[0], X[1] }) - F2) / dx[0];
    J[1][1] = (f2({ X[0], X[1] + dx[1] }) - F2) / dx[1];

    return J;
}

vector<double> calculateNewton(vector<double> currentSolution, const double& epsilon1, const double& epsilon2, const int& maxIterations, const double& M, const bool& print, const int& statsEvery) {
    if (print) {
        cout << "-------------------------------------------------\n";
        cout << "Íà÷àëüíîå ïðèáëèæåíèå: " << currentSolution[0] << " , " << currentSolution[1] << endl << "Èñïîëüçóåòñÿ ";
    }
    if (M == 0.0) { cout << "1 ìåòîä âû÷èñëåíèÿ ÿêîáèàíà.\n\n"; }
    else { cout << "2 ìåòîä âû÷èñëåíèÿ ÿêîáèàíà. M = " << M << "\n\n"; }

    int iteration = 0;
    vector<double> solution(currentSolution);
    double F1 = f1(solution);
    double F2 = f2(solution);
    vector<double> F = { -F1, -F2 };
    vector<double> delta_x(2);
    vector<double> prev_solution(solution);
    vector<vector<double>> J(2, vector<double>(2));

    while (iteration < maxIterations) {
        F1 = f1(solution);
        F2 = f2(solution);
        F = { -F1, -F2 };
        prev_solution = solution;
        
        //âû÷èñëåíèå ìàòðèöû ßêîáè
        if (M == 0.0) { J = jacobian(solution); }
        else { J = jacobian(solution, M); }

        //âû÷èñëåíèå íåâÿçêè
        delta_x = calculate(J, F);

        // Óòî÷íåíèå ðåøåíèÿ
        solution[0] += delta_x[0];
        solution[1] += delta_x[1];

        //âû÷èñëåíèå ïîãðåøíîñòè
        double delta1 = maximum({ abs(F1), abs(F2) }).first;
        double delta2;
        if (maximum(solution).first < 1) { delta2 = abs(maximum(delta_x).first); }
        else { 
            int size = delta_x.size();
            vector<double> val(size);
            for (int i = 0; i < size; ++i) {
                val[i] = delta_x[i] / solution[i];
            }
            delta2 = abs(maximum(val).first) ; 
        }

        //âûâîä ïðîìåæóòî÷íîãî çíà÷åíèÿ
        if (print) {
            if (!(iteration % statsEvery)) {
                cout << "Èòåðàöèÿ " << iteration + 1 << ":\n";
                cout << " delta1 = " << delta1 << "\n";
                cout << " delta2 = " << delta2 << "\n";
                cout << "     x1 = " << solution[0] << "\n";
                cout << "     x2 = " << solution[1] << "\n";
            }
        }

        // Ïðîâåðêà êðèòåðèÿ çàâåðøåíèÿ èòåðàöèè
        if (delta1 <= epsilon1 && delta2 <= epsilon2) {
            if (print) {
                cout << endl << "Ðåøåíèå íàéäåíî ïîñëå " << iteration + 1 << " èòåðàöèé." << endl;
                if (iteration % statsEvery) {
                    cout << " delta1 = " << delta1 << "\n";
                    cout << " delta2 = " << delta2 << "\n";
                }
                cout << "     x1 = " << solution[0] << endl;
                cout << "     x2 = " << solution[1] << "\n\n\n";
            }
            break;
        }
        iteration++;
    }
    if (iteration == 100) { cout << "IER = 2"; }
    return solution;
}
