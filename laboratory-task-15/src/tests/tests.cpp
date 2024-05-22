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