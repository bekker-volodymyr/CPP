#include <iostream>
#include "DynArr.h"

DynArr::DynArr(int s) : size(s)
{
    arr = new int[size];

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Виклик конструктора з параметром.";
    std::cout << "Розмір масиву: " << size << std::endl;
    std::cout << "Адреса масиву: " << arr << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

DynArr::DynArr(const DynArr& other) : size(other.size)
{
    arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Виклик конструктора копіювання.";
    std::cout << "Розмір масиву: " << size << std::endl;
    std::cout << "Адреса масиву: " << arr << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

DynArr& DynArr::operator=(const DynArr& other)
{
    if (this != &other) // Перевірка на самоприсвоєння
    {
        delete[] arr; // Звільнення старого масиву
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = other.arr[i];
        }
    }


    std::cout << "--------------------------------" << std::endl;
    std::cout << "Виклик оператора присвоєння з копіюванням.";
    std::cout << "Розмір масиву: " << size << std::endl;
    std::cout << "Адреса масиву: " << arr << std::endl;
    std::cout << "--------------------------------" << std::endl;

    return *this;
}

DynArr::DynArr(DynArr&& other) noexcept : arr(other.arr), size(other.size)
{
    other.arr = nullptr; // Звільнення ресурсу в переміщеному об'єкті
    other.size = 0;

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Виклик конструктора переміщення.";
    std::cout << "Розмір масиву: " << size << std::endl;
    std::cout << "Адреса масиву: " << arr << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

DynArr& DynArr::operator=(DynArr&& other) noexcept
{
    if (this != &other) // Перевірка на самоприсвоєння
    {
        delete[] arr; // Звільнення старого масиву
        arr = other.arr; // Переміщення ресурсу
        size = other.size;

        other.arr = nullptr; // Звільнення ресурсу в переміщеному об'єкті
        other.size = 0;
    }

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Виклик оператора присвоєння з переміщенням.";
    std::cout << "Розмір масиву: " << size << std::endl;
    std::cout << "Адреса масиву: " << arr << std::endl;
    std::cout << "--------------------------------" << std::endl;

    return *this;
}

DynArr::~DynArr()
{

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Виклик деструктора.";
    std::cout << "Розмір масиву: " << size << std::endl;
    std::cout << "Адреса масиву: " << arr << std::endl;
    std::cout << "--------------------------------" << std::endl;

    delete[] arr; // Звільнення динамічного масиву
}

int DynArr::operator[](int index) const
{
    return arr[index];
}

int& DynArr::operator[](int index)
{
    return arr[index];
}

void DynArr::randomize()
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100; // Випадкові числа від 0 до 99
    }
}

void DynArr::print() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}