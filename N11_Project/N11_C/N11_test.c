/*Робота з valarray
Project number 11
It was made by Uzhvenko Yuliia 
Computer Mathematics/ group 1/ 2 curs
Email: uzhvenkojulia@knu.ua
Date 02.12.2024 */

#include "N11.h"
#include <stdio.h>
#include <stdlib.h>

// Тестування створення вектора
void test_create_vector() {
    printf("Test: Create Vector\n");
    Vector* vec = create_vector(5);  // Створюємо вектор з 5 елементів
    printf("Vector created with size %d\n", vec->size);
    free_vector(vec);
}
/*Коментар: 
1. При запуску тесту програма створює вектор розміру 5.
2. Очікуваний вивід:
   Test: Create Vector
   Vector created with size 5
3. Це лише тест на створення вектора, вводити дані не потрібно.*/

/* 
Для цього тесту потрібно створити файл:
vector_output.txt 
Приклад виведення:
1.000000
2.000000
3.000000
*/

// Тестування введення та виведення вектора
void test_input_output_vector() {
    printf("Test: Input and Output Vector\n");
    Vector* vec = create_vector(3);                       // Створюємо вектор з 3 елементів
    input_vector(vec);                                    // Вводимо значення для вектора з клавіатури
    output_vector(vec, "vector_output.txt");              // Виводимо вектор в файл
    printf("Vector data saved to vector_output.txt\n");
    free_vector(vec);
}
/*Коментар: 
1. Програма запитує у користувача значення для вектора з 3 елементів.
2. Користувач вводить 3 значення для вектора, наприклад: 
   1.0 2.0 3.0
3. Результат буде збережений у файл "vector_output.txt".
4. Очікуваний вивід:
   Test: Input and Output Vector
   Vector data saved to vector_output.txt
5. Перевірити, чи збережено вектор у файл.*/

/* 
Для цього тесту потрібно створити файл:
matrix_output.txt 
Приклад виведення:
1.000000  2.000000
3.000000  4.000000
*/

// Тестування створення матриці
void test_create_matrix() {
    printf("Test: Create Matrix\n");
    Matrix* mat = create_matrix(2, 3);  // Створюємо матрицю 2x3
    printf("Matrix created with size %d x %d\n", mat->rows, mat->cols);
    free_matrix(mat);
}
/*Коментар: 
1. Створюється матриця з розмірами 2x3.
2. Очікуваний вивід:
   Test: Create Matrix
   Matrix created with size 2 x 3
3. Тест перевіряє правильність створення матриці з заданими розмірами.*/

/* 
Для цього тесту потрібно створити файл:
matrix_output.txt 
Приклад виведення:
1.000000  2.000000
3.000000  4.000000
*/

// Тестування введення та виведення матриці
void test_input_output_matrix() {
    printf("Test: Input and Output Matrix\n");
    Matrix* mat = create_matrix(2, 2);                // Створюємо матрицю 2x2
    input_matrix(mat);                                // Вводимо елементи матриці з клавіатури
    output_matrix(mat, "matrix_output.txt");          // Виводимо матрицю у файл
    printf("Matrix data saved to matrix_output.txt\n");
    free_matrix(mat);
}
/*Коментар: 
1. Користувач вводить елементи для матриці розміру 2x2.
2. Вводимо, наприклад:
   1 2
   3 4
3. Результат зберігається в файл "matrix_output.txt".
4. Очікуваний вивід:
   Test: Input and Output Matrix
   Matrix data saved to matrix_output.txt*/

/* 
Для цього тесту потрібно створити файл:
addition_result.txt 
Приклад виведення:
6.000000  8.000000
10.000000 12.000000
*/

// Тестування додавання матриць
void test_add_matrices() {
    printf("Test: Add Matrices\n");
    Matrix* A = create_matrix(2, 2);
    Matrix* B = create_matrix(2, 2);

    // Заповнюємо матриці
    A->data[0][0] = 1; A->data[0][1] = 2; A->data[1][0] = 3; A->data[1][1] = 4;
    B->data[0][0] = 5; B->data[0][1] = 6; B->data[1][0] = 7; B->data[1][1] = 8;

    Matrix* result = add_matrices(A, B);

    if (result != NULL) {
        output_matrix(result, "addition_result.txt");
        printf("Matrix addition result saved to addition_result.txt\n");
        free_matrix(result);
    }

    free_matrix(A);
    free_matrix(B);
}
/*Коментар:
1. Додаємо дві матриці 2x2:
   Матриця A:
   1 2
   3 4
   
   Матриця B:
   5 6
   7 8
2. Результат додавання матриць:
   6 8
   10 12
3. Очікуваний вивід:
   Test: Add Matrices
   Matrix addition result saved to addition_result.txt*/

/* 
Для цього тесту потрібно створити файл:
multiplication_result.txt 
Приклад виведення:
58.000000  64.000000
139.000000  154.000000
*/

