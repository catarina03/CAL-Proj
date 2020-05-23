//
// Created by Adriana on 20/05/2020.
//

#include "Application.h"
#include <iostream>
#include <vector>
using namespace std;

Application::Application(string name) {
    this->name = name;
}

void Application::addPassenger(Passenger *passenger) {
    int passengerID = passenger->getPassengerID();
    if (passengerExists(passengerID)){
        cout << "You're already registered as a passenger on MeetUpRider!" << endl;
    }
    else{
        this->passengers.push_back(passenger);
    }

}

void Application::removePassenger(Passenger *passenger) {
    int passengerID = passenger->getPassengerID();
    if (!passengerExists(passengerID)){
        cout << "You're trying to delete a passenger that is not registered on MeetUpRider!" << endl;
    }
    else{
        for(int i = 0; i < passengers.size(); i++){
            if(passengers.at(i)->getPassengerID() == passengerID)
                passengers.erase(passengers.begin()+i);
        }
    }
}

bool Application::passengerExists(int passengerID) {
    for(Passenger* passenger : passengers){
        if(passenger->getPassengerID()==passengerID)
            return true;
    }
    return false;
}

void Application::addDriver(Driver *driver) {
    int driverID = driver->getDriverID();
    if (driverExists(driverID)){
        cout << "You're already registered as a driver on MeetUpRider!" << endl;
    }
    else{
        this->drivers.push_back(driver);
    }

}

void Application::removeDriver(Driver *driver) {
    int driverID = driver->getDriverID();
    if (!driverExists(driverID)){
        cout << "You're trying to delete a driver that is not registered on MeetUpRider!" << endl;
    }
    else{
        for(int i = 0; i < drivers.size(); i++){
            if(drivers.at(i)->getDriverID() == driverID)
                drivers.erase(drivers.begin()+i);
        }
    }
}

bool Application::driverExists(int driverID) {
    for(Driver* driver : drivers){
        if(driver->getDriverID()==driverID)
            return true;
    }
    return false;
}

int Application::findRide() {

    //fazemos aqui o processamento dos dados de entrada e dos grafos

    return 0;
}

void Application::showResults(){
    Graph<Coordinates> graph = mapParser("../Maps/GridGraphs/16x16/nodes.txt", "../Maps/GridGraphs/16x16/edges.txt");

    //floyd warshall
    /*
    graph.floydWarshallShortestPath();
    vector<Coordinates> path=graph.getfloydWarshallPath(make_pair(0,0),make_pair(333,222));
    */
    //Dijkstra

    graph.dijkstraShortestPathByID(0);
    //vector<Coordinates> path = graph.getPathTo(make_pair(300, 600)); //Works in 4x4 and 8x8

    vector<Coordinates> path = graph.getPathTo(make_pair(333, 222)); //Works in 4x4 and 8x8 and 16x16


    showGraph(&graph, path);

    /*
    //A*
    //16x16
    Coordinates orig = make_pair(0, 0);
    Coordinates dest = make_pair(333, 222);
    vector<Coordinates> result = graph.AStarShortestPathByInfo(orig, dest);
    showGraph(&graph, result);
     */

}


void Application::updatePassengerRecord(Passenger *passenger){
    vector<string> initialPassengers;
    string line;
    ifstream loadfile;
    loadfile.open("../src/passengerRecord.txt");
    if(loadfile.is_open()){
        while(getline(loadfile, line)){
            initialPassengers.push_back(line);
        }
    }
    else{
        cout << "Error on opening passenger log file 1" << endl;
    }
    loadfile.close();

    ofstream updatedfile;
    updatedfile.open("../src/passengerRecord.txt");
    if(updatedfile.is_open()){
        for(string passenger_loop : initialPassengers){
            updatedfile << passenger_loop << endl;
        }
        updatedfile << to_string(passenger->getPassengerID()) << endl;
        updatedfile << passenger->getOriginPassenger() << endl;
        updatedfile << passenger->getDestinationPassenger() << endl;
        updatedfile << to_string(passenger->getEarliestDepartureTime()) << endl;
        updatedfile << to_string(passenger->getLatestDepartureTime()) << endl;
    }
    else{
        cout << "Error on opening passenger log file 2" << endl;
    }
    updatedfile.close();
}

void Application::updateDriverRecord(Driver *driver){
    vector<string> initialDrivers;
    string line;
    ifstream loadfile;
    loadfile.open("../src/driverRecord.txt");
    if(loadfile.is_open()){
        while(getline(loadfile, line)){
            initialDrivers.push_back(line);
        }
    }
    else{
        cout << "Error on opening passenger log file 1" << endl;
    }
    loadfile.close();

    ofstream updatedfile;
    updatedfile.open("../src/driverRecord.txt");
    if(updatedfile.is_open()){
        for(string driver_loop : initialDrivers){
            updatedfile << driver_loop << endl;
        }
        updatedfile << to_string(driver->getDriverID()) << endl;
        updatedfile << driver->getOriginDriver() << endl;
        updatedfile << driver->getDestinationDriver() << endl;
        updatedfile << to_string(driver->getEarliestDepartureTime()) << endl;
        updatedfile << to_string(driver->getLatestDepartureTime()) << endl;
        updatedfile << to_string(driver->getMaxDetourDistance()) << endl;
        updatedfile << driver->getVehicleId() << endl;
        updatedfile << to_string(driver->getVehicleCapacity()) << endl;
    }
    else{
        cout << "Error on opening passenger log file 2" << endl;
    }
    updatedfile.close();
}