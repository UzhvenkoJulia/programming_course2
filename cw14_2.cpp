#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

// переведення першої літери слова в верхній регістр
void capitalizeFirstLetter(std::string &word) {
    if (!word.empty()) {
        word[0] = toupper(word[0]);
    }
}

// перетворення слова в нижній регістр
std::string toLowerCase(const std::string &word) {
    std::string lowerWord = word;
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
    return lowerWord;
}

int main() {
    std::ifstream inputFile("input.txt");  
    std::ofstream outputFile("output.txt");  

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    std::string word, previousWord, modifiedText;
    bool modifyNextWord = false;  

    while (inputFile >> word) {
        // перевіряємо, чи потрібно змінити поточне слово
        if (modifyNextWord) {
            capitalizeFirstLetter(word);  
            modifyNextWord = false;  
        }

        modifiedText += word + " ";

        std::string lowerPrevious = toLowerCase(previousWord);

        // якщо попереднє слово було "die", "der" або "das", ставимо позначку
        if (lowerPrevious == "die" || lowerPrevious == "der" || lowerPrevious == "das") {
            modifyNextWord = true;
        }

        previousWord = word;
    }

    outputFile << modifiedText;

    inputFile.close();
    outputFile.close();

    std::cout << "File processed successfully. The result is saved in output.txt\n";
}