// Тестування множення матриць
void test_multiply_matrices() {
    printf("Test: Multiply Matrices\n");
    Matrix* A = create_matrix(2, 3);
    Matrix* B = create_matrix(3, 2);

    // Заповнюємо матриці
    A->data[0][0] = 1; A->data[0][1] = 2; A->data[0][2] = 3;
    A->data[1][0] = 4; A->data[1][1] = 5; A->data[1][2] = 6;
    
    B->data[0][0] = 7; B->data[0][1] = 8;
    B->data[1][0] = 9; B->data[1][1] = 10;
    B->data[2][0] = 11; B->data[2][1] = 12;

    Matrix* result = multiply_matrices(A, B);

    if (result != NULL) {
        output_matrix(result, "multiplication_result.txt");
        printf("Matrix multiplication result saved to multiplication_result.txt\n");
        free_matrix(result);
    }

    free_matrix(A);
    free_matrix(B);
}
/*Коментар:
1. Множимо матрицю A 2x3 на матрицю B 3x2:
   Матриця A:
   1 2 3
   4 5 6
   
   Матриця B:
   7 8
   9 10
   11 12
   
2. Результат множення:
   58 64
   139 154
3. Очікуваний вивід:
   Test: Multiply Matrices
   Matrix multiplication result saved to multiplication_result.txt*/

/* 
Для цього тесту потрібно створити файл:
inverse_result.txt 
Приклад виведення:
-2.000000  1.000000
1.500000  -0.500000
*/

// Тестування обчислення детермінанту
void test_determinant() {
    printf("Test: Determinant Calculation\n");
    Matrix* mat = create_matrix(2, 2);
    mat->data[0][0] = 1; mat->data[0][1] = 2;
    mat->data[1][0] = 3; mat->data[1][1] = 4;

    double det = determinant(mat);
    printf("Determinant of matrix: %lf\n", det);

    free_matrix(mat);
}
/*Коментар:
1. Вираховуємо детермінант для матриці 2x2:
   1 2
   3 4
2. Детемінант:
   det = (1 * 4) - (2 * 3) = -2
3. Очікуваний вивід:
   Test: Determinant Calculation
   Determinant of matrix: -2.000000*/

// Тестування обчислення оберненої матриці
void test_inverse() {
    printf("Test: Inverse Calculation\n");
    Matrix* mat = create_matrix(2, 2);
    mat->data[0][0] = 1; mat->data[0][1] = 2;
    mat->data[1][0] = 3; mat->data[1][1] = 4;

    Matrix* inv = inverse(mat);
    if (inv != NULL) {
        output_matrix(inv, "inverse_result.txt");
        printf("Inverse matrix result saved to inverse_result.txt\n");
        free_matrix(inv);
    }

    free_matrix(mat);
}
/*Коментар:
1. Обчислюємо обернену матрицю для 2x2 матриці:
   1 2
   3 4
2. Обернена матриця:
   -2 1
   1.5 -0.5
3. Очікуваний вивід:
   Test: Inverse Calculation
   Inverse matrix result saved to inverse_result.txt*/

/* 
Для цього тесту потрібно створити файл:
matrix_vector_multiplication_result.txt 
Приклад виведення:
14.000000
32.000000
*/

// Тестування множення матриці на вектор
void test_multiply_matrix_vector() {
    printf("Test: Multiply Matrix and Vector\n");
    Matrix* mat = create_matrix(2, 3);
    Vector* vec = create_vector(3);

    // Заповнюємо матрицю та вектор
    mat->data[0][0] = 1; mat->data[0][1] = 2; mat->data[0][2] = 3;
    mat->data[1][0] = 4; mat->data[1][1] = 5; mat->data[1][2] = 6;
    
    vec->data[0] = 1;
    vec->data[1] = 2;
    vec->data[2] = 3;

    Vector* result = multiply_matrix_vector(mat, vec);

    if (result != NULL) {
        output_vector(result, "matrix_vector_multiplication_result.txt");
        printf("Matrix-vector multiplication result saved to matrix_vector_multiplication_result.txt\n");
        free_vector(result);
    }

    free_matrix(mat);
    free_vector(vec);
}
/*Коментар:
1. Множимо матрицю 2x3 на вектор з 3 елементів.
2. Результат множення:
   14 32
3. Очікуваний вивід:
   Test: Multiply Matrix with Vector
   Matrix-Vector multiplication result saved to matrix_vector_multiplication_result.txt*/

/* 
Тестування зчитування даних з файлів:
Для тестування введення з файлів використовуйте файл N11_test.dat:
Приклад даних для вектора:
1
2
3

Приклад даних для матриці:
1 2
3 4
*/

/*int main() {
    test_create_vector();
    test_input_output_vector();
    test_create_matrix();
    test_input_output_matrix();
    test_add_matrices();
    test_multiply_matrices();
    test_determinant();
    test_inverse();
    test_multiply_matrix_vector();

    return 0;
}*/

/*## Usage:
1. Скомпілюйте код (файл N11_test.c) за допомогою:
- 1) gcc -o N11_test N11.c N11_test.c
2. Запустіть тестову програму:
- 2) ./N11_test*/