// Робота з потоками введення/виведення
// С++

// Домашнє завдання 12 12.17

// 17) У текстовому файлі кожний рядок містить кілька натуральних чисел, які розділяються пропусками. 
// Числа визначають вигляд геометричної фігури (номер) та її розміри. 
// Прийнято такі домовленості:

// • відрізок прямої задається координатами своїх кінців і має номер 1;

// • прямокутник задається координатами верхнього лівого й нижнього правого кутів і має номер 2;

// • коло задається координатами центра й радіусом і має номер 3.

// Визначити процедури обчислення:

// відрізка з найбільшою довжиною;
// прямокутника з найбільшим периметром;
// кола з найменшою площею.


#include <iostream>
#include <fstream>  // бібліотека надає функціонал для роботи з файлами
#include <sstream>  // бібліотека надає функціонал для роботи з рядками як з потоками
#include <cmath>
#include <limits>
using namespace std;

// обчислення відстані між двома точками (x1, y1) і (x2, y2)
double calculateLineLength(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// обчислення периметра прямокутника з вершинами (x1, y1) і (x2, y2)
double calculateRectanglePerimeter(int x1, int y1, int x2, int y2) {
    return 2 * (abs(x2 - x1) + abs(y2 - y1));
}

// обчислення площі кола з центром (x, y) і радіусом r
double calculateCircleArea(int r) {
    return M_PI * r * r;
}

int main() {
    ifstream inputFile("shapes.txt");
    
    if (!inputFile) {
        cout << "error: cannot open file" << endl;
        return 1;
    }

    double maxLineLength = 0;                  // max довжина відрізка
    double maxRectanglePerimeter = 0;           // max периметр прямокутника
    double minCircleArea = numeric_limits<double>::max(); // min площа кола

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int shapeType;
        ss >> shapeType;

        if (shapeType == 1) { // відрізок
            int x1, y1, x2, y2;
            ss >> x1 >> y1 >> x2 >> y2;
            double length = calculateLineLength(x1, y1, x2, y2);
            if (length > maxLineLength) {
                maxLineLength = length;
            }
        } else if (shapeType == 2) { // прямокутник
            int x1, y1, x2, y2;
            ss >> x1 >> y1 >> x2 >> y2;
            double perimeter = calculateRectanglePerimeter(x1, y1, x2, y2);
            if (perimeter > maxRectanglePerimeter) {
                maxRectanglePerimeter = perimeter;
            }
        } else if (shapeType == 3) { // коло
            int x, y, r;
            ss >> x >> y >> r;
            double area = calculateCircleArea(r);
            if (area < minCircleArea) {
                minCircleArea = area;
            }
        }
    }

    inputFile.close();

    cout << "The longest line segment length: " << maxLineLength << endl;
    cout << "The rectangle with the largest perimeter: " << maxRectanglePerimeter << endl;
    cout << "The circle with the smallest area: " << minCircleArea << endl;

    return 0;
}