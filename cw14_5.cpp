#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

void createFile(const string& filename, int N) {
    ofstream file(filename);
    if (!file) {
        cerr << "Failed to open the file!" << endl;
        return;
    }
    
    for (int i = 0; i < N; ++i) {
        string surname, group;
        int course, numGrades;
        
        cout << "Enter student's surname: ";
        cin >> surname;
        cout << "Enter student's course: ";
        cin >> course;
        cout << "Enter student's group: ";
        cin >> group;
        cout << "Enter the number of grades: ";
        cin >> numGrades;
        
        file << surname << ", " << course << ", " << group << ", ";
        
        for (int j = 0; j < numGrades; ++j) {
            int grade;
            cout << "Enter grade " << j + 1 << ": ";
            cin >> grade;
            if (j != 0) {
                file << ", "; // add comma between grades
            }
            file << grade;
        }
        file << endl;
    }
    
    file.close();
    cout << "File successfully created!" << endl;
}

double calculateAverage(const vector<int>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

void findWorstStudent(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open the file!" << endl;
        return;
    }
    
    string line;
    string worstSurname;
    double worstAverage = numeric_limits<double>::infinity();
    
    while (getline(file, line)) {
        stringstream ss(line);
        string surname, course, group, gradesStr;
        int courseNum;
        
        getline(ss, surname, ',');
        getline(ss, course, ',');
        getline(ss, group, ',');
        getline(ss, gradesStr);
        
        stringstream gradesStream(gradesStr);
        vector<int> grades;
        int grade;
        
        while (gradesStream >> grade) {
            grades.push_back(grade);
            if (gradesStream.peek() == ',') {
                gradesStream.ignore();
            }
        }
        
        double average = calculateAverage(grades);
        
        if (average < worstAverage) {
            worstAverage = average;
            worstSurname = surname;
        }
    }
    
    file.close();
    
    cout << "The student with the worst average grade is: " << worstSurname << " (average grade: " << worstAverage << ")" << endl;
}

int main() {
    int N;
    string filename = "students.txt";
    
    cout << "Enter the number of students: ";
    cin >> N;
    
    createFile(filename, N);
    
    findWorstStudent(filename);
}