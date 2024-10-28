#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void task1() {
    double x, y, res;
    cout << "enter x and y: ";
    if (cin >> x >> y) {
        res = pow(x, y);
        cout << res << ", " << scientific << res << endl;
    } else {
        cerr << "invalid input" << endl;
    }
}

void task2() {
    size_t sz;
    char str[11]; 
    unsigned a;
    unsigned long long sum = 0UL; 
    unsigned n = 0;
    cout << "enter numbers (end with EOF):\n";
    unsigned mas[1000];

    while (cin.get(str, 11)) {
        try {
            a = stoul(str, &sz);
            if (sz == 0) {
                cerr << "invalid number: " << str << endl;
                continue;
            }
            mas[n] = a;
            n++;
            sum += a;
        } catch (...) {
            cerr << "conversion error" << endl;
        }
    }
    cout << "sum: " << sum << "\n";
}

void task3() {
    unsigned n;
    double res;
    cout << "enter n: ";
    if (cin >> n) {
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        for (int i = 1; i <= n; i++) {
            cout << " " << i << "      ";
        }
        cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        for (int i = 1; i <= n; i++) {
            res = sqrt(i);
            cout.precision(3);
            cout << " " << res << "    ";
        }
        cout << endl; // для відокремлення виходу
    } else {
        cerr << "invalid input" << endl;
    }
}

void task4() {
    unsigned n;
    cout << "enter n: ";
    cin >> n;
    int *m = new int[n];
    double *x = new double[n];
    for (unsigned i = 0; i < n; i++) {
        cout << "m[" << i << "] = ";
        cin >> m[i];
    }

    ifstream f1("input4.txt");
    if (!f1) {
        cerr << "error opening input4.txt" << endl;
        delete[] m;
        delete[] x;
        return;
    }

    unsigned i = 0;
    while (f1 >> x[i] && i < n) {
        clog << i << "-th number = x[" << i + 1 << "] " << "\n";
        i++;
    }
    f1.close();

    if (i < n) {
        cout << "\nnot enough data in file" << endl;
    }

    ofstream f2("output4.txt");
    for (unsigned j = 0; j < i; j++) { 
        double z = pow(x[j], m[j]);
        f2 << z << "\n";
    }
    f2.close();
    delete[] x;
    delete[] m;
}

void task5() {
    ifstream inputFile("input5.txt"); 
    if (!inputFile) {
        cerr << "error opening input file" << endl;
        return;
    }

    unsigned long long numbers[1000]; 
    int count = 0;
    unsigned long long num;

    while (inputFile >> num && count < 1000) {
        numbers[count++] = num;
    }
    inputFile.close();

    ofstream outputFile("output5.txt");
    if (!outputFile) {
        cerr << "error opening output file" << endl;
        return;
    }

    outputFile << fixed; 
    for (int i = count - 1; i >= 0; --i) {
        if (numbers[i] >= 0) {
            double sqrtResult = sqrt(numbers[i]);
            outputFile.precision(3); 
            outputFile << sqrtResult << endl;
        } else {
            outputFile << "invalid input due to negative number" << endl;
        }
    }

    outputFile.close();
}

int main() {
    // розкоментуйте для виконання конкретних завдань
    // task1();
    // task2();
    // task3();
    // task4();
    // task5();
}
