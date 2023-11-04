#include <iostream>

//  Factory Pattern
/*
    Factory Pattern is a creational design pattern
    that provides an interface for creating objects
    in a superclass but allows subclasses to alter
    type of objects that will be created....
*/

class Product {
public :
    virtual ~Product() { }
    virtual std::string Operation() const = 0;
};

class ConcreteProduct1 : public Product {
    std::string Operation() const override {
        return "{Result of the ConcreteProduct1}";
    }
};

class ConcreteProduct2 : public Product {
    std::string Operation() const override {
        return "{Result of the ConcreteProduct2}";
    }
};

class Creator {
public :
    virtual ~Creator() { }
    
    virtual Product *FactoryMethod() const = 0; 
    
    std::string SomeOperation() const {
        Product* product = this->FactoryMethod();
        std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};

class ConcreteCreator1 : public Creator {
public :
    Product* FactoryMethod() const override {
        return new ConcreteProduct1();
    }
};
class ConcreteCreator2 : public Creator {
public :
    Product* FactoryMethod () const override {
        return new ConcreteProduct2();
    }
};

void ClientCode(const Creator& creator) {
    std::cout << "Client: Im not aware of the creator's class, but it still works.\n"
    << creator.SomeOperation() << std::endl;
}
int main() {
    std::cout << "App: Launched with the ConcreteCreator1.\n";
    Creator *creator = new ConcreteCreator1();
    ClientCode(*creator);
    std::cout << std::endl;
    std::cout << "App: Launched with the ConcreteCreator2.\n";
    ++creator = new ConcreteCreator2();
    ClientCode(*creator);
    delete creator, --creator;

    return 0;
}
