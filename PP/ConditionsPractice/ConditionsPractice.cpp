#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    // Налаштовуємо консоль для підтримки кирилиці
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int number;
    int power;

    cout << "Введіть число: ";
    cin >> number;
    cout << "Введіть ступінь (від 0 до 7): ";
    cin >> power;

    int result;

    // Обчислення степеня вручну для ступенів від 0 до 7
    switch (power) {
        case 0: result = 1; break;
        case 1: result = number; break;
        case 2: result = number * number; break;
        case 3: result = number * number * number; break;
        case 4: result = number * number * number * number; break;
        case 5: result = number * number * number * number * number; break;
        case 6: result = number * number * number * number * number * number; break;
        case 7: result = number * number * number * number * number * number * number; break;
        default: result = -1; break;
    }

    if (result == -1) {
        cout << "Введено ступінь, що не підтримується." << endl;
    } else {
        cout << "Результат дорівнює: " << result << endl;
    }

    // Альтернатива — можна використати:
    // cout << "Результат (через pow): " << pow(number, power) << endl;

    return 0;
}
