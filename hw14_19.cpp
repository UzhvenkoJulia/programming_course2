#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;

int main() {
    char c;
    cout << "Enter a capital Latin letter: ";
    cin >> c;
    
    // перетворюємо на малу літеру для порівняння
    char lower_c = tolower(c);
    char upper_c = toupper(c);

    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    string word;
    bool found = false;

    // читаємо кожне слово з вхідного файлу
    while (inputFile >> word) {
        // видаляємо розділові знаки з початку та кінця слова
        size_t start = 0;
        size_t end = word.length() - 1;

        // видаляємо символи, що не є літерами, з початку слова
        while (start < word.length() && !isalpha(word[start])) {
            start++;
        }

        // видаляємо символи, що не є літерами, з кінця слова
        while (end > start && !isalpha(word[end])) {
            end--;
        }

        // якщо слово після очищення має хоча б одну літеру
        if (start <= end) {
            word = word.substr(start, end - start + 1);
            // перевіряємо, чи починається слово на задану літеру
            if (tolower(word[0]) == lower_c) {
                outputFile << word << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No words found starting with the letter " << c << "." << endl;
    }

    inputFile.close();
    outputFile.close();
}