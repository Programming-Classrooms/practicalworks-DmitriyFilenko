#ifndef SESSION2STUDENT_HPP
#define SESSION2STUDENT_HPP

#include "src/session1student/session1student.hpp"

class Session2Student : public Session1Student {
private:
    int32_t grades[5];

public:
    Session2Student(std::string _name, int32_t _course, std::string _group, int32_t _recordBookNumber, const int32_t _grades1[], const int32_t _grades2[]);
    Session2Student(const Session2Student& other);

    double calculateAverage() const override;

    int32_t getGrade(int32_t index) const;
    void setGrade(int32_t index, int32_t grade);

    friend std::ostream& operator<<(std::ostream& os, const Session2Student& student);
};

#endif
