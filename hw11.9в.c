// Робота з бінарними файлами на С
// Домашнє завдання 11
//11.9В

// Дано файл F, компоненти якого є цілими числами.
// Файл містить рівну к-сть додатних і від'ємних чисел -
// перевірте це
// і в противному випадку видайте відповідне повідомлення та не робить нічого.
// Використовуючи допоміжний файл Н,
// переписати компоненти файлу F до файлу G так, щоб у файлі G:

// в) числа йшли таким чином:
// два додатних, два від'ємних тощо.
// Якщо це неможливо - то переписати поки можливо в такому вигляді, а останні два числа вивести на консоль.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// підрахунок додатніх та від'ємних чисел
void count_numbers(const char *filename, int *positive_count, int *negative_count) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("error opening file");
        exit(EXIT_FAILURE);
    }

    int number;
    while (fread(&number, sizeof(int), 1, file) == 1) {
        if (number > 0) {
            (*positive_count)++;
        } else if (number < 0) {
            (*negative_count)++;
        }
    }

    fclose(file);
}

// переписування чисел у новий файл з чергуванням
void alternate_write(const char *input_file, const char *output_file) {
    FILE *file_in = fopen(input_file, "rb");
    FILE *file_out = fopen(output_file, "wb");
    if (!file_in || !file_out) {
        perror("error opening file");
        exit(EXIT_FAILURE);
    }

    int number;
    int positive_count = 0, negative_count = 0;
    int positive[MAX_SIZE], negative[MAX_SIZE];

    // зчитуємо числа з файлу F
    while (fread(&number, sizeof(int), 1, file_in) == 1) {
        if (number > 0) {
            positive[positive_count++] = number;
        } else if (number < 0) {
            negative[negative_count++] = number;
        }
    }

    // перевірка на рівність кількостей
    if (positive_count != negative_count) {
        printf("error: the counts of positive and negative numbers are not equal\n");
        fclose(file_in);
        fclose(file_out);
        return;
    }

    // записуємо у файл G
    int i;
    for (i = 0; i < positive_count; i += 2) {
        if (i < positive_count) {
            fwrite(&positive[i], sizeof(int), 1, file_out);
            fwrite(&positive[i + 1], sizeof(int), 1, file_out);
        }
        if (i < negative_count) {
            fwrite(&negative[i], sizeof(int), 1, file_out);
            fwrite(&negative[i + 1], sizeof(int), 1, file_out);
        }
    }

    // вивід залишкових чисел, якщо такі є
    if (positive_count % 2 != 0) {
        printf("remaining positive numbers: %d\n", positive[positive_count - 1]);
    }
    if (negative_count % 2 != 0) {
        printf("remaining negative numbers: %d\n", negative[negative_count - 1]);
    }

    fclose(file_in);
    fclose(file_out);
}

// читання і відображення вмісту G.bin
void read_binary_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("error opening file");
        return;
    }

    int number;
    printf("contents of %s:\n", filename);
    while (fread(&number, sizeof(int), 1, file) == 1) {
        printf("%d\n", number);
    }

    fclose(file);
}

// створення бінарного файлу F
void create_binary_file(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("error opening file");
        exit(EXIT_FAILURE);
    }

    int positive_numbers[] = {5, 10, 15, 20};
    int negative_numbers[] = {-3, -9, -12, -18};

    fwrite(positive_numbers, sizeof(int), sizeof(positive_numbers) / sizeof(int), file);
    fwrite(negative_numbers, sizeof(int), sizeof(negative_numbers) / sizeof(int), file);

    fclose(file);
    printf("file %s created successfully\n", filename);
}

int main() {
    const char *input_filename = "F.bin";
    const char *output_filename = "G.bin";

    create_binary_file(input_filename);

    int positive_count = 0, negative_count = 0;
    count_numbers(input_filename, &positive_count, &negative_count);

    // якщо к-сть додатних і від'ємних рівна, переписуємо числа з чергуванням у G.bin
    if (positive_count == negative_count) {
        alternate_write(input_filename, output_filename);
        read_binary_file(output_filename);
    } else {
        printf("the counts of positive and negative numbers are not equal, no action taken\n");
    }

}