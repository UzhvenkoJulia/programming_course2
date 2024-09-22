#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

// Завдання 1: Робота з натуральним тризначним числом
void task1() {
    unsigned number;
    int units, tens, hundreds, sum, reversed;

    printf("Task 1: Working with a three-digit number\n");
    printf("Enter a number (100-999): ");
    scanf("%u", &number);

    if (number >= 100 && number <= 999) {
        // Розбиваємо число на одиниці, десятки та сотні
        units = number % 10;
        tens = (number / 10) % 10;
        hundreds = number / 100;
        sum = units + tens + hundreds;

        // Виводимо кожну цифру
        printf("Ones: %d, Tens: %d, Hundreds: %d\n", units, tens, hundreds);

        printf("Sum of numbers: %d\n", units + tens + hundreds);

        // Перевернене число
        reversed = units * 100 + tens * 10 + hundreds;
        printf("Inverted number: %d\n", reversed);
    } else {
        printf("The number is not three digits!\n");
    }
}

// Завдання 2: Перестановка цифр тризначного числа
void task2() {
    unsigned number;
    int units, tens, hundreds;

    printf("\nTask 2: Rearrange the numbers\n");
    printf("Enter a three-digit number: ");
    scanf("%u", &number);

    if (number >= 100 && number <= 999) {
        units = number % 10;
        tens = (number / 10) % 10;
        hundreds = number / 100;

        // Якщо всі цифри різні
        if (units != tens && tens != hundreds && units != hundreds) {
            printf("Possible permutations of numbers:\n");
            printf("%u%u%u \n", units, tens, hundreds);
            printf("%u%u%u \n", units, hundreds, tens);
            printf("%u%u%u \n", hundreds, units, tens);
            printf("%u%u%u \n", hundreds, tens, units);
            printf("%u%u%u \n", tens, hundreds, units);
            printf("%u%u%u \n", tens, units, hundreds);
        } else {
            printf("The numbers are not different!\n");
        }
    } else {
        printf("The number is not three digits!\n");
    }
}

// Завдання 3: Добуток трьох чисел
void task3() {
    long long a, b, c, product;

    printf("\nTask 3: Product of three numbers\n");
    printf("Enter three numbers separated by a space: ");
    scanf("%lld %lld %lld", &a, &b, &c);

    product = a * b * c;
    printf("Product of numbers: %lld\n", product);
}

uint16_t mult(uint8_t x, uint8_t y) {
    return x * y;
}

// Завдання 4: Множення двох чисел
void task4() {
    uint8_t x, y;
    uint16_t z;

    printf("\nTask 4: Multiplication of two numbers\n");
    printf("Enter two numbers: ");
    scanf("%hhu %hhu", &x, &y);

    z = mult(x, y);
    printf("Multiplication result: %u\n", z);
}

// Завдання 5: Порівняння двох чисел
void task5() {
    int a, b;

    /*int a, b, max, min;

    printf("a = ");
    scanf("%d", &a);

    printf("b = ");
    scanf("%d", &b);

    // if (a > b) {
    //     printf("%d > %d\n", a, b);
    // }
    // else if (a < b) {
    //     printf("%d < %d\n", a, b);
    // }
    // else {
    //     printf("%d = %d\n", a, b);
    // }

    max = a > b ? a : b;
    printf("Max = %d \n", max);

    min = a < b ? a : b;
    printf("Min = %d \n", min);

    }*/

    printf("\nTask 5: Comparing two numbers\n");
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a > b) {
        printf("Bigger number: %d\n", a);
    } else {
        printf("Bigger number: %d\n", b);
    }
}

// Завдання 6: Порівняння за модулем
void task6() {
    int a, b, c;

    /*if (abs(a) > abs(b) && abs(a) > abs(c)){
    printf("Max = %d \n", a);
    }
    else if (abs(b) > abs(a) && abs(b) > abs(c)){
    printf("Max = %d \n", b);
    }
    else{
    printf("Max = %d \n", c);
    }

    if (abs(a) < abs(b) && abs(a) < abs(c)){
    printf("Min = %d \n", a);
    }
    else if (abs(b) < abs(a) && abs(b) < abs(c)){
    printf("Min = %d \n", b);
    }
    else{
    printf("Min = %d \n", c);
    }


    int zero(double x){
    const double eps = 1e-9;
    return fabs(x) < eps;
    }*/

    printf("\nTask 6: Comparison by module\n");
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    a = abs(a);
    b = abs(b);
    c = abs(c);

    int max = a > b ? (a > c ? a : c) : (b > c ? b : c);
    printf("Maximum by module: %d\n", max);
}

