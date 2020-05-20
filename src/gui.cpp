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

    string originPassenger;
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

    string destinationPassenger;
    cin >> originPassenger;

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
    cin >> passengerID;

    Passenger newPassenger(passengerID, originPassenger, destinationPassenger, earliestDepartureTime, latestDepartureTime);
    Passenger *ptrToNewPassenger = &newPassenger;
    application.addPassenger(ptrToNewPassenger);

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||              1) Find a ride!               ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||              2) Go back to main menu       ||||||||||" << endl;;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;



     int choice;
     cin >> choice;
     if(choice == 1){

         if(!application.findRide()){    //se o processamento dos dados retornar sucesso
             application.showResults();
         }
         else{
             exit(2);  //processamento dos dados falhou
         }
     }
     else{
         startMenu(application);
     }

}

void driverMenu(Application &application) {
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

    string originDriver;
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

    string destinationDriver;
    cin >> originDriver;

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
    cout << "||||||||||   Please enter your license plate number   ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    string vehicleId;
    cin >> vehicleId;

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
    cin >> driverID;

    Driver newDriver(driverID, originDriver, destinationDriver, earliestDepartureTime, latestDepartureTime, maxDetourDistance, vehicleId, vehicleCapacity);
    Driver *ptrToNewDriver = &newDriver;
    application.addDriver(ptrToNewDriver);


    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                 MeetUpRider                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||             1) Find a ride!                ||||||||||" << endl;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||             2) Go back to main menu        ||||||||||" << endl;;
    cout << "||||||||||                                            ||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    int choice;
    cin >> choice;
    if(choice == 1){

        if(!application.findRide()){    //se o processamento dos dados retornar sucesso
            application.showResults();
        }
        else{
            exit(2);  //processamento dos dados falhou
        }
    }
    else{
        startMenu(application);
    }
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
