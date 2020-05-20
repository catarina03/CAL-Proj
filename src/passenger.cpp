//
// Created by Adriana on 20/05/2020.
//

#include "passenger.h"

Passenger::Passenger(int passengerID, string originPassenger, string destinationPassenger, int earliestDepartureTime,
                     int latestDepartureTime):passengerID(passengerID) {
    this->originPassenger = originPassenger;
    this->destinationPassenger = destinationPassenger;
    this->earliestDepartureTime = earliestDepartureTime;
    this->latestDepartureTime = latestDepartureTime;
}

int Passenger::getPassengerID() {
    return this->passengerID;
}

string Passenger::getOriginPassenger() {
    return this->originPassenger;
}

string Passenger::getDestinationPassenger() {
    return this->destinationPassenger;
}

int Passenger::getEarliestDepartureTime() {
    return this->earliestDepartureTime;
}

int Passenger::getLatestDepartureTime() {
    return this->latestDepartureTime;
}