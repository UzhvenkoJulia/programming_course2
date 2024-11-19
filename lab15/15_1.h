// Створення власних класів. Інкапсуляція.

// 1) клас раціональне число
// nominator - ціле число, denominator - натуральне число.

// скорочення раціонального числа через НСД
// перевантаження 
// точність 0.01 
// phi^2 \ 12 = 1 - 1\2^2 + 1\3^2 - 1\4^2 + ...

#pragma once
// #pragma once — це директива препроцесора в C++, яка використовується для запобігання багаторазовому включенню одного і того ж заголовкового файлу в різні частини коду. 
// Це є альтернативою традиційним механізмам include guard, які використовують макроси #ifndef, #define і #endif.
#include <iostream>
#include <cmath>

class Rational {
private:
    int nom;
    unsigned denom;
public:
    Rational(): nom(0), denom(0) {}
    Rational(int x, unsigned y): nom(x), denom(y) {
        reduce();
    }
    void show();
    int input();
    int set_norm(int x) {
        nom = x;
        return 0;
    }
    int set_denom(int y) {
        if(y != 0) {
            denom = y;
            return 0;
        }
        return -1;
    }
    Rational add(const Rational& x);
    Rational mull(const Rational& y);
    bool less(const Rational& x) {
        return(nom * x.denom < denom * x.nom);
    }
    double compare(double z) {
        return (fabs(z - (nom + 0.) / denom));
    }
    static unsigned gcd(unsigned x, unsigned y);
private:
    void reduce();
};