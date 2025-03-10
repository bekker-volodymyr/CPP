#include <iostream>
#include <Windows.h> // для доступу WinAPI функцій

using namespace std;



int main() {
    SetConsoleOutputCP(1251); // встановлення кодування виводу консолі
    SetConsoleCP(1251); // встановлення кодування вводу консолі
    
    cout << "Іі Її Єє Ґґ!\n";

    // Type Conversion - Перетворення типів

    // Неявне перетворення
    bool boolean = 10;

    int integer1 = 5;
    float floatNumber = 1.4;

    cout << integer1 + floatNumber;

    // Явне перетворення
    int integer = (int)3.4;
    
    double double1 = 4.5;
    double double2 = 5.6;

    cout << (int)(double1 * double2);

    // Звужуюче перетворення
    float float1 = 5.78;
    int int1 = float1; // Дробова частина відкидається - втрата інформації

    // Розширююче перетворення
    //int int1 = 5;
    //double double1 = int1; 

    // Перетворення у виразі
    int i = 27;
    short s = 2;
    float  f = 22.3;
    bool b = false;

    float result = i - f + s * b; // результат типу float

    // Спискова ініціалізація
    int x = 2.88; // звужуєче перетворення - x зберігає 2
    // int y = { 3.56 }; // помилка - звужуюче перетворення

    // if
    int number1, number2;
    cin >> number1;
    cin >> number2;
    if (number1 < number2) {
        cout << "Перше число менше ніж друге" << endl;
    }
    else if (number1 > number2) {
        cout << "Перше число більше ніж дурге" << endl;
    }
    else {
        cout << "Числа рівні" << endl;
    }


    // Логічне АБО - ||
    int num;
    cin >> num;

    if (num <= 1 || num >= 10) {
        cout << "Число не потрапляє в діапазон від 1 до 10" << endl;
    }

    if ( !(num > 10) ) {
        cout << "Число менше 10" << endl;
    }

    cout << (num % 2 == 0) ? "Число парне" : "Число непарне";

    // Switch
    int day = 3;
    switch (day) {
        case 1: cout << "Понеділок"; break;
        case 2: cout << "Вівторок"; break;
        case 3: cout << "Середа"; break;
        default: cout << "Невідомий день";
    }



    // Switch with enum
    enum PlayerStatus {
        Online, Offline, Unknown
    };

    PlayerStatus status = Online;
    switch (status) {
    case Online: cout << "Гравець в мережі" << endl;
    case Offline: cout << "Гравець не в мережі" << endl;
    default: cout << "Статус гравця невідомий" << endl;
    }

    return 0;
}

