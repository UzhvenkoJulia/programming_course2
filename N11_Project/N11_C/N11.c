/*Робота з valarray
Project number 11
It was made by Uzhvenko Yuliia 
Computer Mathematics/ group 1/ 2 curs
Email: uzhvenkojulia@knu.ua
Date 02.12.2024 */


#include "N11.h"                  // Підключаємо заголовочний файл N11.h, де оголошуються структури та функції для роботи з векторами
#include <stdlib.h>               // Підключаємо стандартну бібліотеку для роботи з пам'яттю та процесами (malloc, free, exit,..)
#include <stdio.h>                // Підключаємо бібліотеку для вводу/виводу (printf,..)
#include <errno.h>                // Підключаємо бібліотеку для роботи з помилками (перемінна errno,..)
#include <string.h>               // Підключаємо бібліотеку для роботи з рядками (strerror,..)
#include <time.h>                 // Підключаємо бібліотеку для роботи з часом 


// Створення нового вектора
Vector* create_vector(int size) {                                                // Декларуємо функцію для створення вектора заданого розміру
    Vector* vec = (Vector*)malloc(sizeof(Vector));                               // Виділяємо пам'ять для структури вектора
    if (vec == NULL) {                                                           // Перевіряємо, чи успішно виділена пам'ять для вектора
        printf("Error allocating memory for vector: %s\n", strerror(errno));     // Якщо ні, виводимо помилку
        exit(EXIT_FAILURE);                                                      // Завершуємо програму з помилкою
    }
    vec->size = size;                                                             // Присвоюємо розмір вектора
    vec->data = (double*)malloc(sizeof(double) * size);                           // Виділяємо пам'ять для елементів вектора (масиву типу double)
    if (vec->data == NULL) {                                                      // Перевіряємо, чи успішно виділена пам'ять для елементів вектора
        printf("Error allocating memory for vector data: %s\n", strerror(errno)); // Якщо ні, виводимо помилку
        free(vec);                                                                // Звільняємо вже виділену пам'ять для структури вектора
        exit(EXIT_FAILURE);                                                       // Завершуємо програму з помилкою
    }
    return vec;                                                                   // Повертаємо вказівник на створений вектор
}

// Вивільнення пам'яті для вектора
void free_vector(Vector* vec) {
    free(vec->data);
    free(vec);
}

// Введення елементів вектора з консолі
void input_vector(Vector* vec) {
    printf("Enter %d elements of the vector:\n", vec->size);
    for (int i = 0; i < vec->size; i++) {                                                // Цикл, що ітерує по кожному елементу вектора (від 0 до size-1)
        while (scanf("%lf", &vec->data[i]) != 1) {                                       // Читаємо число типу double з консолі, поки ввід некоректний
            printf("Invalid input! Please enter an integer or a fractional number\n");   // Виводимо повідомлення про помилку при некоректному вводі
            while(getchar() != '\n');                                                    //Очищаємо буфер вводу (відкидаємо невірний ввід до нового рядка)
        }
    }
}

// Виведення елементів вектора у файл
void output_vector(Vector* vec, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file for writing: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Vector of size %d:\n", vec->size);
    for (int i = 0; i < vec->size; i++) {    // Цикл, що ітерує по всіх елементах вектора (від 0 до size-1)
        fprintf(file, "%lf ", vec->data[i]); // Записує значення елемента вектора у файл, форматуючи як double ("%lf")
    }
    fclose(file);
}

