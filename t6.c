// 6 завдання

#include <stdio.h>

int main() {
    double C, F;

    printf("Enter the temperature in degrees Celsius: ");
    scanf("%lf", &C);

    F = (9.0 / 5.0) * C + 32.0;

    printf("F = %.2lf\n", F);

    return 0;
}
