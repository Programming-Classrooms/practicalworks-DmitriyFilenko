#include <stdexcept>
#include <gtest/gtest.h>
#include "../MyMatrix/MyMatrix.hpp"


TEST(MyMatrixTest, DefaultConstructor) {
    MyMatrix matrix;
    EXPECT_EQ(matrix.getRows(), 0);
    EXPECT_EQ(matrix.getColumns(), 0);
}

TEST(MyMatrixTest, SquareConstructor) {
    int32_t size = 3;
    MyMatrix matrix(size);
    EXPECT_EQ(matrix.getRows(), size);
    EXPECT_EQ(matrix.getColumns(), size);
}

TEST(MyMatrixTest, CustomConstructor) {
    int32_t rows = 2;
    int32_t columns = 3;
    MyMatrix matrix(rows, columns);
    EXPECT_EQ(matrix.getRows(), rows);
    EXPECT_EQ(matrix.getColumns(), columns);
}

TEST(MyMatrixTest, CopyConstructor) {
    MyMatrix matrix(2, 2);
    matrix.setElement(5, 0, 0);
    MyMatrix copy(matrix);
    EXPECT_EQ(copy.getElement(0, 0), 5);
}

TEST(MyMatrixTest, AssignmentOperator) {
    MyMatrix matrix(2, 2);
    matrix.setElement(5, 0, 0);
    MyMatrix copy;
    copy = matrix;
    EXPECT_EQ(copy.getElement(0, 0), 5);
}

TEST(MyMatrixTest, ElementAccess) {
    MyMatrix matrix(2, 2);
    matrix.setElement(5, 0, 0);
    EXPECT_EQ(matrix.getElement(0, 0), 5);
}

TEST(MyMatrixTest, MatrixMultiplication) {
    MyMatrix matrix1(2, 3);
    MyMatrix matrix2(3, 2);
    matrix1.setElement(1, 0, 0);
    matrix1.setElement(2, 0, 1);
    matrix1.setElement(3, 1, 0);
    matrix1.setElement(4, 1, 1);
    matrix1.setElement(5, 1, 2);
    matrix2.setElement(6, 0, 0);
    matrix2.setElement(7, 0, 1);
    matrix2.setElement(8, 1, 0);
    matrix2.setElement(9, 1, 1);
    matrix2.setElement(10, 2, 0);
    matrix2.setElement(11, 2, 1);

    MyMatrix result = matrix1 * matrix2;

    // Проверяем результат умножения
    EXPECT_EQ(result.getElement(0, 0), 22);
    EXPECT_EQ(result.getElement(0, 1), 25);
    EXPECT_EQ(result.getElement(1, 0), 100);
    EXPECT_EQ(result.getElement(1, 1), 112);
}