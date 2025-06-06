#include <iostream>
// #include <windows.h> тільки на Windows

using namespace std;

// Структура для збереження інформації про дату.
// Інформація зібрана в одному складовому типі.
struct date {
    int day;            // День
    int month;          // Місяць
    int year;           // Рік
    int weekday;        // Номер дня тижня
    char mon_name[15];  // Назва місяця
} date1;

struct person
{
    char name[50];      // Ім'я, прізвище, по батькові.
    char address[50];   // Домашня адреса.
    int zipcode[2];     // Поштовий індекс.
    int s_number[2];    // Код соц.забезпечення.
    int salary[4];      // Зарплата.
    date birthdate;     // Дата народження.
    date hiredate;      // Дата прийому на роботу.
};

struct point {
    int x;
    int y;
} p1, p2, p3;

union Data {  // 4 байт - все розміщується в одному блоці пам'яті
    char c;  // 1 байт
    int i;   // 4 байти
};

void PrintDate(const date& d)
{
    cout << d.day << "." << d.month << "." << d.year
         << " " << d.weekday << ", " << d.mon_name << '\n';
}


int main()
{
    // Тільки на Windows
    // SetConsoleOutputCP(1251);
    // SetConsoleCP(1251);

    // Приклад використання об'єднання (union)
    {
        cout << "Розмір об'єднання Union: " << sizeof(Data) << '\n';
        Data data;

        data.c = 'h'; // Присвоєння значення типу char
        cout << "Значення char: " << data.c << '\n'; // Виводиться 'h'
        cout << "Значення int: " << data.i << '\n';  // Виводиться 104 (ASCII код 'h')

        data.i = 123; // Присвоєння значення типу int, char перезаписується
        cout << "Значення int: " << data.i << '\n';  // Виводиться 123
        cout << "Значення char: " << data.c << '\n'; // Виводиться '}' (символ, що відповідає 123 в ASCII)
    }

    struct Test { // 8 байт - вирівнювання
        char c; // 1 байт
        int i;  // 4 байти
    };

    Test d = { '#', 77 };
    cout << "Розмір структури: " << sizeof(Test) << "\n" << "Розмір об'єкту структури: " << sizeof(d) << '\n';

    int value = 10;
    bool boolean = false;
    bool* ptr = &boolean;
    int arr[10];

    cout << "Розмір змінної з типом int: " << sizeof(value) << '\n';
    cout << "Розмір змінної з типом bool: " << sizeof(boolean) << '\n';
    cout << "Розмір покажчику: " << sizeof(ptr) << '\n';
    cout << "Розмір масиву типу int на 10 елементів: " << sizeof(arr) << '\n';

    point pa = { 12, 31 };

    // Ініціалізація одного об'єкта іншим об'єктом
    // Відбувається створення точної копії
    point pb = pa;

    point p = { 10, 11 };

    cout << sizeof(p) << endl;

    // Доступ до елементу структури
    cout << p.x << '\n';
    // Отримання адреси об'єкту структури
    point* pp = &p;
    // Доступ до елементу струкутри через покажчик
    cout << pp->x << '\n';

    // Створення та ініціалізація
    date myBirthday = { 20, 7, 1981, 1, "Червень" };

    // Зміна значення
    myBirthday.year = 1988;

    // Отримання даних
    cout << "Я народився " << myBirthday.day << " " << myBirthday.mon_name << " " << myBirthday.year << ".\n";

    cout << sizeof(myBirthday) << endl;

    PrintDate(myBirthday);
}