/*Робота з valarray
Project number 11
It was made by Uzhvenko Yuliia 
Computer Mathematics/ group 1/ 2 curs
Email: uzhvenkojulia@knu.ua
Date 02.12.2024 */

/*#include <iostream>
#include <cassert>
#include "N11.cpp"  // Підключаємо реалізацію класів SVector та SMatrix

// Тестування для SVector
void testSVector() {
    // Створення вектора
    SVector v;
    v.add(0, 5.0);
    v.add(2, 10.0);
    v.add(3, -3.0);

    // Тест: Вивести значення вектора
    std::cout << "Testing SVector:\n";
    v.print();
    std::cout << "Expected: \nIndex: 0, Value: 5.0\nIndex: 2, Value: 10.0\nIndex: 3, Value: -3.0\n";
    
    // Тест: Додавання векторів
    SVector v2;
    v2.add(0, 1.0);
    v2.add(1, 2.0);
    SVector result = v.add(v2);
    
    std::cout << "Testing addition of SVector v and v2:\n";
    result.print();
    std::cout << "Expected: \nIndex: 0, Value: 6.0\nIndex: 1, Value: 2.0\nIndex: 2, Value: 10.0\nIndex: 3, Value: -3.0\n";
    
    // Тест: Множення вектора на скаляр
    SVector result2 = v.multiply(2.0);
    std::cout << "Testing multiplication of SVector v by 2:\n";
    result2.print();
    std::cout << "Expected: \nIndex: 0, Value: 10.0\nIndex: 2, Value: 20.0\nIndex: 3, Value: -6.0\n";
}

// Тестування для SMatrix
void testSMatrix() {
    // Створення матриці
    SMatrix m;
    m.add(0, 0, 1.0);
    m.add(0, 1, 2.0);
    m.add(1, 0, 3.0);
    m.add(1, 1, 4.0);
    
    // Тест: Вивести матрицю
    std::cout << "Testing SMatrix:\n";
    m.print();
    std::cout << "Expected:\n1 2\n3 4\n";

    // Тест: Додавання матриць
    SMatrix m2;
    m2.add(0, 0, 5.0);
    m2.add(0, 1, -2.0);
    m2.add(1, 0, -1.0);
    m2.add(1, 1, 3.0);
    
    SMatrix result = m.add(m2);
    std::cout << "Testing addition of SMatrix m and m2:\n";
    result.print();
    std::cout << "Expected:\n6 0\n2 7\n";
    
    // Тест: Множення матриць
    SMatrix m3;
    m3.add(0, 0, 1.0);
    m3.add(0, 1, 0.0);
    m3.add(1, 0, 0.0);
    m3.add(1, 1, 1.0);
    
    SMatrix result2 = m.multiply(m3);
    std::cout << "Testing multiplication of SMatrix m and identity matrix:\n";
    result2.print();
    std::cout << "Expected:\n1 2\n3 4\n";
    
    // Тест: Обчислення детермінанту
    double det = m.det();
    std::cout << "Testing determinant of matrix m: " << det << "\n";
    std::cout << "Expected: 4.0\n";
    
    // Тест: Обчислення оберненої матриці
    try {
        SMatrix inv = m.inverse();
        std::cout << "Testing inverse of matrix m:\n";
        inv.print();
        std::cout << "Expected:\n4 -2\n-3 1\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// Виконання тестів без main
namespace {
    // Викликається при запуску програми
    struct TestRunner {
        TestRunner() {
            testSVector();
            testSMatrix();
        }
    };
    
    // Об'єкт для автоматичного запуску тестів
    TestRunner runner;
}*/



#include "N11(cpp).h"    // Підключення заголовочного файлу для основних класів і функцій
#include <chrono>        // Для роботи з часовими вимірюваннями
#include <iostream>      // Для виводу даних у консоль
#include <fstream>       // Для роботи з файлами
#include <string>        // Для роботи з рядками

// Функція для вимірювання часу виконання функцій
template<typename Func, typename... Args> // Використання шаблону для прийому будь-якої функції та її аргументів
/*typename... Args:
Args — це пакет шаблонних параметрів (template parameter pack).
... позначає, що Args може включати довільну кількість типів.
Цей механізм дозволяє створювати функції, які приймають довільну кількість аргументів різних типів.*/
void measureExecutionTime(const std::string& functionName, Func func, Args&&... args) {
    // Початок вимірювання часу
    auto start = std::chrono::high_resolution_clock::now();
    // Виклик переданої функції з аргументами
    func(std::forward<Args>(args)...);
    // Кінець вимірювання часу
    auto end = std::chrono::high_resolution_clock::now();
    // Обчислення тривалості виконання у секундах
    std::chrono::duration<double> elapsed = end - start;
    // Виведення часу виконання у консоль
    std::cout << functionName << " executed in " << elapsed.count() << " seconds.\n";
}

int main() {
    int rows = 3, cols = 3;
    SMatrix mat = createMatrix(rows, cols);
    SVector vec = createVector(cols);

    std::cout << "Choose input mode (1 for console, 2 for file): ";
    int inputMode;
    std::cin >> inputMode;

    if (inputMode == 1) {
        inputMatrix(mat, rows, cols);
        inputVector(vec, cols);
    } else if (inputMode == 2) {
        loadMatrixFromFile(mat, "N11_test.dat");
        loadVectorFromFile(vec, "N11_test_vector.dat");  // Припускаємо, що вектор зберігається у окремому файлі
    } else {
        std::cerr << "Invalid input mode selected\n";
        return 1;
    }

    std::cout << "Matrix:\n";
    printMatrix(mat, 3); // Виведення матриці з точністю до 3 знаків після коми

    std::cout << "Vector:\n";
    printVector(vec, 3); // Виведення вектора з точністю до 3 знаків після коми

    // Тест обчислення детермінанту
    measureExecutionTime("Determinant Calculation", [&]() {
        double det = determinant(mat);
        std::cout << "Determinant: " << det << "\n";
    });

    // Тест обчислення оберненої матриці
    measureExecutionTime("Matrix Inversion", [&]() {
        SMatrix invMat = inverse(mat);
        std::cout << "Inverse Matrix:\n";
        printMatrix(invMat, 3);
    });

    // Тест розв'язку системи рівнянь
    measureExecutionTime("Solving System of Equations", [&]() {
        SVector solution = solve(mat, vec);
        std::cout << "Solution Vector:\n";
        printVector(solution, 3);
    });

    // Тест операції згортки
    SMatrix kernel = createMatrix(2, 2);  // Визначення зразка ядра 2x2
    kernel[0][0] = 1; kernel[0][1] = 0;
    kernel[1][0] = 0; kernel[1][1] = -1;
 
    // Вимірювання часу виконання операції згортки
    SMatrix convOutput;
    measureExecutionTime("Convolution Operation", [&]() {
        // Лямбда-функція, яка виконує операцію згортки
        /*Передає матриці mat (вхідна матриця) і kernel (ядро згортки) у функцію convolve.*/
        convolve(mat, kernel, convOutput);
        std::cout << "Convolution Result:\n";
        printMatrix(convOutput, 3);
    });

    // Тест збереження матриці у файл
    saveMatrixToFile(mat, "matrix_output.txt");
    std::cout << "Matrix saved to matrix_output.txt.\n";

    // Тест збереження вектора у файл
    saveVectorToFile(vec, "vector_output.txt");
    std::cout << "Vector saved to vector_output.txt.\n";

    return 0;
}