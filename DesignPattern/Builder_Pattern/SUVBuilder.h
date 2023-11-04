#pragma once
#include "CarBuilder.h" 

using std::string;

class SUVBuilder : public CarBuilder {
public :
    SUVBuilder();
    void BuildBrand(string) override;
    void BuildModel(string) override;
    void BuildColor(string) override;
};
