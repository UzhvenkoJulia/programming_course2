#include <stdio.h>

// функція для обчислення факторіалу
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// функція для обчислення степеня x^k
double power(double x, int k) {
    double result = 1;
    for (int i = 0; i < k; i++) {
        result *= x;
    }
    return result;
}

// осн ф для обчислення x_k = (x^k) / k!
double calculate_term(double x, int k) {
    return power(x, k) / factorial(k);
}

int main() {
    double x;
    int k;

    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the k value: ");
    scanf("%d", &k);

    double result = calculate_term(x, k);
    printf("x_%d = %lf\n", k, result);
}