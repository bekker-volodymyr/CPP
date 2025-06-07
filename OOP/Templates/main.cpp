#include <iostream>
using namespace std;

#include "Box.h"
#include "DynArr.h"

// Перевантаження функцій - статичний поліморфізм
int sum(int a, int b);
double sum(double x, double y);

// Шаблонні функції - статичний поліморфізм
template <typename T>
T multiply(T a, T b);

// Перевантаження операторів - статичний поліморфізм
class MathVector
{
    private:
        double x, y;
    public:
        MathVector(double x, double y) : x(x), y(y) {}
        // Перевантаження оператора +
        MathVector operator+(const MathVector& other) const
        {
            return MathVector(x + other.x, y + other.y);
        }
};

// Створення псевдониму для типу
typedef int MY_INT;
using MyInt = int;

int main()
{
    // Перевантаження функцій - статичний поліморфізм
    {
        // Версія функції визначена до запуску програми - статичний поліморфізм
        cout << sum(5, 10) << '\n';     // Виклик функції для int
        cout << sum(5.5, 10.5) << '\n'; // Виклик функції для double
    }

    // Шаблонні функції - статичний поліморфізм
    {
        // Версія функції визначена до запуску програми - статичний поліморфізм
        cout << multiply(5, 10) << '\n';     // Виклик шаблону для int
        cout << multiply(5.5, 10.5) << '\n'; // Виклик шаблону для double
    }

    // Перевантаження операторів - статичний поліморфізм
    {
        MathVector v1(1.0, 2.0);
        MathVector v2(3.0, 4.0);
        MathVector v3 = v1 + v2; // Виклик перевантаженого оператора + для MathVector
        int number = 5 + 10; // Виклик оператора + для int
    }

    // Шаблонні класи - статичний поліморфізм
    {
        // Автоматичне визначення типу
        Box intBox(42);
        cout << "Box contains: " << intBox.getValue() << '\n';

        // Явне визначення типу
        Box<double> doubleBox;
        doubleBox.setValue(2.718);
        cout << "Box contains: " << doubleBox.getValue() << '\n';
    }

    // Шаблонний динамічний масив - статичний поліморфізм
    {
        DynArr<int> intArray(5);
        for (int i = 0; i < intArray.getSize(); ++i)
        {
            intArray[i] = i * 2; // Заповнення масиву
        }
        intArray.print(); // Виведення масиву

        DynArr<double> doubleArray(3);
        for (int i = 0; i < doubleArray.getSize(); ++i)
        {
            doubleArray[i] = i * 1.5; // Заповнення масиву
        }
        doubleArray.print(); // Виведення масиву
    }
    
    return 0;
}

int sum(int a, int b)
{
    return a + b;
}
double sum(double x, double y)
{
    return x * y;
}

template <typename T>
T multiply(T a, T b)
{
    return a * b;
}