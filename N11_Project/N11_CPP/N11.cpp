/*Робота з valarray
Project number 11
It was made by Uzhvenko Yuliia 
Computer Mathematics/ group 1/ 2 curs
Email: uzhvenkojulia@knu.ua
Date 02.12.2024 */

/*#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <stdexcept>
#include <valarray>
#include <chrono>

// Оголошення класу SVector
class SVector {
public:
    // Зберігає елементи вектора у вигляді пари "ключ-значення", де ключ — індекс, а значення — елемент вектора
    std::map<int, double> values;

    // Додає елемент до вектора за заданим індексом
    // Якщо значення не нульове, воно додається до map
    void add(int index, double value) {
        if (value != 0.0) { // Перевірка, щоб не додавати нульові значення
            values[index] = value; // Додаємо пару "індекс - значення"
        }
    }

    // Виводить елементи вектора на екран
    void print() const {
        // Проходимо по всіх елементах map і виводимо їх
        for (const auto& entry : values) {
            std::cout << "Index: " << entry.first << ", Value: " << entry.second << std::endl;
        }
    }

    // Записує елементи вектора у файл
    void writeToFile(std::ofstream& file) const {
        // Проходимо по всіх елементах map і записуємо їх у файл
        for (const auto& entry : values) {
            file << "Index: " << entry.first << ", Value: " << entry.second << std::endl;
        }
    }

    // Додає два вектора
    // Для кожного елементу з другого вектора додаємо його значення до відповідного елемента в першому векторі
    SVector add(const SVector& other) const {
        SVector result = *this; // Створюємо копію поточного вектора
        // Проходимо по кожному елементу з другого вектора і додаємо до результату
        for (const auto& entry : other.values) {
            result.add(entry.first, result.values[entry.first] + entry.second); // Оновлюємо значення
        }
        return result; // Повертаємо результат
    }

    // Множить вектор на скаляр
    SVector multiply(double scalar) const {
        SVector result; // Створюємо новий вектор для результату
        // Проходимо по всіх елементах вектора і множимо їх на скаляр
        for (const auto& entry : values) {
            result.add(entry.first, entry.second * scalar); // Додаємо результат до нового вектора
        }
        return result; // Повертаємо результат
    }
};

class SMatrix {
public:
    std::map<std::pair<int, int>, double> values;

    void add(int row, int col, double value) {
        if (value != 0.0) {
            values[{row, col}] = value;
        }
    }

    void print() const {
        int maxRow = 0, maxCol = 0;
        for (const auto& entry : values) {
            maxRow = std::max(maxRow, entry.first.first);
            maxCol = std::max(maxCol, entry.first.second);
        }

        for (int i = 0; i <= maxRow; ++i) {
            for (int j = 0; j <= maxCol; ++j) {
                auto it = values.find({i, j});
                if (it != values.end()) {
                    std::cout << std::setw(6) << it->second;
                } else {
                    std::cout << std::setw(6) << 0;
                }
            }
            std::cout << std::endl;
        }
    }

    void writeToFile(std::ofstream& file) const {
        int maxRow = 0, maxCol = 0;
        for (const auto& entry : values) {
            maxRow = std::max(maxRow, entry.first.first);
            maxCol = std::max(maxCol, entry.first.second);
        }

        // Проходимо по всіх рядках матриці
        for (int i = 0; i <= maxRow; ++i) {
        // Проходимо по всіх стовпцях матриці
            for (int j = 0; j <= maxCol; ++j) {
            // Шукаємо елемент в map за парою (i, j) (рядок, стовпець)
                auto it = values.find({i, j});
                if (it != values.end()) {
                    file << it->second << " ";
                } else {
                    file << 0 << " ";
                }
            }
            // Переходимо на новий рядок після кожного завершеного рядка матриці
            file << std::endl;
        }
    }

    SMatrix add(const SMatrix& other) const {
        // Створюємо копію поточної матриці як результат
        SMatrix result = *this;
        // Проходимо по всіх елементах матриці 'other'
        for (const auto& entry : other.values) {
        // Додаємо значення поточної матриці 'result' до відповідного елемента
        // Додаємо нове значення до елементу результату
            result.add(entry.first.first, entry.first.second, result.values[entry.first] + entry.second);
        }
        return result;
    }

    SMatrix multiply(const SMatrix& other) const {
        SMatrix result;
        for (const auto& entry1 : values) {
            for (const auto& entry2 : other.values) {
                if (entry1.first.second == entry2.first.first) {
                    result.add(entry1.first.first, entry2.first.second,
                               result.values[{entry1.first.first, entry2.first.second}] +
                               entry1.second * entry2.second);
                }
            }
        }
        return result;
    }

    double det() const {
        if (values.size() == 4) {
            auto a = values.at({0, 0}), b = values.at({0, 1}),
                 c = values.at({1, 0}), d = values.at({1, 1});
            return a * d - b * c;
        }
        else if (values.size() == 9) {
            auto a = values.at({0, 0}), b = values.at({0, 1}), c = values.at({0, 2}),
                 d = values.at({1, 0}), e = values.at({1, 1}), f = values.at({1, 2}),
                 g = values.at({2, 0}), h = values.at({2, 1}), i = values.at({2, 2});
            return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
        }
        return 0.0;
    }

    SMatrix inverse() const {
        double detValue = det();
        if (detValue == 0) {
            throw std::runtime_error("Matrix is singular and cannot be inverted");
        }

        SMatrix inv;
        if (values.size() == 4) {
            auto a = values.at({0, 0}), b = values.at({0, 1}),
                 c = values.at({1, 0}), d = values.at({1, 1});
            inv.add(0, 0, d / detValue);
            inv.add(0, 1, -b / detValue);
            inv.add(1, 0, -c / detValue);
            inv.add(1, 1, a / detValue);
        }
        return inv;
    }
};

void readMatrixFromFile(const std::string& filename, SMatrix& matrix) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return;
    }

    int rows, cols;
    file >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        std::cerr << "Invalid matrix dimensions in the file!" << std::endl;
        return;
    }

    double value;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file >> value;
            matrix.add(i, j, value);
        }
    }

    file.close();
}

void readVectorFromFile(const std::string& filename, SVector& vector) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return;
    }

    int numElements;
    file >> numElements;

    if (numElements <= 0) {
        std::cerr << "Invalid number of elements in the file!" << std::endl;
        return;
    }

    int index;
    double value;
    for (int i = 0; i < numElements; ++i) {
        file >> index >> value;
        vector.add(index, value);
    }

    file.close();
}

void writeToFile(const std::string& filename, const SMatrix& matrix, const SVector& vector, double determinant, const SMatrix& inverseMatrix) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file for writing!" << std::endl;
        return;
    }

    // Запис матриці
    file << "Matrix:\n";
    matrix.writeToFile(file);

    // Запис вектора
    file << "\nVector:\n";
    vector.writeToFile(file);

    // Запис детермінанту
    file << "\nDeterminant: " << determinant << "\n";

    // Запис оберненої матриці
    file << "\nInverse Matrix:\n";
    inverseMatrix.writeToFile(file);

    file.close();
    std::cout << "Results have been written to " << filename << std::endl; // додаткове повідомлення
}

int main() {
    int inputMethod;
    std::cout << "Choose input method (1 - Console, 2 - File): ";
    std::cin >> inputMethod;

    SMatrix matrix;
    SVector vector;

    if (inputMethod == 1) {
        // Введення через консоль
        int rows, cols;
        std::cout << "Input Matrix:\nEnter number of rows and columns: ";
        std::cin >> rows >> cols;

        std::cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                double value;
                std::cin >> value;
                matrix.add(i, j, value);
            }
        }

        std::cout << "Matrix:\n";
        matrix.print();

        int numElements;
        std::cout << "Input Vector:\nEnter number of elements in vector: ";
        std::cin >> numElements;

        std::cout << "Enter vector elements (index and value):\n";
        for (int i = 0; i < numElements; ++i) {
            int index;
            double value;
            std::cin >> index >> value;
            vector.add(index, value);
        }

        std::cout << "Vector:\n";
        vector.print();

    } else {
        // Введення з файлу
        std::string matrixFile, vectorFile;
        std::cout << "Enter matrix file name: ";
        std::cin >> matrixFile;
        readMatrixFromFile(matrixFile, matrix);

        std::cout << "Enter vector file name: ";
        std::cin >> vectorFile;
        readVectorFromFile(vectorFile, vector);
    }

    // Обчислення детермінанту та оберненої матриці
    try {
        double determinant = matrix.det();
        SMatrix inverseMatrix = matrix.inverse();

        // Запит назви файлу для зберігання результатів
        std::string outputFile;
        std::cout << "Enter output file name to save the results: ";
        std::cin >> outputFile;

        // Запис результатів у файл
        writeToFile(outputFile, matrix, vector, determinant, inverseMatrix);
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}*/



