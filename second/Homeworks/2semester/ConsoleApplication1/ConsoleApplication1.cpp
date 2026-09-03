#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Исходная функция f(x) = cos(3x) - x^3
double f(double x) {
    return cos(3 * x) - pow(x, 3);
}

// Производная f'(x) для метода Ньютона: -3*sin(3x) - 3*x^2
double df(double x) {
    return -3 * sin(3 * x) - 3 * pow(x, 2);
}

// Функция phi(x) для метода простых итераций: 1/3 * acos(x^3)
double phi(double x) {
    return -(1.0 / 3.0) * acos(pow(x, 3));
}

// 1. Метод половинного деления (бисекции)
void bisectionMethod(double a, double b, double eps) {
    int iterations = 0;
    double x;
    while ((b - a) > eps) {
        iterations++;
        x = (a + b) / 2.0;
        if (f(a) * f(x) <= 0) b = x;
        else a = x;
    }
    cout << "--- Метод половинного деления ---" << endl;
    cout << "Корень: " << setprecision(12) << x << endl;
    cout << "Итераций: " << iterations << endl;
    cout << "Проверка f(x): " << f(x) << endl << endl;
}

// 2. Метод хорд
void chordMethod(double a, double b, double eps) {
    int iterations = 0;
    double x_prev = a;
    double x_curr = b;
    double x_next;

    do {
        iterations++;
        x_next = x_curr - f(x_curr) * (x_curr - x_prev) / (f(x_curr) - f(x_prev));
        x_prev = x_curr;
        x_curr = x_next;
    } while (abs(f(x_curr)) > eps); // Условие из скрина по точности f(x)

    cout << "--- Метод хорд ---" << endl;
    cout << "Корень: " << x_curr << endl;
    cout << "Итераций: " << iterations << endl;
    cout << "Проверка f(x): " << f(x_curr) << endl << endl;
}

// 3. Метод Ньютона (касательных)
void newtonMethod(double x0, double eps) {
    int iterations = 0;
    double x = x0;
    double x_next;

    do {
        iterations++;
        x_next = x - f(x) / df(x);
        if (abs(x_next - x) < eps) break;
        x = x_next;
    } while (true);

    cout << "--- Метод Ньютона ---" << endl;
    cout << "Корень: " << x_next << endl;
    cout << "Итераций: " << iterations << endl;
    cout << "Проверка f(x): " << f(x_next) << endl << endl;
}

// 4. Метод простых итераций
void simpleIterationMethod(double x0, double eps) {
    int iterations = 0;
    double x_curr = x0;
    double x_next;

    do {
        iterations++;
        x_next = phi(x_curr);
        if (abs(x_next - x_curr) < eps) break;
        x_curr = x_next;
    } while (iterations < 1000); // Ограничитель для безопасности

    cout << "--- Метод простых итераций ---" << endl;
    cout << "Корень: " << x_next << endl;
    cout << "Итераций: " << iterations << endl;
    cout << "Проверка f(x): " << f(x_next) << endl << endl;
}

int main() {
    // Входные данные со скринов
	setlocale(LC_ALL, "Russian");
    double a = -0.59398;
    double b = -0.59397;
    double eps = 1e-12;

    bisectionMethod(a, b, eps);
    chordMethod(a, b, eps);
    newtonMethod(b, eps);
    simpleIterationMethod(a, eps);

    return 0;
}