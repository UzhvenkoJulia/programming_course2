// Робота з бінарними файлами на С
// Домашнє завдання 11
//11.12В

// Дано файл, який містить відомості про іграшки:
// указано назву іграшки (напр., м'яч, лялька, конструктор тощо),
// її вартість у гривнях
// і вікові межі для дітей, яким іграшка призначається (напр., для дітей від двох до п'яти років).
// Скласти функції, що виводять наступні результати у бінарний файл та на консоль:

// в) пошуку назв найдорожчих іграшок
// (ціна яких відрізняється від ціни найдорожчої іграшки не більш ніж на а грн);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_TOYS 100

// представлення іграшки
typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int age_min;
    int age_max;
} Toy;

void write_toys_to_file(const char *filename, Toy toys[], int toy_count) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("error opening file");
        exit(EXIT_FAILURE);
    }
    fwrite(toys, sizeof(Toy), toy_count, file);
    fclose(file);
    printf("data has been written to %s\n", filename);
}

int read_toys_from_file(const char *filename, Toy toys[]) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("error opening file");
        exit(EXIT_FAILURE);
    }
    int toy_count = 0;
    while (fread(&toys[toy_count], sizeof(Toy), 1, file) == 1) {
        toy_count++;
    }
    fclose(file);
    return toy_count;
}

void find_expensive_toys(Toy toys[], int toy_count, float a, const char *output_filename) {
    FILE *file = fopen(output_filename, "wb");
    if (!file) {
        perror("error opening file");
        exit(EXIT_FAILURE);
    }

    // максимал ціна
    float max_price = toys[0].price;
    for (int i = 1; i < toy_count; i++) {
        if (toys[i].price > max_price) {
            max_price = toys[i].price;
        }
    }

    printf("max price: %.2f\n", max_price);

    printf("toys within %.2f UAH of the max price:\n", a);
    for (int i = 0; i < toy_count; i++) {
        if (toys[i].price >= max_price - a) {
            printf("toy: %s, price: %.2f\n", toys[i].name, toys[i].price);
            fwrite(&toys[i], sizeof(Toy), 1, file);
        }
    }

    fclose(file);
    printf("filtered data has been written to %s\n", output_filename);
}

int main() {
    Toy toys[MAX_TOYS] = {
        {"Ball", 120.75, 2, 5},
        {"Doll", 400.63, 3, 7},
        {"Constructor", 750.49, 5, 10},
        {"Puzzle", 128.00, 4, 8},
        {"Car", 610.30, 1, 6}
    };
    int toy_count = 5;

    const char *input_filename = "toys.bin";
    write_toys_to_file(input_filename, toys, toy_count);

    Toy read_toys[MAX_TOYS];
    toy_count = read_toys_from_file(input_filename, read_toys);

    float a = 20.0;
    const char *output_filename = "expensive_toys.bin";
    find_expensive_toys(read_toys, toy_count, a, output_filename);
}