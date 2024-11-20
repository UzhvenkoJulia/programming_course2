// Ввести рядок, що складається з символів латинського алфавіту, 
// слова в якому відокремлені пробілами (одним або декількома). 
// Перетворити кожне слово в рядку, видаливши з нього всі входження передостанньої літери цього слова 
// якщо довжина слова більше ніж 2 (к-сть пробілів між словами не змінювати).

/*#include <iostream>
#include <sstream> // для роботи з потоками рядків
#include <string>
#include <cctype> // для функцій isspace

// обробка слова
std::string processWord(const std::string& word) {
    if (word.length() <= 2) {
        return word; // якщо довжина слова <= 2, нічого не змінюємо
    }

    char secondLastChar = word[word.length() - 2]; // передостання літера слова
    std::string result;

    for (char c : word) {
        if (c != secondLastChar) {
            result += c; // додаємо символ, якщо він не передостанній
        }
    }

    return result;
}

// обробка рядка
std::string processString(const std::string& input) {
    std::istringstream stream(input);
    std::ostringstream result;
    std::string word;

    bool firstWord = true;

    while (stream >> word) {
        if (!firstWord) {
            result << ' '; // зберігаємо пробіл між словами
        }
        firstWord = false;

        result << processWord(word);
    }

    // додаємо оригінальні пробіли (якщо були декілька)
    std::string output = result.str();
    size_t pos = 0;
    for (char c : input) {
        if (std::isspace(c)) {
            output.insert(pos, " ");
            ++pos;
        } else {
            ++pos;
        }
    }

    return output;
}

int main() {
    std::string input;

    std::cout << "Enter the line: ";
    std::getline(std::cin, input);

    std::string output = processString(input);

    std::cout << "Result: " << output << std::endl;

}*/


#include <iostream>
#include <string>
#include <cctype>

std::string processWord(const std::string& word) {
    if (word.length() <= 2) {
        return word; 
    }

    char secondLastChar = word[word.length() - 2]; 
    std::string result;

    for (char c : word) {
        if (c != secondLastChar) {
            result += c; // додаємо символ, якщо він не передостанній
        }
    }

    return result;
}

std::string processString(const std::string& input) {
    std::string result;
    std::string currentWord;
    bool insideWord = false; // чи ми зараз обробляємо слово

    for (char c : input) {
        if (std::isspace(c)) {
            if (insideWord) {
                // якщо ми закінчили обробляти слово
                result += processWord(currentWord);
                currentWord.clear();
                insideWord = false;
            }
            result += c; // додаємо пробіл(и) до результату
        } else {
            insideWord = true;
            currentWord += c; // накопичуємо слово
        }
    }

    // обробка останнього слова, якщо воно є
    if (!currentWord.empty()) {
        result += processWord(currentWord);
    }

    return result;
}

int main() {
    std::string input;

    std::cout << "Enter the line: ";
    std::getline(std::cin, input);

    std::string output = processString(input);

    std::cout << "Result: " << output << std::endl;

}