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


// Замість char використовувати шаблонний тип T для створення класу, що підтримує будь-який тип, наприклад, char, int, std::string..
// Внести відповідні зміни в контейнер std::unordered_set, щоб він використовував шаблонний тип T замість конкретного типу char.

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set> // - заголовковий файл у C++, який надає можливість використовувати контейнер std::unordered_set.
#include <algorithm>
#include <stdexcept> // - містить визначення винятків (exception classes) для обробки помилок.

template <typename T> // шаблон класу для підтримки будь-якого типу
class StringHandler {
private:
    std::unordered_set<T> allowedChars; // множина допустимих символів
    std::vector<T> inputString;          // введений рядок (вектор, щоб підтримувати будь-які типи)

    // перевіряє, чи всі символи в рядку є допустимими
    bool isValidString(const std::vector<T>& str) {
        for (const T& ch : str) {
            if (allowedChars.find(ch) == allowedChars.end()) {
                return false;
            }
        }
        return true;
    }

public:
    // конструктор
    StringHandler(const std::vector<T>& allowed)
        : allowedChars(allowed.begin(), allowed.end()) {}

    void inputFromConsole() {
        std::cout << "Enter a string (use space as delimiter for multiple elements): ";
        std::string line;
        std::getline(std::cin, line);
        inputString.clear();
        
        // розділення введеного рядка за пробілами на елементи типу T
        std::istringstream iss(line);
        T item;
        while (iss >> item) {
            inputString.push_back(item);
        }

        if (!isValidString(inputString)) {
            throw std::invalid_argument("Input contains invalid characters");
        }
    }

    void outputToConsole() const {
        std::cout << "Current string: ";
        for (const T& ch : inputString) {
            std::cout << ch << " ";
        }
        std::cout << std::endl;
    }

    void inputFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::ios_base::failure("Failed to open file");
        }

        inputString.clear();
        T item;
        while (file >> item) {
            inputString.push_back(item);
        }
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
        
        for (const T& ch : inputString) {
            file << ch << " ";
        }
        file.close();
    }

    // додавання допустимого символу
    void addAllowedChar(const T& ch) {
        allowedChars.insert(ch);
    }

    // видалення допустимого символу
    void removeAllowedChar(const T& ch) {
        allowedChars.erase(ch);
    }

    // отримання довжини рядка
    size_t getLength() const {
        return inputString.size();
    }

    // конкатенація рядків
    void concatenate(const StringHandler<T>& other) {
        std::unordered_set<T> resultAllowedChars;
        for (const T& ch : allowedChars) {
            if (other.allowedChars.find(ch) != other.allowedChars.end()) {
                resultAllowedChars.insert(ch);
            }
        }
        allowedChars = resultAllowedChars;

        std::vector<T> newString = inputString;
        newString.insert(newString.end(), other.inputString.begin(), other.inputString.end());

        std::vector<T> validString;
        for (const T& ch : newString) {
            if (allowedChars.find(ch) != allowedChars.end()) {
                validString.push_back(ch);
            }
        }
        inputString = validString;
    }

    // отримання хешу рядка (проста хеш-функція)
    size_t hash() const {
        size_t hashValue = 0;
        for (const T& ch : inputString) {
            hashValue = hashValue * 31 + std::hash<T>()(ch); // використовуємо стандартний хеш-функцію для T
        }
        return hashValue;
    }
};

int main() {
    try {
        // допустимі символи для типу char
        std::vector<char> allowed = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        StringHandler<char> strHandler1(allowed);

        strHandler1.inputFromConsole();
        strHandler1.outputToConsole();

        strHandler1.addAllowedChar('h');
        strHandler1.inputFromConsole();
        strHandler1.outputToConsole();

        strHandler1.outputToFile("output.txt");
        strHandler1.inputFromFile("output.txt");
        strHandler1.outputToConsole();

        StringHandler<char> strHandler2({'a', 'b', 'c', 'h'});
        strHandler2.inputFromConsole();
        strHandler1.concatenate(strHandler2);
        strHandler1.outputToConsole();

        std::cout << "String hash: " << strHandler1.hash() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Хеш-функція реалізована як проста множення з коефіцієнтом (31)
