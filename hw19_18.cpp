// Стандартна бібліотека С++. Послідовні контейнери та контейнери-адаптори

// Ввести з консолі список L натуральних чисел. Вставити після кожного непарного елементу з першої половини вихідного списку 
// число -1, а перед кожним парним елементом другої половини -2.

// STL

#include <iostream>
#include <list>
#include <iterator> // для std::next

int main() {
    std::list<int> L; // використання контейнера std::list
    int n;

    std::cout << "Enter the list of natural numbers (end with 0):\n";
    while (std::cin >> n && n != 0) {
        L.push_back(n); // додаємо елементи в список
    }

    if (L.empty()) {
        std::cout << "The list is empty. Exiting...\n";
        return 0;
    }

    // ітератори для роботи з елементами
    size_t size = L.size();
    
    auto it = L.begin();
    size_t half = size / 2; // середина списку
    size_t index = 0;  // лічильник позиції елемента

    // обробка першої половини списку
    while (index < half && it != L.end()) {
        if (*it % 2 != 0) {
            it = std::next(it); // переходимо до наступного елемента
            it = L.insert(it, -1); // вставляємо -1 після непарного елемента
        }
        ++it;
        ++index;
    }

    // обробка другої половини списку
    while (it != L.end()) {
        if (*it % 2 == 0) {
            it = L.insert(it, -2); // вставляємо -2 перед парним елементом
            ++it;
        }
        ++it; 
    }

    std::cout << "Modified list:\n";
    for (const auto& elem : L) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}