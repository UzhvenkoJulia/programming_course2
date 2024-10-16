// Динамічні масиви. Робота з вказівниками

// Домашнє завдання 9
// 9.9т

#include <stdio.h>
#include <stdlib.h>

// N -  к-сть рядків
// M - к-сть стовпців

// двовимірн масив
void inputMatrix(float **matrix, int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }
}

void printMatrix(float **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// додавання рядка після кожного парного рядка
float **addRowAfterEvenRows(float **matrix, int *rows, int cols) {
    int newRows = *rows + (*rows / 2);  // к-сть нових рядків
    float **newMatrix = (float **)malloc(newRows * sizeof(float *));
    if (newMatrix == NULL) {
        printf("Memory allocation error\n");
        return NULL;
    }

    int newRowIdx = 0;
    for (int i = 0; i < *rows; i++) {
        newMatrix[newRowIdx] = matrix[i];
        newRowIdx++;
        if ((i + 1) % 2 == 0) {
            newMatrix[newRowIdx] = (float *)calloc(cols, sizeof(float));
            if (newMatrix[newRowIdx] == NULL) {
                printf("Memory allocation error\n");
                return NULL;
            }
            newRowIdx++;
        }
    }

    *rows = newRows;
    return newMatrix;
}

int main() {
    int N, M;

    printf("Enter the number of rows (N): ");
    scanf("%d", &N);
    printf("Enter the number of columns (M): ");
    scanf("%d", &M);

    float **matrix = (float **)malloc(N * sizeof(float *));
    if (matrix == NULL) {
        printf("ПMemory allocation error\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        matrix[i] = (float *)malloc(M * sizeof(float));
        if (matrix[i] == NULL) {
            printf("Error allocating memory for row %d\n", i);
            return 1;
        }
    }

    inputMatrix(matrix, N, M);
    printf("Initial matrix:\n");

    printMatrix(matrix, N, M);
    matrix = addRowAfterEvenRows(matrix, &N, M);

    if (matrix == NULL) {
        return 1;
    }

    printf("Matrix after adding rows:\n");
    printMatrix(matrix, N, M);

    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
}