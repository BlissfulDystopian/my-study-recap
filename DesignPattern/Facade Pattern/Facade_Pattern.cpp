#include <iostream>
#include <vector>
using std::string;

/*
  Facade is A structural design pattern that provides a
  simplified interface to a library, a framework, or 
  any other complex set of classes

  Facade adalah desain pattern struktural yang
  menyuguhkan antarmuka sederhana untuk library,
  framework atau set class kompleks lain

*/

#include <iostream>
#include <vector>

#define ROTATE_AMOUNT 90

//  Command Pattern
class Position {
    int x, y;

public :
    // Constructor
    Position(int x  = 0, int y = 0) : x(x), y(y) {  }

    int GetXAxis() { return x; }

    int GetYAxis() { return y; }

    void AddXAxis() { ++x; }

    void AddYAxis() { ++y; }

    void ReduceXAxis() { --x; }

    void ReduceYAxis() { --y; }
};
class Rotation {
    unsigned short minRange, maxRange, z; 
public :
    Rotation(std::string facing = "upward") : minRange(0), maxRange(360) {
        if(facing == "upward") { z = 0; }
        else if(facing == "right") { z = 90; }
        else if(facing == "downward") { z = 180; }
        else if(facing == "left") { z = 270; }
    }
    
    std::string GetFacing() {
        switch(z) {
            case 0 :
            case 360 :
                return "upward";
            case 90 :
                return "right";
            case 180 :
                return "downward";
            case 270 : 
                return "left";
        }
    }

    void operator++() { 
        if(z == maxRange)
            z = minRange; 
        z += ROTATE_AMOUNT;
    }
    
    void operator--() {
        if(z == minRange)
            z = maxRange;
        z -= ROTATE_AMOUNT;
    }
};

// Object as an Interface;
class Object {
protected :    
    Position position;

public :
    // Constructor
    // Object(const Position& position = Position()) : position(position) { }

    virtual Position GetPosition() { return this->position; };

    virtual void SetPosition(const Position& pos) { 
        this->position = pos;
    }
    virtual void PrintObjectInfo() = 0;
    
};
class ControllableObject : public Object {
private :
    Rotation rotation;
public :
    ControllableObject(Position position = Position(), Rotation rotation = Rotation()) : rotation(rotation) {
        this->position = position;
    }
    void PrintObjectInfo() override {
        std::cout << 
            "Type : Controllable Object\nPosition : " <<
            position.GetXAxis() << ", " << position.GetYAxis() <<
            "\nIsFacing : " << rotation.GetFacing() << 
        std::endl;  
    }
    void Move(std::string movement) {
        if(movement == "forward") {
            if(rotation.GetFacing() == "upward") {
                // y++
                position.AddYAxis();
            } 
            else if(rotation.GetFacing() == "downward") {
                // y--
                position.ReduceYAxis();
            }
            else if(rotation.GetFacing() == "right") {
                // x++
                position.AddXAxis();
            }
            else if(rotation.GetFacing() == "left"){
                // x--
                position.ReduceXAxis();
            }
            std::cout << "MovingForward\n";
        } 
        else if(movement == "backward") {
            if(rotation.GetFacing() == "upward") {
                // y--
                position.ReduceYAxis();
            } 
            else if(rotation.GetFacing() == "downward") {
                // y++
                position.AddYAxis();
            }
            else if(rotation.GetFacing() == "right") {
                // x--
                position.ReduceXAxis();
            }
            else {
                // x++
                position.AddXAxis();
            }
            std::cout << "Moving Backward!\n";
        }
        PrintObjectInfo();
    }
    void Turn(std::string turn) {
        if(turn == "right") {
            ++rotation;
        }
        else if(turn == "left") {
            --rotation;
        }
        PrintObjectInfo();
    }

};
// interface Command
class Command {
public :
    // Pure Virtual function0
    virtual void Execute(ControllableObject* const) = 0;
};
//  Concrete Command
class MoveCommand : public Command {
    std::string movement;

public :
    MoveCommand(std::string movement = "forward") : movement(movement) { } 
        
    void SetMovement(std::string movement) { 
        this->movement = movement;
    }

    void Execute(ControllableObject* const receiver) override { 
        receiver->Move(movement);
    }
};
// Concrete Command 2
class TurnCommand : public Command {
    std::string turn;

public :
    TurnCommand(std::string turn = "right") : turn(turn) { }

    void SetTurn(std::string turn) {
        this->turn = turn;
    }
    void Execute(ControllableObject* const receiver) {
        receiver->Turn(turn);
    }

};
// Invoker Command list juga termasuk sebagai Facade
class CommandList {
    std::vector <Command*> commandList;
    ControllableObject* CommandReceiver;

public :
    CommandList(ControllableObject* const receiver) : commandList(), CommandReceiver(receiver){ }
    void SetCommand(Command* command) {
        commandList.push_back(command);
        std::cout << "Command Added!\n";   
    }
    void UndoCommand() {
        commandList.pop_back();
    }
    void ExecuteCommand() {
        commandList.shrink_to_fit();
        for(int i = 0; i <= commandList.size(); i++) {
            commandList[i]->Execute(CommandReceiver);
        }
    }
    void SetCommandReceiver(ControllableObject* const receiver) {
        this->CommandReceiver = receiver;
    }
};

// Main as a Client 
int main() {
    ControllableObject controllable = ControllableObject(Position(0, 0), Rotation("right"));
    controllable.PrintObjectInfo();
    CommandList commandList = CommandList(&controllable);
    
    commandList.SetCommand(new TurnCommand("right"));
    commandList.SetCommand(new MoveCommand("forward"));
    commandList.SetCommand(new TurnCommand("left"));
    
    commandList.ExecuteCommand();
    
    return 0;
}
