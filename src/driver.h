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
    string originDriver;
    string destinationDriver;
    int earliestDepartureTime;
    int latestDepartureTime;
    int maxDetourDistance;
    string vehicleId;  //license plate number
    int vehicleCapacity;

    Driver(int driverID, string originDriver, string destinationDriver, int earliestDepartureTime, int latestDepartureTime, int maxDetourDistance, string vehicleId, int vehicleCapacity);

    int getDriverID();
    string getOriginDriver();
    string getDestinationDriver();
    int getEarliestDepartureTime();
    int getLatestDepartureTime();
    int getMaxDetourDistance();
    string getVehicleId();
    int getVehicleCapacity();
};


#endif //CAL_PROJ_DRIVER_H
