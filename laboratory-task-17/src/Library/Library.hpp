#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <cstdlib>
#include <vector>
#include "src/Book/Book.hpp"


class Library {
public:
    void addBook(const Book &book);
    void removeBook(const std::string &title);
    Book* searchByTitle(const std::string &title);
    std::vector<Book> searchByAuthor(const Author &author);
    void loadFromFile(const std::string &filename);

private:
    std::vector<Book> books;
};

#endif // LIBRARY_HPP
