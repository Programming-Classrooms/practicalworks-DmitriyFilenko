/*Задание 5. Подпрограммы

Вычислить значение определенного интеграла с аналитически заданной подынтегральной
функцией с заданной точностью eps
Г) по формуле трапеций;
Д) по формуле Симпсона (параболических трапеций).
1: x * atan(x)
2: 1.0 / ((x + 1) * sqrt(x * x + 1))
3: x * sqrt(1 + x)
*/


#include <iostream>
#include <cmath>
#include <stdio.h>

// Функции, которые будут вычислять значения подынтегральных функций
double func1(double x) {
    return x * atan(x);
}

double func2(double x) {
    return 1.0 / ((x + 1) * sqrt(x * x + 1));
}

double func3(double x) {
    return x * sqrt(1 + x);
}

// Метод трапеций
double trapezoidalRule(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.5 * (func(a) + func(b));

    for (int i = 1; i < n; ++i) {
        result += func(a + i * h);
    }

    return h * result;
}

// Метод Симпсона
double simpsonsRule(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double result = func(a) + func(b);

    for (int i = 1; i < n; i += 2) {
        result += 4 * func(a + i * h);
    }

    for (int i = 2; i < n - 1; i += 2) {
        result += 2 * func(a + i * h);
    }

    return h / 3 * result;
}

int main() {
    // Заданные интегралы и интервалы интегрирования
    double a1, b1, a2, b2, a3, b3;
    a1 = 0.0;  // Нижний предел интегрирования для первого интеграла
    b1 = 1.7;  // Верхний предел интегрирования для первого интеграла
    a2 = 0.0;  // Нижний предел интегрирования для второго интеграла
    b2 = 0.6;  // Верхний предел интегрирования для второго интеграла
    a3 = 2.0;  // Нижний предел интегрирования для третьего интеграла
    b3 = 7.0;  // Верхний предел интегрирования для третьего интеграла

    // Количество подотрезков (можно настроить)
    int n = 10000000;

    std::cout << "\nIntegral 1 (x * arctan(x)): \n";
    std::cout << "\nTrapezoidal Rule: " << "\n";
    printf("%10.7f", trapezoidalRule(func1, a1, b1, n));
    std::cout << "\nSimpson's Rule: " << "\n";
    printf("%10.7f", simpsonsRule(func1, a1, b1, n));
    std::cout << "\nIntegral 2 (1 / ((x+1)(sqrt(x * x + 1)))): \n";
    std::cout << "\nTrapezoidal Rule: " << "\n";
    printf("%10.7f", trapezoidalRule(func2, a2, b2, n));
    std::cout << "\nSimpson's Rule: " << "\n";
    printf("%10.7f", simpsonsRule(func2, a2, b2, n));
    std::cout << "\nIntegral 3 (x * (sqrt(1 + x))): \n";
    std::cout << "\nTrapezoidal Rule: " << "\n";
    printf("%10.7f", trapezoidalRule(func3, a3, b3, n));
    std::cout << "\nSimpson's Rule: " << "\n";
    printf("%10.7f", simpsonsRule(func3, a3, b3, n));

    return 0;
}
