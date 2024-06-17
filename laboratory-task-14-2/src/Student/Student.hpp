#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Student {
private:
    static int32_t nextId;
    const int32_t id;
    std::string name;
    int32_t course;
    std::string group;
    const int32_t recordBookNumber;

public:
    Student(std::string _name, int32_t _course, std::string _group, int32_t _recordBookNumber);
    Student(const Student& other);

    int32_t getId() const;
    std::string getName() const;
    void setName(std::string _name);
    int32_t getCourse() const;
    void setCourse(int32_t _course);
    std::string getGroup() const;
    void setGroup(std::string _group);
    int32_t getRecordBookNumber() const;

    virtual double calculateAverage() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif // STUDENT_HPP
