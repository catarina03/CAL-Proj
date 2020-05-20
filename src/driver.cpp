//
// Created by Adriana on 20/05/2020.
//

#include "driver.h"

Driver::Driver(string originDriver, string destinationDriver, int earliestDepartureTime, int latestDepartureTime,
               int maxDetourDistance, string vehicleId, int vehicleCapacity) {
    this->originDriver = originDriver;
    this->destinationDriver = destinationDriver;
    this->earliestDepartureTime = earliestDepartureTime;
    this->latestDepartureTime = latestDepartureTime;
    this->maxDetourDistance = maxDetourDistance;
    this->vehicleId = vehicleId;
    this->vehicleCapacity = vehicleCapacity;
}

string Driver::getOriginDriver() {
    return this->originDriver;
}

string Driver::getDestinationDriver() {
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

string Driver::getVehicleId() {
    return this->vehicleId;
}

int Driver::getVehicleCapacity() {
    return this->vehicleCapacity;
}
