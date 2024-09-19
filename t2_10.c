// Завдання 2.10
// Трикутник заданий довжиною своїх сторін. Знайти та вивести величину кутів трикутника у радіанах та градусах.

// Використовую теорему косинусів для обчислення кутів трикутника.
// cos(alpha) = (b2 + c2 - a2) / 2bc

#include <stdio.h>
#include <math.h> //  використ стандартну бібліотеку для функції acos

// Функція для перетворення радіанів у градуси
double radians_to_degrees(double radians) {
    return radians * (180.0 / M_PI); // |*180/phi
}

int main() {
    double a, b, c;

    printf("Enter the lengths of the sides of the triangle:\n");
    printf("Side a: ");
    scanf("%lf", &a);
    printf("Side b: ");
    scanf("%lf", &b);
    printf("Side c: ");
    scanf("%lf", &c);

    // Перевірка, чи трикутник існує
    if (a + b > c && a + c > b && b + c > a) {
        // Обчислюємо кути за теоремою косинусів
        double angle_A = acos((b*b + c*c - a*a) / (2.0 * b * c));
        double angle_B = acos((a*a + c*c - b*b) / (2.0 * a * c));
        double angle_C = acos((a*a + b*b - c*c) / (2.0 * a * b));

        // Виведення кутів у радіанах та градусах
        printf("\nTriangle angles in radians:\n");
        printf("Angle A: %f radian\n", angle_A);
        printf("Angle B: %f radian\n", angle_B);
        printf("Angle C: %f radian\n", angle_C);

        printf("\nTriangle angles in degrees:\n");
        printf("Angle A: %f degrees\n", radians_to_degrees(angle_A));
        printf("Angle B: %f degrees\n", radians_to_degrees(angle_B));
        printf("Angle C: %f degrees\n", radians_to_degrees(angle_C));
    } else {
        printf("Such a triangle does not exist\n");
    }
}