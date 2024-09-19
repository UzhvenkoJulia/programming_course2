// Точка простору задана декартовими координатами "(х, у, z)".
// Перевірити, чи належить вона -циліндру-, вісь якого збігається з віссю "Oz".
// Висота дорівнює h, а -нижня основа- лежить у площині "Оху" та має радіус r.

// Завдання 3.22 (домашнє завдання)

#include <stdio.h>
#include <math.h>

// межі висоти циліндра (від 0 до h)
int isPointInCylinder(double x, double y, double z, double r, double h) {
    // перевірка, чи точка знаходиться у висоті циліндра
    if (z < 0 || z > h) {
        return 0; // т. поза висотою циліндра
    }

    // перевірка, чи т. знаходиться в радіусі основи циліндра
    double distance = sqrt(x * x + y * y);
    if (distance <= r) {
        return 1; // т. всередині циліндра
    }

    return 0; // т. поза циліндром
}

int main() {
    // приклад точок для перевірки
    double x, y, z;
    double r = 5.0;
    double h = 10.0;

    printf("(x, y, z): ");
    scanf("%lf %lf %lf", &x, &y, &z);

    if (isPointInCylinder(x, y, z, r, h)) {
        printf("The point is inside the cylinder.\n");
    } else {
        printf("The point is outside the cylinder.\n");
    }
}