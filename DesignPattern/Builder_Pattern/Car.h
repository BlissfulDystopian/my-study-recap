#pragma once

using std::string;

class Car {
    std::string brand;
    std::string model;
    std::string color;
public :
    Car();
    void SetBrand(std::string);
    void SetModel(std::string);
    void SetColor(std::string);
    void ShowCar();
};


