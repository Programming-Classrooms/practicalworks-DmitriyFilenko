#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "src/Book/Book.hpp"
#include <vector>
#include <algorithm>
#include <iostream>


class Library {
public:
    void addBook(const Book& book);
    Book* findBook(const std::string& isbn);
    void removeBook(const std::string& isbn);
    void listBooks() const;
    void addAuthor(const std::string& isbn, const std::string& author);
    void removeAuthor(const std::string& isbn, const std::string& author);
    void sortByISBN();
    void sortByTitle();

private:
    std::vector<Book> books;
};

#endif // LIBRARY_HPP
