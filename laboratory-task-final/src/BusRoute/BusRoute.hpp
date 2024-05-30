#ifndef BUSROUTE_HPP
#define BUSROUTE_HPP


#include <iostream> // std::cin/out
#include <algorithm>
#include <stdexcept> // try-catch
#include <queue> // container
#include <string> // std::string


class BusRoute{
private:
int32_t routeNumber;
std::string driverName;
int32_t busNumber;
std::string busMark;
public:
BusRoute(){}; // Конструктор по умолчанию
BusRoute(int32_t routeNumberRhs, std::string driverNameRhs, int32_t busNumberRhs, std::string busMarkRhs): // Конструктор с параметрами
 routeNumber(routeNumberRhs),
 driverName(driverNameRhs),
 busNumber(busNumberRhs),
 busMark(busMarkRhs){}
 BusRoute(BusRoute&);
 ~BusRoute() = default; // Деструктор
 void setRouteNumber(int32_t routeNumberRhs);
 void setDriverName(std::string nameRhs);
 void setBusNumber(int32_t busNumberRhs);
 void setBusMark(std::string busMarkRhs);

 int32_t getRouteNumber();
 std::string getDriverName();
 int32_t getBusNumber();
 std::string getBusMark();

 friend std::ostream& operator<<(std::ostream& out, BusRoute obj){
    out << "\nНомер:" << obj.routeNumber << "\nВодитель:"  << obj.driverName << "\nРегистрационный номер:"  << obj.busNumber << "\nМарка автобуса:"  << obj.busMark;
 return out;
 }
};

#endif //BUSROUTE_HPP