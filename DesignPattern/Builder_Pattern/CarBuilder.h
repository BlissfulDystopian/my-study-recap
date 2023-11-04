#pragma once
#include "Car.h"

using std::string;

class CarBuilder {
protected :
    Car* car;

public :
    CarBuilder();
    virtual void BuildBrand(string) = 0;
    virtual void BuildModel(string) = 0;
    virtual void BuildColor(string) = 0;

    Car* GetCar();
};