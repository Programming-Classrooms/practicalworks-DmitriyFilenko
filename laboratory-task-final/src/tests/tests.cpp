#include <stdexcept>
#include <gtest/gtest.h>
#include "src/function/function.hpp"
#include "src/BusRoute/BusRoute.hpp"


TEST(testCase, testName) 
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
