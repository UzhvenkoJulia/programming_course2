// Динамічні масиви. Робота з вказівниками
// Робота з масивами, функціями та управління пам'яттю

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Завдання 1: Ввести масив дійсних чисел і підрахувати суму квадратів елементів
/*void input_sqt_matr(int n) {
     double arr[n];
     for (int i = 0; i < n; i++) {
             scanf("%lf", &arr[i]);
         }
     }*/

void task1() {
    int n;
    printf("Task 1:\nEnter the number of array elements: ");
    scanf("%d", &n);

    double *arr = (double *)malloc(n * sizeof(double));
    if (!arr) {
        printf("Memory allocation error\n");
        return;
    }

    printf("Enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    double sum_of_squares = 0;
    for (int i = 0; i < n; i++) {
        sum_of_squares += arr[i] * arr[i];
    }

    /*double sum_sqrt(const double* arr, int n) {
    double sum = 0;
    double* beg = arr;
    double* end = arr + n;
    for (beg <= end; beg++;) {
    double n_arr = *beg;
    sum += pow(n_arr, 2);
    }
    return sum;
    }*/

    printf("The sum of the squares of the elements: %.2f\n", sum_of_squares);
    free(arr);
}

/*struct Stack {
    int data;
    struct Stack* addr;
}stack;

int input_vec(double** arr, size_t n) {
    double* arr2 = (double*)malloc(n * sizeof(*arr));
    if (arr2 == NULL) {
        return 1;
    }
    for (size_t i = 0; i < n; i++) {
        printf("Enter elems for fow %zu: \n", i);
        scanf("%lf", &arr2[i]);
    }
    *arr = arr2;
    return 0;
}

void delete_vec(double *arr) {
    if(!arr){free(arr);}
}

int subt_vec(const double *ar1, const double *ar2, double **ar3, size_t n) {
    if(ar1 == NULL || ar2 == NULL) {
        return 1;
    }
    *ar3 = (double*)malloc(n * sizeof(**ar3));
    if(*ar3 == NULL) {
        return 1;
    }
    for(size_t i = 0; i < n; i++) {
        *ar3[i] = ar1[i] - ar2[i];
    }
    return 0;
}

void output_vec(const double *arr, size_t n) {
    for(size_t i = 0; i < n; i++) {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}*/

// Завдання 2: Ввести масив цілих чисел і підрахувати кількість повних квадратів і кубів
void task2() {
    int arr[100], count = 0;
    printf("\nTask 2:\nEnter whole numbers (end with 0):\n");

    while (count < 100) {
        int num;
        scanf("%d", &num);
        if (num == 0) break;
        arr[count++] = num;
    }

    int squares = 0, cubes = 0;
    for (int i = 0; i < count; i++) {
        int sqrt_val = (int)sqrt(arr[i]);
        if (sqrt_val * sqrt_val == arr[i]) squares++;
        int cbrt_val = (int)cbrt(arr[i]);
        if (cbrt_val * cbrt_val * cbrt_val == arr[i]) cubes++;
    }

    printf("Number of full squares: %d\n", squares);
    printf("Number of full cubes: %d\n", cubes);
}

/*void task2() {
    struct Stack s;
    int x, i = 0, a[100];
    do {
        struct Stack t;
        scanf("%d", &x);
        t.data = x;
        t.addr = malloc(sizeof(stack));
        t.addr = stack.addr;
        s.addr = NULL;
        s.data = 0;
    } while(x != 0);
    struct Stack t1;
    while(s.addr != NULL) {
        x = s.data;
        s = *(s.addr);
    }
}*/

// Завдання 3: Створити функцію для роботи з векторами
void task3() {
    size_t n;
    double *vec1, *vec2, *vec3; // double *vec1 = create_vector(n);
                                // double *vec2 = create_vector(n);
    /*double* create_vector(int n) {
    return (double *)malloc(n * sizeof(double));
    }*/
    /*input_vec(&vec1, n);
    output_vec(vec1, n);
    input_vec(&vec2, n);
    output_vec(vec2, n);*/
    /*// vec3 = sub_vec(vec1, vec2, n);
    // output_vec(vec3, n);
    // delete_vec(vec1);
    // delete_vec(vec2);
    // delete_vec(vec3);*/
    /*subt_vec(vec1, vec2, &vec3, n);
    output_vec(vec3, n);
    delete_vec(vec1);
    delete_vec(vec2);*/

    /*void output_matr1(const double *matr, size_t size);

    void output_matr2(const double **matr, size_t n) {
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                printf("%lf", matr[i][j]);
            }
            printf("\n");
        }
    }

    void input_matr1(const double *matr, size_t n);

    int input_matr2(double **matr, size_t n) {
        for (size_t i = 0; i < n; i++) {
            for(size_t j = 0; j < n; j++) {
                scanf("%lf", &matr[i][j]);
            }
        }
        return 0;
    }

    int create_matr2(double **matr, size_t n){

        matr = (double **)calloc(n, sizeof(*matr));
        if(matr == NULL) {
            return -1;
        }
        for(size_t i  = 0; i < n; i++) {
            matr[i] = (double*)calloc(n, sizeof(double));
            if (matr[i] == NULL) {
                return -1;
            }
        }
        return 0;
    }

    void delete_matr1(double *matr, size_t n);

    int delete_matr2(double **matr, size_t n) {
        if(matr == NULL) {
            return -1;
        }
        for (size_t i = 0; i < n; i++) {
            free(matr[i]);
        }
        free(matr);
    }*/

    /*void delete_vec(double *arr) {
        if(arr){free(arr);}
    }*/

    printf("\nTask 3:\nEnter the size of the vectors: ");
    scanf("%zu", &n);

    vec1 = (double *)malloc(n * sizeof(double));
    vec2 = (double *)malloc(n * sizeof(double));
    vec3 = (double *)malloc(n * sizeof(double));

    /*void free_vector(double* vec) {
    free(vec);
    }*/

    if (!vec1 || !vec2 || !vec3) {
        printf("Memory allocation error\n");
        free(vec1);
        free(vec2);
        free(vec3);
        return;
    }

    printf("Enter the elements of the first vector:\n");
    for (size_t i = 0; i < n; i++) {
        scanf("%lf", &vec1[i]);
    }

    printf("Enter the elements of the second vector:\n");
    for (size_t i = 0; i < n; i++) {
        scanf("%lf", &vec2[i]);
    }

    // Calculate the difference
    /*double *difference = create_vector(n);
    for (int i = 0; i < n; i++) {
    difference[i] = vec1[i] - vec2[i];
    }*/
    for (size_t i = 0; i < n; i++) {
        vec3[i] = vec1[i] - vec2[i];
    }

    /*int mull_matr1(const double **matr1, const double **matr2, double **matr3, size_t n) {
        if(matr1 == NULL || matr2 == NULL) {
            return -1;
        }
        create_matr2(matr3, n);
        double elem = 0.0;
        for(size_t i = 0; i < n; i++) {
            for(size_t j = 0; j < n; j++) {
                for (size_t k = 0; k < n; k++) {
                    matr3[i][j]+= matr1[i][j] * matr2[k][j];
                }
            }
        }
    }*/

    printf("The difference of vectors:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%.2f ", vec3[i]);
    }
    printf("\n");

    free(vec1);
    free(vec2);
    free(vec3);
}

