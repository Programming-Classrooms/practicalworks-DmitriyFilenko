#include <gtest/gtest.h>
#include "src/Student/Student.hpp"


TEST(StudentTest, FullNameTest) {
    Student student("Alice", 3, "GroupA");
    EXPECT_EQ(student.getFullName(), "Alice");
}

TEST(StudentTest, CourseTest) {
    Student student("Bob", 2, "GroupB");
    EXPECT_EQ(student.getCourse(), 2);
}

TEST(StudentTest, GroupTest) {
    Student student("Charlie", 1, "GroupC");
    EXPECT_EQ(student.getGroup(), "GroupC");
}

TEST(StudentTest, CompareByFullNameTest) {
    Student student1("Alice", 3, "GroupA");
    Student student2("Bob", 2, "GroupB");
    EXPECT_TRUE(compareByFullName(student1, student2));
}

TEST(StudentTest, CompareByCourseAndGroupTest) {
    Student student1("Alice", 3, "GroupA");
    Student student2("Bob", 3, "GroupB");
    EXPECT_TRUE(compareByCourseAndGroup(student1, student2));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}