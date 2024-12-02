/*Робота з valarray
Project number 11
It was made by Uzhvenko Yuliia 
Computer Mathematics/ group 1/ 2 curs
Email: uzhvenkojulia@knu.ua
Date 02.12.2024 */

/*Захист від багаторазового включення (include guard) у заголовковому файлі 
в мові C++ (та C). Запобігає повторному включенню одного й того ж заголовкового файлу 
в один і той самий файл перекладу, що може призводити до помилок компіляції.*/
#ifndef N11_H
#define N11_H

// Підключення усіх необхідних бібліотек для подальшої правильної роботи коду
#include <stdio.h>
#include <stdlib.h>

// Оголошення структур для векторів і матриць
typedef struct {
    int size;
    double* data; // data є вказівником на змінну або область пам'яті, де зберігається значення типу double
} Vector;

typedef struct {
    int rows;
    int cols;
    double** data;
} Matrix;

// Функції для роботи з векторами
Vector* create_vector(int size);                                 // Декларуємо функцію для створення вектора заданого розміру
void free_vector(Vector* vec);                                   // Декларуємо функцію для звільнення пам'яті, виділеної для вектора
void input_vector(Vector* vec);                                  // Введення даних у вектор (можливо, з клавіатури або іншого джерела)
void output_vector(Vector* vec, const char* filename);           // Запис даних з вектора у файл
void input_vector_from_file(Vector* vec, const char* filename);  // Заповнення вектора даними, зчитаними з файл
void output_vector_to_console(Vector* vec);                      // Виведення даних вектора на консоль

// Функції для роботи з матрицями
Matrix* create_matrix(int rows, int cols);                       // Декларуємо функцію для створення матриці заданого розміру (рядки та стовпці)
void free_matrix(Matrix* mat);                                   // Декларуємо функцію для звільнення пам'яті, виділеної для матриці
void input_matrix(Matrix* mat);                                  // Введення даних у матрицю (можливо, з клавіатури або іншого джерела)
void output_matrix(Matrix* mat, const char* filename);           // Запис даних з матриці у файл
void input_matrix_from_file(Matrix* mat, const char* filename);  // Заповнення матриці даними, зчитаними з файлу
void output_matrix_to_console(Matrix* mat);                      // Виведення даних матриці на консоль


// Операції з матрицями
Matrix* add_matrices(Matrix* A, Matrix* B);                      // Декларуємо функцію для додавання двох матриць A і B
Matrix* multiply_matrices(Matrix* A, Matrix* B);                 // Декларуємо функцію для множення двох матриць A і B
double determinant(Matrix* mat);                                 // Декларуємо функцію для обчислення детермінанту матриці
Matrix* inverse(Matrix* mat);                                    // Декларуємо функцію для обчислення оберненої матриці
Vector* multiply_matrix_vector(Matrix* mat, Vector* vec);        // Декларуємо функцію для множення матриці на вектор

#endif // N11_H (закриває директиву #ifndef)