#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Цикл while - виконується, поки умова істинна
    int i = 0;
    while (i < 5) {
        cout << "while: " << i << endl;
        i++; // Збільшуємо i
    }

    // Цикл do-while - виконується хоча б один раз, навіть якщо умова хибна
    int j = 0;
    do {
        cout << "do-while: " << j << endl;
        j++;
    } while (j < 5);

    // Цикл for - включає ініціалізацію, умову та оновлення змінної
    for (int k = 0; k < 5; k++) {
        cout << "for: " << k << endl;
    }

    // Нескінченний цикл
    while (true) {
        cout << "Це нескінченний цикл" << endl;
    }
}
