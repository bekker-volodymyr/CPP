#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Отримання коду символу
    cout << "Код символу 'B': " << (int)'B' << '\n';
    cout << "Код символу '+': " << (int)'+' << '\n';
    cout << "Код символу '?': " << (int)'?' << '\n';
    
}