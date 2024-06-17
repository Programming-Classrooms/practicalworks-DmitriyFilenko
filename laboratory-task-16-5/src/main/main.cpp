
#include "src/Student/Student.hpp"


int main() {
    // Чтение данных из файла Students.txt
    const std::string filePath = "src/data/Students.txt";
    const std::string filePathFIO = "src/data/Fio.txt";
    const std::string filePathGroups = "src/data/Groups.txt";

    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file Students.txt" << std::endl;
        return 1;
    }

    std::vector<Student> students;
    std::string fullName, group;
    int32_t course;
    while (inputFile >> fullName >> course >> group) {
        students.emplace_back(fullName, course, group);
    }
    inputFile.close();

    // Сортировка студентов по фамилии и запись в файл Fio.txt
    std::sort(students.begin(), students.end(), compareByFullName);
    std::ofstream fioFile(filePathFIO);
    for (const auto& student : students) {
        fioFile << student.getFullName() << " " << student.getCourse() << " " << student.getGroup() << std::endl;
    }
    fioFile.close();

    // Сортировка студентов по курсу и группе и запись в файл Groups.txt
    std::sort(students.begin(), students.end(), compareByCourseAndGroup);
    std::ofstream groupsFile(filePathGroups);
    for (const auto& student : students) {
        groupsFile << student.getFullName() << " " << student.getCourse() << " " << student.getGroup() << std::endl;
    }
    groupsFile.close();

    std::cout << "Files Fio.txt and Groups.txt have been created successfully." << std::endl;

    return 0;
}
