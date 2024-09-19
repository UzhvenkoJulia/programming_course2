// 8 завдання

#include <stdio.h>

int main() {
    int n = 5;  // кількість чисел у кожному ряді (можна змінити)
    double sum1 = 0, sum2 = 0, num;

    // Введення першого ряду дійсних чисел
    printf("Enter %d numbers of the first row:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &num);
        sum1 += num;  // підрахунок суми першого ряду
    }

    // Введення другого ряду дійсних чисел
    printf("Enter %d numbers of the second row:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &num);
        sum2 += num;  // підрахунок суми другого ряду
    }

    double diff = sum1 - sum2;

    double avg1 = sum1 / n;
    double avg2 = sum2 / n;

    printf("The difference in amounts: %.2lf\n", diff);
    printf("Arithmetic average of the first row: %.2lf\n", avg1);
    printf("The arithmetic mean of the second row: %.2lf\n", avg2);
}
