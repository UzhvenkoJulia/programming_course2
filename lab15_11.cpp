// Книжка - назва, автор, к-сть сторінок, рік видання
// каталог - масив книжок, що зберігається у файл


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// Клас Book
class Book {
private:
    std::string title;
    std::string author;
    int pages;
    int year;

public:
    // Конструктор
    Book(const std::string& title, const std::string& author, int pages, int year)
        : title(title), author(author), pages(pages), year(year) {}

    // Гетери - методи, які надають доступ до значень приватних змінних класу. 
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getPages() const { return pages; }
    int getYear() const { return year; }

    void display() const {
        std::cout << "Name: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "Number of pages: " << pages << "\n"
                  << "Year of publication: " << year << "\n";
    }

    void saveToFile(std::ofstream& file) const {
        file << title << '\n' << author << '\n' << pages << '\n' << year << '\n';
    }

    static Book loadFromFile(std::ifstream& file) {
        std::string title, author;
        int pages, year;
        std::getline(file, title);
        std::getline(file, author);
        file >> pages >> year;
        file.ignore(); // пропустити новий рядок після читання числа
        return Book(title, author, pages, year);
    }
};

void searchByTitle(const std::vector<Book>& catalog, const std::string& title) {
    bool found = false;
    for (const auto& book : catalog) {
        if (book.getTitle() == title) {
            book.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "A book with a title \"" << title << "\" not found\n";
    }
}

void searchByAuthor(const std::vector<Book>& catalog, const std::string& author) {
    bool found = false;
    for (const auto& book : catalog) {
        if (book.getAuthor() == author) {
            book.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Author's book \"" << author << "\" not found\n";
    }
}

// завантаження каталогу з файлу
std::vector<Book> loadCatalog(const std::string& filename) {
    std::vector<Book> catalog;
    std::ifstream file(filename);
    if (file.is_open()) {
        while (file.peek() != EOF) {
            catalog.push_back(Book::loadFromFile(file));
        }
        file.close();
    } else {
        std::cerr << "Failed to open file " << filename << " for reading\n";
    }
    return catalog;
}

void saveCatalog(const std::vector<Book>& catalog, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& book : catalog) {
            book.saveToFile(file);
        }
        file.close();
    } else {
        std::cerr << "Failed to open file" << filename << " for recording\n";
    }
}

int main() {
    std::string filename = "catalog.txt";

    std::vector<Book> catalog = loadCatalog(filename);

    int choice;
    do {
        std::cout << "\nMenu:\n"
                  << "1. Add a book\n"
                  << "2. Search by name\n"
                  << "3. Search by author\n"
                  << "4. Exit\n"
                  << "Your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // пропустити залишок рядка

        switch (choice) {
        case 1: {
            std::string title, author;
            int pages, year;
            std::cout << "Enter name: ";
            std::getline(std::cin, title);
            std::cout << "Enter author: ";
            std::getline(std::cin, author);
            std::cout << "Enter the number of pages: ";
            std::cin >> pages;
            std::cout << "Enter year of publication: ";
            std::cin >> year;
            catalog.emplace_back(title, author, pages, year);
            saveCatalog(catalog, filename);
            break;
        }
        case 2: {
            std::string title;
            std::cout << "Enter a name to search for: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            searchByTitle(catalog, title);
            break;
        }
        case 3: {
            std::string author;
            std::cout << "Enter the author to search: ";
            std::cin.ignore();
            std::getline(std::cin, author);
            searchByAuthor(catalog, author);
            break;
        }
        case 4:
            std::cout << "Goodbye!!\n";
            break;
        default:
            std::cout << "Wrong choice. Try again\n";
        }
    } while (choice != 4);

    return 0;
}