// Завдання 7(a): Розв'язання квадратного рівняння
void task7_a() {
    double a, b, c;

    printf("\nExercise 7(a): Solving a quadratic equation\n");
    printf("Enter the coefficients a, b, c for the equation ax^2 + bx + c = 0:\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    /*if (zero(a) && !zero(b) && !zero(c)){
    double x = - c / b;
    printf("x1 = %lf \n", x);
    }
    if (zero(c) && !zero(a) && !zero(b)){
    int x1 = 0;
    double x2 = - a / b;
    printf("x1 = %d, x2 = %lf \n", x1, x2);
    }
    if (zero(b) && !zero(a) && !zero(c)){
    int x = - c / a;
    if (x > 0){

    double x1 = sqrt(x);
    double x2 = - sqrt(x);
    printf("x1 = %lf, x2 = %lf \n", x1, x2);
    }

    if (x < 0){
    printf("No real roots.\n");
    }
    }
    if (a > 0 && b > 0 && c >0){
    int d = pow(b, 2) - 4 * a * c;
    if (d > 0){
    double x1 = ( -b + sqrt(d)) / (2 * a);
    double x2 = ( -b - sqrt(d)) / (2 * a);
    printf("x1 = %lf, x2 = %lf \n", x1, x2);
    }
    else if (d == 0){
    double x = -b / (2 * a);
    printf("x1 = %lf \n", x);
    }
    else if (d < 0){
    printf("No real roots.\n");
    }
    }
    if (zero(b) && zero(c) && !zero(a)){
    if (a > 0){
    double x1 = sqrt(a);
    double x2 = - sqrt(a);
    printf("x1 = %lf, x2 = %lf \n", x1, x2);
    }
    if (a < 0){
    printf("No real roots\n");
    }
    }
    if (zero(a) && zero(c) && !zero(b)){
    double x1 = -b;
    printf("x1 = %lf \n", x1);
    }
    if (zero(a) && zero(b)){
    printf("No equation exists\n");
    }*/

    if (a == 0) {
        printf("This is not a quadratic equation!\n");
    } else {
        double D = b * b - 4 * a * c;
        if (D > 0) {
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);
            printf("Junctions: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
        } else if (D == 0) {
            double x = -b / (2 * a);
            printf("Solution: x = %.2lf\n", x);
        } else {
            printf("There are no real roots\n");
        }
    }
}

// Завдання 7(b): Розв'язання рівняння четвертого ступеня
void task7_b() {
    double a, b, c;
    double x1, x2, D;
    double EPS = 1e-8;
    int flag;
    printf("ax^4+bx^2+c.\n Enter value a, b, c = ");
    scanf("%lf %lf %lf", &a, &b, &c);
    D = (b*b) - (4*a*c);
    flag = 1;

    if (fabs(a) < EPS) {
        // a == 0, bx^2 + c = 0
        if (fabs(b) < EPS) {
            if (fabs(c) < EPS) {
                printf("Infinite solutions (0 = 0)\n");
            } else {
                printf("There are no solutions (b = 0, c != 0)!\n");
            }
        } else {
            // bx^2 + c = 0
            x1 = -c / b;
            if (x1 < 0) {
                printf("There are no solutions!\n");
            } else {
                printf("x1 = %.4lf, x2 = %.4lf\n", sqrt(x1), -sqrt(x1));
            }
        }
    } else {
        if (D < 0) {
            printf("There are no solutions!\n");
            flag = 0;
        } else if (fabs(D) < EPS) {
            x1 = -b / (2 * a);
        } else {
            x1 = (-b - sqrt(D)) / (2 * a);
            x2 = (-b + sqrt(D)) / (2 * a);
        }

        if (flag == 1) {
            if (x1 >= 0 && x2 >= 0) {
                printf("x1 = %.4lf, x2 = %.4lf, x3 = %.4lf, x4 = %.4lf\n",
                       sqrt(x1), -sqrt(x1), sqrt(x2), -sqrt(x2));
            } else if (x1 < 0 && x2 < 0) {
                printf("There are no solutions!\n");
            } else if (x1 < 0 && x2 > 0) {
                printf("x1 = %.4lf, x2 = %.4lf\n", sqrt(x2), -sqrt(x2));
            } else if (x1 > 0 && x2 < 0) {
                printf("x1 = %.4lf, x2 = %.4lf\n", sqrt(x1), -sqrt(x1));
            }
        }
    }
}
/*if (d > 0){
double y1 = (-b + sqrt(d)) / (2 * a);
double y2 = (-b - sqrt(d)) / (2 * a);
if (y1 >= 0 && y2 >= 0){
double x1 = sqrt(y1);
double x2 = -sqrt(y1);
double x3 = sqrt(y2);
double x4 = -sqrt(y2);
printf("x1 = %lf, x2 = %lf, x3 = %lf, x4 = %lf \n", x1, x2, x3, x4);
}
if (y1 >= 0 && y2 < 0){
double x1 = sqrt(y1);
double x2 = -sqrt(y1);
printf("x1 = %lf, x2 = %lf \n", x1, x2);
}
if (y1 < 0 && y2 >= 0){
double x1 = sqrt(y2);
double x2 = -sqrt(y2);
printf("x1 = %lf, x2 = %lf \n", x1, x2);
}
if (y1 < 0 && y2 < 0){
printf("No real roots. \n");
}*/

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7_a();
    task7_b();

    return 0;
}
