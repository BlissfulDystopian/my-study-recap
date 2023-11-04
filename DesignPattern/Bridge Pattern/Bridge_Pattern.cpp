#include <iostream>

// Bridge Pattern
/*
 *  Bridge is a structural design pattern that lets you split a 
 *  large class or a set of closely related classes into two 
 *  separate hirarchies
 * 
 *  Adalah desain pattern struktural yang memisah 
 *  class besar atau sekelompok class yang berkaitan 
 *  menjadi dua hirarki yang terpisah (Abstraksi dan 
 *  Implementasi) yang dapat di kembangkan secara 
 *  mandiri satu sama lain
 * 
 *  Adalah jawaban dari composition > inheritance
 */


// Contoh penerapan desain pattern bridge

/*  Ketika kita memiliki kelas Bentuk, yang memiliki 
 *  turunan kotak dan Bulat, lalu kita ingin menambahkan
 *  modifier warna (biru, merah)ke dalam kelas bentuk kita, kita tidak
 *  memerlukan pembuatan kelas KotakMerah, kotakBiru dsb. Bila kita
 *  menambahkan 1 bentuk baru dan 1 warna yang berbeda maka akan membuat
 *  tiga class baru
 */


class Color {
protected :    
    std::string color;
public :    
    virtual void PrintInfo() const = 0;
};

class Red : public Color {
public :     
    Red() { color = "Red"; }
    
    void PrintInfo() const override {
        std::cout << color;
    }

};

class Blue : public Color {
public :     
    Blue() { color = "Blue"; }
    
    void PrintInfo() const override {
        std::cout << color;
    }

};
//  Abstraction
class Shape {
protected :    
    std::string typeShape;
    Color& color; // Ini harus diisi cokk bangsat
public :
    Shape() : color(*new Red()) { }

    virtual void PrintInfo() const = 0;
};

//  Implementation
class Circle : public Shape {
public :    
    Circle() {
        color = *new Red();
    }
    Circle(Color& color) {
        this->color = color;
        typeShape = "Circle";
    }
    void PrintInfo() const override {
        color.PrintInfo(); 
        std::cout << " " << typeShape << std::endl;
    }
};

class Square : public Shape {
public :
    Square() {
        color = *new Red();
    }    
    Square(Color& color) {
        this->color = color;
        typeShape = "Square";
    }
    void PrintInfo() const override {
        color.PrintInfo(); 
        std::cout << " " << typeShape << std::endl;
    }
};

int main() {
    Square square = Square(*new Red());
    Circle circle = Circle(*new Blue());
    
    square.PrintInfo();
    circle.PrintInfo();
    
    return 0;
}