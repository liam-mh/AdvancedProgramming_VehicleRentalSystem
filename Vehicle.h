#pragma once
#include <string>
#include <cstring>

using namespace std;

class Vehicle
{
private:
    string registration, type, make, model;
    int age;

public:
    Vehicle();
    Vehicle(string registration, string type, string make, string model, int age);
    ~Vehicle();

    //int costPerDay();
    //void displayVehicle();

};
