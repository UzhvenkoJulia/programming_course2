// Робота з класом рядок на С++

// Даний рядок-речення з символів латинського алфавіту. 
// Перетворити рядок так, щоб кожне слово починалося з великої літери.

#include <iostream>
#include <string>
#include <cctype> // для функцій toupper, isspace

// перетворення рядка
std::string capitalizeWords(const std::string& input) {
    std::string result = input;
    bool newWord = true; // прапорець для визначення початку нового слова

    for (size_t i = 0; i < result.size(); ++i) {
        if (std::isspace(result[i])) {
            newWord = true; // якщо символ пробіл, готуємось до нового слова
        } else if (newWord) {
            result[i] = std::toupper(result[i]); // робимо літеру великою
            newWord = false; // далі всередині слова
        }
    }

    return result;
}

int main() {
    std::string input;

    std::cout << "Enter the line: ";
    std::getline(std::cin, input);

    std::string output = capitalizeWords(input);

    std::cout << "Result:" << output << std::endl;

}