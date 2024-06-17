#include <algorithm>
#include "Book.hpp"


Book::Book(int32_t id, const std::string &title, int32_t year) : id(id), title(title), year(year) {}

void Book::addAuthor(const Author &author) {
    authors.push_back(author);
    std::sort(authors.begin(), authors.end());
}

void Book::removeAuthor(const Author &author) {
    authors.erase(std::remove(authors.begin(), authors.end(), author), authors.end());
}

std::string Book::getTitle() const {
    return title;
}

int32_t Book::getID() const {
    return id;
}

int32_t Book::getYear() const {
    return year;
}

std::vector<Author> Book::getAuthors() const {
    return authors;
}
