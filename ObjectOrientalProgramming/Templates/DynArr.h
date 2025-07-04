#pragma once

template <typename T>
class DynArr {
private:
    T* arr;
    int size;
public:
    DynArr(int s);
    // Семантика копіювання
    DynArr(const DynArr<T>& other);
    DynArr<T>& operator=(const DynArr<T>& other);
    // Семантика переміщення
    DynArr(DynArr<T>&& other) noexcept;
    DynArr<T>& operator=(DynArr<T>&& other) noexcept;

    ~DynArr();

    T operator[](int index) const;
    T& operator[](int index);

    int getSize() const {
        return size;
    }

    void print() const;
};

template <typename T>
DynArr<T>::DynArr(int s) : size(s)
{
    arr = new T[size];
}

template <typename T>
DynArr<T>::DynArr(const DynArr<T>& other) : size(other.size)
{
    arr = new T[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }
}

template <typename T>
DynArr<T>& DynArr<T>::operator=(const DynArr<T>& other)
{
    if (this != &other) // Перевірка на самоприсвоєння
    {
        delete[] arr; // Звільнення старого масиву
        size = other.size;
        arr = new T[size];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
DynArr<T>::DynArr(DynArr<T>&& other) noexcept : arr(other.arr), size(other.size)
{
    other.arr = nullptr; // Звільнення ресурсу в переміщеному об'єкті
    other.size = 0;
}

template <typename T>
DynArr<T>& DynArr<T>::operator=(DynArr<T>&& other) noexcept
{
    if (this != &other) // Перевірка на самоприсвоєння
    {
        delete[] arr; // Звільнення старого масиву
        arr = other.arr; // Переміщення ресурсу
        size = other.size;

        other.arr = nullptr; // Звільнення ресурсу в переміщеному об'єкті
        other.size = 0;
    }

    return *this;
}

template <typename T>
DynArr<T>::~DynArr()
{
    delete[] arr; // Звільнення динамічного масиву
}

template <typename T>
T DynArr<T>::operator[](int index) const
{
    return arr[index];
}

template <typename T>
T& DynArr<T>::operator[](int index)
{
    return arr[index];
}

template <typename T>
void DynArr<T>::print() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}