// Робота з класами. Наслідування та поліморфізм

// чисто віртуальний клас, метод

// Описати клас Студент на базі класу Person. 
// У класі Студент повинна бути інформація про оцінки отримані ним протягом сесії (за 5-ти бальною та 100 бальною шкалами).
// Скласти програму для обчислення нарахованої студентам стипендії в залежності від результатів сесії:

// • За старим підходом нарахування стипендії (середній бал за всі іспити має бути не меншим ніж 4 за 5-ти бальною шкалою).
// • З новим підходом нарахування стипендії (стипендію отримують 40% від загального числа студентів, які є найкращими по рейтингу)

// Вказівка: інформацію про студентів представити у вигляді масиву. Дані зчитувати з клавіатури.

// To meet the requirement that students should be of 2 different but connected classes, we can refactor the code by separating the Student class into two related classes:
// one class for handling personal information (Person) and another class for managing academic details and scholarship calculations (StudentDetails).


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

// Person class handling personal information
class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& name = "", int age = 0) : name(name), age(age) {}

    virtual void input() {
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter age: ";
        std::cin >> age;
    }

    virtual void display() const {
        std::cout << "Name: " << name << ", Age: " << age;
    }
};

// StudentDetails class for academic details
class StudentDetails {
private:
    std::vector<int> grades5; // 5-point scale grades
    std::vector<int> grades100; // 100-point scale grades
    double average5; // average grade for 5-point scale
    double average100; // average grade for 100-point scale

public:
    StudentDetails() : average5(0), average100(0) {}

    void inputGrades() {
        grades5.resize(5);
        grades100.resize(5);

        std::cout << "Enter grades (5-point scale): ";
        for (int& grade : grades5) {
            std::cin >> grade;
        }

        std::cout << "Enter grades (100-point scale): ";
        for (int& grade : grades100) {
            std::cin >> grade;
        }

        calculateAverages();
    }

    void displayGrades() const {
        std::cout << "\n5-point grades: ";
        for (int grade : grades5) {
            std::cout << grade << " ";
        }
        std::cout << "\n100-point grades: ";
        for (int grade : grades100) {
            std::cout << grade << " ";
        }
        std::cout << "\nAverage (5-point): " << average5;
        std::cout << "\nAverage (100-point): " << average100;
    }

    double getAverage5() const { return average5; }
    double getAverage100() const { return average100; }

private:
    void calculateAverages() {
        average5 = std::accumulate(grades5.begin(), grades5.end(), 0.0) / grades5.size();
        average100 = std::accumulate(grades100.begin(), grades100.end(), 0.0) / grades100.size();
    }
};

// Combined Student class that inherits from Person and includes StudentDetails
class Student : public Person {
private:
    StudentDetails details;

public:
    Student(const std::string& name = "", int age = 0) : Person(name, age) {}

    void input() override {
        Person::input();
        details.inputGrades();
    }

    void display() const override {
        Person::display();
        details.displayGrades();
    }

    double getAverage5() const { return details.getAverage5(); }
    double getAverage100() const { return details.getAverage100(); }
};

// Scholarship calculation function
void calculateScholarships(const std::vector<Student>& students) {
    std::cout << "\nScholarships based on old system:\n";
    for (const auto& student : students) {
        if (student.getAverage5() >= 4.0) {
            std::cout << student.getAverage5() << " - Eligible for scholarship\n";
        } else {
            std::cout << student.getAverage5() << " - Not eligible for scholarship\n";
        }
    }

    std::cout << "\nScholarships based on new system:\n";
    std::vector<double> averages;
    for (const auto& student : students) {
        averages.push_back(student.getAverage100());
    }

    // Sort to determine top 40% of students
    std::sort(averages.begin(), averages.end(), std::greater<>());

    size_t top40Percent = averages.size() * 0.4;

    for (size_t i = 0; i < students.size(); ++i) {
        if (std::find(averages.begin(), averages.begin() + top40Percent, students[i].getAverage100()) != averages.end()) {
            std::cout << "Student " << i + 1 << ": Eligible for scholarship\n";
        } else {
            std::cout << "Student " << i + 1 << ": Not eligible for scholarship\n";
        }
    }
}

int main() {
    int n;
    std::cout << "Enter number of students: ";
    std::cin >> n;

    std::vector<Student> students(n);

    for (int i = 0; i < n; ++i) {
        std::cout << "\nStudent " << i + 1 << ":\n";
        students[i].input();
    }

    std::cout << "\nStudent data:\n";
    for (const auto& student : students) {
        student.display();
        std::cout << "\n";
    }

    calculateScholarships(students);

    return 0;
}
