#include <gtest/gtest.h>
#include "src/Student/Student.hpp"


// Test fixture for student file processing
class StudentFileProcessingTest : public ::testing::Test {
protected:
    std::vector<Student> students;

    void SetUp() override {
        // Create some sample student data for testing
        students.emplace_back("John Smith", 3, "A");
        students.emplace_back("Alice Johnson", 2, "B");
        students.emplace_back("Bob White", 1, "C");
    }
};

// Test case for reading student data from a file
TEST_F(StudentFileProcessingTest, ReadStudentsFromFile) {
    std::string filePath = "src/data/StudentsTest.txt";
    std::ofstream testFile(filePath);
    testFile << "John 3 A\n";
    testFile << "Alice 2 B\n";
    testFile << "Bob 1 C\n";
    testFile.close();

    std::vector<Student> expectedStudents = {
        Student("John", 3, "A"),
        Student("Alice", 2, "B"),
        Student("Bob", 1, "C")
    };

    ASSERT_EQ(readStudentsFromFile(filePath), expectedStudents);
}

// Test case for sorting students by full name and writing to a file
TEST_F(StudentFileProcessingTest, SortByFullNameAndWriteToFile) {
    std::vector<Student> students = {
        Student("John Smith", 3, "A"),
        Student("Alice Johnson", 2, "B"),
        Student("Bob White", 1, "C")
    };

    std::string filePath = "src/data/SortedByFullNameTest.txt";
    sortByFullNameAndWriteToFile(students, filePath);

    std::ifstream testFile(filePath);
    std::string line;
    std::vector<std::string> fileContent;
    while (std::getline(testFile, line)) {
        fileContent.push_back(line);
    }
    testFile.close();

    std::vector<std::string> expectedFileContent = {
        "Alice Johnson 2 B",
        "Bob White 1 C",
        "John Smith 3 A"
    };

    ASSERT_EQ(fileContent, expectedFileContent);
}

// Test case for sorting students by course and group and writing to a file
TEST_F(StudentFileProcessingTest, SortByCourseAndGroupAndWriteToFile) {
    std::vector<Student> students = {
        Student("John Smith", 3, "B"),
        Student("Alice Johnson", 1, "C"),
        Student("Bob White", 2, "A")
    };

    std::string filePath = "src/data/SortedByCourseAndGroupTest.txt";
    sortByCourseAndGroupAndWriteToFile(students, filePath);

    std::ifstream testFile(filePath);
    std::string line;
    std::vector<std::string> fileContent;
    while (std::getline(testFile, line)) {
        fileContent.push_back(line);
    }
    testFile.close();

    std::vector<std::string> expectedFileContent = {
        "Alice Johnson 1 C",
        "Bob White 2 A",
        "John Smith 3 B"
    };

    ASSERT_EQ(fileContent, expectedFileContent);
}

// Test case for handling an empty list of students
TEST_F(StudentFileProcessingTest, EmptyStudentsList) {
    std::vector<Student> students;

    std::string filePath = "src/data/EmptyStudentsTest.txt";
    sortByFullNameAndWriteToFile(students, filePath);

    std::ifstream testFile(filePath);
    bool isEmpty = testFile.peek() == std::ifstream::traits_type::eof();
    testFile.close();

    ASSERT_TRUE(isEmpty);
}

// Test case for handling a file with no students data
TEST_F(StudentFileProcessingTest, NoDataInFile) {
    std::string filePath = "src/data/NoDataTest.txt";
    std::ofstream testFile(filePath);
    testFile.close();

    std::vector<Student> students = readStudentsFromFile(filePath);

    ASSERT_TRUE(students.empty());
}

// Test case for handling invalid file path
TEST_F(StudentFileProcessingTest, InvalidFilePath) {
    std::string filePath = "invalid_path/Students.txt";
    std::vector<Student> students = readStudentsFromFile(filePath);

    ASSERT_TRUE(students.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}