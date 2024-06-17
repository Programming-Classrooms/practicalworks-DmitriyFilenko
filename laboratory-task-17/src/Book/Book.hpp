#ifndef BOOK_HPP
#define BOOK_HPP

#include <cstdlib>
#include <string>
#include <vector>
#include "src/Author/Author.hpp"

class Book {
public:
    Book(int32_t id, const std::string &title, int32_t year);

    void addAuthor(const Author &author);
    void removeAuthor(const Author &author);
    std::string getTitle() const;
    int32_t getID() const;
    int32_t getYear() const;
    std::vector<Author> getAuthors() const;

private:
    int32_t id;
    std::string title;
    int32_t year;
    std::vector<Author> authors;
};

#endif // BOOK_HPP
