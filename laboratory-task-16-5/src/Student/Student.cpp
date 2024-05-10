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

bool compareByFullName(const Student& s1, const Student& s2) {
    return s1.getFullName() < s2.getFullName();
}

bool compareByCourseAndGroup(const Student& s1, const Student& s2) {
    if (s1.getCourse() == s2.getCourse()) {
        return s1.getGroup() < s2.getGroup();
    }
    return s1.getCourse() < s2.getCourse();
}

std::vector<Student> readStudentsFromFile(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    std::vector<Student> students;
    std::string fullName, group;
    int32_t course;
    while (inputFile >> fullName >> course >> group) {
        students.emplace_back(fullName, course, group);
    }
    inputFile.close();
    return students;
}

void sortByFullNameAndWriteToFile(const std::vector<Student>& students, const std::string& filePath) {
    std::vector<Student> sortedStudents = students;
    std::sort(sortedStudents.begin(), sortedStudents.end(), compareByFullName);
    std::ofstream outputFile(filePath);
    for (const auto& student : sortedStudents) {
        outputFile << student.getFullName() << " " << student.getCourse() << " " << student.getGroup() << std::endl;
    }
    outputFile.close();
}

void sortByCourseAndGroupAndWriteToFile(const std::vector<Student>& students, const std::string& filePath) {
    std::vector<Student> sortedStudents = students;
    std::sort(sortedStudents.begin(), sortedStudents.end(), compareByCourseAndGroup);
    std::ofstream outputFile(filePath);
    for (const auto& student : sortedStudents) {
        outputFile << student.getFullName() << " " << student.getCourse() << " " << student.getGroup() << std::endl;
    }
    outputFile.close();
}
