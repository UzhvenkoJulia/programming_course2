// 20 завдання
// A=xxx.xxx - число з трьома знаками після крапки.
// B=xxExxx - число у форматі наукового запису (наприклад 1.23Е3, що означає 1.23×10^3).
// C=xxx.xxxx - число з чотирма знаками після крапки.

#include <stdio.h>

int main() {
    double A, B, C;

    printf("Enter numbers in the format A=xxx.xxx, B=xxExxx, C=xxx.xxxx: ");
    scanf("A=%lf, B=%lf, C=%lf", &A, &B, &C);

    // Виведення для перевірки
    printf("A: %.3lf\n", A);
    printf("B: %.2le\n", B);  // Науковий формат для B
    printf("C: %.4lf\n", C);

    double arithmetic_mean = (A + B + C) / 3.0;
    double harmonic_mean = 3.0 / ((1.0 / A) + (1.0 / B) + (1.0 / C));

    printf("Arithmetic average:: %.2lf\n", arithmetic_mean);
    printf("Harmonic mean: %.2lf\n", harmonic_mean);
}
