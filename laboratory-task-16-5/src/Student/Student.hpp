#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
public:
    Student(const std::string& fullName, int32_t course, const std::string& group);

    const std::string& getFullName() const;
    int getCourse() const;
    const std::string& getGroup() const;

private:
    std::string fullName;
    int32_t course;
    std::string group;
};

#endif // STUDENT_HPP
