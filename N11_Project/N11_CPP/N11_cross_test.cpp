/*Робота з valarray
Project number 11
It was made by Uzhvenko Yuliia 
Computer Mathematics/ group 1/ 2 curs
Email: uzhvenkojulia@knu.ua
Date 02.12.2024 */

/*#include "N11(cpp).h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>

// Функція для запуску тестів
void runTests() {
    int rows = 3, cols = 3;
    
    // Створення та ініціалізація матриць
    SMatrix mat1 = createMatrix(rows, cols);
    SMatrix mat2 = createMatrix(rows, cols);
    inputMatrix(mat1, rows, cols);
    inputMatrix(mat2, rows, cols);

    // Виведення введених матриць
    std::cout << "Matrix 1:\n";
    printMatrix(mat1, 2);
    std::cout << "Matrix 2:\n";
    printMatrix(mat2, 2);

    // Тестування детермінанту
    double det1 = determinant(mat1);
    double det2 = determinant(mat2);
    std::cout << "Determinant of Matrix 1: " << det1 << "\n";
    std::cout << "Determinant of Matrix 2: " << det2 << "\n";

    // Тестування оберненої матриці
    SMatrix invMat1 = inverse(mat1);
    SMatrix invMat2 = inverse(mat2);
    std::cout << "Inverse of Matrix 1:\n";
    printMatrix(invMat1, 2);
    std::cout << "Inverse of Matrix 2:\n";
    printMatrix(invMat2, 2);

    // Створення векторів
    SVector vec1 = createVector(cols);
    SVector vec2 = createVector(cols);
    inputVector(vec1, cols);
    inputVector(vec2, cols);

    // Виведення векторів
    std::cout << "Vector 1:\n";
    printVector(vec1, 2);
    std::cout << "Vector 2:\n";
    printVector(vec2, 2);

    // Тестування рішення системи рівнянь
    SVector sol1 = solve(mat1, vec1);
    SVector sol2 = solve(mat2, vec2);
    std::cout << "Solution of system for Matrix 1 and Vector 1:\n";
    printVector(sol1, 2);
    std::cout << "Solution of system for Matrix 2 and Vector 2:\n";
    printVector(sol2, 2);

    // Порівняння матриць
    // Використовуємо функцію `compareMatrices` для перевірки еквівалентності двох матриць
    // Параметри:
    // - `mat1` і `mat2` — матриці для порівняння
    // - `0.01` — допустима похибка (tolerance)
    if (compareMatrices(mat1, mat2, 0.01)) {
        std::cout << "Matrix 1 and Matrix 2 are approximately equal\n";
    } else {
        std::cout << "Matrix 1 and Matrix 2 are different\n";
    }

    // Порівняння векторів
    if (compareVectors(vec1, vec2, 0.01)) {
        std::cout << "Vector 1 and Vector 2 are approximately equal\n";
    } else {
        std::cout << "Vector 1 and Vector 2 are different\n";
    }
}

// Функція для вимірювання часу виконання тестів
void measureExecutionTime() {
    auto start = std::chrono::high_resolution_clock::now();
    runTests();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Test execution time: " 
              << duration.count() << " seconds\n";
}

int main() {
    std::cout << "Cross-test between C and C++ implementations\n";

    // Запуск тестів і вимірювання часу
    measureExecutionTime();

    return 0;
}*/



#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring> // Додано для використання функції `strcspn`, яка дозволяє знаходити індекс першого входження будь-якого символу з заданого набору в рядку.

using namespace std;

void compare_programs() {
    // Відкриваємо два файли для порівняння (C та C++)
    FILE* fp_c = fopen("N11_test_output_c.txt", "r");
    FILE* fp_cpp = fopen("N11_test_output_cpp.txt", "r");

    /*Зміст файлів `N11_test_output_c.txt` та `N11_test_output_cpp.txt` повинен бути однаковим, якщо реалізації на C і C++ працюють коректно. 
Кожен рядок представляє результат виконання певної операції або виведення матриці/вектора.

Приклад вмісту файлів:

N11_test_output_c.txt:
Index: 0, Value: 5.0
Index: 2, Value: 10.0
Matrix:
1.0 2.0 3.0
4.0 5.0 6.0
7.0 8.0 9.0
Determinant: 0.0
Execution time: 0.0023 seconds

N11_test_output_cpp.txt:
Index: 0, Value: 5.0
Index: 2, Value: 10.0
Matrix:
1.0 2.0 3.0
4.0 5.0 6.0
7.0 8.0 9.0
Determinant: 0.0
Execution time: 0.0019 seconds

Коментарі:
1. Результати операцій з векторами/матрицями (наприклад, індекси та значення, матриці після операцій).
2. Виконання математичних функцій (наприклад, детермінант).
3. Час виконання операцій, якщо застосовується.

Файли мають бути однаковими за змістом (окрім можливих незначних відхилень у часі виконання) для підтвердження коректності реалізацій на обох мовах.*/


    if (fp_c == NULL || fp_cpp == NULL) {
        cerr << "Error opening one or both files" << endl;
        return;
    }

    // Змінні для зчитування рядків з файлів
    // `line_c` і `line_cpp` використовуються для збереження рядків, які зчитуються з двох файлів: одного з результатами на C, іншого — на C++.
    char line_c[1024], line_cpp[1024];

    // Лічильники для порівняння рядків
    // `line_number` відстежує номер рядка, що порівнюється, для виведення точного місця розбіжності.
    // `mismatch_found` вказує, чи була знайдена розбіжність між вмістом двох файлів.
    int line_number = 1;
    bool mismatch_found = false;

    // Читаємо файли по рядку та порівнюємо
    while (fgets(line_c, sizeof(line_c), fp_c) != NULL && fgets(line_cpp, sizeof(line_cpp), fp_cpp) != NULL) {
        // Очищаємо кінці рядків від символів нового рядка
        line_c[strcspn(line_c, "\n")] = '\0';
        line_cpp[strcspn(line_cpp, "\n")] = '\0';

        // Якщо рядки не збігаються, виводимо помилку
        if (string(line_c) != string(line_cpp)) {
            if (!mismatch_found) {
                cout << "Mismatch found" << endl;
                mismatch_found = true;
            }
            cout << "Line " << line_number << ":" << endl;
            cout << "C Output: " << line_c << endl;
            cout << "C++ Output: " << line_cpp << endl;
        }
        line_number++;
    }

    // Перевіряємо, чи не залишилися зайві рядки в одному з файлів
    if (fgets(line_c, sizeof(line_c), fp_c) != NULL || fgets(line_cpp, sizeof(line_cpp), fp_cpp) != NULL) {
        cout << "Files have different lengths" << endl;
    }

    // Якщо знайшли розбіжності, виводимо додаткову інформацію
    if (!mismatch_found) {
        cout << "The outputs match" << endl;
    }

    // Закриваємо файли
    fclose(fp_c);
    fclose(fp_cpp);
}

int main() {
    compare_programs();
    return 0;
}