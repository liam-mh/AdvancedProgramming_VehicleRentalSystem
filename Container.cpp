#include "Container.h"
#include "Car.h"
#include "Bike.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Container::Container() {};
Container::~Container() {};

void Container::addItem(Vehicle* vehicle)
{
    vehicles.push_back(vehicle);
}

void Container::displayReg()
{
    cout << "Displaying Items" << std::endl;
    for (int i = 0; i < vehicles.size(); i++) 
    {
        cout << vehicles[i]->getVehicleReg() << " ";
    }
}

void Container::displayMainData()
{
    for (int i = 0; i < vehicles.size(); i++)
    {
        cout << left << setw(24) << vehicles[i]->getVehicleReg();

        if ((typeid(*vehicles[i]) == typeid(Car)))
        {
            cout << left << setw(17) << setprecision(2) << fixed << vehicles[i]->costPerDay();
            cout << left << setw(17) << "Car" << endl;
        }
        else 
        {
            cout << left << setw(17) << setprecision(2) << fixed << vehicles[i]->costPerDay();
            cout << left << setw(17) << "Bike" << endl;
        }

    }
    cout << "" << endl;
}

void Container::addItemPage()
{
    int engine, wheels, doors, seats, age = 0;
    string registration, type, make, model;
    
    int option = NULL;

    while (option != 9)
    {
        cout << "Add a vehicle" << endl;
        cout << "-------------" << endl;
        cout << "Here we will create a new vehicle to add." << endl;
        cout << "Do you wish to continue?" << endl;
        cout << "" << endl;
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cin >> option;
        cout << "" << endl;
        if (option == 2)
            break;

        option = NULL;
        cout << "What kind of vehicle would you like to add? A car or bike?" << endl;
        cout << "" << endl;
        cout << "1) Car" << endl;
        cout << "2) Bike" << endl;
        cin >> option;
        cout << "" << endl;
        if (option == 1)
        {
            createCar();
        }
    } 
}

void Container::createCar()
{
    int doors, seats, age = 0;
    string registration, type, make, model;

    cout << "Please enter the registration plate?" << endl;
    cout << "Must be in the following format where A = a letter, and 1 = a number:" << endl;
    cout << "AA11 AAA   example: DY62 HYT" << endl;
    cin >> registration;
 
    checkRegFormat(registration);
    
    /*
    Left off needing to loop to check reg is done
    finish add item
    finish create car
    */
  
}

bool Container::checkRegFormat(string reg)
{
    bool check = true;
    if (8 == reg.length())
    {
        const char* arr = reg.c_str();
        for (int i = 0; i < 8; i++)
        {
            if (i == 2 || i == 3)
                isdigit(arr[i]) ? check : check = false;
            else if (i == 4)
                isblank(arr[i]) ? check : check = false;
            else
                (isalpha(arr[i])) ? check : check = false;
        }
    }
    else
    {
        check = false;
    }
    return check;
}

