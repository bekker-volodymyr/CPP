#include <iostream>
#include <Windows.h>

#include "Header.h"
#include "Header.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    TestFunc();
}


//#define PI 3.1425
//
//#define TEST 10     // Визначаємо константу TEST
//int number = TEST;  // Використовуємо значення
//#undef TEST         // Прибираємо визначення константи
//
//#define TEST "C++"  // Визначаємо константу TEST з новим значенням
//const char* str = TEST; 
//#undef TEST
//
//#define STR "Дуже довгий рядковий літерал з купою символів "\
//    "який потрібно розбити на декілька рядків"
//
//
//int main()
//{
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);
//
//    cout << "Препроцесор" << endl;
//
//    cout << "Константа PI: " << PI << '\n';
//
//    cout << STR << '\n';
//
//#if 15 + 10
//    cout << "Цей код зкомпілюється тільки якщо 15+10 != 0\n";
//#endif
//
//
//
//#ifdef TEST
//    cout << "Цей код зкомпілюється тільки якщо "\
//        "константа TEST була визначена директивою #define\n";
//#endif
//
//}
