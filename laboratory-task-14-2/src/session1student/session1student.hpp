#ifndef SESSION1STUDENT_HPP
#define SESSION1STUDENT_HPP

#include "src/Student/Student.hpp"

class Session1Student : public Student {
private:
    int32_t grades[4];

public:
    Session1Student(std::string _name, int32_t _course, std::string _group, int32_t _recordBookNumber, const int32_t _grades[]);
    Session1Student(const Session1Student& other);

    double calculateAverage() const override;

    int32_t getGrade(int32_t index) const;
    void setGrade(int32_t index, int32_t grade);

    friend std::ostream& operator<<(std::ostream& os, const Session1Student& student);
};

#endif // SESSION1STUDENT_HPP
