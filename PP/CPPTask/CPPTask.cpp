#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251); // Для коректного виводу українських символів у Windows

    int sum = 0;
    int temp;

    // Цикл, який підсумовує всі введені числа, доки не буде введено 0
    do {
        cout << "Введіть число: ";
        cin >> temp;
        sum += temp;
    } while (temp != 0);

    cout << "Сума чисел, які ви ввели: " << sum << '\n';

    return 0;
}
