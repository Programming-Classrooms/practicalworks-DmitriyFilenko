#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>

// Объявление класса Train
class Train {
public:
    int32_t number;
    std::string destination;
    std::string type;
    std::string departureTime;
    int32_t travelTime;

    // =======================================================================================
    // ===================================== Конструктор =====================================
    // =======================================================================================

    Train(int32_t num, std::string dest, std::string t, std::string depTime, int32_t travel);

    // =======================================================================================
    // ===================================== Деструктор ======================================
    // =======================================================================================
    
    ~Train() {}

    // Функция для вывода информации о поезде
    void printTrainInfo();
};

#endif //TRAIN_HPP
