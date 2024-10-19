// Робота з бінарними файлами на С

//2

// менш по модулю за задане число а > 0
// видалити всі елем з файлу F, які менші по модулю за число float

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void createFileF(const char* filenameF) {
    FILE* fileF = fopen(filenameF, "w");
    if (fileF == NULL) {
        printf("failed to create file F.txt\n");
        return;
    }

    double data[] = {2.5, 4.8, -3.1, 6.7, -2.9, 3.5, -7.0, 1.2};
    int size = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < size; i++) {
        fprintf(fileF, "%lf ", data[i]);
    }

    fclose(fileF);  
}

void createFileG(const char* filenameF, const char* filenameG, double a) {
    FILE* fileF = fopen(filenameF, "r");
    FILE* fileG = fopen(filenameG, "w");

    if (fileF == NULL) {
        printf("failed to open file F.txt for reading\n");
        return;
    }
    if (fileG == NULL) {
        printf("failed to open file G.txt for writing\n");
        fclose(fileF); // close F if G cannot be opened
        return;
    }

    double value;
    // read each number from file F
    while (fscanf(fileF, "%lf", &value) == 1) {
        // if the number is smaller in absolute value than a, write it to file G
        if (fabs(value) < a) {
            fprintf(fileG, "%lf ", value);
        }
    }

    fclose(fileF);
    fclose(fileG);
}

void removeFromFileF(const char* filenameF, double a) {
    FILE* fileF = fopen(filenameF, "r");
    FILE* tempFile = fopen("temp.txt", "w");

    if (fileF == NULL) {
        printf("failed to open file F.txt for reading\n");
        return;
    }
    if (tempFile == NULL) {
        printf("failed to open temporary file for writing\n");
        fclose(fileF);
        return;
    }

    double value;
    // read each number from file F and write only those that are not smaller than a
    while (fscanf(fileF, "%lf", &value) == 1) {
        if (fabs(value) >= a) {
            fprintf(tempFile, "%lf ", value);
        }
    }

    fclose(fileF);
    fclose(tempFile);

    // Replace original file F with the updated content
    remove(filenameF);  // remove original file F
    rename("temp.txt", filenameF);  // rename temporary file to F
}

int main() {
    double a;
    printf("enter a positive number a: ");
    scanf("%lf", &a);  

    // check that a > 0
    if (a <= 0) {
        printf("a must be greater than 0\n");
        return 1;
    }

    const char* filenameF = "F.txt";  
    const char* filenameG = "G.txt";  

    createFileF(filenameF);
    createFileG(filenameF, filenameG, a);
    removeFromFileF(filenameF, a);

    printf("operation completed\n");
}