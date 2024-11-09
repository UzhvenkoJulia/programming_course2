#include <iostream>
#include <fstream>
#include <cctype>  // для перевірки символів

using namespace std;

int main() {
    char f_name[] = "Test.txt";  
    fstream f(f_name);  
    if(!f) {  
        cerr << "error reading file" << f_name << "\n";
        return 1;  
    }

    char c;  // зчитування кожного символу з файлу
    int num = 0;  // зберігання поточного числа
    int num2 = 0;  // зберігання попереднього числа
    int summ = 0;  
    int prev_sign = 0;  // відстеження попереднього знаку (0 - не встановлено, 1 - плюс, 2 - мінус)

    while(f >> c) {  // читання символів з файлу, поки не досягнемо кінця
        if(isdigit(c)) { 
            int d = c - '0';  // перетворення символу в цифру
            num = num * 10 + d;  // формування числа (наприклад, з "5" і "3" утворюється 53)
        }
        else if(c == '-') {  
            num2 = num;  
            num = 0;  
            if (prev_sign == 1 || prev_sign == 0) {  // якщо попередній знак був плюс або ще не був встановлений
                summ += num2;  
            }
            else if(prev_sign == 2) {  
                summ -= num2;  
            }
            prev_sign = 2;  
        }
        else if(c == '+') {  
            num2 = num;  
            num = 0;  
            if (prev_sign == 1 || prev_sign == 0) {  
                summ += num2;  
            }
            else if(prev_sign == 2) {  
                summ -= num2;  
            }
            prev_sign = 1; 
        }
        else if(c == '=') {  
            num2 = num;  
            if(prev_sign == 1) {  
                summ += num2;  
            }
            else if(prev_sign == 2) {  
                summ -= num2; 
            }
            cout << "sum = " << summ << "\n";  
        }
        else {  // якщо символ не є цифрою, плюсом, мінусом або рівністю
            cout << "Not required format:" << c << "- incorrect symbol\n";  
        }
    }
}