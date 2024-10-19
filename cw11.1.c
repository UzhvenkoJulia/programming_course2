// Робота з бінарними файлами на С

//1

#include <stdio.h>
#include <stdlib.h>

void saveArrayToFile(const char* filename, double* array, int size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("failed to open file for writing\n");
        return;
    }

    // each array element to the file
    for (int i = 0; i < size; i++) {
        fprintf(file, "%lf ", array[i]);
    }
    fclose(file);
}

void printArrayFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("failed to open file for reading\n");
        return;
    }

    double value;
    int first = 1; // Прапорець для того, щоб правильно виводити коми
    // read values from the file and print them comma-separated
    while (fscanf(file, "%lf", &value) == 1) {
        if (!first) {
            printf(", "); // + кому після першого елемента
        }
        printf("%lf", value);
        first = 0;
    }
    printf("\n");
    fclose(file); 
}

int main() {
    int size;
    printf("enter the size of the array: ");
    scanf("%d", &size); 

    double* array = (double*)malloc(size * sizeof(double));

    printf("enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("element %d: ", i + 1);
        scanf("%lf", &array[i]);
    }

    const char* filename = "array.txt";

    saveArrayToFile(filename, array, size);

    printf("file content:\n");
    printArrayFromFile(filename);

    free(array);
}