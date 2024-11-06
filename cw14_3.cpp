#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string reverseWords(const string& text) {
    stringstream input(text);
    string word, decodedText;
    
    // опрацювання кожного слова або розділеної пунктуацією групу
    while (input >> word) {
        reverse(word.begin(), word.end());
        decodedText += word + " ";
    }

    return decodedText;
}

int main() {
    ifstream inFile("encoded_text.txt");  
    ofstream outFile("decoded_text.txt"); 

    if (!inFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    string line, decodedMessage;
    
    while (getline(inFile, line)) {
        // розшифруйте поточний рядок і додайте його до останнього повідомлення
        decodedMessage += reverseWords(line) + "\n";
    }

    outFile << decodedMessage;

    cout << "Decoding complete!! Check decoded_text.txt for results" << endl;

    inFile.close();
    outFile.close();
}