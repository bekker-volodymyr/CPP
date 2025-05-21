#include <iostream>
using namespace std;

class Transport {
public:
	Transport()
	{
		cout << "Конструктор класу Transport\n";
	}
	~Transport() {
		cout << "Деструктор класу Transport\n";
	}
};

class Car : public Transport {
public:
	Car()
	{
		cout << "Конструктор класу Car\n";
	}
	~Car() {
		cout << "Деструктор класу Car\n";
	}
};

class Truck : public Car {
public:
	Truck()
	{
		cout << "Конструктор класу Truck\n";
	}
	~Truck() {
		cout << "Деструктор класу Truck\n";
	}
};