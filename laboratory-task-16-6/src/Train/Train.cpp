#include "Train.hpp"

Train::Train(int32_t num, std::string dest, std::string t, std::string depTime, int32_t travel) {
        number = num;
        destination = dest;
        type = t;
        departureTime = depTime;
        travelTime = travel;
    }

void Train::printTrainInfo() {
        std::cout << "Номер поезда: " << number << std::endl;
        std::cout << "Пункт назначения: " << destination << std::endl;
        std::cout << "Тип поезда: " << type << std::endl;
        std::cout << "Время отправления: " << departureTime << std::endl;
        std::cout << "Время в пути: " << travelTime << " ч." << std::endl;
        std::cout << std::endl;
    }
