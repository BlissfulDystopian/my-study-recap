#pragma once
#include "Car.h"
#include "CarBuilder.h"
#include "SedanBuilder.h"
#include <iostream>

using std::string;

SedanBuilder::SedanBuilder() 
{ 
    car = new Car(); 
}

void SedanBuilder::BuildBrand(string brand)
{
    car->SetBrand(brand);
}
void SedanBuilder::BuildModel(string model) 
{
    car->SetModel(model);
}
void SedanBuilder::BuildColor(string color) 
{
    car->SetColor(color);
}