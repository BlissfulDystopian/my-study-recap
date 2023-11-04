#pragma once

#include "SUVBuilder.h"
#include <iostream>

using std::string;

SUVBuilder::SUVBuilder() { car = new Car(); }

void SUVBuilder::BuildBrand(string brand)
{
    car->SetBrand(brand);
}
void SUVBuilder::BuildModel(string model) 
{
    car->SetModel(model);
}
void SUVBuilder::BuildColor(string color) 
{
    car->SetColor(color);
}