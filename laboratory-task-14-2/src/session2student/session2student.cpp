#include "session2student.hpp"


Session2Student::Session2Student(std::string _name, int32_t _course, std::string _group, int32_t _recordBookNumber, const int32_t _grades1[], const int32_t _grades2[])
    : Session1Student(_name, _course, _group, _recordBookNumber, _grades1) {
    for (int32_t i = 0; i < 5; ++i) {
        grades[i] = _grades2[i];
    }
}

Session2Student::Session2Student(const Session2Student& other)
    : Session1Student(other), grades{other.grades[0], other.grades[1], other.grades[2], other.grades[3], other.grades[4]} {}

double Session2Student::calculateAverage() const {
    double sum = 0.0;
    for (int32_t i = 0; i < 5; ++i) {
        sum += grades[i];
    }
    return sum / 5.0;
}

int32_t Session2Student::getGrade(int32_t index) const {
    if (index >= 0 && index < 5)
        return grades[index];
    else
        return -1; // or throw an exception
}

void Session2Student::setGrade(int32_t index, int32_t grade) {
    if (index >= 0 && index < 5)
        grades[index] = grade;
    // else throw an exception
}

std::ostream& operator<<(std::ostream& os, const Session2Student& student) {
    os << static_cast<const Student&>(student) << "Session 1 Grades: [";
    for (int32_t i = 0; i < 3; ++i) {
        os << student.grades[i] << ' ';
    }
    os << student.grades[3] << "], Session 2 Grades: [" << student.grades[4] << "]";
    return os;
}
