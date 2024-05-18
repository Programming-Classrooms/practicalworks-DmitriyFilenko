#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <vector>


class Book {
public:
    Book(const std::string& isbn, const std::string& title, double price, size_t count);
    
    std::string getISBN() const;
    std::string getTitle() const;
    std::vector<std::string> getAuthors() const;
    double getPrice() const;
    size_t getCount() const;

    void addAuthor(const std::string& author);
    void removeAuthor(const std::string& author);

private:
    std::string isbn;
    std::string title;
    std::vector<std::string> authors;
    double price;
    size_t count;
};

#endif // BOOK_HPP
