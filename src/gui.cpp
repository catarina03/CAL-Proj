//
// Created by Adriana on 20/05/2020.
//
#include "gui.h"
#include "passenger.h"
#include "driver.h"
#include <iostream>
#include "Application.h"
using namespace std;


void startMenu(Application &application) {
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||           1) I'm looking for a ride        ||||||||||" << endl;
    cout << "||||||||||           2) I want to share my car        ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||           3) Help                          ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||           4) Exit                          ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int choice;
    cin >> choice;

    switch(choice){
        case 1: {
            passengerMenu(application);
            break;
        }
        case 2: {
            driverMenu(application);
            break;
        }
        case 3: {
            helpMenu(application);
            break;
        }
        case 4: {
            cout << "We're sad to see you go  :( \n"
                 << "Exiting application...\n\n" ;

            break;
        }
    }

}

void passengerMenu(Application &application) {

    string location = chooseLocation(application);

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||      Please enter your origin address      ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int originPassenger;
    cin >> originPassenger;

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||   Please enter your destination address    ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int destinationPassenger;
    cin >> destinationPassenger;


    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "|||||||||| Please enter your earliest departure time  ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int earliestDepartureTime;
    cin >> earliestDepartureTime;

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||  Please enter your latest departure time   ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int latestDepartureTime;
    cin >> latestDepartureTime;

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||            Please enter your NIF           ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int passengerID;
    int passengerIDLength;

    do{
        cin >> passengerID;
        passengerIDLength = to_string(passengerID).length();
        if(passengerIDLength != 9) {
            cout << "The NIF has to have 9 digits and you introduced " << passengerIDLength << endl;
            cout << "Please enter your NIF again: " << endl;
        }
    }while(passengerIDLength != 9);
    //crasha se passengerIDLength for maior que 10...

    Passenger newPassenger(passengerID, originPassenger, destinationPassenger, earliestDepartureTime, latestDepartureTime);
    Passenger *ptrToNewPassenger = &newPassenger;
    application.addPassenger(ptrToNewPassenger);
    application.updatePassengerRecord(ptrToNewPassenger, location);

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||              1) Find a ride!               ||||||||||" << endl;
    cout << "||||||||||              2) Connectivity               ||||||||||" << endl;
    cout << "||||||||||              3) Go back to main menu       ||||||||||" << endl;;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;



     int choice;
     cin >> choice;
     if(choice == 1){

         if(!application.findRide()){    //se o processamento dos dados retornar sucesso
             application.showResults(location, originPassenger, destinationPassenger);
             startMenu(application);
         }
         else{
             exit(2);  //processamento dos dados falhou
         }
     }
     if(choice == 2){
         string lower_location = location;
         transform(lower_location.begin(), lower_location.end(), lower_location.begin(),
                   [](unsigned char c){ return std::tolower(c); });
         string fileNode = "../Maps/"+location+"Maps/"+lower_location+"_full_nodes_xy.txt";
         string fileEdge = "../Maps/"+location+"Maps/"+lower_location+"_full_edges.txt";
         Graph<Coordinates> graph = mapParser(fileNode, fileEdge);
         vector<Coordinates> res = graph.bfs(originPassenger);
         showGraph(&graph, res);
         getchar();
         startMenu(application);
     }

}

void driverMenu(Application &application) {

    string location = chooseLocation(application);


    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||      Please enter your origin address      ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int originDriver;
    cin >> originDriver;

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||   Please enter your destination address    ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int destinationDriver;
    cin >> destinationDriver;

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "|||||||||| Please enter your earliest departure time  ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int earliestDepartureTime;
    cin >> earliestDepartureTime;

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||  Please enter your latest departure time   ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int latestDepartureTime;
    cin >> latestDepartureTime;

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "|||||||||| Please enter your maximum detour distance  ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int maxDetourDistance;
    cin >> maxDetourDistance;

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||    Please enter your vehicle's capacity    ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int vehicleCapacity;
    cin >> vehicleCapacity;

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||            Please enter your NIF           ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int driverID;
    int driverIDLength;
    do{
        cin >> driverID;
        driverIDLength = to_string(driverID).length();
        if(driverIDLength != 9) {
            cout << "The NIF has to have 9 digits and you introduced " << driverIDLength << endl;
            cout << "Please enter your NIF again: " << endl;
        }
    }while(driverIDLength != 9);
    //crasha se driverIDLength for maior que 10...

    Driver newDriver(driverID, originDriver, destinationDriver, earliestDepartureTime, latestDepartureTime, maxDetourDistance, vehicleCapacity);
    Driver *ptrToNewDriver = &newDriver;
    application.addDriver(ptrToNewDriver);
    application.updateDriverRecord(ptrToNewDriver, location);


    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||             1) Find a ride!                ||||||||||" << endl;
    cout << "||||||||||             2) Connectivity                ||||||||||" << endl;
    cout << "||||||||||             3) Go back to main menu        ||||||||||" << endl;;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int choice;
    cin >> choice;

    if(choice == 1){

        if(!application.findRide()){    //se o processamento dos dados retornar sucesso
            application.showResults(location, originDriver, destinationDriver);
            startMenu(application);
        }
        else{
            exit(2);  //processamento dos dados falhou
        }
    }
    if(choice == 2){
        string lower_location = location;
        transform(lower_location.begin(), lower_location.end(), lower_location.begin(),
                  [](unsigned char c){ return std::tolower(c); });
        string fileNode = "../Maps/"+location+"Maps/"+lower_location+"_full_nodes_xy.txt";
        string fileEdge = "../Maps/"+location+"Maps/"+lower_location+"_full_edges.txt";
        Graph<Coordinates> graph = mapParser(fileNode, fileEdge);
        vector<Coordinates> res = graph.bfs(originDriver);
        showGraph(&graph, res);
        getchar();
        startMenu(application);
    } startMenu(application);

}

void helpMenu(Application &application) {
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||     MeetUpRider is an application that     ||||||||||" << endl;
    cout << "||||||||||     can help you find a ride or share      ||||||||||" << endl;
    cout << "||||||||||     your vehicle to help out people        ||||||||||" << endl;
    cout << "||||||||||     that are going your way!               ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||     Help us help others and the            ||||||||||" << endl;
    cout << "||||||||||     environment by using MeetUpRider!      ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||     Go back and choose if you want a       ||||||||||" << endl;
    cout << "||||||||||     ride or if you have a car you want     ||||||||||" << endl;
    cout << "||||||||||     to share!                              ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||     0) Go back                             ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int choice;
    cin >> choice;
    if(choice == 0){
        startMenu(application);
    }
    else{
        cout << "Please enter '0' to go back :)" << endl;
        helpMenu(application);
    }
}

string chooseLocation(Application &application){
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||             Choose your location           ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||             1) Porto                       ||||||||||" << endl;
    cout << "||||||||||             2) Penafiel                    ||||||||||" << endl;
    cout << "||||||||||             3) Espinho                     ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int option;
    cin >> option;

    switch(option){
        case 1:
            application.loadPassengerDriverRecord("Porto");
            application.showPortoMap();
            return "Porto";
        case 2:
            application.loadPassengerDriverRecord("Penafiel");
            application.showPenafielMap();
            return "Penafiel";
        case 3:
            application.loadPassengerDriverRecord("Espinho");
            application.showEspinhoMap();
            return "Espinho";
        default:
            break;
    }

    return "errorLocation";

}
