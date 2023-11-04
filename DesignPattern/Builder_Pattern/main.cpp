#include <iostream>
#include "Car.cpp"
#include "CarBuilder.cpp"
#include "SedanBuilder.cpp"
#include "SUVBuilder.cpp" 


int main() {
    
    CarBuilder* builder = new SedanBuilder();
    builder->BuildBrand("Mazda");
    builder->BuildModel("3 Hatchback");
    builder->BuildColor("Soul Red Metallic");
    
    Car* carOne = builder->GetCar();
    delete builder;

    builder = new SUVBuilder();
    builder->BuildBrand("Mazda");
    builder->BuildModel("CX-5");
    builder->BuildColor("Machine Grey");

    Car* carTwo = builder->GetCar();
    delete builder;

    carOne->ShowCar();
    carTwo->ShowCar();    
}