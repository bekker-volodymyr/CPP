#pragma once
#include <iostream>
#include <string>

class Animal
{
private:
	std::string name;
	int age;
public:
	Animal(const std::string& name, int age) : name(name), age(age) {}
	
	std::string getName() const { return name; }
	int getAge() const { return age; }
	
	void setName(const std::string& newName) { name = newName; }
	void setAge(int newAge) { age = newAge; }
	
	virtual void makeSound() const = 0; // Чисто віртуальна функція
	virtual ~Animal() {} // Віртуальний деструктор
};

class Monkey : public Animal
{
	public:
	Monkey(const std::string& name, int age) : Animal(name, age) {}
	void makeSound() const override {
		std::cout << getName() << " каже: У-А-А!" << std::endl;
	}
};

class Elephant : public Animal
{
	public:
	Elephant(const std::string& name, int age) : Animal(name, age) {}
	void makeSound() const override {
		std::cout << getName() << " каже: Тру-ту!" << std::endl;
	}
};

