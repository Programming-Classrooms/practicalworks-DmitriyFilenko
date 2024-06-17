#include <gtest/gtest.h>
#include "src/TDeque/TDeque.hpp"

// TEST(TDeque, TDeque) {
//     TDeque<int> TDeque;

//     TDeque.InsFront(1);
//     TDeque.InsRear(2);
//     TDeque.InsFront(0);
//     TDeque.InsRear(3);

//     EXPECT_EQ(TDeque.Size(), 4);
// }
TEST(test, test1){
    EXPECT_EQ(1,1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
// Тесты для класса TDeque с целыми числами
TEST(TDequeTest, IntDequeOperations) {
    TDeque<int> deque;

    // Проверка начального состояния
    EXPECT_EQ(deque.GetSize(), 0);

    // Добавление элементов в начало и конец
    deque.InsFront(1);
    deque.InsRear(2);
    deque.InsFront(0);
    deque.InsRear(3);

    // Проверка размеров и элементов
    EXPECT_EQ(deque.GetSize(), 4);
    EXPECT_EQ(deque.GetByIndex(0), 0);
    EXPECT_EQ(deque.GetByIndex(1), 1);
    EXPECT_EQ(deque.GetByIndex(2), 2);
    EXPECT_EQ(deque.GetByIndex(3), 3);

    // Удаление элементов из начала и конца
    int value;
    EXPECT_TRUE(deque.DelFront(value));
    EXPECT_EQ(value, 0);
    EXPECT_TRUE(deque.DelRear(value));
    EXPECT_EQ(value, 3);
    EXPECT_TRUE(deque.DelFront(value));
    EXPECT_EQ(value, 1);
    EXPECT_TRUE(deque.DelRear(value));
    EXPECT_EQ(value, 2);

    // Проверка на пустоту после удаления всех элементов
    EXPECT_EQ(deque.GetSize(), 0);
}

// Тесты для класса TDeque с char*
TEST(TDequeTest, CharDequeOperations) {
    TDeque<char*> deque;

    // Создание строк для тестов
    char str1[] = "first";
    char str2[] = "second";
    char str3[] = "third";
    char str4[] = "fourth";

    // Добавление строк в дек
    deque.InsFront(str1);
    deque.InsRear(str2);
    deque.InsFront(str3);
    deque.InsRear(str4);

    // Проверка размеров и элементов
    EXPECT_EQ(deque.GetSize(), 4);
    EXPECT_STREQ(deque.GetByIndex(0), str3);
    EXPECT_STREQ(deque.GetByIndex(1), str1);
    EXPECT_STREQ(deque.GetByIndex(2), str2);
    EXPECT_STREQ(deque.GetByIndex(3), str4);

    // Удаление элементов из начала и конца
    char* value;
    EXPECT_TRUE(deque.DelFront(value));
    EXPECT_STREQ(value, str3);
    EXPECT_TRUE(deque.DelRear(value));
    EXPECT_STREQ(value, str4);
    EXPECT_TRUE(deque.DelFront(value));
    EXPECT_STREQ(value, str1);
    EXPECT_TRUE(deque.DelRear(value));
    EXPECT_STREQ(value, str2);

    // Проверка на пустоту после удаления всех элементов
    EXPECT_EQ(deque.GetSize(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
