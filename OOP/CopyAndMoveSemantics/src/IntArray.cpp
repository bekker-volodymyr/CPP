#include "IntArray.h"

#include <iostream>
#include <stdexcept> // Для std::out_of_range

IntArray::IntArray() : data(nullptr), size(0) {}

IntArray::IntArray(size_t size) : size(size)
{
    data = (size > 0) ? new int[size]{0} : nullptr; // Ініціалізуємо нулями
}

IntArray::~IntArray()
{
    if (data != nullptr)
        delete[] data;
}

// --- Семантика копіювання ---

// Конструктор копіювання
IntArray::IntArray(const IntArray &other) : size(other.size)
{
    if (size > 0)
    {
        data = new int[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    else
    {
        data = nullptr;
    }
}

// Оператор присвоювання копіюванням (Copy Assignment)
IntArray &IntArray::operator=(const IntArray &other)
{
    if (this == &other)
        return *this; // Захист від самоприсвоювання (arr = arr)

    if (data != nullptr)
        delete[] data; // Звільняємо стару пам'ять поточного об'єкта

    size = other.size;
    if (size > 0)
    {
        data = new int[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    else
    {
        data = nullptr;
    }
    return *this;
}

// --- Семантика переміщення ---

// Конструктор переміщення
IntArray::IntArray(IntArray &&other) noexcept
    : data(other.data), size(other.size)
{
    std::cout << "Move constructor\n";
    other.data = nullptr; // Залишаємо донора порожнім, щоб деструктор не видалив дані
    other.size = 0;
}

// Оператор присвоювання переміщенням
IntArray &IntArray::operator=(IntArray &&other) noexcept
{
    std::cout << "Move operator\n";
    if (this != &other)
    {
        // Видаляємо старі дані поточного об'єкта
        delete[] data;

        // Перехоплюємо дані
        data = other.data;
        size = other.size;

        // Зачищаємо донора
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

// --- Перевантаження операторів індексації ---

// Версія для не-константних об'єктів
int &IntArray::operator[](size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("Index is out of bounds for IntArray!");
    }
    return data[index];
}

// Версія для константних об'єктів
const int &IntArray::operator[](size_t index) const
{
    if (index >= size)
    {
        throw std::out_of_range("Index is out of bounds for constant IntArray!");
    }
    return data[index];
}

// --- Допоміжні методи ---

size_t IntArray::getSize() const
{
    return size;
}