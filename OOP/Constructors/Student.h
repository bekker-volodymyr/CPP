#pragma once

#include <iostream>
using namespace std;

class Student {
private:
	char* _name = nullptr;
	int* _grades = nullptr;
	int _gradesCount;
public:
	Student() = default;
	Student(const char* n, int* g, int gc);
	~Student();

	int avgGrade();

	// Модифікатори
	void SetName(const char* value);
	void SetGrades(int* g, int gc);

	//Інспектори
	char* GetName() {
		return _name;
	}
	int* GetGrades() {
		return _grades;
	}
	int GetGradesCount() {
		return _gradesCount;
	}
};