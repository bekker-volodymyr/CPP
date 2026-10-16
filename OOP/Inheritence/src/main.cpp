#include <iostream>

class Vehicle
{
protected:
    std::string brand;
    int speed;

public:
    Vehicle(const std::string &b, int s) : brand(b), speed(s)
    {
        std::cout << "[1] Base constructor call (Vehicle)\n";
    }

    ~Vehicle()
    {
        std::cout << "[4] Base destructor Vehicle (Vehicle)\n";
    }

    void showInfo() const
    {
        std::cout << "Brand: " << brand << ", Speed: " << speed << " km/h\n";
    }
};

class Car : public virtual Vehicle
{
protected:
    int passengerCapacity;

public:
    Car(const std::string &b, int s, int passengers)
        : Vehicle(b, s), passengerCapacity(passengers)
    {
        std::cout << "[2] Child constructor (Car)\n";
    }

    ~Car()
    {
        std::cout << "[3] Child destructor Car\n";
    }

    void drive()
    {
        std::cout << "Car of brand" << brand << " moves on the roads\n";
    }
};

class Airplane : public virtual Vehicle
{
protected:
    int maxAltitude;

public:
    Airplane(const std::string &b, int s, int altitude)
        : Vehicle(b, s), maxAltitude(altitude)
    {
        std::cout << "[2b] Constructor Airplane\n";
    }

    ~Airplane()
    {
        std::cout << "[3b] Destructor Airplane\n";
    }

    void fly()
    {
        std::cout << brand << " flyes " << maxAltitude << "м!\n";
    }
};

class FlyingCar : public Car, public Airplane
{
public:
    FlyingCar(const std::string &b, int s, int passengers, int altitude)
        : Vehicle(b, s),
          Car(b, s, passengers),
          Airplane(b, s, altitude)
    {
        std::cout << "[2c] Constructor FlyingCar\n";
    }

    ~FlyingCar()
    {
        std::cout << "[3c] Destructor FlyingCar\n";
    }

    void transformAndGo()
    {
        std::cout << "--- Flying car starts ---\n";
        drive();
        fly();
    }
};

class Animal
{
public:
    void makeSound()
    {
        std::cout << "Abstract animal sound\n";
    }
};

class Frog : public Animal
{
public:
    void makeSound()
    {
        std::cout << "QUa-qua!\n";
    }
};

class Dog : public Animal
{
public:
    void makeSound()
    {
        std::cout << "WOOF-WOOF!\n";
    }
};

int main(int argc, char **argv)
{
    Frog frog;

    frog.makeSound();

    FlyingCar myFlyingCar("SkyCruiser", 300, 4, 3000);

    myFlyingCar.showInfo();

    // Car myCar("Tesla", 220, 5);

    // myCar.showInfo();
    // myCar.drive();

    return 0;
}
