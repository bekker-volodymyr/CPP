#include <iostream>
#include <cmath> // Для std::abs
#include "Fraction.h"

// Анонімний простір імен для допоміжних функцій (щоб не змінювати Fraction.h)
namespace
{
    // Алгоритм Евкліда для знаходження найбільшого спільного дільника (НСД)
    int getGCD(int a, int b)
    {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return (a == 0) ? 1 : a;
    }

    // Спрощення дробу та нормалізація знаку
    void simplifyFraction(int &num, int &denom)
    {
        if (denom == 0)
            return;

        int gcd = getGCD(num, denom);
        num /= gcd;
        denom /= gcd;

        // Знак мінуса має зберігатися лише в чисельнику
        if (denom < 0)
        {
            num = -num;
            denom = -denom;
        }
    }
}

// Конструктор для ініціалізації чисельника та знаменника
Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom == 0 ? 1 : denom)
{
    if (denom == 0)
    {
        std::cout << "Denominator cannot be zero. Setting to 1." << std::endl;
    }

    // Скорочуємо дріб одразу при створенні об'єкта
    simplifyFraction(numerator, denominator);
}

Fraction Fraction::add(const Fraction &f1, const Fraction &f2)
{
    int num = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    int denom = f1.denominator * f2.denominator;

    // Конструктор автоматично скоротить результат
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
    // Спрощення не потрібне, оскільки НСД(a+b, b) = НСД(a, b).
    // Якщо дріб був скорочений, він таким і залишиться.
    return *this;
}

// Постфіксна форма оператора ++
Fraction Fraction::operator++(int)
{
    Fraction temp = *this;
    ++(*this);
    return temp;
}

// Перевантаження оператора <<
std::ostream &operator<<(std::ostream &os, const Fraction &f)
{
    os << f.numerator << "/" << f.denominator;
    return os;
}

// Перевантаження оператора >>
std::istream &operator>>(std::istream &is, Fraction &f)
{
    char slash; // Для зчитування символу '/'
    is >> f.numerator >> slash >> f.denominator;
    if (f.denominator == 0)
    {
        std::cout << "Denominator cannot be zero. Setting to 1." << std::endl;
        f.denominator = 1;
    }

    // Обов'язкове скорочення після ручного вводу значень
    simplifyFraction(f.numerator, f.denominator);

    return is;
}

// Перевантаження оператора + для додавання цілого числа
Fraction operator+(int value, const Fraction &f)
{
    int num = f.numerator + value * f.denominator;

    // Конструктор автоматично скоротить результат
    return Fraction(num, f.denominator);
}