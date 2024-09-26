// Домашнє завдання 5_5.16є
// Скласти програми наближеного обчислення суми усіх доданків,
// абсолютна величина яких не менше епсілон > 0:
// є) y = 1\1+x = 1-x+x2-x3+..., (|x| < 1) - сума ряду Тейлора

#include <stdio.h>
#include <math.h> // fabs() - обчислення абсолютної величини числа типу double

int main() {
    double x, epsilon;

    /*while (1) {
    printf("x (|x| < 1): ");
    scanf("%lf", &x);
    if (fabs(x) < 1) {
    break; // вихід з циклу, якщо умова виконується
    }
    printf("The value of x must be less than 1 in absolute value (|x| < 1)\n");
    }

    while (1) {
    printf("е (epsilon > 0): ");
    scanf("%lf", &epsilon);
    if (epsilon > 0) {
    break; 
    }
    printf("Epsilon must be a positive number (epsilon > 0)\n");
    }*/

    printf("Enter the value x (|x| < 1): ");
    scanf("%lf", &x);
    printf("Enter epsilon (epsilon > 0): ");
    scanf("%lf", &epsilon);

    if (fabs(x) >= 1) {
        printf("The value of x must be less than 1 in absolute value (|x| < 1)\n");
        return 1;
    }

    if (epsilon <= 0) {
        printf("Epsilon must be a positive number (epsilon > 0)\n");
        return 1;
    }

    double sum = 0.0;
    double term = 1.0; // перший член ряду
    int n = 0;

    // обчисл суми ряду
    while (fabs(term) >= epsilon) {
        sum += term;
        n++; // збільш лічильник
        term = pow(-x, n); // обчисл наступний член (-x^n)
    }

    printf("The sum of the series for x = %.6f, epsilon = %.6f: y = %.6f\n", x, epsilon, sum);
}