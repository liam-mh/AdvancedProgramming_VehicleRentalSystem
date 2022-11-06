#pragma once
#include "Vehicle.h"
#include <vector>
using namespace std;

class Container
{
private:
    vector<Vehicle> vehicles;

public:
    Container();
    ~Container();

    //void insertInto();
    void displayAll();
    void searchForBike();
    void searchForCar();
};
