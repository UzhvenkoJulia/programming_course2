// Домашнє завдання 7: 7.9б, 7.10е
// Статичні масиви. Лінійні масиви

// Програма для знаходження мінімального дійсного числа та кількості квадратів непарних цілих чисел

#include <stdio.h>
#include <math.h>

// знаходження мін дійсн ч з масиву
double find_min(double arr[], int n) {
    double min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// для підрахунку к-сті квадратів непарних ч у масиві
int count_odd_squares(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) { // чи є число непарним?
            int root = (int)sqrt(arr[i]);
            if (root * root == arr[i]) { // квадратом?
                printf("%d is the square of an odd number\n", arr[i]);
                count++;
            } else {
                printf("%d is odd but not a perfect square\n", arr[i]);
            }
        } else {
            printf("%d is an even number and is not considered\n", arr[i]);
        }
    }
    return count;
}

int main() {
    int n;

    // б)
    printf("Enter the number of real numbers n:\n");
    scanf("%d", &n);

    double real_numbers[n];
    printf("Enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &real_numbers[i]);
    }

    double min_value = find_min(real_numbers, n);
    printf("Minimum number: %.2lf\n", min_value);

    // е)
    printf("Enter the number of integers n:\n");
    scanf("%d", &n);

    int integers[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &integers[i]);
    }

    int odd_square_count = count_odd_squares(integers, n);
    printf("Number of squares of odd numbers: %d\n", odd_square_count);
    
}