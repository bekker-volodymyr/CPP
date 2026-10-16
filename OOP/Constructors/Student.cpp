#include <iostream>
#include "Student.h"
using namespace std;


Student::Student(const char* n, int* g, int gc) {
	SetName(n);
	SetGrades(g, gc);
}

int Student::avgGrade() {
	if (_grades == nullptr || _gradesCount == 0) {
		return 0;
	}
	else {
		int sum = _grades[0];
		for (int i = 1; i < _gradesCount; i++) {
			sum += _grades[i];
		}
		return sum / _gradesCount;
	}
}

void Student::SetName(const char* value) {
	if (_name != nullptr) delete[] _name;

	if (value != nullptr) {
		int len = strlen(value) + 1;
		_name = new char[len];
		strcpy_s(_name, len, value);
	}
	else {
		_name = nullptr;
	}
}

void Student::SetGrades(int* g, int gc) {
	if (_grades != nullptr) delete[] _grades;

	if (g != nullptr && gc > 0) {
		_gradesCount = gc;
		_grades = new int[gc];
		for (int i = 0; i < gc; i++) {
			_grades[i] = g[i];
		}
	}
	else {
		_gradesCount = 0;
		_grades = nullptr;
	}
}

Student::~Student() {
	if (_name != nullptr)
		delete[] _name;

	if (_grades != nullptr)
		delete[] _grades;
}