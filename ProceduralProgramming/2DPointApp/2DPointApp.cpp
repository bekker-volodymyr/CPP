#include <iostream>
#include <Windows.h>
#include "point.h"

using namespace std;

// Запитує у користувача дві точки та заносить значення у передані посилання
void getUserPoints(Point& p1, Point& p2);

int main()
{
    SetConsoleOutputCP(1251);

    // Змінні для роботи з двома точками
    Point p1, p2;

    short choice;
    while(true)
    {
        // Меню
        cout << "1 - Відстань між точками\n"\
            "2 - Центральна точка\n"\
            "0 - Вихід\n";
        cout << "Оберіть операцію: ";
        cin >> choice;

        switch (choice) {
        case 0: 
            cout << "Допобаченя!\n";
            return 0;
        case 1:
            // Відстань
            getUserPoints(p1, p2);
            cout << "Відстань між точками: " << calcDistance(p1, p2) << '\n';
            break;
        case 2:
            // Середня точка
            getUserPoints(p1, p2);
            cout << "Центральна точка: ";
            printPoint(midPoint(p1, p2));
            cout << '\n';
            break;
        default:
            cout << "Некоректний варіант, спробуйте ще раз.\n";
        }
    }
}

void getUserPoints(Point& p1, Point& p2) {
    cout << "Введіть першу точку: \n";
    p1 = readPoint();
    cout << "Введіть другу точку: \n";
    p2 = readPoint();
}