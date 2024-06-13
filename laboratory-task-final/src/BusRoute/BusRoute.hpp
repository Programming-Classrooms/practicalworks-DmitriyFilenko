#ifndef BUSROUTE_HPP
#define BUSROUTE_HPP


#include <cstdlib>
#include <iostream> 
#include <fstream>
#include <sstream> 
#include <vector> 
#include <queue>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <set>


class BusRoute {
private:
    std::string routeNumber;
    std::string busDriver;
    std::string busNumber;
    std::string busMark;

public:
    BusRoute() = default;

    BusRoute(std::string routeNumberRhs, std::string busDriverRhs, std::string busNumberRhs, std::string busMarkRhs)
        : routeNumber(routeNumberRhs), busDriver(busDriverRhs), busNumber(busNumberRhs), busMark(busMarkRhs) {}

    ~BusRoute() = default;

    std::string getRouteNumber() const { return routeNumber; }
    std::string getBusDriver() const { return busDriver; }
    std::string getBusNumber() const { return busNumber; }
    std::string getBusMark() const { return busMark; }

    void setRouteNumber(const std::string& routeNumberRhs) { routeNumber = routeNumberRhs; }
    void setBusDriver(const std::string& busDriverRhs) { busDriver = busDriverRhs; }
    void setBusNumber(const std::string& busNumberRhs) { busNumber = busNumberRhs; }
    void setBusMark(const std::string& busMarkRhs) { busMark = busMarkRhs; }

    friend std::ostream& operator<<(std::ostream& out, const BusRoute& BR) {
        out << "\nНомер Маршрута: " << BR.getRouteNumber()
            << "\nВодитель: " << BR.getBusDriver()
            << "\nНомер автобуса: " << BR.getBusNumber()
            << "\nМарка Автобуса: " << BR.getBusMark() << '\n';
        return out;
    }

    BusRoute& operator=(const BusRoute& BR) {
        if (this != &BR) {
            setRouteNumber(BR.getRouteNumber());
            setBusDriver(BR.getBusDriver());
            setBusNumber(BR.getBusNumber());
            setBusMark(BR.getBusMark());
        }
        return *this;
    }

    friend bool operator<(const BusRoute& BR1, const BusRoute& BR2) {
        return BR1.getBusNumber() < BR2.getBusNumber();
    }

    bool operator==(const BusRoute& other) const {
        return routeNumber == other.routeNumber &&
               busNumber == other.busNumber;
    }
};


#endif //BUSROUTE_HPP