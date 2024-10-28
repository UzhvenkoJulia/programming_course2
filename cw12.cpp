#include <iostream>
#include <cmath>
#include <string>
#include <fstream> // бібліотека надає функціонал для роботи з файлами
#include <iomanip> // для setw та setprecision
using namespace std;

void task1() {
    cout << "x = ";
    double x = 0, y = 0;
    cin >> x;
    cout << "y = ";
    cin >> y;
    double z = pow(x, y);
    cout << "result in decimal: " << z << endl;
    cout << "result in scientific notation: " << scientific << z << endl;
}

void task2() {
    char str[11];
    unsigned long long sum = 0UL;
    cout << "enter n: ";
    unsigned n = 0;
    cin >> n;
    unsigned long long mas[1000];
    unsigned count = 0;
    cin.ignore();
    while (count < n) {
        cin.get(str, 11);
        cin.ignore();
        unsigned long long a = stoull(str);
        mas[count] = a;
        sum += a;
        count++;
    }
    cout << "sum = " << sum << "\n";
}

void task3() {
    unsigned n = 0;
    cout << "enter n: ";
    cin >> n;
    if (n == 0) return; 

    int line_length = (n + 1) * 8;
    string line(line_length, '+');
    cout << line << endl;

    for (unsigned i = 1; i <= n; i++) {
        cout << setw(8) << i << " ";
    }

    cout << endl;
    cout << line << endl;

    for (unsigned i = 1; i <= n; i++) {
        double root = sqrt(i);
        if (root == floor(root)) {
            cout << setw(8) << setprecision(0) << root << " ";
        } else {
            cout << setw(8) << setprecision(2) << root << " ";
        }
    }
    cout << endl;
    cout << line << endl;
}

void task4() {
    unsigned n;
    cout << "enter n: ";
    cin >> n;

    int* m = new int[n];
    double* x = new double[n];

    for (unsigned i = 0; i < n; i++) {
        cout << "m[" << i << "]= ";
        cin >> m[i];
    }

    ifstream f1("input.txt");
    if (!f1.is_open()) {
        cout << "failed to open input.txt" << endl;
        delete[] m;
        return;
    }

    unsigned i = 0;
    while (i < n && f1 >> x[i]) {
        i++;
    }
    f1.close();

    if (i < n) {
        cout << "not enough data in file" << endl;
    } else {
        ofstream f2("output.txt");
        if (!f2.is_open()) {
            cout << "failed to open output.txt" << endl;
            delete[] x;
            delete[] m;
            return;
        }
        for (unsigned j = 0; j < n; j++) {
            double z = pow(x[j], m[j]);
            f2 << z << endl;
        }
        f2.close();
    }
    delete[] x;
    delete[] m;
}

void task5() {
    double mas[1 << 16]; // 2^16
    ifstream f1("input_1.txt");
    if (!f1.is_open()) {
        cout << "failed to open input_1.txt" << endl;
        return;
    }

    unsigned i = 0;
    while (f1 >> mas[i]) {
        i++;
    }
    f1.close();

    for (unsigned j = i; j > 0; j--) {
        double res = sqrt(mas[j - 1]);
        cout << setprecision(4) << res << endl;
    }
}

int main() {
    int task = 1;
    cout << "task = ";
    cin >> task;
    if (task == 1) {
        task1();
    } else if (task == 2) {
        task2();
    } else if (task == 3) {
        task3();
    } else if (task == 4) {
        task4();
    } else if (task == 5) {
        task5();
    } else {
        cout << "invalid task number" << endl;
    }
}