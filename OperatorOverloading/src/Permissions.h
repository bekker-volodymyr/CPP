#pragma once

#include <iostream>

class Permissions
{
private:
    unsigned int mask;

public:
    // Константи для зручності (можна також використовувати enum class)
    static const unsigned int None = 0;
    static const unsigned int Read = 1 << 0;  // 1
    static const unsigned int Write = 1 << 1; // 2
    static const unsigned int Exec = 1 << 2;  // 4

    // Конструктор
    Permissions(unsigned int m = None) : mask(m) {}

    // Перевантаження побітового OR (|) для об'єднання прав
    // Реалізовано як зовнішня функція для симетрії
    friend Permissions operator|(const Permissions &p1, const Permissions &p2)
    {
        return Permissions(p1.mask | p2.mask);
    }

    // Перевантаження побітового AND (&) для перевірки наявності прав
    friend Permissions operator&(const Permissions &p1, const Permissions &p2)
    {
        return Permissions(p1.mask & p2.mask);
    }

    // Перевантаження логічного NOT (!)
    // Повертає true, якщо прав взагалі немає
    bool operator!() const
    {
        return mask == None;
    }

    // Метод для виводу маски
    void print() const
    {
        std::cout << "Mask: " << mask << "\n";
    }
};