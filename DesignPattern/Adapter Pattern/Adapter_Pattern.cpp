#include <iostream>

// Interface
class Bird {
public :
    // Method dengan const adalah method read-only
    virtual void Fly() const = 0;
    virtual void MakeSound() const = 0;
};

class Sparrow : public Bird {
public :
    void Fly() const override {
        std::cout << "Flying" << std::endl;
    }
    void MakeSound() const override {
        std::cout << "Chirp-chirp" << std::endl;
    }
};
//  Interface
class ToyDuck {
public : 
    virtual void Squeak() const = 0;
};

// Adaptee
class RubberToyDuck : public ToyDuck {
public :
    void Squeak() const override {
        std::cout << "Squeak-Squeak" << std::endl;
    }
};

class BirdAdapter : public ToyDuck { 
    Bird &bird; // Cuma minta reference
public :    
    BirdAdapter(Bird& bird) : bird(bird) { }

    void Squeak() const override {
        bird.MakeSound();
    }
};


// Main as a client
int main() {
    Sparrow sparrow;
    RubberToyDuck duck;

    ToyDuck &birdAdapter = *(new BirdAdapter(sparrow));
    std::cout << "Sparrow..." << std::endl;
    sparrow.Fly();
    sparrow.MakeSound();

    std::cout << "ToyDuck..." << std::endl;
    duck.Squeak();

    std::cout << "BirdAdapter..." << std::endl;
    birdAdapter.Squeak();
    return 0;
}