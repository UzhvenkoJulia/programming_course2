// Реалізуйте функції та напишіть відповідну до кожної з них функцію,
// що буде рахувати їх похідні (за нескінченість прийміть найбільше можливе число типу double)

// Завдання домашнє 3.23 д)
// sReLu(tl, tr, al, ar, x)={ tl + al (x-tl), x <= tl
// 0, tl < x < tr
// tr + ar (x-tr), x >= tr

#include <stdio.h>
#include <float.h> // Для DBL_MAX

double sReLu(double tl, double tr, double al, double ar, double x) {
    if (x <= tl) {
        return tl + al * (x - tl);
    } else if (x < tr) {
        return 0.0;
    } else {
        return tr + ar * (x - tr);
    }
}

double sReLu_derivative(double tl, double tr, double al, double ar, double x) {
    if (x <= tl) {
        return al;
    } else if (x < tr) {
        return 0.0;
    } else {
        return ar;
    }
}

int main() {
    double tl, tr, al, ar, x;

    printf("Enter tl, tr, al, ar: ");
    scanf("%lf %lf %lf %lf", &tl, &tr, &al, &ar);
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Перевірка на допустимість параметрів
    if (tl >= tr) {
        printf("Error: tl must be less than tr\n");
        return 1;
    }

    double result = sReLu(tl, tr, al, ar, x);
    double derivative = sReLu_derivative(tl, tr, al, ar, x);

    printf("sReLu(%lf) = %lf\n", x, result);
    printf("sReLu'(%lf) = %lf\n", x, derivative);
}
