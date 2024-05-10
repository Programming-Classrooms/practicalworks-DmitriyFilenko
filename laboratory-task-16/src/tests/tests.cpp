#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "../function/function.hpp"

//Фикстура для теста
class FunctionTest : public ::testing::Test {
protected:
    std::vector<int32_t> numbers;
    std::vector<std::vector<int32_t>> matrix;
    std::vector<std::string> words;

    void SetUp() override {
        numbers = {1, 2, 3, 4, 5};

        matrix = {{1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};

        std::ifstream fin("src/data/something.txt");
        std::string word;
        while (fin >> word) {
            words.push_back(word);
        }
        fin.close();
    }
};

TEST_F(FunctionTest, VectorManipulation) {

    EXPECT_EQ(std::accumulate(numbers.begin(), numbers.end(), 0), 15);

    EXPECT_EQ(std::count(numbers.begin(), numbers.end(), 3), 1);

    EXPECT_TRUE(std::all_of(numbers.begin(), numbers.end(), [](int32_t i) { return i > 0; }));
    
    int32_t middle = std::accumulate(numbers.begin(), numbers.end(), 0) / numbers.size();

    std::replace_if(numbers.begin(), numbers.end(), [](int32_t i) { return i == 0; }, middle);

    EXPECT_EQ(std::count(numbers.begin(), numbers.end(), 0), 0);
}

TEST_F(FunctionTest, MatrixOperations) {

    int32_t rows = 3;
    int32_t columns = 3;

    deleteMaxElement(matrix, rows, columns);
    bool maxElementExists = false;

   for (const auto& row : matrix) {
        if (std::find(row.begin(), row.end(), 9) != row.end()) {
            maxElementExists = true;
            break;
        }
    }
    EXPECT_FALSE(maxElementExists);
}

TEST_F(FunctionTest, FileReadingAndWordManipulation) {

    EXPECT_EQ(words.size(), 11);
    
    std::vector<std::string> sortedWords = words;
    std::sort(sortedWords.begin(), sortedWords.end());

    EXPECT_NE(words, sortedWords);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
