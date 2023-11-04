#include <iostream>
#define MAX_ROTATION 4
#define MIN_ROTATION 0

#pragma region Weapon
// Abstract
class Weapon {

public :
    virtual void DoSomething() const  = 0; 
    virtual std::string PrintInfo() const = 0;
};

class Plunger : public Weapon { 

public :    
    Plunger() { }
    
    void DoSomething() const override {
        std::cout << "My Plunger is hitting the button!\n";
    }
    
    std::string PrintInfo() const override { return "plunger"; }
};

class Vacuum : public Weapon {

public :
    Vacuum() { }

    void DoSomething() const override { 
        std::cout << "My Vacuum is sucking these garbage!\n";
    }

    std::string PrintInfo() const override { return "vacuum"; }
};

#pragma endregion Weapon

class Object {
    int x, y;

public :
    Object(int x = 0, int y = 0) : x(x), y(y) { }
};

class ControllableObject : Object {
    int rotation;

public :
    ControllableObject() : Object() { }
    
    void TurnLeft() { 
        if(rotation == MIN_ROTATION)
            rotation = MAX_ROTATION;
        --rotation;
    }

    void TurnRight() {
        if(rotation == MAX_ROTATION)
            rotation = MIN_ROTATION;
        ++rotation;
    } 
};

class Rabbid : ControllableObject {

public :
    Rabbid() : ControllableObject() { }
};

class ArmedRabbid : ControllableObject {
    Weapon *weapon;
public :
    ArmedRabbid(Weapon* const weapon) : weapon(weapon), ControllableObject() { } 

    void PrintInfo() { 
        std::cout << "I'm an Armed Rabbid, and i carry " << weapon->PrintInfo() << " in my hand\n";
    }
    void Interact() {
        weapon->DoSomething();
    }
};

class Robot : ControllableObject {
    Weapon *weapon;
public :
    Robot(Weapon* const weapon) : weapon(weapon), ControllableObject() { } 
    
    void PrintInfo() { 
        std::cout << "I'm a dang Robot, and i carry " << weapon->PrintInfo() << " in my hand\n";
    }
    void Interact() {
        weapon->DoSomething();
    }
};

int main() {
    // Instantiate robot with a plunger
    Robot* robot = new Robot(new Plunger());
    robot->PrintInfo(); 
    robot->Interact();

    ArmedRabbid* armedRabbid = new ArmedRabbid(new Plunger());
    armedRabbid->PrintInfo();
    armedRabbid->Interact();
    std::cout << std::endl;
    
    delete robot, armedRabbid;

    robot = new Robot(new Vacuum());
    robot->PrintInfo();
    robot->Interact();

    std::cout << std::endl;

    armedRabbid = new ArmedRabbid(new Vacuum());
    armedRabbid->PrintInfo();
    armedRabbid->Interact();

    std::cout << std::endl;

    delete robot, armedRabbid;
    return 0;
}