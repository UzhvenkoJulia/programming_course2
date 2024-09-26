// Домашнє завдання 5_5.11в
// Скласти програму для обчислення сум
// Sn = Σ n k=1 k!\ak, де a1=a2=1, ak=(ak-1) + ((ak-1) \ 2^k), k = 3,4,...

#include <stdio.h>

/*unsigned long long factorial(int n) { // обчислн факторіала
    if (n == 0 || n == 1) {
        return 1; // факторіал 0 та 1 = 1
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i; // обчислення факторіала
    }
    return result;
}*/

double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    }
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i; 
    }
    return result;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("n must be a natural number (n >= 1)\n");
        return 1;
    }

    // масив для зберігання значень a_k
    double a[100]; // можемо збільш, якщо що
    a[1] = 1.0;
    a[2] = 1.0;

    // обчислн знач a_k для k = 3, 4, ..., n
    for (int k = 3; k <= n; k++) {
        a[k] = a[k-1] + (a[k-1] / (1 << k)); // a[k] = a[k-1] + a[k-1] / 2^k
    }

    double S_n = 0.0;
    for (int k = 1; k <= n; k++) {
        S_n += (double)factorial(k) / a[k]; // + k! / a_k до суми
    }

    printf("S_%d = %.6f\n", n, S_n);
}