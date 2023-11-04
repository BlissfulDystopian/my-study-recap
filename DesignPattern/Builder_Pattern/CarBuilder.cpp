#pragma once
#include "CarBuilder.h"
#include <iostream>

CarBuilder::CarBuilder() : car() { }

Car* CarBuilder::GetCar() 
{ 
    return car; 
}
