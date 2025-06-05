#pragma once

class DynArr {
private:
    int* arr;
    int size;
public:
    DynArr() = default; // Конструктор за замовчуванням

    DynArr(int s);
    // Семантика копіювання
    DynArr(const DynArr& other);
    DynArr& operator=(const DynArr& other);
    // Семантика переміщення
    DynArr(DynArr&& other) noexcept;
    DynArr& operator=(DynArr&& other) noexcept;

    ~DynArr();

    int operator[](int index) const;
    int& operator[](int index);

    int getSize() const {
        return size;
    }

    void randomize();
    void print() const;
};