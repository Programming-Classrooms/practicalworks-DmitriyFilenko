#include <stdexcept>
#include <gtest/gtest.h>
#include "src/MyString/MyString.hpp"


TEST(testCase, testName) 
{
    EXPECT_EQ(1, 1);
}

TEST(MyStringTest, DefaultConstructor) {
  MyString str;
  EXPECT_EQ(str.strSize(), 1);
  EXPECT_STREQ(str.getStr(), "");  // Ensure null termination
  EXPECT_EQ(MyString::howMany(), 1);  // Check static counter
}

TEST(MyStringTest, CStringConstructor) {
  const char* cstr = "Hello";
  MyString str(cstr);
  EXPECT_EQ(str.strSize(), strlen(cstr));
  EXPECT_STREQ(str.getStr(), cstr);
}

TEST(MyStringTest, CopyConstructor) {
  MyString str1("Original");
  MyString str2(str1);
  EXPECT_EQ(str1.strSize(), str2.strSize());
  EXPECT_STREQ(str1.getStr(), str2.getStr());  // Deep copy verification
  EXPECT_NE(str1.getStr(), str2.getStr());     // Pointers should differ
  EXPECT_EQ(MyString::howMany(), 2);
}

TEST(MyStringTest, Destructor) {
  int initialCount = MyString::howMany();
  {
    MyString str("Temporary");
  }
  EXPECT_EQ(MyString::howMany(), initialCount);
}

TEST(MyStringTest, getStr) {
  MyString str("Test");
  char* returnedStr = str.getStr();
  EXPECT_STREQ(returnedStr, str.getStr());
  EXPECT_NE(returnedStr, str.getStr());   // Pointer to a copy
  delete[] returnedStr;            // Avoid memory leak
}

TEST(MyStringTest, setStrCString) {
  MyString str("Old");
  str.setStr("New");
  EXPECT_EQ(str.strSize(), strlen("New"));
  EXPECT_STREQ(str.getStr(), "New");
  EXPECT_EQ(MyString::howMany(), 1);  // Old string deallocated
}

TEST(MyStringTest, setStrMyString) {
  MyString str1("Source");
  MyString str2;
  str2.setStr(str1);
  EXPECT_EQ(str1.strSize(), str2.strSize());
  EXPECT_STREQ(str1.getStr(), str2.getStr());
  EXPECT_NE(str1.getStr(), str2.getStr());     // Pointers should differ
  EXPECT_EQ(MyString::howMany(), 2);
}


TEST(MyStringTest, setSize) {
  MyString str("Short");
  str.setSize(10);
  EXPECT_EQ(str.strSize(), 10);
  EXPECT_STREQ(str.getStr(), "Short\0\0\0\0\0");  // Padding with null chars
}


TEST(MyStringTest, AssignmentOperatorSelf) {
  MyString str("Original");
  str = str;
  EXPECT_EQ(str.strSize(), strlen("Original"));
  EXPECT_STREQ(str.getStr(), "Original");
  EXPECT_EQ(MyString::howMany(), 1);  // No reallocation
}

TEST(MyStringTest, AssignmentOperatorCString) {
  MyString str("Old");
  str = "New";
  EXPECT_EQ(str.strSize(), strlen("New"));
  EXPECT_STREQ(str.getStr(), "New");
  EXPECT_EQ(MyString::howMany(), 1);  // Old string deallocated
}

TEST(MyStringTest, stringLow) {
  MyString str("MiXeD cAsE");
  str.stringLow();
  EXPECT_EQ(str.strSize(), strlen("MiXeD cAsE"));
  EXPECT_STREQ(str.getStr(), "mixed case");
}

TEST(MyStringTest, stringUp) {
  MyString str("mixed case");
  str.stringUp();
  EXPECT_EQ(str.strSize(), strlen("mixed case"));
  EXPECT_STREQ(str.getStr(), "MIXED CASE");
}

TEST(MyStringTest, has) {
  MyString str("Occurrence");
  EXPECT_EQ(str.has('c'), 3);
  EXPECT_EQ(str.has('x'), 0);
  EXPECT_EQ(str.has('z'), 0);
}

TEST(MyStringTest, ComparisonOperators) {
  MyString str1("Apple");
  MyString str2("Banana");
  MyString str3("Apple");

  EXPECT_TRUE(str1 < str2);
  EXPECT_TRUE(str2 > str1);
  EXPECT_EQ(str1, str3);
}

TEST(MyStringTest, StreamOutput) {
  MyString str("Output test");
  std::stringstream ss;
  ss << str;
  EXPECT_EQ(ss.str(), "Output test");
}

TEST(MyStringTest, ConcatenationOperator) {
  MyString str1("Hello, ");
  MyString str2("world!");
  MyString result = str1 + str2;
  EXPECT_EQ(result.strSize(), strlen("Hello, world!"));
  EXPECT_STREQ(result.getStr(), "Hello, world!");
  str1 = str1 + str2;
  EXPECT_EQ(str1.strSize(), strlen("Hello, world!"));
  EXPECT_STREQ(str1.getStr(), "Hello, world!");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
