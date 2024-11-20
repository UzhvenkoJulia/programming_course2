// Перетворення типів та робота з виключеннями

// перетворення вгору та вниз
// static_cast

// Створіть клас роботи з рядком, який має наступну властивість: 
// користувач задає власноруч допустиму множину символів, 
// з яких може складатись цей рядок у вигляді масиву символів. 
// Члени класу: масив допустимих символів та його довжина, масив введених символів та його довжина. 
// Методи класу:

// • перезавантажте методи введення/виведення в/з консолі та в/з текстового файлу; 

// • методи зміни (додавання/видалення) допустимих символів;

// • довжина рядку;

// • конкатенація рядків (при цьому допустимі символи - це перетин множин допустимих символів, тобто після конкатенації в нас може зменшитися результатний рядок);

// • хеш рядку (ваш будь-який розумний варіант хешу). ??

// Забезпечити ініціювання помилки при неправильному введенні та ро боті з рядками та роботі з файлами.


#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set> // -  заголовковий файл у C++, який надає можливість використовувати контейнер std::unordered_set. Цей контейнер зберігає унікальні значення, забезпечуючи швидкий доступ до них за допомогою хешування.
#include <algorithm>
#include <stdexcept> // - містить визначення винятків (exception classes) для обробки помилок.

class StringHandler {
private:
    std::unordered_set<char> allowedChars; // Множина допустимих символів
    std::string inputString;               // Введений рядок

    // перевіряє, чи всі символи в рядку є допустимими
    bool isValidString(const std::string& str) {
        for (char ch : str) {
            if (allowedChars.find(ch) == allowedChars.end()) {
                return false;
            }
        }
        return true;
    }

public:
    // конструктор
    StringHandler(const std::vector<char>& allowed)
        : allowedChars(allowed.begin(), allowed.end()) {}

    void inputFromConsole() {
        std::cout << "Enter a string: ";
        std::getline(std::cin, inputString);
        if (!isValidString(inputString)) {
            throw std::invalid_argument("Input contains invalid characters");
        }
    }

    void outputToConsole() const {
        std::cout << "Current string: " << inputString << std::endl;
    }

    void inputFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::ios_base::failure("Failed to open file");
        }
        std::getline(file, inputString);
        file.close();
        if (!isValidString(inputString)) {
            throw std::invalid_argument("File contains invalid characters");
        }
    }

    void outputToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::ios_base::failure("Failed to open file");
        }
        file << inputString;
        file.close();
    }

    // додавання допустимого символу
    void addAllowedChar(char ch) {
        allowedChars.insert(ch);
    }

    // видалення допустимого символу
    void removeAllowedChar(char ch) {
        allowedChars.erase(ch);
    }

    // отримання довжини рядка
    size_t getLength() const {
        return inputString.length();
    }

    // конкатенація рядків
    void concatenate(const StringHandler& other) {
        std::unordered_set<char> resultAllowedChars;
        for (char ch : allowedChars) {
            if (other.allowedChars.find(ch) != other.allowedChars.end()) {
                resultAllowedChars.insert(ch);
            }
        }
        allowedChars = resultAllowedChars;

        std::string newString = inputString + other.inputString;
        std::string validString;
        for (char ch : newString) {
            if (allowedChars.find(ch) != allowedChars.end()) {
                validString += ch;
            }
        }
        inputString = validString;
    }

    // отримання хешу рядка (проста хеш-функція)
    size_t hash() const {
        size_t hashValue = 0;
        for (char ch : inputString) {
            hashValue = hashValue * 31 + ch;
        }
        return hashValue;
    }
};

int main() {
    try {
        // допустимі символи
        std::vector<char> allowed = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        StringHandler strHandler1(allowed);

        strHandler1.inputFromConsole();
        strHandler1.outputToConsole();

        strHandler1.addAllowedChar('h');
        strHandler1.inputFromConsole();
        strHandler1.outputToConsole();

        strHandler1.outputToFile("output.txt");
        strHandler1.inputFromFile("output.txt");
        strHandler1.outputToConsole();

        StringHandler strHandler2({'a', 'b', 'c', 'h'});
        strHandler2.inputFromConsole();
        strHandler1.concatenate(strHandler2);
        strHandler1.outputToConsole();

        std::cout << "String hash: " << strHandler1.hash() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

}

// Хеш-функція реалізована як проста множення з коефіцієнтом (31).