// Завдання 4: Створити функцію для роботи з матрицями

/*double** create_matrix(int n) {
    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)calloc(n, sizeof(double)); // ініціалізуємо нулями
    }
    return matrix;
}

void free_matrix(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
*/

void task4() {
    int n;
    printf("\nTask 4:\nEnter the size of the matrices: ");
    scanf("%d", &n);

    double **matrix1 = (double **)malloc(n * sizeof(double *));  // create_matrix(n)
    double **matrix2 = (double **)malloc(n * sizeof(double *));
    double **result = (double **)malloc(n * sizeof(double *));  // double** matr3 = mult_matrix((const double**)matr1, (const double**)matr2, n);

    for (int i = 0; i < n; i++) {
        matrix1[i] = (double *)malloc(n * sizeof(double));
        matrix2[i] = (double *)malloc(n * sizeof(double));
        result[i] = (double *)malloc(n * sizeof(double));
        /*for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }*/
    }

    if (!matrix1 || !matrix2 || !result) {
        printf("Memory allocation error\n");
        return;
    }

    printf("Enter the elements of the first matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    // Matrix multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;  // Initialize the result matrix
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Product of matrices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    // Freeing allocated memory
    for (int i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1); // free_matrix(matrix1, n);
    free(matrix2);  // free_matrix(matrix2, n);
    free(result);  // free_matrix(result, n);
    /*printf("Result of multiplication:\n");
    output_matr((const double**)matr3, n);

    delete_matr(matr1, n);
    delete_matr(matr2, n);
    delete_matr(matr3, n);*/
}

int main() {
    task1();
    task2();
    task3();
    task4();
}