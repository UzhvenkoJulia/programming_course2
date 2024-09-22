#include <stdio.h>
#include <math.h>
#include <float.h>

// функція для обчислення n-го значення послідовного sin
void task1() {
    double x, y;
    int n;

    printf("Enter x: ");
    scanf("%lf", &x);

    printf("Enter n: "); // к-сть ітерацій n
    scanf("%d", &n);

    // початкове значення y дорівнює x
    y = x;
    // виконуємо n послідовних обчислень синуса
    for (int i = 0; i < n; i++) {
        y = sin(y); // обчислення sin для поточного y
    }

    printf("Result: %lf\n", y);
}

// функція для виведення факторіальних виразів у двох випадках
void task2() {
    unsigned int n;

    // n для першого факторіального виразу
    printf("Enter n: ");
    scanf("%u", &n);

    // Виводимо вираз 1 * 2 * ... * n
    for (int i = 1; i < n; i++) {
        printf("%d * ", i);
    }
    printf("%u\n", n);

    unsigned int m;

    // m для другого факторіального виразу
    printf("Enter m: ");
    scanf("%u", &m);

    for (int i = m; i > 1; i--) { // виводимо вираз m * (m-1) * ... * 1
        printf("%u * ", i);
    }
    printf("1\n");
}

// функція для обчислення степеневої суми
void task3() {
    int n = 3, x = 2;
    int result = 1; // початкове значення результату

    // обчислення степеневої суми y = 1 + x^1 + x^2 + ... + x^n
    for (int i = 1; i <= n; i++) {
        result += pow(x, i); // + кожен степінь числа x
    }

    printf("y = %d\n", result);
}

// функція для обчислення суми зі зростаюч коеф
void task4() {
    double x, result = 0;
    unsigned int n, power = 1;

    printf("Enter x and n: ");
    scanf("%lf %u", &x, &n);

    // обчислення суми y = 1*x + 2*x^2 + ... + n*x^n
    for (unsigned int i = 1; i <= n; i++) {
        power *= x; // обчисл x^i
        result += i * power; // + i * x^i до результату
    }

    printf("y = %lf\n", result);
}

// функція для обчислення подвійного факторіала (n!!)
void task5() {
    unsigned int n, result = 1;

    printf("Enter n: ");
    scanf("%u", &n);

    // якщо n парне, множимо лише парні числа
    if (n % 2 == 0) {
        for (unsigned int i = 2; i <= n; i += 2) {
            result *= i;
        }
    }
    // якщо непарне, множимо лише непарні числа
    else {
        for (unsigned int i = 1; i <= n; i += 2) {
            result *= i;
        }
    }

    printf("y = n!! = %u\n", result);
}

// функція для обчислення з використанням коренів квадратних
void task6_a() {
    unsigned int n;
    double y = sqrt(2); // початкове значення y

    printf("Enter n: ");
    scanf("%u", &n);

    // обчисл суму коренів квадратних
    for (unsigned int i = 1; i < n; i++) {
        y += sqrt(y); // + до y корінь з попереднього y
    }

    printf("y = %lf\n", y);
}

void task6_b() {
    unsigned int n;
    double y;

    printf("Enter n: ");
    scanf("%u", &n);

    // початкове значення y з формули sqrt(3 * (n - 1) + sqrt(3 * n))
    y = sqrt(3 * (n - 1) + sqrt(3 * n));

    for (unsigned int i = 1; i < n; i++) {
        y += sqrt(y);
    }

    printf("y = %lf\n", y);
}

// функція для обчислення степеневої суми з факторіалами
void task7() {
    unsigned int n;
    double x, result = 1.0, power = 1.0, factorial = 1.0;

    printf("Enter n: ");
    scanf("%u", &n);

    printf("Enter x: ");
    scanf("%lf", &x);

    // обчисл суму y = 1 + (x^1 / 1!) + (x^2 / 2!) + ... + (x^n / n!)
    for (unsigned int i = 1; i <= n; i++) {
        power *= x; // обчисл x^i
        factorial *= i; // обчисл i!
        result += power / factorial; // + x^i / i! до результату
    }

    printf("y = %lf\n", result);
}

// функція для пошуку максимального k, при якому 4^k <= m
void task8() {
    unsigned int m, k = 0, result = 1;

    printf("Enter m >= 1: ");
    scanf("%u", &m);

    // збільш k, поки 4^k не перевищить m
    while (result <= m) {
        k++;
        result = pow(4, k); // обчисл 4^k
    }

    printf("max(k) = %u\n", k - 1);
}

// функція для пошуку мінімального 2^r, яке більше за n
void task9() {
    unsigned int n, result = 1, power = 1;

    printf("Enter n: ");
    scanf("%u", &n);

    // збільш r, поки 2^r не стане більшим за n
    while (result <= n) {
        power++;
        result = pow(2, power);
    }

    printf("min = %u\n", result);
}

// функція для обчислення машинного епсилона типу float
void task10() {
    float a = 1.0f;
    float eps = DBL_EPSILON; // стандарт знач машинного епсилона

    // ділимо a на 2, поки 1.0 + a не дорівнює 1.0
    while (1.0f + a != 1.0f) {
        a /= 2.0f;
    }

    printf("Smallest a: %.5e\n", 2 * a);
    printf("Machine epsilon for float: %.5e\n", eps);
}

// функція для обчислення суми, середнього арифметичного та геометричного значення
void task11() {
    int count = 0, i = 0;
    double sum = 0, product = 1, num;

    // запитуємо значення елементів, доки вони не стануть наближеними до нуля
    do {
        printf("a[%d] = ", i++);
        scanf("%lf", &num);

        // додаємо до суми і добутку тільки позитивні значення
        if (num > DBL_EPSILON) {
            sum += num;
            product *= num;
            count++;
        }
    } while (fabs(num) > DBL_EPSILON); // завершуємо цикл, коли введено число, близьке до нуля

    // обчисл середнє арифметичне і геометричне значення
    double average = sum / count;
    double geometric_mean = pow(product, 1.0 / count);

    printf("Sum: %.2lf\n", sum);
    printf("Arithmetic average: %.2lf\n", average);
    printf("Geometric mean: %.2lf\n", geometric_mean);
}

// функція для обчислення субфакторіала !n (кількість розташувань без фіксованих елементів)
void task12() {
    unsigned int n;
    double subfact = 1;

    printf("Enter n (n < 25): ");
    scanf("%u", &n);

    // обчисл значення субфакторіала
    for (unsigned int i = 1; i <= n; i++) {
        subfact = subfact * i + pow(-1, i); // формула для !n
    }

    printf("!%u = %.0f\n", n, subfact);
}

int main() {
    int task;

    printf("Select task (1-12): ");
    scanf("%d", &task);

    switch (task) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 61:
            task6_a();
            break;
        case 62:
            task6_b();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 9:
            task9();
            break;
        case 10:
            task10();
            break;
        case 11:
            task11();
            break;
        case 12:
            task12();
            break;
        default:
            printf("Invalid task number.\n");
    }
}