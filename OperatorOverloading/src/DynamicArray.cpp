#include <iostream>
#include "DynamicArray.h"

DynamicArray::DynamicArray(int size) : size(size)
{
    if (size <= 0)
    {
        std::cout << "Size must be greater than 0. Setting size to 1.\n";
    }
    data = new int[size];
}

DynamicArray::DynamicArray(const DynamicArray &other) : size(other.size)
{
    data = new int[size];
    for (int i = 0; i < size; ++i)
    {
        data[i] = other.data[i];
    }
}
DynamicArray &DynamicArray::operator=(const DynamicArray &other)
{
    if (this != &other)
    {
        delete[] data; // Звільняємо старий масив
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

DynamicArray::~DynamicArray()
{
    delete[] data; // Звільняємо динамічно виділену пам'ять
}