#include "N11(cpp).h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>  // Для форматування виводу

// Функція для створення матриці заданого розміру
SMatrix createMatrix(int rows, int cols) {
    SMatrix mat(SVector(0.0, cols), rows);  // Створення матриці розміру rows x cols
    return mat;
}

// Функція для створення вектора заданого розміру
SVector createVector(int size) {
    return SVector(0.0, size);  // Створення вектора розміру size
}

// Функція для введення матриці з консолі
void inputMatrix(SMatrix& mat, int rows, int cols) {
    std::cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> mat[i][j];
        }
    }
}

// Функція для введення вектора з консолі
void inputVector(SVector& vec, int size) {
    std::cout << "Enter the elements of the vector (" << size << "):\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> vec[i];
    }
}

// Функція для виведення матриці на консоль
void printMatrix(const SMatrix& mat, int precision) {
    std::cout << std::fixed << std::setprecision(precision);  // Встановлюємо точність виведення
    for (const auto& row : mat) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

// Функція для виведення вектора на консоль
void printVector(const SVector& vec, int precision) {
    std::cout << std::fixed << std::setprecision(precision);  // Встановлюємо точність виведення
    for (double val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// Функція для обчислення детермінанту матриці
double determinant(const SMatrix& mat) {
    if (mat.size() == 2) {
        // Детермінант для матриці 2x2
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }
    // Для більших матриць можна реалізувати рекурсивний алгоритм чи використати бібліотеку
    return 0.0; // Тимчасовий варіант для більш складних матриць
}
/* Для більших матриць можна скористатися бібліотекою
       Наприклад, використаємо бібліотеку для лінійної алгебри, 
       таку як <Eigen> або <armadillo>, яка надає зручні функції для обчислення детермінанту. */

    /*
    #include <Eigen/Dense>
    using namespace Eigen;
    
    // Перетворюємо нашу матрицю SMatrix у формат, що підтримується бібліотекою Eigen
    MatrixXd eigenMatrix(mat.size(), mat[0].size());
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            eigenMatrix(i, j) = mat[i][j];
        }
    }
    
    // Обчислюємо детермінант
    return eigenMatrix.determinant();
    */

// Функція для знаходження оберненої матриці
SMatrix inverse(const SMatrix& mat) {
    int n = mat.size();
    SMatrix invMat = createMatrix(n, n);
    // Просте обертання матриці 2x2
    if (n == 2) {
        double det = determinant(mat);
        if (det != 0) {
            invMat[0][0] = mat[1][1] / det;
            invMat[0][1] = -mat[0][1] / det;
            invMat[1][0] = -mat[1][0] / det;
            invMat[1][1] = mat[0][0] / det;
        }
    }
    return invMat;
}

// Функція для розв'язування системи рівнянь
SVector solve(const SMatrix& mat, const SVector& vec) {
    int n = mat.size();
    SVector solution = createVector(n);
    // Тимчасова реалізація (для складніших методів можна реалізувати елементи Гауса або інші методи)
    for (int i = 0; i < n; ++i) {
        solution[i] = vec[i]; // Тимчасове значення
    }
    return solution;
}

// Функція для виконання операції згортки
void convolve(const SMatrix& input, const SMatrix& kernel, SMatrix& output) {
    // Визначення розмірів вихідної матриці після згортки
    int rows = input.size() - kernel.size() + 1;        // К-сть рядків вихідної матриці
    int cols = input[0].size() - kernel[0].size() + 1;  // К-сть стовпців вихідної матриці
    
    // Створення вихідної матриці заданого розміру
    output = createMatrix(rows, cols);

    // Перебір кожного елемента вихідної матриці
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double sum = 0.0;  // Змінна для зберігання суми при згортці

            // Перебір елементів ядра (kernel)
            for (int ki = 0; ki < kernel.size(); ++ki) {
                for (int kj = 0; kj < kernel[ki].size(); ++kj) {
                    // Згортка: множення елементів матриці input на відповідні елементи ядра kernel
                    // і додавання до суми
                    sum += input[i + ki][j + kj] * kernel[ki][kj];
                }
            }
            // Присвоєння отриманого значення до відповідного елемента вихідної матриці
            output[i][j] = sum;
        }
    }
}

// Функція для збереження матриці у файл
void saveMatrixToFile(const SMatrix& mat, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Failed to open file for writing\n";
        return;
    }
    for (const auto& row : mat) {
        for (double val : row) {
            outFile << val << " ";
        }
        outFile << "\n";
    }
    outFile.close();
}

