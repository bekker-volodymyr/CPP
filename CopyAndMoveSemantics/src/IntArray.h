#pragma once

class IntArray
{
private:
    int *data;
    size_t size;

public:
    // Конструктори та деструктор
    IntArray();                     // Конструктор за замовчуванням
    explicit IntArray(size_t size); // Конструктор з розміром (explicit забороняє неявне перетворення типу)
    ~IntArray();                    // Деструктор (звільнення пам'яті)

    // Семантика копіювання (Глибоке копіювання)
    IntArray(const IntArray &other);
    IntArray &operator=(const IntArray &other);

    // Семантика переміщення (Оптимізація без копіювання)
    IntArray(IntArray &&other) noexcept;
    IntArray &operator=(IntArray &&other) noexcept;

    // Перевантаження оператора індексації []
    int &operator[](size_t index);             // Для запису: arr[0] = 5;
    const int &operator[](size_t index) const; // Для читання константних об'єктів: int x = arr[0];

    // Допоміжні методи
    size_t getSize() const;
};