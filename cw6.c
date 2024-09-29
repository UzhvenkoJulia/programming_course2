#include <stdio.h>
// Бітові операції

void firstTask() {
    unsigned char n;
    printf("n < 64 = ");
    scanf("%hhu", &n);
    unsigned long long result = 1ULL << n;
    printf("result = %llu \n", result);
}

void secondTask() {
    unsigned char n, k;
    int output;

    printf("n = ");
    scanf("%hhu", &n);

    printf("k = ");
    scanf("%hhu", &k);

    output = n | (1 << k);
    printf("output: %d \n", output);
}

void thirdTask() {
    unsigned long long m, output;
    int j;

    printf("m = ");
    scanf("%llu", &m);

    printf("j = ");
    scanf("%d", &j);

    output = m & ~(1ULL << j);

    printf("%llu \n", output);
    printf("%llx \n", output);
}

void fourthTask() {
    unsigned n, swapped;

    printf("n = ");
    scanf("%u", &n);

    unsigned byte1 = n & 0xFF;
    unsigned byte2 = (n >> 8) & 0xFF;
    unsigned byte3 = (n >> 16) & 0xFF;
    unsigned byte4 = (n >> 24) & 0xFF;
    swapped = (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4;
    printf("swapped result: %u \n", swapped);
    printf("swapped result (hexadecimal): 0x%X \n", swapped);
}

void fifthTask() {
    unsigned long long n;
    unsigned maxCount = 0, count = 0;

    printf("n = ");
    scanf("%llu", &n);

    while (n) {
        if (n & 1) {
            count++;
            if (count > maxCount) {
                maxCount = count;
            }
        } else {
            count = 0;
        }
        n >>= 1;
    }

    printf("max count of ones = %u \n", maxCount);
}

void sixthTaskA() {
    unsigned char x;

    printf("x = ");
    scanf("%hhu", &x);
    for (int i = 1; i < 33; i++) {
        unsigned long long y = ((i & (i - 1)) > 0);
        printf("i = %d, y = %llu\n", i, y);
        if (!(i & (i - 1))) printf("%u \n", i);
    }
}

void sixthTaskB() {
    unsigned char x;

    printf("x = ");
    scanf("%hhu", &x);
    for (int i = 1; i < 33; i++) {
        unsigned long long y = i & (-i);
        printf("i = %d, y = %llu\n", i, y);

        int count = 0;
        int temp = i;
        while (temp % 2 == 0) {
            temp /= 2;
            count++;
        }
        printf("count = %d \n", count);
    }
}

void seventhTask() {
    unsigned value = 0x12345678;

    unsigned byte1 = value & 0xFF; // 0x78
    unsigned byte2 = (value >> 8) & 0xFF; // 0x56
    unsigned byte3 = (value >> 16) & 0xFF; // 0x34
    unsigned byte4 = (value >> 24) & 0xFF; // 0x12

    if (byte1 == 0x78 && byte2 == 0x56 && byte3 == 0x34 && byte4 == 0x12) {
        printf("little-endian \n");
    } else if (byte1 == 0x12 && byte2 == 0x34 && byte3 == 0x56 && byte4 == 0x78) {
        printf("big-endian \n");
    } else {
        printf("unknown architecture \n");
    }
}

void twentySeventhTask() {
    unsigned long long n, m; // 64
    int i = 0;

    printf("n = ");
    scanf("%llu", &n);

    printf("m = ");
    scanf("%llu", &m);

    unsigned long long diff = n ^ m;

    while (i < 64) {
        if (diff & (1ULL << i)) printf("%d \n", i);
        i++;
    }
}

int main() {
    int task;
    printf("task = ");
    scanf("%d", &task);

    switch (task) {
        case 1: firstTask(); break;
        case 2: secondTask(); break;
        case 3: thirdTask(); break;
        case 4: fourthTask(); break;
        case 5: fifthTask(); break;
        case 6:
            sixthTaskA();
            sixthTaskB();
            break;
        case 7: seventhTask(); break;
        case 27: twentySeventhTask(); break;
        default: printf("invalid task number.\n"); break;
    }

}