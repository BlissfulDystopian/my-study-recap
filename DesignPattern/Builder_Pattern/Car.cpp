#pragma once
#include "Car.h"
#include <iostream>

Car::Car() : brand(), model(), color() { }
void Car::SetBrand(std::string brand) 
{
    this->brand = brand;
}
void Car::SetModel(std::string model) 
{
    this->model = model;
}
void Car::SetColor(std::string color) 
{
    this->color = color;
}
void Car::ShowCar() 
{
    std::cout << brand << " " << model << " " <<  color << std::endl;
}

