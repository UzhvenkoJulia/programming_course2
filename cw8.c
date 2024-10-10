#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 20
#define EPSILON 1e-6

#define MAX_M 25
#define MAX_N 25
#define MAX_LARGE 100

// вивед м
void print_matrix(int rows, int cols, double matrix[rows][cols], int is_integer) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (is_integer) {
                printf("%d ", (int)matrix[i][j]);
            } else {
                printf("%.2lf ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Завдання 1: Замінити всі M на N в цілій матриці
void task_1(int matrix[3][3], int N, int M) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == M) {
                matrix[i][j] = N;
            }
        }
    }
}

void test_task1() {
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {5, 8, 9}};
    task_1(matrix1, 0, 5);  // замінюємо 5 на 0

    int expected_matrix[3][3] = {{1, 2, 3}, {4, 0, 6}, {0, 8, 9}};
    int passed = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix1[i][j] != expected_matrix[i][j]) {
                passed = 0;
                break;
            }
        }
    }

    if (passed) {
        printf("Test1 for task1 passed successfully\n");
    } else {
        printf("Test1 for task1 failed\n");
    }
}

// 2: Замінити елемент з індексами [i][j] на значення a, в дійсній матриці
void task_2(double matrix[3][3], int i, int j, double a) {
    if (i >= 0 && i < 3 && j >= 0 && j < 3) {
        matrix[i][j] = a;
    } else {
        printf("The index is out of bounds\n");
    }
}

void test_task2() {
    double matrix2[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    task_2(matrix2, 1, 1, 99.99); // замінюємо елемент [1][1] на 99.99
    if (fabs(matrix2[1][1] - 99.99) < 0.001) {
        printf("Test1 for task2 passed successfully\n");
    } else {
        printf("Test1 for task2 failed\n");
    }
}

// 3: Введення дійсної матриці розміром m x n з перевіркою обмеження на 20x20
void input_matrix(int m, int n, double matrix[m][n]) {
    if (m > 0 && m <= 20 && n > 0 && n <= 20) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("Enter an item [%d][%d]: ", i, j);
                scanf("%lf", &matrix[i][j]);
            }
        }
    } else {
        printf("m and n should be between 1 and 20!\n");
    }
}

void test_task3() {
    int m = 3, n = 3;
    double matrix[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    double expected[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

    int passed = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (fabs(matrix[i][j] - expected[i][j]) > 0.001) {
                passed = 0;
                break;
            }
        }
    }

    if (passed) {
        printf("Test1 for task3 passed successfully\n");
    } else {
        printf("Test1 for task3 failed\n");
    }
}

// 4: Введення матриці розміром m x n (до 25x25) рядок за рядком

/*unsigned m, n;
    printf("Enter m and n : \n");
    scanf("%u %u", &m, &n);
    double matrix[m][n];
    for(int i = 0; i < m; i++) {
        printf("matrix[%d]: \n", i);
        for(int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%.0lf ", matrix[i][j]);
        }
        printf("\n");
    }*/

void task_4(int m, int n, double **matrix) {
    if (m > 0 && m <= MAX_M && n > 0 && n <= MAX_N) {
        for (int i = 0; i < m; i++) {
            printf("matrix[%d]: ", i);
            for (int j = 0; j < n; j++) {
                scanf("%lf", &matrix[i][j]);
            }
        }
    } else {
        printf("m and n should be between 1 and %d!\n", MAX_M);
    }
}

/*void task_4(int m, int n, double matrix[m][n]) {
    if (m > 0 && m <= MAX_M && n > 0 && n <= MAX_N) {
        for (int i = 0; i < m; i++) {
            printf("matrix[%d]: ", i);
            for (int j = 0; j < n; j++) {
                scanf("%lf", &matrix[i][j]);
            }
        }
    } else {
        printf("m and n should be between 1 and %d!\n", MAX_M);
    }
}*/

