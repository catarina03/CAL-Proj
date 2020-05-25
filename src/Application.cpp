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

    int originDriver = drivers[0]->getOriginDriver();
    int destinationDriver = drivers[0]->getDestinationDriver();
    indexes.push_back(originDriver);
    //for(Passenger* passenger : passengers){
    //    indexes.push_back(passenger->getOriginPassenger());
    //    indexes.push_back(passenger->getDestinationPassenger());
    //}
    indexes.push_back(destinationDriver);

    return 0;
}

int Application::showResults(string location, int origin, int destination){

    if(location == "Porto"){
        Graph<Coordinates> graph = mapParser("../Maps/PortoMaps/porto_strong_nodes_xy.txt", "../Maps/PortoMaps/porto_strong_edges.txt");
        vector<Coordinates> res;
        vector<Coordinates> tempStorage;
        for(unsigned int i = 0; i < (indexes.size()-1); i++){
            tempStorage = graph.AStarShortestPathByID(indexes.at(i), indexes.at(i+1));
            for(unsigned int j = 0; j < tempStorage.size(); j++){
                res.push_back(tempStorage.at(i));
            }
        }

        showGraph(&graph, res);
    }
    else if(location == "Penafiel"){
        Graph<Coordinates> graph = mapParser("../Maps/PenafielMaps/penafiel_strong_nodes_xy.txt", "../Maps/PenafielMaps/penafiel_strong_edges.txt");
        vector<Coordinates> res;
        vector<Coordinates> tempStorage;
        for(unsigned int i = 0; i < indexes.size(); i++){
            tempStorage = graph.AStarShortestPathByID(indexes.at(i), indexes.at(i+1));
            for(unsigned int j = 0; j < tempStorage.size(); j++){
                res.push_back(tempStorage.at(i));
            }
        }
        //showGraph(&graph, res);
    }
    else if (location == "Espinho"){
        Graph<Coordinates> graph = mapParser("../Maps/EspinhoMaps/espinho_strong_nodes_xy.txt", "../Maps/EspinhoMaps/espinho_strong_edges.txt");
        vector<Coordinates> res = graph.AStarShortestPathByID(origin, destination);
        showGraph(&graph, res);
    }
    
    //Graph<Coordinates> graph = mapParser("../Maps/GridGraphs/16x16/nodes.txt", "../Maps/GridGraphs/16x16/edges.txt");

    //floyd warshall
    
    //graph.floydWarshallShortestPath();
    //vector<Coordinates> path=graph.getfloydWarshallPath(make_pair(0,0),make_pair(333,222));
    
    //Dijkstra

    //graph.dijkstraShortestPathByID(0);
    //vector<Coordinates> path = graph.getPathTo(make_pair(300, 600)); //Works in 4x4 and 8x8

    //vector<Coordinates> path = graph.getPathTo(make_pair(333, 222)); //Works in 4x4 and 8x8 and 16x16


    //showGraph(&graph, path);
    
    /*
    //A*
    //16x16
    Coordinates orig = make_pair(0, 0);
    Coordinates dest = make_pair(333, 222);
    vector<Coordinates> result = graph.AStarShortestPathByInfo(orig, dest);
    showGraph(&graph, result);
     */

    return 0;
}


void Application::updatePassengerRecord(Passenger *passenger, string location){
    vector<string> initialPassengers;
    string line;
    ifstream loadfile;
    string filenamePassenger = "../src/passengerRecord"+location+".txt";
    loadfile.open(filenamePassenger);
    if(loadfile.is_open()){
        while(getline(loadfile, line)){
            initialPassengers.push_back(line);
        }
    }
    else{
        cout << "Error on updating passenger record file" << endl;
    }
    loadfile.close();

    ofstream updatedfile;
    updatedfile.open(filenamePassenger);
    if(updatedfile.is_open()){
        for(string passenger_loop : initialPassengers){
            updatedfile << passenger_loop << endl;
        }
        updatedfile << to_string(passenger->getPassengerID()) << endl;
        updatedfile << to_string(passenger->getOriginPassenger()) << endl;
        updatedfile << to_string(passenger->getDestinationPassenger()) << endl;
        updatedfile << to_string(passenger->getEarliestDepartureTime()) << endl;
        updatedfile << to_string(passenger->getLatestDepartureTime()) << endl;
    }
    else{
        cout << "Error on updating passenger record file" << endl;
    }
    updatedfile.close();
}

