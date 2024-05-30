#include "Student.hpp"

int32_t Student::nextId = 1;

Student::Student(std::string _name, int32_t _course, std::string _group, int32_t _recordBookNumber)
    : id(nextId++), name(_name), course(_course), group(_group), recordBookNumber(_recordBookNumber) {}

Student::Student(const Student& other)
    : id(other.id), name(other.name), course(other.course), group(other.group), recordBookNumber(other.recordBookNumber) {}

int32_t Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

void Student::setName(std::string _name) {
    name = _name;
}

int32_t Student::getCourse() const {
    return course;
}

void Student::setCourse(int32_t _course) {
    course = _course;
}

std::string Student::getGroup() const {
    return group;
}

void Student::setGroup(std::string _group) {
    group = _group;
}

int32_t Student::getRecordBookNumber() const {
    return recordBookNumber;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "============================================\nID: " << student.id << "\nName: " << student.name << "\nCourse: " << student.course
       << "\nGroup: " << student.group << "\nRecord Book Number: " << student.recordBookNumber<<'\n';
    return os;
}
