#include <iostream>
#include <Windows.h>

using namespace std;

void Foo() {
    // Якась функція
}

int sum(int, int);

double sum(double, double);
double substruct(double, double);
double multiply(double, double);
double divide(double, double);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "Адреса функції Foo: " << Foo << endl;

    // Дужки навколо назви покажчика обов'язкові
    // Без дужок компілятор сприйматиме запис 
    // як прототип функції, що повертає покажчик на int
    int (*sumptr) (int, int) = sum;

    // Виклик функції через покажчик
    cout << sumptr(10, 12) << endl;


    // Масив покажчиків на функції, 
    // що повертають тип double та приймають два параметри типу double
    double (*calcptr[])(double, double) = { sum, substruct, multiply, divide };

    double a, b;
    int choice;

    cout << "Введіть число a: ";
    cin >> a;
    cout << "Введіть число b: ";
    cin >> b;

    cout << "Оберіть операцію:\n";
    cout << "1. Сума\n";
    cout << "2. Різниця\n";
    cout << "3. Добуток\n";
    cout << "4. Ділення\n";
    cout << "Введіть номер операції: ";
    cin >> choice;

    cout << (*calcptr[choice - 1])(a, b) << "\n";

    // auto та decltype
    auto a1 = 0; //int
    decltype (a1) a2 = a1; // те саме, що й auto a2=a1;
    typedef decltype (a1) АTYPE; //АTYPE є синонімом int
    ATYPE а3 = 5;

}

int sum(int a, int b) {
    return a + b;
}

double sum(double a, double b) {
    return a + b;
}

double substruct(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) return NULL;
    return a / b;
}
