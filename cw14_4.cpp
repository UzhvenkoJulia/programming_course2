#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>
#include <regex> // регулярні вирази


/*
using namespace std;

bool checkTags(ifstream f1, string openTD = "<td>", string closeTD = "</td>") {
    int opentag = 0;
    int closetag = 0;
    string buf;
    while(!f1.eof()) {
        if(f1 >> buf) {
            if(buf == openTD) {
                opentag ++;
            }
            else if(buf == closeTD) {
                closetag ++;
            }
            if(closetag > opentag) {
                return false;
            }
            else {
                break;
            }
        }
        return closetag == opentag;
    }
}

int main() {
    const char* fileName = "input_4.txt";
    ifstream f1(fileName);
    if(f1.bad()) {
        cerr << "Error opening file " << fileName << endl;
    }
    cout << "Check" << boolalpha << checkTags(f1);
    f1.close();
}*/


// функція для перевірки правильності тегів <td>
bool checkTdTags(const std::string& line) {
    std::stack<std::string> tagStack;  // стек для зберігання відкритих тегів
    
    // використовуємо регулярний вираз для знаходження тегів <td> та </td>
    std::regex tdRegex("<(/?td)>");
    std::smatch match;
    std::string::const_iterator searchStart(line.cbegin());

    while (std::regex_search(searchStart, line.cend(), match, tdRegex)) {
        // якщо знайдено відкритий тег <td>
        if (match.str(1) == "td" && match.str(0)[1] != '/') {
            tagStack.push(match.str(0));  // додаємо відкритий тег у стек
        } else if (match.str(1) == "td" && match.str(0)[1] == '/') {
            // якщо тег </td>, то перевіряємо чи є відповідний відкритий тег
            if (!tagStack.empty() && tagStack.top() == "<td>") {
                tagStack.pop();  // відповідний відкритий тег знайдений, забираємо його з стека
            } else {
                return false;
            }
        }
        searchStart = match.suffix().first;  // продовжуємо пошук після знайденого тегу
    }

    // якщо стек порожній, значить всі теги коректно закриті
    return tagStack.empty();
}

int main() {
    std::ifstream inputFile("input_4.txt");  
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    std::string line;
    bool allTagsCorrect = true;

    while (std::getline(inputFile, line)) {
        // перевіряємо правильність тегів <td> в кожному рядку
        if (!checkTdTags(line)) {
            std::cout << "Error in line: " << line << std::endl;
            allTagsCorrect = false;
        }
    }

    if (allTagsCorrect) {
        std::cout << "All <td> tags are correct" << std::endl;
    } else {
        std::cout << "Errors detected in <td> tags" << std::endl;
    }

    inputFile.close();
}