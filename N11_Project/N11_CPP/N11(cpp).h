/*Робота з valarray
Project number 11
It was made by Uzhvenko Yuliia 
Computer Mathematics/ group 1/ 2 curs
Email: uzhvenkojulia@knu.ua
Date 02.12.2024 */

/*#ifndef N11_CPP_H
#define N11_CPP_H

#include <map> // "ключ-значення"
#include <valarray>
#include <iostream>

class SVector {
public:
    std::map<int, double> values;

    void add(int index, double value);
    void print() const;
    SVector add(const SVector& other) const;
    SVector multiply(double scalar) const;
};

class SMatrix {
public:
    std::map<std::pair<int, int>, double> values;

    void add(int row, int col, double value);
    void print() const;
    SMatrix add(const SMatrix& other) const;
    SMatrix multiply(const SMatrix& other) const;
    double det() const;
    SMatrix inverse() const;
};

void writeToFile(const std::string& filename, const SMatrix& matrix, const SVector& vector);
void readMatrixFromFile(const std::string& filename, SMatrix& matrix);
void readVectorFromFile(const std::string& filename, SVector& vector);

#endif // N11_CPP_H*/


#ifndef N11_CPP_H
#define N11_CPP_H

// #include <map>
#include <valarray>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>  // Для форматування виводу

// Типи для векторів та матриць
typedef std::valarray<double> SVector;
typedef std::valarray<SVector> SMatrix;

// Функції для створення та введення матриць та векторів
SMatrix createMatrix(int rows, int cols);
SVector createVector(int size);
void inputMatrix(SMatrix& mat, int rows, int cols);
void inputVector(SVector& vec, int size);

// Функції для виведення матриць та векторів
void printMatrix(const SMatrix& mat, int precision = 6);
void printVector(const SVector& vec, int precision = 6);

// Функції для матричних операцій
double determinant(const SMatrix& mat);
SMatrix inverse(const SMatrix& mat);
SVector solve(const SMatrix& mat, const SVector& vec);

// Функції для конволюції
void convolve(const SMatrix& input, const SMatrix& kernel, SMatrix& output);

// Функції для роботи з файлами
void saveMatrixToFile(const SMatrix& mat, const std::string& filename);
void loadMatrixFromFile(SMatrix& mat, const std::string& filename);
void saveVectorToFile(const SVector& vec, const std::string& filename);
void loadVectorFromFile(SVector& vec, const std::string& filename);

// Функції для порівняння результатів між C та C++ реалізаціями
// Без параметрів за замовчуванням в оголошеннях
bool compareMatrices(const SMatrix& mat1, const SMatrix& mat2, double tolerance);
bool compareVectors(const SVector& vec1, const SVector& vec2, double tolerance);

// Функція для вимірювання часу виконання
void measureExecutionTime(void (*func)(), const std::string& functionName);

#endif // N11_CPP_H

/*
# Основні типи:
- SVector: визначає вектор, використовуючи std::valarray<double>, що є зручним для обчислень, де елементи мають тип double.
- SMatrix: визначає матрицю як масив масивів типу SVector. Таким чином, це 2D-масив, де кожен елемент — це вектор, що зберігає значення в рядку матриці.

# Функції для роботи з матрицями та векторами:
1. createMatrix та createVector: створюють матриці та вектори відповідного розміру.
2. inputMatrix та inputVector: функції для введення значень матриць і векторів.
3. printMatrix та printVector: функції для виведення матриць і векторів на екран з параметром точності для форматування виводу.

# Матричні операції:
1. determinant: обчислює детермінант матриці.
2. inverse: обчислює обернену матрицю.
3. solve: вирішує систему лінійних рівнянь з матрицею коефіцієнтів та вектором правих частин.

# Функції для конволюції:
- convolve: здійснює операцію конволюції між вхідною матрицею та ядром.

# Робота з файлами:
1. saveMatrixToFile та saveVectorToFile: зберігають матрицю або вектор у файл.
2. loadMatrixFromFile та loadVectorFromFile: завантажують матрицю або вектор з файлу.

# Порівняння результатів:
- compareMatrices та compareVectors: функції для порівняння двох матриць або двох векторів з врахуванням заданого допуску (tolerance).

# Час виконання:
- measureExecutionTime: функція для вимірювання часу виконання функції.

# Приклад використання:
Приклад програми, що використовує ці функції:

(.cpp)
#include "N11.h"

int main() {
    // Створення матриці та вектора
    SMatrix mat = createMatrix(3, 3); // Створюємо матрицю розміру 3x3
    SVector vec = createVector(3);    // Створюємо вектор розміру 3

    // Заповнення матриці та вектора
    inputMatrix(mat, 3, 3); // Вводимо значення для матриці 3x3
    inputVector(vec, 3);    // Вводимо значення для вектора розміру 3

    // Виведення матриці та вектора
    printMatrix(mat); // Виводимо матрицю
    printVector(vec); // Виводимо вектор

    // Матричні операції
    double det = determinant(mat); // Обчислюємо детермінант матриці
    std::cout << "Determinant: " << det << std::endl;

    SMatrix inv = inverse(mat);   // Обчислюємо обернену матрицю
    printMatrix(inv); 

    // Рішення системи рівнянь
    SVector solution = solve(mat, vec); // Розв'язуємо систему лінійних рівнянь
    printVector(solution);

    // Збереження результату в файл
    saveMatrixToFile(mat, "matrix.txt"); // Зберігаємо матрицю у файл matrix.txt
    saveVectorToFile(vec, "vector.txt"); // Зберігаємо вектор у файл vector.txt

    return 0;

Приклад файлів:
matrix.txt — може містити матрицю, яку ви хочете зберегти, наприклад:
1 2 3
4 5 6
7 8 9

vector.txt — може містити вектор:
1
2
3

Додаткові функції:
measureExecutionTime може бути використана для вимірювання часу виконання будь-якої з функцій, 
щоб порівняти ефективність різних операцій. Наприклад:
measureExecutionTime([](){ solve(mat, vec); }, "Solving linear system");
}*/