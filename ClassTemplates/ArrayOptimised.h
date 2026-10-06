#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
    T *arr;
    int size;
    int capacity; // Додано: зарезервована пам'ять

public:
    // Конструктор тепер приймає початкову місткість (за замовчуванням 10)
    Array(int cap = 10);

    // Правило 5
    Array(const Array<T> &other);
    Array<T> &operator=(const Array<T> &other);
    Array(Array<T> &&other) noexcept;
    Array<T> &operator=(Array<T> &&other) noexcept;
    ~Array();

    T operator[](int index) const;
    T &operator[](int index);

    void pushBack(T value);
    void popBack();
    void reserve(int newCapacity); // Новий метод для ручного виділення пам'яті

    int getSize() const { return size; }
    int getCapacity() const { return capacity; } // Геттер для місткості
    void print() const;
};

// ================= Реалізація =================

template <typename T>
Array<T>::Array(int cap) : size(0), capacity(cap)
{
    arr = new T[capacity]; // Одразу виділяємо пам'ять під capacity, але size = 0
}

template <typename T>
Array<T>::Array(const Array<T> &other) : size(other.size), capacity(other.capacity)
{
    arr = new T[capacity];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        delete[] arr;
        size = other.size;
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::Array(Array<T> &&other) noexcept : arr(other.arr), size(other.size), capacity(other.capacity)
{
    other.arr = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> &&other) noexcept
{
    if (this != &other)
    {
        delete[] arr;
        arr = other.arr;
        size = other.size;
        capacity = other.capacity;

        other.arr = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}

template <typename T>
T Array<T>::operator[](int index) const
{
    return arr[index];
}

template <typename T>
T &Array<T>::operator[](int index)
{
    return arr[index];
}

// ---------------- Ключові оптимізовані методи ----------------

template <typename T>
void Array<T>::reserve(int newCapacity)
{
    // Якщо нова місткість менша або рівна поточній, нічого не робимо
    if (newCapacity <= capacity)
        return;

    T *newArr = new T[newCapacity];

    // Копіюємо наявні елементи
    for (int i = 0; i < size; ++i)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

template <typename T>
void Array<T>::pushBack(T value)
{
    // Якщо місце закінчилося, збільшуємо масив вдвічі
    if (size == capacity)
    {
        int newCap = (capacity == 0) ? 1 : capacity * 2;
        reserve(newCap);
    }

    // Тепер точно є місце, просто записуємо і збільшуємо size
    arr[size] = value;
    size++;
}

template <typename T>
void Array<T>::popBack()
{
    if (size > 0)
    {
        size--; // Ніякого delete[]. Ми просто "ховаємо" елемент
    }
}

template <typename T>
void Array<T>::print() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}