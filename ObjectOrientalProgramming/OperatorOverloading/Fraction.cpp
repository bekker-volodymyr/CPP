#include <iostream>
#include "Fraction.h"

// Конструктор для ініціалізації чисельника та знаменника
Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom == 0 ? 1 : denom)
{
    if (denominator == 0)
    {
        std::cout << "Denominator cannot be zero. Setting to 1." << std::endl;
    }
}

Fraction Fraction::add(const Fraction &f1, const Fraction &f2)
{
    int num = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    int denom = f1.denominator * f2.denominator;
    return Fraction(num, denom);
}

Fraction Fraction::printFraction(const Fraction &f)
{
    std::cout << "Fraction: " << f.numerator << "/" << f.denominator << std::endl;
    return f;
}

// Префіксна форма оператора ++
Fraction &Fraction::operator++()
{
    numerator += denominator;
    return *this;
}

// Постфіксна форма оператора ++
// (int параметр для відрізнення)
Fraction Fraction::operator++(int)
{
    Fraction temp = *this; // Зберігаємо поточний стан
    ++(*this);             // Викликаємо префіксну форму
    return temp;           // Повертаємо старий стан
}

// Перевантаження операторів << та >>
std::ostream &operator<<(std::ostream &os, const Fraction &f)
{
    os << f.numerator << "/" << f.denominator;
    return os;
}

std::istream &operator>>(std::istream &is, Fraction &f)
{
    char slash; // Для зчитування символу '/'
    is >> f.numerator >> slash >> f.denominator;
    if (f.denominator == 0)
    {
        std::cout << "Denominator cannot be zero. Setting to 1." << std::endl;
        f.denominator = 1;
    }
    return is;
}

// Перевантаження оператора + для додавання цілого числа
// Лівий операнд як цілочисельне значення (перший параметр)
// Правий операнд як об'єкт Fraction (другий параметр)
Fraction operator+(int value, const Fraction &f)
{
    int num = f.numerator + value * f.denominator;
    return Fraction(num, f.denominator);
}