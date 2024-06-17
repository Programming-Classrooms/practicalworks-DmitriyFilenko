#include "session1student.hpp"


Session1Student::Session1Student(std::string _name, int32_t _course, std::string _group, int32_t _recordBookNumber, const int32_t _grades[])
    : Student(_name, _course, _group, _recordBookNumber) {
    for (int32_t i = 0; i < 4; ++i) {
        grades[i] = _grades[i];
    }
}

Session1Student::Session1Student(const Session1Student& other)
    : Student(other), grades{other.grades[0], other.grades[1], other.grades[2], other.grades[3]} {}

double Session1Student::calculateAverage() const {
    int32_t sum = 0;
    for (int32_t i = 0; i < 4; ++i) {
        sum += grades[i];
    }
    return static_cast<float>(sum) / 4.0;
}

int32_t Session1Student::getGrade(int32_t index) const {
    if (index >= 0 && index < 4)
        return grades[index];
    else
        return -1; // or throw an exception
}

void Session1Student::setGrade(int32_t index, int32_t grade) {
    if (index >= 0 && index < 4)
        grades[index] = grade;
    // else throw an exception
}

std::ostream& operator<<(std::ostream& os, const Session1Student& student) {
    os << static_cast<const Student&>(student) << ", Grades: [";
    for (int32_t i = 0; i < 3; ++i) {
        os << student.grades[i] << ' ';
    }
    os << student.grades[3] << "]";
    return os;
}
