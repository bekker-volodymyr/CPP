#include <iostream>
#include <string>

using namespace std;

int main()
{

    // Ініціалізація рядка
    {
        string str = "Hello, World!";
        cout << str << '\n';
    }

    // Довжина рядка
    {
        string str = "Hello, World!";
        size_t length = str.length();
        // size_t size = str.size(); аналогічно
        cout << "Довжина рядка: " << length << '\n';
    }

    // Конкатенація рядків
    {
        string str1 = "Hello, ";
        string str2 = "World!";
        string str3 = str1 + str2;

        cout << str3 << '\n';
    }

    // Доступ до символів рядка
    {
        string str = "Hello, World!";
        char firstChar = str[0]; // Перший символ
        char lastChar = str[str.length() - 1]; // Останній символ

        cout << "Перший символ: " << firstChar << '\n';
        cout << "Останній символ: " << lastChar << '\n';

        cout << str.at(0) << '\n'; // Перший символ
        cout << str.at(str.length() - 1) << '\n'; // Останній символ

        // Вихід за межі рядка - невизначена поведінка
        cout<<str[100] << '\n';

        // Викине виключення out_of_range
        // cout<<str.at(100) << '\n'; 
    }

    // Перевірка на порожній рядок
    {
        string str = "";

        if (str.empty()) {
            cout << "Рядок порожній\n";
        } else {
            cout << "Рядок не порожній\n";
        }
    }

    // Порівняння рядків
    {
        string str1 = "Hello";
        string str2 = "World";

        if (str1 == str2) {
            cout << "Рядки однакові\n";
        } else {
            cout << "Рядки різні\n";
        }
    }

    // Заміна, пошук, підрядки
    {
        string str = "Hello, World!";
        size_t pos = str.find("World");

        if (pos != string::npos) {
            cout << "Знайдено 'World' на позиції: " << pos << '\n';
            str.replace(pos, 5, "C++");
            cout << "Після заміни: " << str << '\n';
        } else {
            cout << "'World' не знайдено\n";
        }

        // Отримання підрядка
        string subStr = str.substr(0, 5);
        cout << "Підрядок: " << subStr << '\n';
    }

    // Вставка та видалення
    {
        string str = "Hello, World!";
        str.insert(5, " Beautiful");
        cout << "Після вставки: " << str << '\n';

        str.erase(5, 10); // Видаляємо " Beautiful"
        cout << "Після видалення: " << str << '\n';
    }

    // Перетворення в числові типи
    {
        string str = "12345";
        int number = stoi(str); // Перетворення рядка в int
        cout << "Число: " << number << '\n';

        // Перетворення в double
        string strDouble = "123.45";
        double dNumber = stod(strDouble);
        cout << "Дійсне число: " << dNumber << '\n';
    }

    // Перетворення чисел в рядки
    {
        int number = 12345;
        string str = to_string(number);
        cout << "Рядок з числа: " << str << '\n';

        double dNumber = 123.45;
        string strDouble = to_string(dNumber);
        cout << "Рядок з дійсного числа: " << strDouble << '\n';
    }

    return 0;
}