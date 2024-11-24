// Робота з класами. Наслідування та поліморфізм

// unsigned byear; // рік народження

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Person {
public:
    string name;
    unsigned byear;
    
    virtual void input() {
        cin.ignore(); // очищення буфера перед введенням
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter birth year: ";
        cin >> byear;
    }
    
    virtual void show() const {
        cout << "Name: " << name << "\nBirth year: " << byear << endl;
    }
    
    friend ostream &operator<<(ostream &out, const Person &p) {
        out << p.name << " " << p.byear;
        return out;
    }
    
    friend istream &operator>>(istream &in, Person &p) {
        in >> ws; // пропускає будь-які пробіли або символи нового рядка
        getline(in, p.name, ' ');
        in >> p.byear;
        return in;
    }
};

class Acquaintance : public Person {
public:
    string phone_number;

    void input() override {
        Person::input();
        cin.ignore(); // очищення буфера перед введенням номера телефону
        cout << "Enter phone number: ";
        getline(cin, phone_number);
    }
    
    void show() const override {
        Person::show();
        cout << "Phone number: " << phone_number << endl;
    }

    friend ostream &operator<<(ostream &out, const Acquaintance &a) {
        out << static_cast<const Person &>(a) << " " << a.phone_number;
        return out;
    }
    
    friend istream &operator>>(istream &in, Acquaintance &a) {
        in >> static_cast<Person &>(a);
        in.ignore(); // очищення буфера після року народження
        getline(in, a.phone_number);
        return in;
    }
};

class PhoneBook {
private:
    Acquaintance contacts[100];
    int count;

public:
    PhoneBook() : count(0) {}

    void add_contact(const string &filename) {
        if (count >= 100) {
            cout << "Phone book is full" << endl;
            return;
        }
        cout << "Adding new contact:\n";
        contacts[count].input();
        count++;
        save_file(filename);
        cout << "Contact added and saved to file: " << filename << endl;
    }

    void save_file(const string &filename) const {
        ofstream file(filename, ios::app);
        if (!file) {
            cout << "Error opening file for writing" << endl;
            return;
        }
        file << contacts[count - 1] << endl;
    }

    void search_name(const string &name) const {
        for (int i = 0; i < count; i++) {
            if (contacts[i].name == name) {
                cout << "Contact found:\n";
                contacts[i].show();
                return;
            }
        }
        cout << "Contact not found\n";
    }

    void change_phone_number(const string &name, const string &new_number) {
        for (int i = 0; i < count; i++) {
            if (contacts[i].name == name) {
                contacts[i].phone_number = new_number;
                cout << "Phone number updated for " << name << "." << endl;
                return;
            }
        }
        cout << "Contact not found\n";
    }

    void open_file(const string &filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file for reading" << endl;
            return;
        }
        count = 0;
        while (file >> contacts[count]) {
            count++;
        }
        cout << "Phone book loaded successfully from " << filename << endl;
    }

    void show_contacts() const {
        cout << "Phone book:\n";
        for (int i = 0; i < count; i++) {
            contacts[i].show();
            cout << "------------------------------" << endl;
        }
    }
};

int main() {
    PhoneBook phoneBook1;
    string filename = "phonebook.txt";

    // Створення файлу для тестування
    string create_file = "phone_book.txt";
    ofstream testFile(create_file);
    testFile << "Yuliia 1992 1234567891\n";
    testFile << "Bob 1991 9876543211\n";
    testFile << "Rob 2020 54321\n";
    testFile << "Diana 2007 98765\n";
    testFile << "Vika 1964 11243\n";
    testFile.close();

    phoneBook1.open_file(create_file);
    phoneBook1.show_contacts();

    cout << "\nSearching for Bob:\n";
    phoneBook1.search_name("Bob");

    cout << "\nChanging phone number for Diana:\n";
    phoneBook1.change_phone_number("Diana", "9993 213456");
    phoneBook1.show_contacts();

    cout << "\nAdding a new contact:\n";
    phoneBook1.add_contact(filename);
    phoneBook1.show_contacts();

    return 0;
}