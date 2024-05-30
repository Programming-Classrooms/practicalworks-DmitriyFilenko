#include "BusRoute.hpp"

BusRoute::BusRoute(BusRoute& rhs){
    this->busMark = rhs.busMark;
    this->busNumber = rhs.busNumber;
    this->driverName = rhs.driverName;
    this->routeNumber = rhs.routeNumber;
}

 void BusRoute::setRouteNumber(int32_t routeNumberRhs){
    this->routeNumber = routeNumberRhs;
 }
 void BusRoute::setDriverName(std::string nameRhs){
    this->driverName = nameRhs;
 }
 void BusRoute::setBusNumber(int32_t busNumberRhs){
    this->busNumber = busNumberRhs;
 }
 void BusRoute::setBusMark(std::string busMarkRhs){
    this->busMark = busMarkRhs;
 }

 int32_t BusRoute::getRouteNumber(){
return this->routeNumber;
 }
 std::string BusRoute::getDriverName(){
return this->driverName;
 }
 int32_t BusRoute::getBusNumber(){
return this->busNumber;
 }
 std::string BusRoute::getBusMark(){
return this->busMark;
 }