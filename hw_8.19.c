// Статичні масиви. Багатовимірні масиви
// Домашнє завдання 8.19

// Дана цілочисельна матриця розміру m x n.
// Знайти елемент, який є максимальним у своєму рядку і мінімальним в совоєму стовпці.
// Якщо такий елемент відстутній, то вивести 0.

#include <stdio.h>

#define M 10  // макс к-сть рядків
#define N 10  // макс к-сть стовпців

// чи є елемент макс у своєму рядку?
int isMaxInRow(int matrix[M][N], int row, int col, int n) {
    for (int j = 0; j < n; j++) {
        if (matrix[row][j] > matrix[row][col]) {
            return 0;  // знайдено більший елемент
        }
    }
    return 1;  // елемент є макс у рядку
}

// чи є елемент мін у своєму стовпці?
int isMinInCol(int matrix[M][N], int row, int col, int m) {
    for (int i = 0; i < m; i++) {
        if (matrix[i][col] < matrix[row][col]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int matrix[M][N];
    int m, n;

    printf("the number of rows (m): ");
    scanf("%d", &m);
    printf("the number of columns (n): ");
    scanf("%d", &n);

    printf("the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int found = 0;  // змінна для перевірки, чи знайдено елемент
    int result = 0;

    for (int i = 0; i < m; i++) {  // пошук елемента, який є макс у рядку і мін у стовпці
        for (int j = 0; j < n; j++) {
            if (isMaxInRow(matrix, i, j, n) && isMinInCol(matrix, i, j, m)) {
                result = matrix[i][j];
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        printf("Item found: %d\n", result);
    } else {
        printf("Element not found, result: 0\n");
    }

}