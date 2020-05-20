//
// Created by Adriana on 20/05/2020.
//

#ifndef CAL_PROJ_PASSENGER_H
#define CAL_PROJ_PASSENGER_H

#include <string>
using namespace std;

class Passenger {
public:
    string originPassenger;
    string destinationPassenger;
    int earliestDepartureTime;
    int latestDepartureTime;

    Passenger(string originPassenger, string destinationPassenger, int earliestDepartureTime, int latestDepartureTime);

    string getOriginPassenger();
    string getDestinationPassenger();
    int getEarliestDepartureTime();
    int getLatestDepartureTime();

};


#endif //CAL_PROJ_PASSENGER_H
