#include "Book.hpp"
#include <algorithm>


Book::Book(const std::string& isbn, const std::string& title, double price, size_t count)
    : isbn(isbn), title(title), price(price), count(count) {}

std::string Book::getISBN() const {
    return isbn;
}

std::string Book::getTitle() const {
    return title;
}

std::vector<std::string> Book::getAuthors() const {
    return authors;
}

double Book::getPrice() const {
    return price;
}

size_t Book::getCount() const {
    return count;
}

void Book::addAuthor(const std::string& author) {
    authors.push_back(author);
}

void Book::removeAuthor(const std::string& author) {
    authors.erase(std::remove(authors.begin(), authors.end(), author), authors.end());
}
