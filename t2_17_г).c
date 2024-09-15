// Завдання 2.17 г)

// Напишіть власні функції, що обчислюють наступні вирази та відповідні власні функції,
// що будуть рахувати похідні даних функцій
// Приклад:
// f(x) = identity(x) = x, її похідна g(x) = identity_derivative(x) = 1)

// г) f(x) = arctg(x) = tg^(-1) (x)

#include <stdio.h>
#include <math.h>

// Функція обчислення арктангенса
double arctan(double x) {
    return atan(x);
}

// Похідна арктангенса
double arctan_derivative(double x) {
    // Похідна арктангенса: 1 / (1 + x^2)
    return 1.0 / (1.0 + x * x);
}

int main() {
    // Діапазон для обчислень
    double x;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    double f = arctan(x);
    double df = arctan_derivative(x);

    printf("arctg(%.2lf) = %.5lf\n", x, f);
    printf("derivative arctg(%.2lf) = %.5lf\n", x, df);
}