// Завдання 2.6

#include <stdio.h>
#include <math.h>


double length(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

double area(double a, double b, double c) {
    if (a < (b + c) && c < (b + a) && b < (a + c)) {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    else{
        printf("Such a triangle doesn't exist. \n");
        return 0;
    }
}

int main() {

    double a = length(4, 8, 6, 1);
    double b = length(4, 1, 8, 4);
    double c = length(12, 8, 2, 6);

    printf("Length of a = %.3lf \n", a);
    printf("Length of b = %.3lf \n", b);
    printf("Length of c = %.3lf \n", c);

    double triangle_area = area(a, b, c);

    if (triangle_area > 0) {
        printf("Area of triangle = %.3lf \n", triangle_area);
    }

}