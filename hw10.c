// Структури. Створення власного типу

// Домашнє завдання 10
// 10.6г : Визначити типи запису для зображення наступних понять
// та реалізуйте їх функції введення виведення:
// г) адреса (місто, вулиця, будинок, квартира);

// 10.11 : Задано масив Р розмірності N,
// компонентами якого є відомості про мешканців деяких міст.
// Інформація про кожного мешканця містить його прізвище,
// назву міста,
// місцеву адресу у вигляді вулиці,
// будинку,
// квартири.
// Визначити функцію пошуку двох будь-яких жителів, що мешкають у різних містах за однаковою адресою.

#include <stdio.h>
#include <string.h>

#define MAX_RESIDENTS 100
#define MAX_STRING_LENGTH 100

// зберігання адреси
typedef struct {
    char city[MAX_STRING_LENGTH];
    char street[MAX_STRING_LENGTH];
    int house;
    int apartment;
} Address;

// введення адреси

/*strcspn — функція, яка використовується для знаходження довжини початкової частини рядка
 *до першого входження будь-якого символу з заданого набору символів*/

void inputAddress(Address* addr) {
    printf("enter city: ");
    fgets(addr->city, MAX_STRING_LENGTH, stdin);
    addr->city[strcspn(addr->city, "\n")] = 0; // видалення символа нового рядка

    printf("enter street: ");
    fgets(addr->street, MAX_STRING_LENGTH, stdin);
    addr->street[strcspn(addr->street, "\n")] = 0;

    printf("enter house number: ");
    scanf("%d", &addr->house);
    printf("enter apartment number: ");
    scanf("%d", &addr->apartment);
    getchar(); // очистити буфер
}

// виведення адреси
void printAddress(const Address* addr) {
    printf("address: %s, street %s, house %d, apartment %d\n",
           addr->city, addr->street, addr->house, addr->apartment);
}

// 10.6г: адреса
void task10_6g() {
    Address addr;
    printf("enter address details:\n");
    inputAddress(&addr);
    printf("you entered:\n");
    printAddress(&addr);
}

// зберігання інформації про мешканця
typedef struct {
    char surname[MAX_STRING_LENGTH];
    Address address; // вкл структуру адреси
} Resident;

// введення інформації про мешканця
void inputResident(Resident* resident) {
    printf("enter surname: ");
    fgets(resident->surname, MAX_STRING_LENGTH, stdin);
    resident->surname[strcspn(resident->surname, "\n")] = 0;

    printf("enter address:\n");
    inputAddress(&resident->address); // використовуємо функцію введення адреси
}

// пошук жителів з однаковою адресою в різних містах
void findResidentsWithSameAddress(Resident* residents, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            /*strcmp — це функція, яка використовується для порівняння двох рядків*/

            if (strcmp(residents[i].address.city, residents[j].address.city) != 0 &&
                strcmp(residents[i].address.street, residents[j].address.street) == 0 &&
                residents[i].address.house == residents[j].address.house &&
                residents[i].address.apartment == residents[j].address.apartment) {
                printf("found residents:\n");
                printf("1 %s, ", residents[i].surname);
                printAddress(&residents[i].address);
                printf("2 %s, ", residents[j].surname);
                printAddress(&residents[j].address);
                return;
            }
        }
    }
    printf("no residents found with the same address in different cities\n");
}

// 10.11: функція для роботи з мешканцями
void task10_11() {
    Resident residents[MAX_RESIDENTS];
    int n;

    printf("enter the number of residents: ");
    scanf("%d", &n);
    getchar(); // очистити буфер

    for (int i = 0; i < n; i++) {
        printf("\nenter information for resident %d:\n", i + 1);
        inputResident(&residents[i]);
    }

    findResidentsWithSameAddress(residents, n);
}

int main() {
    printf("=== task 10.6g ===\n");
    task10_6g();

    printf("\n=== task 10.11 ===\n");
    task10_11();
    
}