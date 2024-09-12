// 9 завдання

#include <stdio.h>

int main() {
    double x1, x2;

    printf("Enter two real numbers separated by a space: ");
    scanf("%lf %lf", &x1, &x2);

    double arithmetic_mean = (x1 + x2) / 2.0;

    double harmonic_mean = 2.0 / ((1.0 / x1) + (1.0 / x2));

    printf("Arithmetic average: %.2lf\n", arithmetic_mean);
    printf("Harmonic mean: %.2lf\n", harmonic_mean);
}
