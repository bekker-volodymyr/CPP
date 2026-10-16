#pragma once

#include <iostream>
#include <string>

class Enemy {
private:
    int damage;
    int health;
    std::string name;
public:
    Enemy() = default;
    Enemy(int damage, int health, std::string name) : 
        damage(damage), health(health), name(name) { }

    // virtual void Attack() {
    //     std::cout << "Абстрактний ворог не може атакувати\n";
    // }

    virtual void Attack() = 0;

    int getDamage() {
        return damage;
    }
    int getHealth() {
        return health;
    }
    std::string getName() {
        return name;
    }
};

class Swordsman : public Enemy {
public:
    Swordsman(int damage, int health, std::string name) :
        Enemy(damage, health, name) { }

    void Attack() override {
        std::cout << getName() << " б'є мечем та наносить " << getDamage() << " шкоди.\n";
    }
};

class Bomber : public Enemy {
public:
    Bomber(int damage, int health, std::string name) :
        Enemy(damage, health, name) { }

    void Attack() override {
        std::cout << getName() << " кидає бімбу та наносить " << getDamage() << " шкоди.\n";
    }
};

class Shooter : public Enemy {
public:
    Shooter(int damage, int health, std::string name) :
        Enemy(damage, health, name) { }

    void Attack() override {
        std::cout << getName() << " стріляє та наносить " << getDamage() << " шкоди.\n";
    }
};