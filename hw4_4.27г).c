#include <stdio.h>

// функція для обчислення числа pi з точністю epsilon
double calculate_pi(double epsilon) {
    double pi = 0.0; // поточне значення суми для pi
    double term = 0.0; // поточний член суми
    int k = 0; // лічильник для суми

    do {
        // (-1)^k / 4^k * ( (2 / (4k+1)) + (2 / (4k+2)) + (1 / (4k+2)) )
        double sign; // (-1)^k
        if (k % 2 == 0) {
            sign = 1.0; // парне k -> знак 1.0
        } else {
            sign = -1.0; // непарне k -> знак -1.0
        }
        double denominator1 = 4.0 * k + 1.0; // 4k + 1
        double denominator2 = 4.0 * k + 2.0; // 4k + 2
        double power_of_four = 1.0; // 4^k (якщо k = 0, це 1), за допомогою циклу обчислення іде

        // рахуємо 4^k через множення
        for (int i = 0; i < k; i++) {
            power_of_four *= 4.0;
        }

        // обчислення поточного члена суми
        term = sign / power_of_four * ( (2.0 / denominator1) + (2.0 / denominator2) + (1.0 / denominator2) );
        pi += term;
        k++; // збільш лічильник для наступного члена

    } while (term > epsilon || term < -epsilon); // продовжуємо, поки член більше за точність epsilon

    return pi;
}

int main() {
    double epsilon;
    printf("Enter the epsilon precision value: ");
    scanf("%lf", &epsilon);
    double pi = calculate_pi(epsilon);
    printf("Calculated value pi: %.15lf\n", pi);
}