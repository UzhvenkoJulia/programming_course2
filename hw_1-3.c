// 1 завдання
#include <stdio.h>
#include <math.h> // Для функцій sqrt і log

int main() {
    // Вираз 1
    int result1 = 2 + 31;
    printf("2 + 31 = %d\n", result1);

    // Вираз 2
    int result2 = 45 * 54 - 11;
    printf("45 * 54 - 11 = %d\n", result2);

    // Вираз 3
    float result3 = 15 / 4.0;
    printf("15 / 4 = %f\n", result3);

    // Вираз 4
    float result4 = 15.0 / 4;
    printf("15.0 / 4 = %f\n", result4);

    // Вираз 5
    int result5 = 67 % 5;
    printf("67 %% 5 = %d\n", result5);

    // Вираз 6
    float result6 = (2 * 45.1 + 3.2) / 2;
    printf("(2 * 45.1 + 3.2) / 2 = %f\n", result6);

    // 2 завдання

    // Ініціалізація чисел
    float num1 = 10e-4f; // Дійсне число
    double num2 = 24.33E5; // Подвійне дійсне число
    double pi = 3.141592653589793; // Подвійне дійсне число
    long double e = 2.718281828459045L; // Довге дійсне число
    long double sqrt5 = sqrtl(5); // Корінь з 5 (довге дійсне число)
    long double ln100 = logl(100); // Логарифм з основою e від 100 (довге дійсне число)

    printf("10^-4 (float) = %.2f\n", num1);
    printf("24.33E5 (double) = %.2f\n", num2);
    printf("pi (double) = %.2f\n", pi);
    printf("e (long double) = %.2Lf\n", e);
    printf("sqrt(5) (long double) = %.2Lf\n", sqrt5);
    printf("ln(100) (long double) = %.2Lf\n", ln100);

    // 3 завдання

    char a;

    printf("Enter a number: ");
    scanf("%c", &a);

    printf("- %c - %c - %c\n", a, a, a);
    printf("%c | %c | %c\n", a, a, a);
    printf("- %c - %c - %c\n", a, a, a);

}