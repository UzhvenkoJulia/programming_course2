// ПЕРЕТВОРЕННЯ ТИПІВ ТА РОБОТИ З ВИКЛЮЧЕННЯМИ
// static_cast


#include <iostream>
#include <fstream>
#include <cmath>

class Rational { // дріб
// (cin>>, cout<<)
// перевантаження двох операторів віднімання
private:
    int nom;  
    unsigned denom; 

public:
    Rational(int n = 0, unsigned d = 1) : nom(n), denom(d) {
        if (denom == 0) {
            std::cout << "denominator cannot be zero during initialization\n";
            denom = 1; 
        }
        reduce();
    }

    void show() const {
        std::cout << nom << "/" << denom << "\n";
    }

    // оператор введення -> перевантження
    friend std::istream& operator>>(std::istream& in, Rational& r) {
        std::cout << "numerator: ";
        in >> r.nom;
        std::cout << "denominator: ";
        in >> r.denom;

        if (r.denom == 0) {
            std::cout << "denominator cannot be zero during input\n";
            r.denom = 1;
        }

        r.reduce();
        return in;
    }

    // оператор виведення -> перевантження
    friend std::ostream& operator<<(std::ostream& out, const Rational& r) {
        out << r.nom << "/" << r.denom;
        return out;
    }

    // віднімання -> перевантження
    Rational operator-(const Rational& other) const {
        int t = nom * other.denom - denom * other.nom;
        unsigned y = denom * other.denom;
        return Rational(t, y);
    }

    // ділення 
    Rational operator/(const Rational& other) const {
        if (other.nom == 0) {
            std::cout << "cant divide by zero\n";
            return Rational(0, 1); 
        }
        int t = nom * other.denom;
        unsigned y = denom * other.nom;
        return Rational(t, y);
    }

private:
    unsigned gcd(unsigned x, unsigned y) {
        while (y != 0) {
            unsigned temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }

    void reduce() {
        unsigned nsd = gcd(abs(nom), denom);
        nom /= nsd;
        denom /= nsd;
    }
};

// дружня функція запису раціонального дробу в файл
// тіло програми
void write_rational_to_file(const Rational& r, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cout << "failed to open the file for writing\n";
        return;  
    }
    out << r;
    std::cout << "eational number written to file: " << filename << "\n";
}

int main() {
    Rational r1, r2;
    std::cin >> r1;
    std::cin >> r2;
    Rational result = r1 - r2;
    std::cout << "result of subtraction: " << result << std::endl;
    Rational division_result = r1 / r2;
    std::cout << "result of division: " << division_result << std::endl;

    write_rational_to_file(result, "output.txt");

}