#pragma once

class Cat {
private:
	char* nickname;  // поле
	int age;		 // поле
public: // Публічні члени класу - доступні ззовні
	// Getters
	char* GetNickname();
	int GetAge();
	// Setters
	void SetNickname(char* name);
	void SetAge(int a);

	// Методи
	void AskForFood();
	void MakePurr();
	void PrintCat();
};