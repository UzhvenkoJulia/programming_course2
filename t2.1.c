// Завдання 2.1

#include<stdio.h>
#include<math.h>

int main() {
    double x, res;
    printf("x = ");
    scanf("%lf", &x);
    res = cos(x);
    printf("cos(%.3lf) = %.6lf", x, res);
}