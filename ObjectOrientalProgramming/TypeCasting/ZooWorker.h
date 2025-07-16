#pragma once
#include <iostream>
#include <string>

#include "Animal.h"

class ZooWorker
{
private:
	double salary;
	std::string name;
public:
	ZooWorker(const std::string& name, double salary) : name(name), salary(salary) {}

	std::string getName() const { return name; }
	double getSalary() const { return salary; }

	void setName(const std::string& newName) { name = newName; }
	void setSalary(double newSalary) { salary = newSalary; }

	void feedAnimal(const Animal& animal) const {
		if(typeid(animal) == typeid(Monkey)) {
			std::cout << 
				"Працівник зоологічного саду " << name << 
				" годує мавпу " << animal.getName() << " бананом.\n";
		} else if(typeid(animal) == typeid(Elephant)) {
			std::cout 
				<< "Працівник зоологічного саду " << name <<
				" годує слона " << animal.getName() << " цукровою тростиною.\n";
		} else {
			std::cout 
				<< "Працівник зоологічного саду " << name << 
				" годує тварину " << animal.getName() << ".\n";
		}
	}
};

