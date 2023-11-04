#include <iostream>

//  Second Example of Factory pattern

class Transport {
public :
    virtual void Deliver() = 0;    
};
class Truck : public Transport {
    void Deliver() override {
        std::cout << "Items are Delivered by land in a box!\n";
    }
};

class Ship : public Transport {
    void Deliver() override {
        std::cout << "Items are delivered by sea in container!\n";
    }
};
//  Logistic are the creator of Transport
class Logistic {
public :
    virtual ~Logistic() { }

    void PlanDelivery() { std::cout <<"Delivery Planned\n"; }
    //  if it returned, it becomes default creation
    virtual Transport* CreateTransport() const { }
    
    void deliver() {
        Transport* transport = this->CreateTransport();
        transport->Deliver();
        
        delete transport;
    }
};

class RoadLogistic : public Logistic {
    Transport* CreateTransport() const override {
        std::cout << "Truck is ready!\n";
        return new Truck();
    }
};

class SeaLogistic : public Logistic {
    Transport* CreateTransport() const override {
        std::cout << "Ship is ready!\n";
        return new Ship();
    }
};

int main() {
    Logistic* logistic = new RoadLogistic();
//  logistic->CreateTransport();
    logistic->deliver();
    delete logistic;

    logistic = new SeaLogistic();
    logistic->PlanDelivery();
    logistic->deliver();


    return 0;
}