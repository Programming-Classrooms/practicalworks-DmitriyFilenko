#include "Student.hpp"

Student::Student(const std::string& fullName, int32_t course, const std::string& group)
    : fullName(fullName), course(course), group(group) {}

const std::string& Student::getFullName() const {
    return fullName;
}

int32_t Student::getCourse() const {
    return course;
}

const std::string& Student::getGroup() const {
    return group;
}
