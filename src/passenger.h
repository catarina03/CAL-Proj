//
// Created by Adriana on 20/05/2020.
//

#ifndef CAL_PROJ_PASSENGER_H
#define CAL_PROJ_PASSENGER_H

#include <string>
using namespace std;

class Passenger {
public:
    int passengerID; //NIF of the user (which is already guaranteed to be unique)
    int originPassenger;
    int destinationPassenger;
    int earliestDepartureTime;
    int latestDepartureTime;

    Passenger(int passengerID, int originPassenger, int destinationPassenger, int earliestDepartureTime, int latestDepartureTime);

    int getPassengerID();
    int getOriginPassenger();
    int getDestinationPassenger();
    int getEarliestDepartureTime();
    int getLatestDepartureTime();

};


#endif //CAL_PROJ_PASSENGER_H
