#include <iostream>
#include "Cat.h"

// Getters
char* Cat::GetNickname() {
	return nickname;
}
int Cat::GetAge() {
	return age;
}
// Setters
void Cat::SetNickname(char* name) {
	if (name != nullptr) {
		nickname = name;
	}
}
void Cat::SetAge(int a) {
	if (a > 0) {
		age = a;
	}
}

// Методи
void Cat::AskForFood() {
	while (true)
		std::cout << "МІАУУУУУ\n";
}
void Cat::MakePurr() {
	std::cout << "мур-мур-мур\n";
}
void Cat::PrintCat() {
	std::cout << "Ім'я: " << nickname << '\n';
	std::cout << "Вік: " << age << '\n';
}
