#include <stdexcept>
#include <gtest/gtest.h>
#include "../Fraction/Fraction.hpp"


TEST(FractionTest, ConstructorTest) {
    Fraction fraction1(3,4);
    EXPECT_EQ(fraction1.getNum(), 3);
    EXPECT_EQ(fraction1.getDenum(), 4);
}

// Test arithmetic operators
TEST(FractionTest, AdditionTest) {
    Fraction fraction1(3,4);
    Fraction fraction2(2,5);
    Fraction result = fraction1 + fraction2;
    EXPECT_EQ(result.getNum(), 23);
    EXPECT_EQ(result.getDenum(), 20);
}

TEST(FractionTest, SubtractionTest) {
    Fraction fraction1(3,4);
    Fraction fraction2(2,5);
    Fraction result = fraction1 - fraction2;
    EXPECT_EQ(result.getNum(), 7);
    EXPECT_EQ(result.getDenum(), 20);
}

TEST(FractionTest, MultiplicationTest) {
    Fraction fraction1(3,4);
    Fraction fraction2(2,5);
    Fraction result = fraction1 * fraction2;
    EXPECT_EQ(result.getNum(), 3);
    EXPECT_EQ(result.getDenum(), 10);
}

TEST(FractionTest, DivisionTest) {
    Fraction fraction1(3,4);
    Fraction fraction2(2,5);
    Fraction result = fraction1 / fraction2;
    EXPECT_EQ(result.getNum(), 15);
    EXPECT_EQ(result.getDenum(), 8);
}

// Test comparison operators
TEST(FractionTest, ComparisonTest) {
    Fraction fraction1(3,4);
    Fraction fraction2(2,5);
    Fraction fraction3(-1,2);
    EXPECT_TRUE(fraction1 > fraction2);
    EXPECT_TRUE(fraction3 < fraction1);
    Fraction fraction4(6,8);
    EXPECT_TRUE(fraction1 == fraction4);
}

// Test increment and decrement operators
TEST(FractionTest, IncrementDecrementTest) {
    Fraction fraction1(3,4);
    Fraction fraction2(2,5);
    Fraction fraction3(-1,2);
    Fraction result = fraction1++;
    EXPECT_EQ(result, Fraction(3, 4));
    EXPECT_EQ(fraction1, Fraction(7, 4));

    result = ++fraction2;
    EXPECT_EQ(result, Fraction(7, 5));
    EXPECT_EQ(fraction2, Fraction(7, 5));

    result = fraction3--;
    EXPECT_EQ(result, Fraction(-1, 2));
    EXPECT_EQ(fraction3, Fraction(-3, 2));
result.setNum(11);
result.setDenum(4);

    result = --fraction1;
    EXPECT_EQ(result, Fraction(3, 4));
    EXPECT_EQ(fraction1, Fraction(3, 4));
}

// Test other member functions
TEST(FractionTest, OtherFunctionsTest) {
    Fraction fraction(4,6);
    Fraction fraction1(3,4);
    Fraction fraction2(2,5);
    fraction.reduct();
    EXPECT_EQ(fraction.getNum(), 2);
    EXPECT_EQ(fraction.getDenum(), 3);

    EXPECT_DOUBLE_EQ(fraction1.toDouble(), 0.75);
    EXPECT_DOUBLE_EQ(fraction2.toDouble(), 0.4);

    fraction.setNum(5);
    fraction.setDenum(7);
    EXPECT_EQ(fraction.getNum(), 5);
    EXPECT_EQ(fraction.getDenum(), 7);
}

// Test input/output operators
TEST(FractionTest, InputOutputTest) {
    Fraction fraction;
    std::istringstream iss("2/3");
    iss >> fraction;
    std::ostringstream oss;
    oss << fraction;
    EXPECT_EQ(oss.str(), "2/3");
}