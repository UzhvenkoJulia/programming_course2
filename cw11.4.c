// Робота з бінарними файлами на С

//4

// прямокутники

#include <stdio.h>
#include <stdlib.h>

#define MAX_RECTANGLES 100
#define FILENAME "rectangles.txt"

typedef struct {
    int number;
    float x1, y1; // координати верхнього лівого кута
    float x2, y2; // координати нижнього правого кута
} Rectangle;

float calculateArea(Rectangle rect) {
    return (rect.x2 - rect.x1) * (rect.y2 - rect.y1);
}

void writeRectanglesToFile(Rectangle rectangles[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        perror("failed to open file");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %.2f %.2f %.2f %.2f\n", rectangles[i].number, rectangles[i].x1, rectangles[i].y1, rectangles[i].x2, rectangles[i].y2);
    }
    fclose(file);
}

int readRectanglesFromFile(Rectangle rectangles[]) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("failed to open file");
        return 0;
    }
    int count = 0;
    while (fscanf(file, "%d %f %f %f %f", &rectangles[count].number, &rectangles[count].x1, &rectangles[count].y1, &rectangles[count].x2, &rectangles[count].y2) == 5) {
        count++;
    }
    fclose(file);
    return count;
}

void findMaxAreaRectangle(Rectangle rectangles[], int count) {
    if (count == 0) {
        printf("no rectangles in the file\n");
        return;
    }
    int maxIndex = 0;
    float maxArea = calculateArea(rectangles[0]);
    for (int i = 1; i < count; i++) {
        float area = calculateArea(rectangles[i]);
        if (area > maxArea) {
            maxArea = area;
            maxIndex = i;
        }
    }
    printf("rectangle with the largest area:\n");
    printf("number: %d, area: %.2f\n", rectangles[maxIndex].number, maxArea);
}

void deleteRectangleByNumber(Rectangle rectangles[], int *count, int number) {
    for (int i = 0; i < *count; i++) {
        if (rectangles[i].number == number) {
            // зсув масиву
            for (int j = i; j < *count - 1; j++) {
                rectangles[j] = rectangles[j + 1];
            }
            (*count)--;
            printf("rectangle with number %d has been deleted\n", number);
            return;
        }
    }
    printf("rectangle with number %d not found\n", number);
}

// для заміни запису про прямокутник
void replaceRectangleByNumber(Rectangle rectangles[], int count, int number, Rectangle newRect) {
    for (int i = 0; i < count; i++) {
        if (rectangles[i].number == number) {
            rectangles[i] = newRect;
            printf("record for rectangle number %d has been replaced\n", number);
            return;
        }
    }
    printf("rectangle with number %d not found\n", number);
}

int main() {
    Rectangle rectangles[MAX_RECTANGLES];
    int count = 0;

    // створення деяких прямокутників
    rectangles[count++] = (Rectangle){1, 1.0, 1.0, 4.0, 5.0};
    rectangles[count++] = (Rectangle){2, 2.0, 2.0, 5.0, 6.0};
    rectangles[count++] = (Rectangle){3, 0.0, 0.0, 3.0, 3.0};

    writeRectanglesToFile(rectangles, count);
    count = readRectanglesFromFile(rectangles);
    findMaxAreaRectangle(rectangles, count);
    deleteRectangleByNumber(rectangles, &count, 2);
    writeRectanglesToFile(rectangles, count);
    Rectangle newRect = {2, 3.0, 3.0, 6.0, 6.0};
    replaceRectangleByNumber(rectangles, count, 1, newRect);
    writeRectanglesToFile(rectangles, count);
}