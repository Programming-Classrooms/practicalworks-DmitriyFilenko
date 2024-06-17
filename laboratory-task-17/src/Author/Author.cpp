#include "Author.hpp"


Author::Author(const std::string &lastName, const std::string &firstName, const std::string &middleName)
    : lastName(lastName), firstName(firstName), middleName(middleName) {}

std::string Author::getLastName() const {
    return lastName;
}

std::string Author::getFirstName() const {
    return firstName;
}

std::string Author::getMiddleName() const {
    return middleName;
}

bool Author::operator==(const Author &other) const {
    return lastName == other.lastName && firstName == other.firstName && middleName == other.middleName;
}

bool Author::operator<(const Author &other) const {
    if (lastName != other.lastName) return lastName < other.lastName;
    if (firstName != other.firstName) return firstName < other.firstName;
    return middleName < other.middleName;
}
