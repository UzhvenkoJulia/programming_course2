#include <stdio.h>

// більш ефективне, швидке піднесення до степеня
double power(double x, int k) {
    double result = 1.0;
    while (k > 0) {
        if (k % 2 == 1) {
            result *= x;  // k непарне, множимо на x
        }
        x *= x;  // x до квадрата
        k /= 2;
    }
    return result;
}

// обчислення факторіалу з обмеженням на переповнення
double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
        if (fact > 1e16) { // факторіал занадто великий -> зупиняємося
            return fact;  // не обчисл надто великі значення
        }
    }
    return fact;
}

/*double calculate_term(double x, int k) {
double term = 1.0; // x^0 / 0! = 1
double current_power = 1.0; // x^0 = 1
double current_factorial = 1.0; // 0! = 1

// x^k / k! в одному циклі
for (int i = 1; i <= k; i++) {
current_power *= x;
current_factorial *= i;    // поступово * i (факторіал)
term = current_power / current_factorial;
}

return term;
}*/

// обчислення x_k = (x^k) / k!
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
