#include <iostream>

using namespace std;

class Dog {
private:
	char name[50];
	char breed[50];
	int age;
public:
	Dog() = default;

	Dog(char* n, char* b, int a) {
		SetName(n);
		SetBreed(b);
		SetAge(a);
	}

	// Модифікатори
	void SetName(char* value) {
		if (value != nullptr)
			strcpy_s(name, 50, value);
		else
			strcpy_s(name, 50, "Пес Патрон");
	}
	void SetBreed(char* value) {
		if (value != nullptr)
			strcpy_s(breed, 50, value);
		else
			strcpy_s(breed, 50, "Джек-Рассел-Тер'єр");
	}
	void SetAge(int value) {
		if (value >= 0)
			age = value;
		else
			age = 6;
	}

	//Інспектори
	const char* GetName() {
		return name;
	}
	const char* GetBreed() {
		return breed;
	}
	int GetAge() {
		return age;
	}
};