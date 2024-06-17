#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Library.hpp"


void Library::addBook(const Book &book) {
    books.push_back(book);
    std::sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
        return a.getTitle() < b.getTitle();
    });
}

void Library::removeBook(const std::string &title) {
    books.erase(std::remove_if(books.begin(), books.end(), [&title](const Book &book) {
        return book.getTitle() == title;
    }), books.end());
}

Book* Library::searchByTitle(const std::string &title) {
    auto it = std::find_if(books.begin(), books.end(), [&title](const Book &book) {
        return book.getTitle() == title;
    });
    return it != books.end() ? &(*it) : nullptr;
}

std::vector<Book> Library::searchByAuthor(const Author &author) {
    std::vector<Book> result;
    for (const auto &book : books) {
        const auto &authors = book.getAuthors();
        if (std::find(authors.begin(), authors.end(), author) != authors.end()) {
            result.push_back(book);
        }
    }
    return result;
}

void Library::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int32_t id, year;
        std::string title;
        std::string authorData;
        std::getline(iss, title, ',');
        iss >> id >> year;
        Book book(id, title, year);
        while (iss >> authorData) {
            std::istringstream authorStream(authorData);
            std::string lastName, firstName, middleName;
            std::getline(authorStream, lastName, ' ');
            std::getline(authorStream, firstName, ' ');
            std::getline(authorStream, middleName, ' ');
            Author author(lastName, firstName, middleName);
            book.addAuthor(author);
        }
        addBook(book);
    }
}
