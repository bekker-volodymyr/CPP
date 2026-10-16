#include "FriendFunction.h"
#include "Fraction.h"
#include "Permissions.h"
#include "Query.h"

#include <iostream>
#include <compare>
#include <algorithm> // для std::sort

int main()
{
    {
        // Створюємо базові критерії пошуку
        Query isAdult("age >= 18");
        Query hasLicense("has_license = true");
        Query hasVIP("status = 'VIP'");

        // Комбінуємо запити за допомогою && та ||
        // Зверніть увагу: ми будуємо рядок, а не отримуємо bool
        Query finalSearch = (isAdult && hasLicense) || hasVIP;

        finalSearch.print();
        // Результат: SQL WHERE (((age >= 18) AND (has_license = true)) OR (status = 'VIP'))
    }

    {
        Permissions p1(Permissions::Read);
        Permissions p2(Permissions::Write);

        // Використання перевантаженого |
        Permissions both = p1 | p2;
        both.print(); // Виведе Mask: 3 (Read + Write)

        // Використання перевантаженого !
        Permissions empty(Permissions::None);
        if (!empty)
        {
            std::cout << "Користувач не має жодних прав.\n";
        }

        // Перевірка конкретного права через &
        Permissions check = both & Permissions(Permissions::Read);
        if (!check)
        {
            std::cout << "Немає права на читання.\n";
        }
        else
        {
            std::cout << "Право на читання є.\n";
        }
    }

    {
        // Звичайний C-style масив
        Fraction arr[] = {
            Fraction(3, 4),
            Fraction(1, 2),
            Fraction(5, 4),
            Fraction(1, 3)};

        // Обчислюємо кількість елементів у масиві
        int size = sizeof(arr) / sizeof(arr[0]);

        // Сортуємо масив
        // Передаємо покажчик на початок (arr) і покажчик на кінець (arr + size)
        std::sort(arr, arr + size);

        // Альтернативний, більш безпечний спосіб для C++ (робить те саме):
        // std::sort(std::begin(arr), std::end(arr));

        // Виводимо відсортований результат
        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }

    {
        Fraction f1(4, 5), f2(1, 5);

        std::cout << (f1 == f2 ? "true" : "false") << '\n';
        std::cout << (f1 <= f2 ? "true" : "false") << '\n';
        std::cout << (f1 >= f2 ? "true" : "false") << '\n';
        std::cout << (f1 < f2 ? "true" : "false") << '\n';
        std::cout << (f1 > f2 ? "true" : "false") << '\n';
    }

    {
        int a = 10;
        int b = 20;

        // Отримуємо результат порівняння
        std::strong_ordering result = (a <=> b);

        // Порівняння з 0
        if (result < 0)
        {
            std::cout << "a less then b\n"; // Спрацює цей варіант
        }
        else if (result == 0)
        {
            std::cout << "a equals b\n";
        }
        else if (result > 0)
        {
            std::cout << "a greater then b\n";
        }

        // Альтернатива: пряме порівняння з константами типу
        if (result == std::strong_ordering::less)
        {
            std::cout << "a less then b\n";
        }
    }

    // // Приклад використання класу Box та дружньої функції printWidth
    // {
    //     Box box(10.6);
    //     printWidth(box); // Виклик дружньої функції для доступу до приватного члена
    // }

    // // Приклад використання класу Fraction та перевантаження оператора +
    // {
    //     // Приклад використання класу Fraction
    //     Fraction f1(1, 2); // 1/2
    //     Fraction f2(3, 4); // 3/4

    //     // Додавання двох дробів (без перевантаження)
    //     Fraction result = Fraction::add(f1, f2);
    //     Fraction::printFraction(result); // Виведення результату

    //     // Додавання двох дробів (з перевантаженням оператора +)
    //     Fraction f3 = f1 + f2; // Використання оператора +
    //     Fraction::printFraction(f3); // Виведення результату оператора +
    // }

    // // Приклад використання перевантаження унарних операторів
    // {
    //     Fraction f1(1, 2); // 1/2

    //     Fraction::printFraction(-f1); // Використання унарного оператора -
    //     Fraction::printFraction(++f1); // Використання префіксного оператора ++
    //     Fraction::printFraction(f1++); // Використання постфіксного оператора ++
    // }

    // // Приклад використання перевантаження оператора + для додавання цілого числа до дробу
    // {
    //     Fraction f(1, 2);

    //     // Додавання цілого числа до дробу
    //     Fraction result = 2 + f; // Використання перевантаженого оператора +
    //     Fraction::printFraction(result); // Виведення результату
    // }

    // // Приклад використання перевантаження оператора ==
    // {
    //     Fraction f1(1, 2); // 1/2
    //     Fraction f2(2, 4); // 2/4

    //     cout<<(f1 == f2 ? "Equal." : "Not equal.") << '\n';
    // }

    // // Приклад використання операторів << та >>
    // {
    //     Fraction f(1, 2);
    //     cout << "Fraction: " << f << '\n'; // Використання перевантаженого оператора <<

    //     Fraction f2(0, 0); // Створення дробу з нульовим знаменником
    //     cin >> f2; // Використання перевантаженого оператора >>
    //     cout << "Fraction after input: " << f2 << '\n'; // Виведення дробу після введення
    // }

    // // Використання конструктора копіювання та оператора присвоєння
    // {
    //     Fraction f1(1, 2); // 1/2

    //     Fraction f2 = f1; // Використання конструктора копіювання

    //     Fraction f3(0, 0);
    //     f3 = f1; // Використання оператора присвоєння
    // }

    return 0;
}