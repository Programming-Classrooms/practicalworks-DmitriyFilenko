#include "Library.hpp"


void Library::addBook(const Book& book) {
    books.push_back(book);
}

Book* Library::findBook(const std::string& isbn) {
    for (auto& book : books) {
        if (book.getISBN() == isbn) {
            return &book;
        }
    }
    return nullptr;
}

void Library::removeBook(const std::string& isbn) {
    books.erase(std::remove_if(books.begin(), books.end(),
    //если выполнится
     [&isbn](const Book& book) {
        return book.getISBN() == isbn;
    }), books.end());
}

void Library::listBooks() const {
    for (const auto& book : books) {
        std::cout << "\n========================================================\n";
        std::cout << "\nISBN: " << book.getISBN() << "\nНазвание: "
        << book.getTitle() << "\nЦена: "
        << book.getPrice() << "\nКол-во в наличии: "
        << book.getCount() << "\n";
        std::cout << "Авторы:\n";
        for (const auto& author : book.getAuthors()) {
            std::cout << author << "\n";
        }
        std::cout << "\n========================================================\n";
    }
}

void Library::addAuthor(const std::string& isbn, const std::string& author) {
    Book* book = findBook(isbn);
    if (book) {
        book->addAuthor(author);
    }
}

void Library::removeAuthor(const std::string& isbn, const std::string& author) {
    Book* book = findBook(isbn);
    if (book) {
        book->removeAuthor(author);
    }
}

void Library::sortByISBN() {
    std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getISBN() < b.getISBN();
    });
}

void Library::sortByTitle() {
    std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getTitle() < b.getTitle();
    });
}
