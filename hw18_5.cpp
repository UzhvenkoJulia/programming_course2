// Створення шаблонів функцій та шаблонів класів
// простори імен

// Визначити клас Масив, який містить розмір масиву та відповідний масив даних довільного типу.
// Реалізувати в ньому методи сортування як для самого масиву та як статичні методи (inplace):
// б) обмінне сортування "Шейкер-сортування"

#include <iostream>
#include <vector>

// Template class Array
// T - the type of data stored in the array
template <typename T>
class Array {
private:
    std::vector<T> data; // vector to store the array elements
public:
    // default constructor
    Array() = default;

    explicit Array(size_t size) : data(size) {}

    size_t size() const {
        return data.size();
    }

    // method to access an element by index
    T& operator[](size_t index) {
        return data[index];
    }

    // constant method to access an element by index
    const T& operator[](size_t index) const {
        return data[index];
    }

    void print() const {
        for (const auto& element : data) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    // method to sort the array using "Cocktail Shaker Sort" (inplace)
    void shakerSort() {
        bool swapped = true;
        size_t start = 0;
        size_t end = data.size() - 1;

        while (swapped) {
            swapped = false;

            // traverse from left to right
            for (size_t i = start; i < end; ++i) {
                if (data[i] > data[i + 1]) {
                    std::swap(data[i], data[i + 1]);
                    swapped = true;
                }
            }
            // зменшення кінця
            if (!swapped) break;
            --end;

            // traverse from right to left
            for (size_t i = end; i > start; --i) {
                if (data[i - 1] > data[i]) {
                    std::swap(data[i - 1], data[i]);
                    swapped = true;
                }
            }
            ++start;
        }
    }

    // static method to perform shaker sort on a given array
    static void shakerSort(std::vector<T>& array) {
        bool swapped = true;
        size_t start = 0;
        size_t end = array.size() - 1;

        while (swapped) {
            swapped = false;

            // from left to right
            for (size_t i = start; i < end; ++i) {
                if (array[i] > array[i + 1]) {
                    std::swap(array[i], array[i + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
            --end;

            // from right to left
            for (size_t i = end; i > start; --i) {
                if (array[i - 1] > array[i]) {
                    std::swap(array[i - 1], array[i]);
                    swapped = true;
                }
            }
            ++start;
        }
    }
};

int main() {
    // example of using the Array class
    Array<int> myArray(10);

    // filling the array with values
    myArray[0] = 42;
    myArray[1] = 32;
    myArray[2] = 14;
    myArray[3] = 25;
    myArray[4] = 19;
    myArray[5] = 55;
    myArray[6] = 11;
    myArray[7] = 5;
    myArray[8] = 40;
    myArray[9] = 21;

    std::cout << "Initial array: ";
    myArray.print();

    myArray.shakerSort();

    std::cout << "Sorted array: ";
    myArray.print();

    // using the static method for sorting
    std::vector<int> array = {42, 32, 14, 25, 19, 55, 11, 5, 40, 21};
    std::cout << "Array before static sorting: ";
    for (int number : array) std::cout << number << " ";
    std::cout << std::endl;

    Array<int>::shakerSort(array);

    std::cout << "Array after static sorting: ";
    for (int number : array) std::cout << number << " ";
    std::cout << std::endl;

    return 0;
}