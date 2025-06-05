#include <iostream>
#include <cmath>
#include "DynArr.h"

using namespace std;

class Power
{
    int exponent; // Степінь

public:
    Power(int exp) : exponent(exp) {}

    // Перевантаження оператора ()
    double operator()(double base) const
    {
        return std::pow(base, exponent);
    }
};

class Money {
    int cents;

public:
    Money(int dollars, int cents) : cents(dollars * 100 + cents) {}

    // Явне перетворення до double
    explicit operator double() const {
        return cents / 100.0;
    }

    // Неявне перетворення до int (кількість центів)
    operator int() const {
        return cents;
    }
};

DynArr arrFactory(int size)
{
    DynArr arr(size);
    arr.randomize();

    // Повернення за значенням
    // Це викликає конструктор копіювання або оператор присвоєння
    return arr;
}

void testCopy(DynArr obj)
{
    std::cout << "Отримали копію або переміщений обʼєкт\n";
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    // Використання фабричної функції для створення масиву
    // Використання функції testCopy для тестування копіювання
    {
        DynArr arr(10);
        arr.print();         // Виведення масиву на екран
        testCopy(arr);       // Виклик функції для тестування копіювання
        testCopy(move(arr)); // Виклик функції для тестування переміщення
    }

    // Використання rvalue-посилань
    {
        int x = 10;
        int &refx = x; // Створення lvalue-посилання на x

        // int& refxx = x + 5; // Це не дозволено, оскільки x + 5 є rvalue
        // int& refxx = 10; // Це також не дозволено, оскільки 10 є rvalue

        // Це дозволено, оскільки x + 5 є rvalue, і ми можемо створити rvalue-посилання на нього
        int &&refxx = x + 5;
        int &&refmax{max(5, 10)}; // Використання rvalue-посилання для результату функції max

        // Помилка: int&& ref {x}; // Це не дозволено, оскільки x є lvalue
        // int&& ref {x};
    }

    // Присвоєння з переміщенням
    {
        DynArr arr = arrFactory(5); // Виклик фабричної функції, яка повертає об'єкт DynArr
        arr.print();                // Виведення масиву на екран
        arr = arrFactory(10);       // Виклик оператора присвоєння з переміщенням
        arr.print();                // Виведення масиву на екран
    }

    // Використання конструктора переміщення
    {
        DynArr arr1{arrFactory(10)};  // Виклик фабричної функції, яка повертає об'єкт DynArr
        arr1.print();                 // Виведення масиву на екран
        DynArr arr2{std::move(arr1)}; // Виклик конструктора переміщення
        arr2.print();                 // Виведення масиву на екран
        // arr1.print(); // Помилка: arr1 більше не має дійсного масиву після переміщення
        arr1 = arrFactory(5);
    }

    // Використання перевантаженного оператора []
    {
        DynArr arr(5);
        arr.randomize(); // Заповнення масиву випадковими числами
        arr.print();     // Виведення масиву на екран

        // Використання оператора [] для доступу до елементів масиву
        for (int i = 0; i < arr.getSize(); ++i)
        {
            std::cout << "Element at index " << i << ": " << arr[i] << std::endl;
        }
    }

    // Використання класу Power
    {
        Power square(2); // Створення об'єкта Power з експонентом 2
        Power cube(3);   // Створення об'єкта Power з експонентом 3
        double base = 3.0;
        cout << "Квадрат: " << square(base) << endl; // Виведення результату
        cout << "Куб: " << cube(base) << endl;       // Виведення результату
    }

    // Використання операторів перетворення в класі Money
    {
        Money money(5, 99); // Створення об'єкта Money з 5 доларами і 99 центами
        double dollars = (double)(money); // Явне перетворення до double
        int cents = money; // Неявне перетворення до int (кількість центів)

        cout << "Долари: " << dollars << endl; // Виведення доларів
        cout << "Центи: " << cents << endl;   // Виведення кількості центів
    }

    return 0;
}