//
// Created by Adriana on 20/05/2020.
//

#ifndef CAL_PROJ_DRIVER_H
#define CAL_PROJ_DRIVER_H

#include <string>
using namespace std;


class Driver {
public:
    int driverID;  //NIF of the user (which is already guaranteed to be unique)
    int originDriver;
    int destinationDriver;
    int earliestDepartureTime;
    int latestDepartureTime;
    int maxDetourDistance;
    int vehicleCapacity;

    Driver(int driverID, int originDriver, int destinationDriver, int earliestDepartureTime, int latestDepartureTime, int maxDetourDistance, int vehicleCapacity);

    int getDriverID();
    int getOriginDriver();
    int getDestinationDriver();
    int getEarliestDepartureTime();
    int getLatestDepartureTime();
    int getMaxDetourDistance();
    int getVehicleCapacity();
};


#endif //CAL_PROJ_DRIVER_H
