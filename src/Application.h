//
// Created by Adriana on 20/05/2020.
//

#ifndef CAL_PROJ_APPLICATION_H
#define CAL_PROJ_APPLICATION_H


#include "passenger.h"
#include "driver.h"
#include <vector>
#include "Graph/Graph.h"
#include "Utils/Utils.h"
#include "Utils/Visualization.h"


class Application {
public:
    string name;
    vector<Passenger *> passengers;
    vector<Driver *> drivers;

    explicit Application(string name);

    void addPassenger(Passenger *passenger);
    void removePassenger(Passenger *passenger);
    bool passengerExists(int passengerID);

    void addDriver(Driver *driver);
    void removeDriver(Driver *driver);
    bool driverExists(int driverID);

    int findRide();
    void showResults();

    void updatePassengerRecord(Passenger *passenger);
    void updateDriverRecord(Driver *driver);
};


#endif //CAL_PROJ_APPLICATION_H
