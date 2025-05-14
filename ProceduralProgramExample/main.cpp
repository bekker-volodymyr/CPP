#include <iostream>
#include <Windows.h>
#include "Cat.cpp"

using namespace std;

#define MAX_NAME_LEN 30

struct StudentStruct {
    int assessmentCount = 5;
    int assessments[5];

    char name[MAX_NAME_LEN];
};

int avgAssessment(const StudentStruct& st) {
    int sum = st.assessments[0];
    for (int i = 1; i < st.assessmentCount; i++) {
        sum += st.assessments[i];
    }
    return sum / st.assessmentCount;
}

// Клас
class Student {
private: // Приватні поля - доступні тільки всередині класу
    // Дані
    char name[MAX_NAME_LEN]; // поле
    int assessments[5];
    int assessmentCount = 5;
public: // Публічні члени - доступні зовні класу
    // Поведінка
    Student(const char* name, int* assessments) {
        strcpy_s(this->name, 30, name);
        for (int i = 0; i < assessmentCount; i++) {
            this->assessments[i] = assessments[i];
        }
    }
    
    // Метод
    int avgAssessment() {
        int sum = this->assessments[0];
        for (int i = 1; i < this->assessmentCount; i++) {
            sum += this->assessments[i];
        }
        return sum / this->assessmentCount;
    }
};

int main()
{
    SetConsoleOutputCP(1251);

    StudentStruct st = { 5, {10,6,7,9,12}, "Mykola Tarasuk" };

    cout << avgAssessment(st) << '\n';

    int assessments[] = { 10, 6, 7, 9, 12 };

    // Об'єкт та його стан - конкретні значення
    Student student = Student("Mykola Tarasuk", assessments);

    cout << student.avgAssessment() << '\n';

    char nickname[] = "Evil Larry";
    char* nm = new char[strlen(nickname) + 1]; // +1 для '\0'
    strcpy_s(nm, strlen(nickname) + 1, nickname);

    Cat cat;

    // Використання сеттерів
    cat.SetAge(10);
    cat.SetNickname(nm);

    // Використання геттерів
    cout << cat.GetNickname() << '\n';
    cout << cat.GetAge() << '\n';

    delete[] nm;
}