void test_task4() {
    int m = 2, n = 2;
    double matrix4[2][2] = {{1.1, 2.2}, {3.3, 4.4}};
    double expected_matrix[2][2] = {{1.1, 2.2}, {3.3, 4.4}};

    int passed = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (fabs(matrix4[i][j] - expected_matrix[i][j]) > 0.001) {
                passed = 0;
                break;
            }
        }
    }

    if (passed) {
        printf("Test1 for task4 passed successfully\n");
    } else {
        printf("Test1 for task4 failed\n");
    }
}

// 5: Транспонування квадратної матриці
void transpose(int n, double matrix1[n][n], double matrix2[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix2[j][i] = matrix1[i][j];
        }
    }
}

void test_task5() {
    double matrix5[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double transpose_matrix[3][3];
    double expected_transpose[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};

    transpose(3, matrix5, transpose_matrix);

    int passed = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (fabs(transpose_matrix[i][j] - expected_transpose[i][j]) > 0.001) {
                passed = 0;
                break;
            }
        }
    }

    if (passed) {
        printf("Test1 for task5 passed successfully\n");
    } else {
        printf("Test1 for task5 failed\n");
    }
}

// 6: Сума елементів, де i - j = k
/*double sum_elements(int m, int n, double matrix[m][n], int k) {
    double sum = 0.0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i - j) == k) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}*/

void test_task6() {
    double matrix6[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double expected_sum = 15; // елементи головної діагоналі
    double sum = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i - j) == 0) {
                sum += matrix6[i][j];
            }
        }
    }

    if (fabs(sum - expected_sum) < 0.001) {
        printf("Test1 for task6 passed successfully\n");
    } else {
        printf("Test1 for task6 failed\n");
    }
}

// Допоміжна функція: Додавання рядків для методу Гауса
void row_sum(int m, double row1[m], double row2[m], double a) {
    for (int i = 0; i < m; i++) {
        row2[i] += row1[i] * a;
    }
}

// 7: Обчислення детермінанту квадратної матриці

void Gauss_method(int m, double matrix[m][m]) {
    for (int i = 1; i < m; i++) {
        for (int j = i; j < m; j++) {
            row_sum(m, matrix[i - 1], matrix[j], (-1) * matrix[j][i-1] / matrix[i-1][i-1]);
        }
    }
}

double determinant_gauss(int m, double matrix[m][m]) {
    double det = 1;
    Gauss_method(m, matrix);
    for (int i = 0; i < m; i++) {
        det *= matrix[i][i];
    }
    return det;
}

/*double determinant(int n, double matrix[n][n]) {
    double det = 0.0;
    // База рекурсії: детермінант 1x1
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {  // 2x2
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    for (int x = 0; x < n; x++) {  // n x n матриці
        // створюємо підматрицю для мінорів
        double submatrix[n-1][n-1];
        // формуємо підматрицю шляхом видалення 0-го рядка і x-го стовпця
        for (int i = 1; i < n; i++) {
            int sub_j = 0; // індекс для стовпців підматриці
            for (int j = 0; j < n; j++) {
                if (j != x) {
                    submatrix[i-1][sub_j] = matrix[i][j];
                    sub_j++;
                }
            }
        }
        // рекурсивне додавання до детермінанта з відповідним знаком
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(n - 1, submatrix);
    }
    return det;
}*/

void test_task7() {
    double matrix1[3][3] = {{1, 2, 3}, {0, 1, 4}, {5, 6, 0}};
    double det1 = determinant_gauss(3, matrix1);
    if (fabs(det1 - 1) < 0.001) {
        printf("Test1 for task7 passed successfully\n");
    } else {
        printf("Test1 for task7 failed\n");
    }

    double matrix2[2][2] = {{2, 3}, {1, 4}};
    double det2 = determinant_gauss(2, matrix2);
    if (fabs(det2 - 5) < 0.001) {
        printf("Test2 for task7 passed successfully\n");
    } else {
        printf("Test2 for task7 failed\n");
    }
}

