#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    ifstream file("input_1.txt");
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        int shapeType;
        iss >> shapeType;

        if (shapeType == 1) {
            // Відрізок
            double x1, y1, x2, y2;
            iss >> x1 >> y1 >> x2 >> y2;
            // Обчислити довжину відрізка
        } else if (shapeType == 2) {
            // Прямокутник
            double x1, y1, x2, y2;
            iss >> x1 >> y1 >> x2 >> y2;
            // Обчислити периметр прямокутника
        } else if (shapeType == 3) {
            // Коло
            double x, y, r;
            iss >> x >> y >> r;
            // Обчислити площу кола
        }
    }

    return 0;
}