void Application::updateDriverRecord(Driver *driver, string location){
    vector<string> initialDrivers;
    string line;
    ifstream loadfile;
    string filenameDriver = "../src/driverRecord" + location + ".txt";
    cout << filenameDriver << endl;
    loadfile.open(filenameDriver);
    if(loadfile.is_open()){
        while(getline(loadfile, line)){
            initialDrivers.push_back(line);
        }
    }
    else{
        cout << "Error on updating driver record file" << endl;
    }
    loadfile.close();

    ofstream updatedfile;
    updatedfile.open(filenameDriver);
    if(updatedfile.is_open()){
        for(string driver_loop : initialDrivers){
            updatedfile << driver_loop << endl;
        }
        updatedfile << to_string(driver->getDriverID()) << endl;
        updatedfile << to_string(driver->getOriginDriver()) << endl;
        updatedfile << to_string(driver->getDestinationDriver()) << endl;
        updatedfile << to_string(driver->getEarliestDepartureTime()) << endl;
        updatedfile << to_string(driver->getLatestDepartureTime()) << endl;
        updatedfile << to_string(driver->getMaxDetourDistance()) << endl;
        updatedfile << to_string(driver->getVehicleCapacity()) << endl;
    }
    else{
        cout << "Error on updating driver record file" << endl;
    }
    updatedfile.close();
}

void Application::loadPassengerDriverRecord(string location){
    // LOAD PASSENGERS
    int passengerID = 0;
    int originPassenger = 0;
    int destinationPassenger = 0;
    int earliestDepartureTime = 0;
    int latestDepartureTime = 0;
    int counter = 4;

    string line;
    ifstream loadfile;
    string filenamePassenger = "../src/passengerRecord"+location+".txt";

    loadfile.open(filenamePassenger);
    if(loadfile.is_open()){
        while(getline(loadfile, line)){
            counter++;
            if(counter % 5 == 0){
                passengerID = stoi(line);
            }
            else if(counter % 5 == 1){
                originPassenger = stoi(line);
            }
            else if(counter % 5 == 2){
                destinationPassenger = stoi(line);
            }
            else if(counter % 5 == 3){
                earliestDepartureTime = stoi(line);
            }
            else if(counter % 5 == 4){
                latestDepartureTime = stoi(line);
                Passenger newPassenger(passengerID, originPassenger, destinationPassenger, earliestDepartureTime, latestDepartureTime);
                Passenger *ptrToNewPassenger = &newPassenger;
                passengers.push_back(ptrToNewPassenger);
            }

        }
    }
    else{
        cout << "Error on opening passenger log file" << endl;
    }
    loadfile.close();



    // LOAD DRIVERS
    int driverID = 0;
    int originDriver = 0;
    int destinationDriver = 0;
    int earliestDepartureTimeDriver = 0;
    int latestDepartureTimeDriver = 0;
    int maxDetourDistance = 0;
    int vehicleCapacity = 0;

    counter = 6;
    ifstream loadfileDriver;
    string filenameDriver = "../src/driverRecord"+location+".txt";
    loadfileDriver.open(filenameDriver);
    if(loadfileDriver.is_open()){
        while(!loadfileDriver.eof()) {
            getline(loadfileDriver, line);
            driverID = stoi(line);
            getline(loadfileDriver, line);
            originDriver = stoi(line);
            getline(loadfileDriver, line);
            destinationDriver = stoi(line);
            getline(loadfileDriver, line);
            earliestDepartureTimeDriver = stoi(line);
            getline(loadfileDriver, line);
            latestDepartureTimeDriver = stoi(line);
            getline(loadfileDriver, line);
            maxDetourDistance = stoi(line);
            getline(loadfileDriver, line);
            vehicleCapacity = stoi(line);
            Driver newDriver(driverID, originDriver, destinationDriver, earliestDepartureTimeDriver,
                                 latestDepartureTimeDriver, maxDetourDistance, vehicleCapacity);
            Driver *ptrToNewDriver = &newDriver;
            drivers.push_back(ptrToNewDriver);
        }
    }
    else{
        cout << "Error on opening driver log file" << endl;
    }
    loadfileDriver.close();
}

void Application::showPortoMap(){
    Graph<Coordinates> graph = mapParser("../Maps/PortoMaps/porto_strong_nodes_xy.txt", "../Maps/PortoMaps/porto_strong_edges.txt");
    vector<Coordinates> res;
    showGraph(&graph, res);
}
void Application::showPenafielMap(){
    Graph<Coordinates> graph = mapParser("../Maps/PenafielMaps/penafiel_strong_nodes_xy.txt", "../Maps/PenafielMaps/penafiel_strong_edges.txt");
    vector<Coordinates> res;
    showGraph(&graph, res);
}
void Application::showEspinhoMap(){
    Graph<Coordinates> graph = mapParser("../Maps/EspinhoMaps/espinho_strong_nodes_xy.txt", "../Maps/EspinhoMaps/espinho_strong_edges.txt");
    vector<Coordinates> res;
    showGraph(&graph, res);
}
