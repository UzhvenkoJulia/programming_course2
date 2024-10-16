// Динамічні масиви. Робота з вказівниками

// Домашнє завдання 9
// 9.7

#include <stdio.h>
#include <stdlib.h>

int count_powers_of_two(long num) {
    int count = 0;
    while (num % 2 == 0 && num > 0) {
        num /= 2;
        count++;
    }
    return count;
}

int count_powers_of_three(long num) {
    int count = 0;
    while (num % 3 == 0 && num > 0) {
        num /= 3;
        count++;
    }
    return count;
}

int main() {
    int n;

    printf("Enter a natural number n: ");
    scanf("%d", &n);

    // динамічне виділення пам'яті для масиву з n елементів
    long *array = (long *)malloc(n * sizeof(long));
    if (array == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    printf("Enter %d natural numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%ld", &array[i]);
    }

    for (int i = 0; i < n; i++) {
        int power_of_two = count_powers_of_two(array[i]);
        int power_of_three = count_powers_of_three(array[i]);
        printf("Number %ld: power of two = %d, power of three = %d\n", array[i], power_of_two, power_of_three);
    }

    free(array);

}