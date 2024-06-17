#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class Student {
private:
    std::string fullName;
    int32_t course;
    std::string group;
    
public:
    Student(const std::string& fullName, int32_t course, const std::string& group);

    const std::string& getFullName() const;
    int32_t getCourse() const;
    const std::string& getGroup() const;
};

bool compareByFullName(const Student& s1, const Student& s2);

bool compareByCourseAndGroup(const Student& s1, const Student& s2);

std::vector<Student> readStudentsFromFile(const std::string& filePath);

void sortByFullNameAndWriteToFile(const std::vector<Student>& students, const std::string& filePath);

void sortByCourseAndGroupAndWriteToFile(const std::vector<Student>& students, const std::string& filePath);

#endif // STUDENT_HPP
