#include <iostream>

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // Конструктор для ініціалізації чисельника та знаменника
    Fraction(int num, int denom);

    static Fraction add(const Fraction &f1, const Fraction &f2);

    static Fraction printFraction(const Fraction &f);

    // Префіксна форма оператора ++
    Fraction &operator++();

    // Постфіксна форма оператора ++
    // (int параметр для відрізнення)
    Fraction operator++(int);

    // Перевантаження унарного оператора -
    // для зміни знаку дробу
    Fraction operator-() const
    {
        return Fraction(-numerator, denominator);
    }

    // Перевантаження оператора +
    // Лівий операнд як покажчик (this)
    // Правий операнд як параметр
    // Повертає новий об'єкт Fraction
    Fraction operator+(const Fraction &other) const
    {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Перевантаження оператора ==
    bool operator==(const Fraction &other) const
    {
        return (numerator * other.denominator == other.numerator * denominator);
    }

    // Перевантаження оператора !
    // Повертає true, якщо дроб правильний
    // Повертає false, якщо дроб неправильний
    bool operator!() const
    {
        return (numerator < denominator);
    }

    // Перевантаження операторів << та >>
    friend std::ostream &operator<<(std::ostream &os, const Fraction &f);

    friend std::istream &operator>>(std::istream &is, Fraction &f);

    // Перевантаження оператора + для додавання цілого числа
    // Лівий операнд як цілочисельне значення (перший параметр)
    // Правий операнд як об'єкт Fraction (другий параметр)
    friend Fraction operator+(int value, const Fraction &f);
};