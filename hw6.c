// Бітові операції
// Домашнє завдання 6: 6.20, 6.15

// 6.20
// Щоб викреслити i-тий біт із двійкового представлення натурального числа, потрібно розбити число на дві частини:
// молодші біти (від 0 до i-1) та старші біти (від i+1 до кінця).
// Після цього старші біти потрібно змістити на один біт вправо, а потім з'єднати обидві частини

// 6.15
// 32-бітні числа — це цілі числа, які можуть бути представлені 32-бітовим (4-байтовим) двійковим числом.
// У 32-бітній системі значення числа обмежується кількістю бітів — від 0 до 31 (всього 32 біти).

#include <stdio.h>

// 6.15
int count_ones(unsigned int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

// для підрахунку співпадаючих бітів
int count_matching_bits(unsigned int a, unsigned int b) {
    unsigned int xnor = ~(a ^ b); // побітове виключне "або" та інверсія
    return count_ones(xnor);
}

// для викреслення i-го біта
unsigned int remove_bit(unsigned int num, int i) {
    // збереження молодших бітів (від 0 до i-1)
    unsigned int lower_bits = num & ((1U << i) - 1);

    // старші біти (зсунуті вправо на 1)
    unsigned int upper_bits = (num >> (i + 1)) << i;

    // об'єд молодші та зсунуті старші біти
    return upper_bits | lower_bits;
}

int main() {
    unsigned int m, n, num;
    int i;

    // для завдання 6.15
    printf("Enter two natural 32-bit numbers m and n:\n");
    scanf("%u %u", &m, &n);

    unsigned int common_ones = count_ones(m & n);
    printf("Number of common units: %u\n", common_ones);

    unsigned int matching_bits = count_matching_bits(m, n);
    printf("Number of matching bits: %u\n", matching_bits);

    // для завдання 6.20
    printf("Enter the number and bit index to strike out (starting from 0):\n");
    scanf("%u %d", &num, &i);

    unsigned int result = remove_bit(num, i);
    printf("The result after deleting the %d bit: %u\n", i, result);

}