// Функція для завантаження матриці з файлу
void loadMatrixFromFile(SMatrix& mat, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Failed to open file for reading\n";
        return;
    }
    for (auto& row : mat) {
        for (double& val : row) {
            inFile >> val;
        }
    }
    inFile.close();
}

// Функція для збереження вектора у файл
void saveVectorToFile(const SVector& vec, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Failed to open file for writing\n";
        return;
    }
    for (double val : vec) {
        outFile << val << " ";
    }
    outFile << "\n";
    outFile.close();
}

// Функція для завантаження вектора з файлу
void loadVectorFromFile(SVector& vec, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Failed to open file for reading\n";
        return;
    }
    for (double& val : vec) {
        inFile >> val;
    }
    inFile.close();
}

// Функція для порівняння двох матриць з урахуванням точності
bool compareMatrices(const SMatrix& mat1, const SMatrix& mat2, double tolerance) {
    if (mat1.size() != mat2.size()) return false;
    for (size_t i = 0; i < mat1.size(); ++i) {
        for (size_t j = 0; j < mat1[i].size(); ++j) {
            if (std::abs(mat1[i][j] - mat2[i][j]) > tolerance) {
                return false;
            }
        }
    }
    return true;
}

// Функція для порівняння двох векторів з урахуванням точності
bool compareVectors(const SVector& vec1, const SVector& vec2, double tolerance) {
    if (vec1.size() != vec2.size()) return false;
    for (size_t i = 0; i < vec1.size(); ++i) {
        if (std::abs(vec1[i] - vec2[i]) > tolerance) {
            return false;
        }
    }
    return true;
}

// Функція для вимірювання часу виконання
void measureExecutionTime(void (*func)(), const std::string& functionName) {
    // Отримання поточного часу до виконання функції
    auto start = std::chrono::high_resolution_clock::now();

    // Виконання переданої функції
    func();

    // Отримання поточного часу після виконання функції
    auto end = std::chrono::high_resolution_clock::now();

    // Обчислення тривалості виконання функції
    std::chrono::duration<double> duration = end - start;

    // Виведення часу виконання функції
    std::cout << functionName << " execution time: " 
              << duration.count() << " seconds\n";
}