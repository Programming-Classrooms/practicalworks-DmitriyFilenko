
#include "function.hpp"

std::vector<std::vector<int32_t>> deleteMaxElement(std::vector<std::vector<int32_t>>& matrix, int32_t& rows, int32_t& cols) {
    // найти максимальный элемент
    int32_t maxElement = -2147483648;
    int32_t maxRow = -1;
    int32_t maxCol = -1;
    for (int32_t i = 0; i < matrix.size(); ++i) {
        for (int32_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // проверка размеров матрицы
    if (maxRow >= 0 && maxRow < matrix.size() && maxCol >= 0 && maxCol < matrix[maxRow].size()) {
        // удаление строки и столбца
        matrix.erase(matrix.begin() + maxRow);
        for (int32_t i = 0; i < matrix.size(); ++i) {
            matrix[i].erase(matrix[i].begin() + maxCol);
        }
        rows = matrix.size();
        cols = matrix[0].size();
    }

    return matrix;
}

void print(std::vector<std::vector<int32_t>> matrix, int32_t rows, int32_t cols) {
    for (int32_t i = 0; i < rows; ++i) {
        for (int32_t j = 0; j < cols; ++j) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

std::vector < std::vector < int32_t > > sortWithoutSorting(std::vector < std::vector < int32_t > > matrix, int32_t rows, int32_t cols) {
    for (int32_t i = 0; i < rows - 1; ++i) {
        int32_t minRowInd = i;
        for (int32_t j = i + 1; j < rows; ++j) {
        int32_t sum1 = std::accumulate(matrix[minRowInd].begin(), matrix[minRowInd].end(), 0);
        int32_t sum2 = std::accumulate(matrix[j].begin(), matrix[j].end(), 0);
            if (sum2 < sum1) {
                minRowInd = j;
             }
        }
     if (minRowInd != i) {
            std::swap(matrix[i], matrix[minRowInd]);
     }
    }
}
