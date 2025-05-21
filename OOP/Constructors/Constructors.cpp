/*
* 
Конструктор - спеціальний метод класу, який викликається автоматично при створенні об’єкту та 
відповідальний за ініціалізацію його початкового стану (полів).
*/

#include <iostream>
#include <Windows.h>
#include "Monkey.cpp"
#include "Dog.cpp"
#include "Transport.cpp"
#include "Student.h"

int main()
{
    SetConsoleOutputCP(1251);

    {
        // Виклик конструктора без параметрів
        Monkey monkey;

        cout << "Name: " << monkey.GetName() << '\n';
        cout << "Age: " << monkey.GetAge() << '\n';
    }

    {
        char name[] = "Koko";
        // Виклик конструктора з параметрами
        Monkey monkey(name);

        cout << "Name: " << monkey.GetName() << '\n';
        cout << "Age: " << monkey.GetAge() << '\n';
    }

    {
        char name[] = "Evil Monkey";
        int age = 15;
        // Виклик конструктору з параметрами
        Monkey monkey(name, age);

        cout << "Name: " << monkey.GetName() << '\n';
        cout << "Age: " << monkey.GetAge() << '\n';
    }

    {
        // Конструктору за замовченням 
        // Оголошений примусово
        Dog dog;

        // Поля не проініціалізовані!
        // Вивід: сміття!
        cout << dog.GetName() << '\n';
    }

    {
        // Створення об'єкту
        // Виклик конструкторів
        Truck truck;
    }

    {
        char name1[] = "Моріс";
        char name2[] = "Джуліан";
        Monkey mn1(name1);
        Monkey* mn2 = new Monkey(name2);

        // Виклик деструктора через delete
        delete mn2;
        // Деструктор для mn1 викличеться автоматично 
        // При виході з області видимості
    }

    {
        char name[] = "Леонід Кравчук";
        int grades[] = { 4, 6, 10, 5, 1 };
        Student student(name, grades, 5);

        cout << "Середня оцінка студента " 
            << student.GetName() << ": " 
            << student.avgGrade() << '\n';
    }

    {
        // Використання покажчика на об'єкт (масив)
        int size = 3;
        int g1[] = { 5, 6, 2 };
        int g2[] = { 10, 4, 5 };
        int g3[] = { 10, 11, 12 };

        Student* students = new Student[size]
        {
            { "Леонід Кравчук", g1, 3 },
            { "Леонід Кучма", g2, 3 },
            { "Віктор Ющенко", g3, 3 }
        };

        for (int i = 0; i < size; i++) {
            cout << "Середня оцінка студента "
                << students[i].GetName() << ": "
                << students[i].avgGrade() << '\n';
        }

        delete[] students;
    }
}