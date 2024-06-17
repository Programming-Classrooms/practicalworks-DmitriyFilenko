
#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <set>
#include <string>
#include <numeric> 
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <iomanip>


std::vector < std::vector < int32_t > > deleteMaxElement(std::vector<std::vector<int32_t> >&, int32_t&,int32_t&);

void print(std::vector<std::vector<int32_t>> matrix, int32_t rows, int32_t cols);

void sortWithoutSorting(std::vector < std::vector < int32_t > > matrix, int32_t rows, int32_t cols);

#endif //FUNCS_HPP
