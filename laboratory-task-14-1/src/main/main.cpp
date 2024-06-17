#include <iostream>
#include <cstring>
#include <cstdlib>


class Person {
protected:
    char* name;

public:
    Person(const char* _name) {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }

    virtual ~Person() {
        delete[] name;
    }

    const char* getName() const {
        return name;
    }

    void setName(const char* _name) {
        delete[] name;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }

    virtual void display() const {
        std::cout << "Name: " << name << '\n';
    }
};

class Student : public Person {
private:
    int course;
    int group;

public:
    Student(const char* _name, int _course, int _group)
        : Person(_name), course(_course), group(_group) {}

    ~Student() {}

    int getCourse() const {
        return course;
    }

    void setCourse(int _course) {
        course = _course;
    }

    int getGroup() const {
        return group;
    }

    void setGroup(int _group) {
        group = _group;
    }

    void display() const override {
        std::cout << "Student: " << getName() << ", Course: " << course << ", Group: " << group << '\n';
    }
};

class Professor : public Person {
private:
    char* department;

public:
    Professor(const char* _name, const char* _department)
        : Person(_name) {
        department = new char[strlen(_department) + 1];
        strcpy(department, _department);
    }

    ~Professor() {
        delete[] department;
    }

    const char* getDepartment() const {
        return department;
    }

    void setDepartment(const char* _department) {
        delete[] department;
        department = new char[strlen(_department) + 1];
        strcpy(department, _department);
    }

    void display() const override {
        std::cout << "Professor: " << getName() << ", Department: " << department << '\n';
    }
};

int main() {
    Person** persons = new Person*[100];
    int count = 0;

    int choice;
    do {
        std::cout << "Menu:\n"
             << "1. Enter a student\n"
             << "2. Enter a professor\n"
             << "3. Display list of students\n"
             << "4. Display list of professors\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                char name[100];
                int course, group;
                std::cout << "Enter student's name: ";
                std::cin.ignore();
                std::cin.getline(name, 100);
                std::cout << "Enter student's course: ";
                std::cin >> course;
                std::cout << "Enter student's group: ";
                std::cin >> group;
                persons[count++] = new Student(name, course, group);
                break;
            }
            case 2: {
                char name[100], department[100];
                std::cout << "Enter professor's name: ";
                std::cin.ignore();
                std::cin.getline(name, 100);
                std::cout << "Enter professor's department: ";
                std::cin.getline(department, 100);
                persons[count++] = new Professor(name, department);
                break;
            }
            case 3:
                std::cout << "List of students:\n";
                for (int i = 0; i < count; ++i) {
                    Student* student = dynamic_cast<Student*>(persons[i]);
                    if (student)
                        student->display();
                }
                break;
            case 4:
                std::cout << "List of professors:\n";
                for (int i = 0; i < count; ++i) {
                    Professor* professor = dynamic_cast<Professor*>(persons[i]);
                    if (professor)
                        professor->display();
                }
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 5);

    for (int i = 0; i < count; ++i) {
        delete persons[i];
    }
    delete[] persons;

    return 0;
}
