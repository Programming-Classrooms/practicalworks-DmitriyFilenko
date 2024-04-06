#include <stdexcept>
#include <gtest/gtest.h>
#include "../LinkedList/LinkedList.hpp"


// Test constructors
TEST(LinkedListTest, ConstructorTest) {
    LinkedList emptyList;
    EXPECT_EQ(emptyList.popValue(), -1);
}

// Test adding values
TEST(LinkedListTest, AddValueTest) {
    LinkedList list1;
    list1.addValue(3);
    list1.addValue(7);
    list1.addValue(2);

    list1.addValue(10);
    EXPECT_EQ(list1.popValue(), 10);
}

// Test popping values
TEST(LinkedListTest, PopValueTest) {
    LinkedList list1;
    list1.addValue(3);
    list1.addValue(7);
    list1.addValue(2);

    EXPECT_EQ(list1.popValue(), 2);
}

// Test cloning
TEST(LinkedListTest, CloneTest) {
    LinkedList list1;
    list1.addValue(3);
    list1.addValue(7);
    list1.addValue(2);

    LinkedList list3 = list1;
    EXPECT_EQ(list3.popValue(), 2);
    EXPECT_EQ(list3.popValue(), 7);
    EXPECT_EQ(list3.popValue(), 3);
}

// Test sorting and insertion
TEST(LinkedListTest, InsertSortedTest) {
LinkedList list2;
    list2.insertSorted(5);
    list2.insertSorted(1);
    list2.insertSorted(9);
    list2.insertSorted(4);
    EXPECT_EQ(list2.popValue(), 1);
    EXPECT_EQ(list2.popValue(), 4);
    EXPECT_EQ(list2.popValue(), 5);
    EXPECT_EQ(list2.popValue(), 9);
}

// Test searching
TEST(LinkedListTest, SearchTest) {
    LinkedList list1;
    list1.addValue(3);
    list1.addValue(7);
    list1.addValue(2);
    EXPECT_EQ(list1.search(7), 1);
    EXPECT_EQ(list1.search(10), -1);
}

// Test removing by value
TEST(LinkedListTest, RemoveByValueTest) {
     LinkedList list2;
        list2.addValue(5);
        list2.addValue(1);
        list2.addValue(9);

    list2.removeByValue(1);
    list2.removeByValue(9);
    EXPECT_EQ(list2.popValue(), 5);
    EXPECT_EQ(list2.popValue(), -1);
}

// Test adding value at the beginning
TEST(LinkedListTest, AddValueAtBeginTest) {
    LinkedList list1;
    list1.addValue(3);
    list1.addValue(7);
    list1.addValue(2);
    list1.addValueAtBegin(9);
    EXPECT_EQ(list1.popValue(), 9);
    EXPECT_EQ(list1.popValue(), 2);
}

// Test clearing the list
TEST(LinkedListTest, ClearTest) {
    LinkedList list1;
    list1.addValue(3);
    list1.addValue(7);
    list1.addValue(2);
    list1.clear();
    EXPECT_EQ(list1.popValue(), -1);
}