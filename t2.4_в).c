// Завдання 2.4 в) перероблений.
// y = x5 + 5x4 + 10x3 + 10x2 + 5x + 1

//#include <stdio.h>

//double evaluatePolynomial(double x) {
    // Використання схеми Горнера для мінімізації операцій
    // z1 = x + 5
    // z2 = z1 * x + 10
    // z3 = z2 * x +10
    // z4 = z3 * x + 5
    // y = z4 * x + 1

    //return (((((x + 5) * x + 10) * x + 10) * x + 5) * x + 1);
//}

//int main() {
    //double x;
    //printf("Enter the value of x: ");
    //scanf("%lf", &x);

    //double result = evaluatePolynomial(x);
    //printf("The value of the polynomial: %lf\n", result);

    //return 0;
//}

#include <stdio.h>

double evaluatePolynomial(double x) {
    return (((((x + 5) * x + 10) * x + 10) * x + 5) * x + 1);
}

int main() {
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    double result = evaluatePolynomial(x);
    printf("The value of the polynomial: %lf\n", result);

    return 0;
}
