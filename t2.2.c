// Завдання 2.2

#include<stdio.h>
#include<math.h>

int main() {
    double a, b, c;
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    if (a>0 && b>0)
    {
        c = sqrt(a*a + b*b);
        printf("c = %.3lf", c);
    }
    else {
        printf("Incorrectly entered values!");
    }
}