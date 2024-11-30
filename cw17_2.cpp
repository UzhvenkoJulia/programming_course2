// клас людина (члени: ПІБ, стать, вік)
// студент (додано: курс, група, ВУЗ)
// викладач (ВУЗ, посада, з.п.)
// різна к-сть вхідних даних
// клас Аспірант <-(нащадок) студент, викаладач 


#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


class Human {
protected:
    string fullName;
    string gender;
    int age;

public:
    Human() : fullName(""), gender(""), age(0) {}
    Human(string name, string gen, int a) : fullName(name), gender(gen), age(a) {}
    virtual void input() {
        cout << "enter full name: ";
        getline(cin, fullName);
        cout << "enter gender: ";
        getline(cin, gender);
        cout << "enter age: ";
        while (!(cin >> age) || age <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "invalid input, enter a positive integer for AGE: ";
        }
        cin.ignore(); 
    }
    virtual void output() const {
        cout << "full NAME: " << fullName << endl;
        cout << "gender: " << gender << endl;
        cout << "age: " << age << endl;
    }
    virtual ~Human() {}
};
class Student : public Human {
protected:
    int year;
    string group;
    string university;

public:
    Student() : Human(), year(0), group(""), university("") {}
    Student(string name, string gen, int a, int yr, string grp, string uni) 
        : Human(name, gen, a), year(yr), group(grp), university(uni) {}

    void input() override {
        Human::input();
        cout << "enter YEAR: ";
        while (!(cin >> year) || year <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "invalid input, enter a positive integer for YEAR: ";
        }
        cin.ignore();
        cout << "enter group: ";
        getline(cin, group);
        cout << "enter university: ";
        getline(cin, university);
    }

    void output() const override {
        Human::output();
        cout << "year: " << year << endl;
        cout << "group: " << group << endl;
        cout << "university: " << university << endl;
    }
};

class Teacher : public Human {
protected:
    string university;
    string position;
public:
    Teacher() : Human(), university(""), position("") {}
    Teacher(string name, string gen, int a, string uni, string pos)
        : Human(name, gen, a), university(uni), position(pos) {}

    void input() override {
        Human::input();
        cout << "enter University: ";
        getline(cin, university);
        cout << "enter Position: ";
        getline(cin, position);
    }

    void output() const override {
        Human::output();
        cout << "university: " << university << endl;
        cout << "position: " << position << endl;
    }
};
class Postgraduate : public Teacher {
public:
    Postgraduate() : Teacher() {}
    Postgraduate(string name, string gen, int a, string uni, string pos)
        : Teacher(name, gen, a, uni, pos) {}

    void input() override {
        Teacher::input();
    }

    void output() const override {
        Teacher::output();
    }
};

int main() {
    vector<Human*> people;
    int choice;

    do {
        cout << "1. Add Student\n2. Add Teacher\n3. Add Postgraduate\n0. Exit\nChoose an option: ";
        while (!(cin >> choice) || choice < 0 || choice > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "invalid choice";
        }
        cin.ignore();

        Human* person = nullptr;
        if (choice == 1) {
            person = new Student();
        } else if (choice == 2) {
            person = new Teacher();
        } else if (choice == 3) {
            person = new Postgraduate();
        }

        if (person) {
            cout << "\nenter details for the new person:\n";
            person->input();
            people.push_back(person);
            cout << "\nperson added successfully\n\n";
        }
    } while (choice != 0);

    cout << "\npeople in the system:\n";
    for (const auto& person : people) {
        person->output();
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
    }
    for (auto& person : people) {
        delete person;
    }
    
}