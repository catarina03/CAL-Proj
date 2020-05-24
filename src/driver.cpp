//
// Created by Adriana on 20/05/2020.
//

#include "driver.h"

Driver::Driver(int driverID, int originDriver, int destinationDriver, int earliestDepartureTime, int latestDepartureTime,
               int maxDetourDistance, int vehicleCapacity):driverID(driverID) {
    this->originDriver = originDriver;
    this->destinationDriver = destinationDriver;
    this->earliestDepartureTime = earliestDepartureTime;
    this->latestDepartureTime = latestDepartureTime;
    this->maxDetourDistance = maxDetourDistance;
    this->vehicleCapacity = vehicleCapacity;
}

int Driver::getDriverID() {
    return this->driverID;
}

int Driver::getOriginDriver() {
    return this->originDriver;
}

int Driver::getDestinationDriver() {
    return this->destinationDriver;
}

int Driver::getEarliestDepartureTime() {
    return this->earliestDepartureTime;
}

int Driver::getLatestDepartureTime() {
    return this->latestDepartureTime;
}

int Driver::getMaxDetourDistance() {
    return this->maxDetourDistance;
}

int Driver::getVehicleCapacity() {
    return this->vehicleCapacity;
}
