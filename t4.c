// 4 завдання

#include<stdio.h>
int main() {
    // Змінні для мас, відстані та гравітаційної сталої
    double m1, m2, r;
    const double y = 6.673*10e-11f;
    double F;

    printf("Enter the mass of the first body (kg): ");
    scanf("%lf", &m1);
    printf("Enter the mass of the second body (kg): ");
    scanf("%lf", &m2);
    printf("Enter the distance between the bodies (m): ");
    scanf("%lf", &r);

    F = y * ((m1*m2)/(r*r));
    
    printf("The force of attraction F = %e H\n", F);
}