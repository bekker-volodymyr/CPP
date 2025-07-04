#pragma once

#include <string>
#include <iostream>

class Animal {
private:
    std::string name;
public:
    Animal(std::string name) : name(name) { }
    
    std::string GetName() const { return name; }
    // virtual void MakeSound() const {
    //     std::cout << "Я абстрактна тварина, що не може видавати жодних звуків\n";
    // }
    virtual void MakeSound() const = 0;

    virtual ~Animal() {
        std::cout << "Деструктор класу Animal.\n";
    }
};

class Donkey : public Animal {
public:
    Donkey(std::string name) : Animal(name) { }

    void MakeSound() const override {
        std::cout << "І-а\n";
    }
};

class Monkey : public Animal {
public:
    Monkey(std::string name) : Animal(name) { }

    void MakeSound() const override {
        std::cout << "У-а-а\n";
    }
};

class Frog : public Animal {
public:
    Frog(std::string name) : Animal(name) { }

    void MakeSound() const override {
        std::cout << "Ква-ква\n";
    }

    ~Frog() {
        std::cout << "Деструктор класу Frog.\n";
    }
};