// 5 завдання (е)

/*  5a
int main() {
    double x, x_4;
    printf("x = ");
    scanf("%lf", & x);
    x_4= x * x;
    x_4 *= x_4;
    printf("(%lf)^4 = %lf", x, x_4);
}
*/

#include <stdio.h>

// Функція для піднесення до степеня через множення
double power64(double x) {
    double x2 = x * x;      // x^2
    double x4 = x2 * x2;    // x^4
    double x8 = x4 * x4;    // x^8
    double x16 = x8 * x8;   // x^16
    double x32 = x16 * x16; // x^32
    double x64 = x32 * x32; // x^64
    return x64;
}

int main() {
    double x;

    // Введення дійсного числа
    printf("Enter a real number x: ");
    scanf("%lf", &x);

    // Обчислення x^64
    printf("e) x^64 = %.2lf\n", power64(x));
}