int main() {
    int choice;
    printf("Select a task (1-7): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
            int N, M;
            printf("Task 1: Enter N and M: ");
            scanf("%d %d", &N, &M);
            task_1(matrix1, N, M);
            print_matrix(3, 3, (double (*)[3])matrix1, 1); // виводимо як цілу матрицю
            break;
        }

        case 2: {
            double matrix2[3][3] = {{1.0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
            int i, j;
            double a;
            printf("Task 2: Enter i, j and a: ");
            scanf("%d %d %lf", &i, &j, &a);
            task_2(matrix2, i, j, a);
            print_matrix(3, 3, matrix2, 0); // виводимо як дійсну матрицю
            break;
        }

        case 3: {
            int m, n;
            printf("Task 3: Enter m and n: ");
            scanf("%d %d", &m, &n);
            double matrix3[m][n];
            input_matrix(m, n, matrix3);
            print_matrix(m, n, matrix3, 0);
            break;
        }

        case 4: {
            int m, n;
            printf("Task 4: Enter m and n: ");
            scanf("%d %d", &m, &n);
            double **matrix4 = (double **)malloc(m * sizeof(double *));
            for (int i = 0; i < m; i++) {
                matrix4[i] = (double *)malloc(n * sizeof(double));
            }
            task_4(m, n, matrix4);
            print_matrix(m, n, (double (*)[n])matrix4, 0);

            for (int i = 0; i < m; i++) {
                free(matrix4[i]);
            }
            free(matrix4);
            break;
        }

        case 5: {
            double matrix5[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, matrix_transpose[3][3];
            transpose(3, matrix5, matrix_transpose);
            print_matrix(3, 3, matrix_transpose, 0);
            break;
        }

        case 6: {

            /*unsigned m, n;
            int k;
            printf("Enter number (i - j) = k: ");
            scanf("%d", &k);
            printf("Enter m and n: ");
            scanf("%u %u", &m, &n);
            double **matrix6 = (double **)malloc(m * sizeof(double *));
            for (int i = 0; i < m; i++) {
                matrix6[i] = (double *)malloc(n * sizeof(double));
            }
            for (int i = 0; i < m; i++) {
                printf("matrix[%d]: ", i);
                for (int j = 0; j < n; j++) {
                    scanf("%lf", &matrix6[i][j]);
                }
            }
            double sum = sum_elements(m, n, (double (*)[n])matrix6, k);
            printf("The sum is: %.2lf\n", sum);
            for (int i = 0; i < m; i++) {
                free(matrix6[i]);
            }
            free(matrix6);
            break;
        }*/

            unsigned m, n;
            int k;

            double sum = 0.0;

            printf("Enter number (i - j) = k: \n");
            scanf("%d", &k);
            printf("Enter m and n : \n");
            scanf("%u %u", &m, &n);

            double matrix[m][n];

            for(int i = 0; i < m; i++) {  // if (m <= MAX_LARGE && n <= MAX_LARGE)
                printf("matrix[%d]: \n", i);
                for(int j = 0; j < n; j++) {
                    scanf("%lf", &matrix[i][j]);
                }
            }
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if ((i - j) == k) {
                        sum += matrix[i][j];
                    }
                }
            }
            printf("The sum is: %.2lf\n", sum);  /*else {
            printf("m and n should be <= %d!\n", MAX_LARGE);*/
        }  // return sum;
        // }

        case 7: {
            unsigned m;
            printf("Task 7: Enter m: ");
            scanf("%u", &m);
            double matrix7[m][m];
            for (int i = 0; i < m; i++) {
                printf("matrix[%d]: ", i);
                for (int j = 0; j < m; j++) {
                    scanf("%lf", &matrix7[i][j]);
                }
            }
            double det = determinant_gauss(m, matrix7);
            printf("Determinant = %.2lf\n", det);
            break;
        }

        default:
            printf("Wrong choice of task\n");
        break;
    }

    return 0;
}
