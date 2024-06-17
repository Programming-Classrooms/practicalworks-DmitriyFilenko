#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include <algorithm>
#include "src/BusRoute/BusRoute.hpp"

std::queue<std::string> getTokens(const std::string& filePath) {
    std::ifstream fstream(filePath);
    if (!fstream) {
        throw std::invalid_argument("Couldn't read file!\n");
    }
    if (!fstream.is_open()) {
        throw std::invalid_argument("Couldn't open file stream!\n");
    }
    if (fstream.peek() == EOF) {
        throw std::invalid_argument("Couldn't read file! (End Of File reached)\n");
    }

    std::string inputString;
    std::queue<std::string> tokens;
    while (getline(fstream, inputString)) {
        std::stringstream ss(inputString);
        std::string token;
        char delimiter = ' ';
        while (getline(ss, token, delimiter)) {
            if (!token.empty()) {
                tokens.push(token);
            }
        }
    }
    fstream.close();
    return tokens;
}

std::queue<BusRoute> writeRouteToClass(std::queue<std::string> uQ) {
    std::queue<BusRoute> BusRouteQueue;
    size_t size = uQ.size() / 4;
    for (size_t i = 0; i < size; ++i) {
        BusRoute tempRoute;
        tempRoute.setRouteNumber(uQ.front());
        uQ.pop();
        tempRoute.setBusDriver(uQ.front());
        uQ.pop();
        tempRoute.setBusNumber(uQ.front());
        uQ.pop();
        tempRoute.setBusMark(uQ.front());
        uQ.pop();
        BusRouteQueue.push(tempRoute);
    }
    return BusRouteQueue;
}

void printBusRouteQueue(std::queue<BusRoute> BRQ) {
    while (!BRQ.empty()) {
        std::cout << '\t' << BRQ.front();
        BRQ.pop();
    }
    std::cout << '\n';
}

std::queue<BusRoute> sortingQueueByBusNumber(std::queue<BusRoute>& BRQ) {
    std::vector<BusRoute> tempVector;
    while (!BRQ.empty()) {
        tempVector.push_back(BRQ.front());
        BRQ.pop();
    }
    std::sort(tempVector.begin(), tempVector.end(), [](const BusRoute& a, const BusRoute& b) {
        return a.getBusNumber() < b.getBusNumber();
    });
    for (const auto& route : tempVector) {
        BRQ.push(route);
    }
    return BRQ;
}

std::queue<BusRoute> sortingQueueByRouteNumber(std::queue<BusRoute>& BRQ) {
    std::vector<BusRoute> tempVector;
    while (!BRQ.empty()) {
        tempVector.push_back(BRQ.front());
        BRQ.pop();
    }
    std::sort(tempVector.begin(), tempVector.end(), [](const BusRoute& a, const BusRoute& b) {
        return a.getRouteNumber() < b.getRouteNumber();
    });
    for (const auto& route : tempVector) {
        BRQ.push(route);
    }
    return BRQ;
}


std::map<std::string, BusRoute> queueToMap(std::queue<BusRoute>& BRQ) {
    std::map<std::string, BusRoute> BusRouteMap;

    while (!BRQ.empty()) {
        BusRoute tempRoute = BRQ.front();
        BRQ.pop();
        BusRouteMap[tempRoute.getRouteNumber()] = tempRoute;
    }

    return BusRouteMap;
}


void printBusRouteMap(const std::map<std::string, BusRoute>& BusRouteMap) {
    for (const auto& [routeNumber, busRoute] : BusRouteMap) {
        std::cout << "Ключ (Номер маршрута): " << routeNumber << '\n' << busRoute << '\n';
    }
}

void printUniqueBusRoutes(const std::queue<BusRoute>& BRQ) {
    std::set<BusRoute> uniqueBusRoutes;
    std::queue<BusRoute> tempQueue = BRQ;

    while (!tempQueue.empty()) {
        uniqueBusRoutes.insert(tempQueue.front());
        tempQueue.pop();
    }

    for (const auto& busRoute : uniqueBusRoutes) {
        std::cout << busRoute;
    }
	std::cout << '\n';
}


void printDriversByBusMark(const std::queue<BusRoute>& BRQ) {
    std::map<std::string, std::set<std::string>> busMarkToDriversMap;
    std::queue<BusRoute> tempQueue = BRQ;

    while (!tempQueue.empty()) {
        BusRoute currentRoute = tempQueue.front();
        tempQueue.pop();
        busMarkToDriversMap[currentRoute.getBusMark()].insert(currentRoute.getBusDriver());
    }

    for (const auto& [busMark, drivers] : busMarkToDriversMap) {
        std::cout << "Марка автобуса: " << busMark << "\nВодители:\n";
        for (const auto& driver : drivers) {
            std::cout << "\t" << driver << "\n";
        }
        std::cout << "\n";
    }
}


void replaceDriver(std::queue<BusRoute>& BRQ, const std::string& currentDriver, const std::string& newDriver) {
    std::queue<BusRoute> tempQueue;

    while (!BRQ.empty()) {
        BusRoute tempRoute = BRQ.front();
        BRQ.pop();
        if (tempRoute.getBusDriver() == currentDriver) {
            tempRoute.setBusDriver(newDriver);
        }
        tempQueue.push(tempRoute);
    }

    BRQ = tempQueue;
}


size_t countUniqueBusMarks(const std::queue<BusRoute>& BRQ) {
    std::set<std::string> uniqueBusMarks;
    std::queue<BusRoute> tempQueue = BRQ;

    while (!tempQueue.empty()) {
        uniqueBusMarks.insert(tempQueue.front().getBusMark());
        tempQueue.pop();
    }

    return uniqueBusMarks.size();
}




#endif //FUNCTION_HPP