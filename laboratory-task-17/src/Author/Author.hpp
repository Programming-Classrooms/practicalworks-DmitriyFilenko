#ifndef AUTHOR_HPP
#define AUTHOR_HPP

#include <cstdlib>
#include <string>


class Author {
public:
    Author(const std::string &lastName, const std::string &firstName, const std::string &middleName);

    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getMiddleName() const;

    bool operator==(const Author &other) const;
    bool operator<(const Author &other) const;

private:
    std::string lastName;
    std::string firstName;
    std::string middleName;
};

#endif // AUTHOR_HPP
