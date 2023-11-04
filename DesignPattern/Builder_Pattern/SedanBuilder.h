#pragma once
#include "CarBuilder.h" 

using std::string;

class SedanBuilder : public CarBuilder {
public :
    SedanBuilder();

    void BuildBrand(string) override;
    
    void BuildModel(string) override;
    
    void BuildColor(string) override;
};