#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <queue>
#include <fstream>


#include "src/BusRoute/BusRoute.hpp"

void readData(std::queue<BusRoute>& busRoutes, const std::string path);

#endif//FUNCTION_HPP