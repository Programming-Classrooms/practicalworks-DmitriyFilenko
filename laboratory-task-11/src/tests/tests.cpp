
#include <stdexcept>
#include <gtest/gtest.h>
#include "../funcs/funcs.hpp"


TEST(testCase, testName) 
{
    EXPECT_EQ(1, 1);
}

/*
TEST(SortTest, SortsIntsByParity) {
  int data[] = {3, 1, 4, 2, 5};
  int size = sizeof(data) / sizeof(data[0]);

  // Sort by even numbers first
  Sort(data, size, CompareByParity);

  EXPECT_EQ(data[0], 2);
  EXPECT_EQ(data[1], 4);
  EXPECT_EQ(data[2], 1);
  EXPECT_EQ(data[3], 3);
  EXPECT_EQ(data[4], 5);
}
*/
// Assuming Employee is defined
/*
TEST(SortTest, SortsEmployeesBySurname) {
  Employee employees[] = {
    {"Smith", 2},
    {"Johnson", 1},
    {"Williams", 3},
  };
  int size = sizeof(employees) / sizeof(employees[0]);

  // Sort by surname
  Sort(employees, size, CompareEmployees);

  EXPECT_EQ(employees[0].surname, "Johnson");
  EXPECT_EQ(employees[1].surname, "Smith");
  EXPECT_EQ(employees[2].surname, "Williams");
}

TEST(SortTest, SortsEmployeesWithEqualSurnames) {
  Employee employees[] = {
    {"Smith", 2},
    {"Johnson", 1},
    {"Smith", 3},
  };
  int size = sizeof(employees) / sizeof(employees[0]);

  // Sort by surname, then by children (descending)
  Sort(employees, size, CompareEmployees);

  EXPECT_EQ(employees[0].surname, "Johnson");
  EXPECT_EQ(employees[1].children, 3); // Smith with more children comes first
  EXPECT_EQ(employees[2].children, 2);
}
*/
TEST(ReadFromFileTest, ReadsNumbersFromFile) {
  const std::string filename = "src/data/test_numbers.txt";

  // Create a test file with some numbers
  std::ofstream testFile(filename);
  testFile << ":%^&*(\n3\n6\n8\n";
  testFile.close();

  int countNumbers;
  int* allNumbers = ReadNumbersFromFile(filename, &countNumbers);

  ASSERT_NE(allNumbers, nullptr) << "ReadNumbersFromFile returned nullptr";
  EXPECT_EQ(countNumbers, 3);
  EXPECT_EQ(allNumbers[0], 3);
  EXPECT_EQ(allNumbers[1], 6);
  EXPECT_EQ(allNumbers[2], 8);

  // Clean up (optional)
  delete[] allNumbers;
  remove(filename.c_str()); // Remove the test file
}

TEST(ReadFromFileTest, HandlesEmptyFileForNumbers) {
  const std::string filename = "src/data/empty_numbers.txt";
  std::ofstream testFile(filename);
  testFile.close();

  int countNumbers;
  EXPECT_THROW(ReadNumbersFromFile(filename, &countNumbers), std::invalid_argument);
}

TEST(ReadFromFileTest, ReadsSurnamesFromFile) {
  const std::string filename = "src/data/test_surnames.txt";

  // Create a test file with some surnames
  std::ofstream testFile(filename);
  testFile << "^&*()\nSMITH\nJONES\nLEE\n";
  testFile.close();

  int countSurnames;
  std::string* allSurnames = ReadSurnamesFromFile(filename, &countSurnames);

  ASSERT_NE(allSurnames, nullptr) << "ReadSurnamesFromFile returned nullptr";
  EXPECT_EQ(countSurnames, 13);
  EXPECT_EQ(allSurnames[0], "SMITH");
  EXPECT_EQ(allSurnames[1], "JONES");
  EXPECT_EQ(allSurnames[2], "LEE");

  // Clean up (optional)
  delete[] allSurnames;
  remove(filename.c_str()); // Remove the test file
}

TEST(ReadFromFileTest, HandlesEmptyFileForSurnames) {
  const std::string filename = "src/data/empty_surnames.txt";
  std::ofstream testFile(filename);
  testFile.close();

  int countSurnames;
  EXPECT_THROW(ReadSurnamesFromFile(filename, &countSurnames), std::invalid_argument);
}

TEST(ReadFromFileTest, HandlesFileOpenError) {
  const std::string filename = "src/data/nonexistent_file.txt";
  int countNumbers;
  EXPECT_THROW(ReadNumbersFromFile(filename, &countNumbers), std::invalid_argument); // Or a more specific exception type
}

TEST(EmployeeTest, CreatesEmployees) {
  const std::string testSurnames[] = {"Smith", "Johnson", "Williams"};
  const int testNumbers[] = {2, 1, 3};
  int count = sizeof(testSurnames) / sizeof(testSurnames[0]);

  Employee* employees = CreateEmployees(const_cast<std::string*>(testSurnames), const_cast<int*>(testNumbers), count);

  ASSERT_NE(employees, nullptr) << "CreateEmployees returned nullptr";
  EXPECT_EQ(employees[0].surname, "Smith");
  EXPECT_EQ(employees[0].children, 2);
  EXPECT_EQ(employees[1].surname, "Johnson");
  EXPECT_EQ(employees[1].children, 1);
  EXPECT_EQ(employees[2].surname, "Williams");
  EXPECT_EQ(employees[2].children, 3);
  delete[] employees;
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
