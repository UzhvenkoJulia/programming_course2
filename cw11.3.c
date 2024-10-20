// Робота з бінарними файлами на С

//3

// компоненти - цілі числа, нескінченн цик, доки не буде 0
// б) що є ступенем 3;
// д) що є паліндромами

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_NUM 100

int is_power_of_three(int num) {
    if (num < 1) return 0; // exclude negative numbers and 0
    while (num % 3 == 0) {
        num /= 3;
    }
    return num == 1;
}

// check if a number is a palindrome
int is_palindrome(int num) {
    char str[12]; // enough to store a 32-bit signed integer
    sprintf(str, "%d", num);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) return 0;
    }
    return 1;
}

void print_file_content(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("failed to open file");
        return;
    }

    char line[256]; // buffer for reading lines
    printf("content of %s:\n", filename);
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line); // print each line
    }
    fclose(file);
}

int main() {
    FILE *fileF, *fileG;
    int numbers[MAX_NUM];
    int count = 0;

    fileF = fopen("F.txt", "w");
    if (fileF == NULL) {
        perror("failed to create file F");
        return 1;
    }

    printf("enter integers (0 to finish):\n");
    while (1) {
        int num;
        scanf("%d", &num);
        if (num == 0) break;
        numbers[count++] = num; // store the number in the array
        fprintf(fileF, "%d\n", num);
    }
    fclose(fileF);

    fileG = fopen("G.txt", "w");
    if (fileG == NULL) {
        perror("failed to create file G");
        return 1;
    }

    // (b): write powers of 3 to file G
    fprintf(fileG, "numbers that are powers of 3:\n");
    int found_power_of_three = 0; // flag to check if any power of 3 is found
    for (int i = 0; i < count; i++) {
        if (is_power_of_three(numbers[i])) {
            fprintf(fileG, "%d\n", numbers[i]);
            found_power_of_three = 1;
        }
    }
    if (!found_power_of_three) {
        fprintf(fileG, "None\n"); // if none found, indicate that
    }

    // (d): write palindromes to file G
    fprintf(fileG, "numbers that are palindromes:\n");
    int found_palindrome = 0;
    for (int i = 0; i < count; i++) {
        if (is_palindrome(numbers[i])) {
            fprintf(fileG, "%d\n", numbers[i]);
            found_palindrome = 1;
        }
    }
    if (!found_palindrome) {
        fprintf(fileG, "None\n");
    }

    fclose(fileG);
    printf("files created successfully\n");

    // Print the content of files to console
    print_file_content("F.txt");
    print_file_content("G.txt");
}