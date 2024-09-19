// 7 завдання

#include <stdio.h>
#include <math.h>

int main() {
    double x;

    printf("Enter a real number x: ");
    scanf("%lf", &x);

    // Підрахунок цілої та дробової частини
    double int_part = floor(x); // Ціла частина
    double frac_part = x - int_part; // Дробова частина

    // c = ceil(x); //округлення зверху
    // f = floor(x); //округлення знизу
    // r =  round(x); //заокруглення
    // z = (int)x; //ціла частина
    // d = fabs(x-z); //дробова частина

    // Найменше ціле число більше або рівне x (ceil) та найбільше ціле менше або рівне x (floor)
    // ceil(x) знаходить найменше ціле число, більше або рівне х
    // Функція floor(x) знаходить найбільше ціле число, менше або рівне х, і це використовується для обчислення цілої частини
    double ceil_part = ceil(x);
    double floor_part = floor(x);

    printf("Whole part: %.0lf\n", int_part);
    printf("Fractional part: %.2lf\n", frac_part);
    printf("The smallest integer greater than or equal to x: %.0lf\n", ceil_part);
    printf("The largest integer less than or equal to x: %.0lf\n", floor_part);
}