// Створення нової матриці
Matrix* create_matrix(int rows, int cols) {
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    if (mat == NULL) {
        printf("Error allocating memory for matrix: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double**)malloc(sizeof(double*) * rows);
    if (mat->data == NULL) {
        printf("Error allocating memory for matrix data: %s\n", strerror(errno));
        free(mat);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (double*)malloc(sizeof(double) * cols);  // Виділяємо пам'ять для кожного окремого рядка
        if (mat->data[i] == NULL) {
            printf("Error allocating memory for matrix row: %s\n", strerror(errno));
            // Звільняємо вже виділену пам'ять для попередніх рядків
            for (int j = 0; j < i; j++) {
                free(mat->data[j]);
            }
            free(mat->data);
            free(mat);
            exit(EXIT_FAILURE);
        }
    }
    return mat;
}

// Вивільнення пам'яті для матриці
void free_matrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

// Введення елементів матриці з консолі
void input_matrix(Matrix* mat) {
    printf("Enter %d x %d matrix:\n", mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {      // Зовнішній цикл, що ітерує по кожному рядку матриці (від 0 до mat->rows-1)
        for (int j = 0; j < mat->cols; j++) {  // Внутрішній цикл, що ітерує по кожному стовпцю матриці (від 0 до mat->cols-1)
            while (scanf("%lf", &mat->data[i][j]) != 1) {
                printf("Invalid input! Please enter an integer or a fractional number\n");
                while(getchar() != '\n'); 
            }
        }
    }
}

// Виведення елементів матриці у файл
void output_matrix(Matrix* mat, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file for writing: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Matrix of size %d x %d:\n", mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            fprintf(file, "%lf ", mat->data[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Операція додавання матриць
Matrix* add_matrices(Matrix* A, Matrix* B) {
    // Перевірка, чи мають матриці однакові розміри
    if (A->rows != B->rows || A->cols != B->cols) {
        printf("Error: Matrix dimensions do not match for addition\n");
        return NULL;
    }
    // Створення нової матриці для результату додавання з тими ж розмірами, що й у вхідних матриць
    Matrix* result = create_matrix(A->rows, A->cols);
    for (int i = 0; i < A->rows; i++) {
        // Цикл по стовпцях матриць
        for (int j = 0; j < A->cols; j++) {
            // Додавання відповідних елементів з матриць A та B і запис результату в нову матрицю
            result->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }
    return result;
}

// Операція множення матриць
Matrix* multiply_matrices(Matrix* A, Matrix* B) {
    if (A->cols != B->rows) {
        printf("Error: Matrix dimensions do not match for multiplication\n");
        return NULL;
    }
    Matrix* result = create_matrix(A->rows, B->cols);
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < A->cols; k++) {
                result->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }
    return result;
}

// Обчислення детермінанту матриці 2x2
double determinant(Matrix* mat) {
    if (mat->rows == 2 && mat->cols == 2) {
        return mat->data[0][0] * mat->data[1][1] - mat->data[0][1] * mat->data[1][0];
    } else {
        printf("Determinant calculation is only implemented for 2x2 matrices\n");
        return 0;
    }
}

// Обчислення оберненої матриці 2x2
Matrix* inverse(Matrix* mat) {
    if (mat->rows != 2 || mat->cols != 2) {
        printf("Inverse is only implemented for 2x2 matrices\n");
        return NULL;
    }
    double det = determinant(mat);
    if (det == 0) {
        printf("Matrix is singular, cannot compute inverse\n");
        return NULL;
    }
    Matrix* inv = create_matrix(2, 2);
    inv->data[0][0] = mat->data[1][1] / det;
    inv->data[0][1] = -mat->data[0][1] / det;
    inv->data[1][0] = -mat->data[1][0] / det;
    inv->data[1][1] = mat->data[0][0] / det;
    return inv;
}

// Множення матриці на вектор
Vector* multiply_matrix_vector(Matrix* mat, Vector* vec) {
    if (mat->cols != vec->size) {
        printf("Error: Matrix columns do not match vector size.\n");
        return NULL;
    }
    Vector* result = create_vector(mat->rows);
    for (int i = 0; i < mat->rows; i++) {
        result->data[i] = 0;
        for (int j = 0; j < mat->cols; j++) {
            result->data[i] += mat->data[i][j] * vec->data[j];
        }
    }
    return result;
}

// Вибір режиму вводу/виводу для векторів і матриць
void input_vector_from_file(Vector* vec, const char* filename) {
    FILE* file = fopen(filename, "r"); // Використовуємо filename
    if (file == NULL) {
        printf("Could not open file for reading: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < vec->size; i++) {
        if (fscanf(file, "%lf", &vec->data[i]) != 1) {
            printf("The data format in the file is incorrect\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }
    fclose(file);
}

// Виведення результатів на консоль або файл
void output_vector_to_console(Vector* vec) {
    for (int i = 0; i < vec->size; i++) {
        printf("%lf ", vec->data[i]);
    }
    printf("\n");
}

// Виведення матриці на консоль
void output_matrix_to_console(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%lf ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Вибір режиму вводу/виведення для матриць з консолі або з/у файл
void input_matrix_from_file(Matrix* mat, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file for reading: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            if (fscanf(file, "%lf", &mat->data[i][j]) != 1) {
                printf("The data format in the file is incorrect\n");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(file);
}

// Вибір способу вводу/виведення для матриць і векторів
void select_input_output_mode(Vector* vec, Matrix* mat, int use_file, const char* filename) {
    if (use_file) {
        input_vector_from_file(vec, filename); // Завантажуємо вектор з файлу
        input_matrix_from_file(mat, filename); // Завантажуємо матрицю з файлу
    } else {
        input_vector(vec); // Вводимо вектор з консолі
        input_matrix(mat); // Вводимо матрицю з консолі
    }
}

// Операція додавання матриць та векторів з виведенням на консоль чи в файл
void add_matrices_and_output(Matrix* A, Matrix* B, int output_to_file, const char* filename) {
    if (A->rows != B->rows || A->cols != B->cols) {
        printf("Error: Matrix dimensions do not match for addition\n");
        return;
    }
    Matrix* result = add_matrices(A, B);
    if (result == NULL) return;
    if (output_to_file) {
        output_matrix(result, filename); // Виводимо результат у файл
    } else {
        output_matrix_to_console(result); // Виводимо результат на консоль
    }
    free_matrix(result);
}

// Операція множення матриць та векторів з виведенням на консоль чи в файл
void multiply_matrices_and_output(Matrix* A, Matrix* B, int output_to_file, const char* filename) {
    Matrix* result = multiply_matrices(A, B);
    if (result == NULL) return;
    if (output_to_file) {
        output_matrix(result, filename); // Виводимо результат у файл
    } else {
        output_matrix_to_console(result); // Виводимо результат на консоль
    }
    free_matrix(result);
}

// Множення матриці на вектор з виведенням на консоль чи в файл
void multiply_matrix_vector_and_output(Matrix* mat, Vector* vec, int output_to_file, const char* filename) {
    Vector* result = multiply_matrix_vector(mat, vec);
    if (result == NULL) return;

    // Виведення результату на основі режиму (based on the mode)
    if (output_to_file) {
        output_vector(result, filename);  
    } else {
        output_vector_to_console(result); 
    }
    // Звільнення динамічно виділеної пам'яті для результату
    free_vector(result);
}

void read_data_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int a, b;
    // Перевірте формат даних у файлі
    while (fscanf(file, "%d %d", &a, &b) == 2) {
        printf("Read values: a = %d, b = %d\n", a, b);
    }

    // Якщо fscanf не може прочитати пару чисел
    if (ferror(file)) {
        printf("Error reading from file\n");
    } else if (feof(file)) {
        printf("End of file reached\n");
    } else {
        printf("Incorrect data format in the file\n");
    }

    fclose(file);
}

// Функція для отримання імені файлу
void get_filename(char* filename, size_t len) {
    printf("Enter the filename: ");
    if (fgets(filename, len, stdin) == NULL) {
        printf("Error reading filename\n");
        exit(EXIT_FAILURE);
    }
    // Видалення символа нового рядка, якщо він є
    filename[strcspn(filename, "\n")] = '\0';
}

// Прототипи функцій
void read_data_from_file(const char* filename);
void select_input_output_mode(Vector* vec, Matrix* mat, int mode, const char* filename);
void add_matrices_and_output(Matrix* mat1, Matrix* mat2, int mode, const char* filename);
void multiply_matrices_and_output(Matrix* mat1, Matrix* mat2, int mode, const char* filename);
void multiply_matrix_vector_and_output(Matrix* mat, Vector* vec, int mode, const char* filename);

// Основна функція для демонстрації
int main() {

    // Змінна для імені файлу
    char filename[100];

    // Попросити користувача ввести ім'я файлу
    printf("Enter the filename: ");
    scanf("%s", filename);  // Зчитуємо введене ім'я файлу

    // Змінні для вимірювання часу
    clock_t start_time, end_time;
    double total_time;

    // Початок вимірювання часу
    start_time = clock();

    FILE *file = fopen(filename, "r"); // Відкриваємо файл для читання
    if (file == NULL) {
        printf("Error opening file\n"); // Якщо файл не відкривається
        return 1;
    }

    int a, b;
    char line[256]; // Для зчитування кожного рядка

    while (fgets(line, sizeof(line), file)) {              // Читаємо кожен рядок з файлу
        printf("Trying to read: %s", line);                // Виводимо рядок для налагодження
                                                           // Перевіряємо, чи правильно зчитано два числа
        int count = sscanf(line, "%d %d", &a, &b);  
        if (count != 2) {                                  // Якщо не два числа, виводимо помилку
            printf("The data format in the file is incorrect. Read %d values instead of 2\n", count);
        } else {
            printf("Read values: a = %d, b = %d\n", a, b); // Якщо все правильно, виводимо значення
        }
    }

    if (feof(file)) {  // Якщо досягнуто кінця файлу
        printf("End of file reached\n");
    } else {           // Якщо не досягнуто кінця файлу через помилку
        printf("There was an error reading the file\n");
    }

    fclose(file);      // Закриваємо файл після зчитування

    int vec_size = 3, mat_rows = 3, mat_cols = 3;
    Vector* vec = create_vector(vec_size);
    Matrix* mat = create_matrix(mat_rows, mat_cols);

    int mode;
    printf("Choose input/output mode (0 for console, 1 for file): ");
    scanf("%d", &mode);
    if (mode != 0 && mode != 1) {
        printf("Invalid mode\n");
        free_vector(vec);
        free_matrix(mat);
        return EXIT_FAILURE;
    }

    // Викликаємо функцію з іменем файлу, яке ввів користувач
    read_data_from_file(filename);
    
    select_input_output_mode(vec, mat, mode, filename); // Вибір режиму вводу

    int operation;
    printf("Choose operation (1 for add, 2 for multiply matrix-matrix, 3 for multiply matrix-vector): ");
    scanf("%d", &operation);
    switch (operation) {
        case 1:
            add_matrices_and_output(mat, mat, mode, filename);
            break;
        case 2:
            multiply_matrices_and_output(mat, mat, mode, filename);
            break;
        case 3:
            multiply_matrix_vector_and_output(mat, vec, mode, filename);
            break;
        default:
            printf("Invalid operation\n");
            break;
    }

    free_vector(vec);
    free_matrix(mat);

    // Кінець вимірювання часу
    end_time = clock();
    
    // Обчислення часу виконання
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Виведення часу виконання
    printf("Time taken to execute the program: %f seconds\n", total_time);

    return 0;
}