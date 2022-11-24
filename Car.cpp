#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include "Vehicle.h"
#include "Container.h"
#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Car::Car(int doors, int seats, string registration, string make, string model, int age)
    : doors(doors), seats(seats), Vehicle(registration, "Car", make, model, age)
{}

Car::~Car()
{}

Car* Car::createCar()
{
    int option = 0;
    int doors, seats, age = 0;
    string registration, make, model;


    cout << "Please enter the registration plate." << endl;
    cout << "Must be in the following format where A = a letter, and 1 = a number:" << endl;
    cout << "AA11 AAA   example: DY62 HYT" << endl;
    cin.ignore();
    getline(cin, registration);

    //checkRegFormat(registration);
    cout << "" << endl;

    cout << "Please enter the make: ";
    cin >> make;
    cout << endl;

    cout << "And model: ";
    cin >> model;
    cout << endl;

    cout << "The age: ";
    cin >> age;
    cout << "" << endl;

    cout << "And the amount of doors, followed by the amount of seats." << endl;
    cin >> doors >> seats;
    cout << "" << endl;

    cout << "Please confirm these details are correct:" << endl;
    cout << "Registration: " << registration << endl;
    cout << "Make and Model: " << make << " " << model << endl;
    cout << "Age: " << age << endl;
    cout << "Doors: " << doors << endl;
    cout << "Seats: " << seats << endl;
    cout << "" << endl;
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cin >> option;
    cout << "" << endl;
    if (option == 1)
    {
        return new Car(doors, seats, registration, make, model, age);
        cout << make << " " << model << " has been added" << endl;
    }
    else if (option == 2)
        cout << "Please retry and enter the correct details." << endl;


    cout << "**END OF createCar()" << endl;
}

double Car::costPerDay() const
{
    time_t t = time(0);
    tm* tP = localtime(&t);
    int currentYear = (tP->tm_year)+1900;
    int age = currentYear - getVehicleAge();

    double calc = 2500-(age*150)-(doors*200);
    if (calc < 1000)
        return 10.00;
    return calc/100;
}