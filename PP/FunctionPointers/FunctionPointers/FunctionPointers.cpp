#include <iostream>
#include <Windows.h> // Цей заголовок використовується для функцій, що працюють з консоллю Windows

using namespace std;

// Шаблонна функція 'add', яка автоматично визначає тип повернення
// за допомогою 'decltype(a + b)', що дозволяє додавати різні типи даних.
template<typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

// Проста функція Foo
void Foo() {
    // Просто функція
}

// Прототипи функцій для перевантаження 'sum' та інших арифметичних операцій
int sum(int, int);
double sum(double, double);
double substruct(double, double);
double multiply(double, double);
double divide(double, double);

int main()
{
    // Встановлення кодування консолі для коректного відображення українських символів
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Виведення адреси функції Foo
    cout << "Адреса функції Foo: " << (void*)Foo << endl; // Приведення до (void*) для коректного виведення адреси

    // Дужки навколо назви покажчика обов'язкові!
    // Без дужок компілятор сприйматиме запис
    // як прототип функції, що повертає покажчик на int
    int (*sumptr) (int, int) = sum; // Оголошення та ініціалізація покажчика на функцію 'sum' (з цілими числами)

    // Виклик функції через покажчик
    cout << sumptr(10, 12) << endl; // Виклик функції 'sum' через покажчик

    // Масив покажчиків на функції,
    // що повертають тип double та приймають два параметри типу double
    double (*calcptr[])(double, double) = { sum, substruct, multiply, divide }; // Ініціалізація масиву покажчиків

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

    // Виклик відповідної функції через масив покажчиків
    cout << (*calcptr[choice - 1])(a, b) << "\n";

    // Використання 'auto' та 'decltype'
    auto a1 = 0; // 'a1' буде мати тип 'int'
    decltype (a1) a2 = a1; // 'a2' матиме той самий тип, що й 'a1' (тобто 'int'). Те саме, що й 'auto a2=a1;'

    auto x = 5;      // 'x' буде 'int'
    auto y = 3.14;   // 'y' буде 'double'
    auto z = x + y;  // 'z' буде 'double', оскільки 'int + double = double' (автоматичне підвищення типу)

    int num_a = 10; // Перейменував змінну, щоб уникнути конфлікту імен з 'a' вище
    decltype(num_a) num_b; // 'num_b' матиме тип 'int', як і 'num_a'
    
    // Тип 'w' буде 'double',
    // але без ініціалізації
    decltype(x + y) w; // 'w' матиме тип 'double', як результат виразу 'x + y'
    
    return 0; // Гарна практика - повертати 0 з main, якщо програма завершилась успішно
}

// Визначення функції 'sum' для цілих чисел
int sum(int a, int b) {
    return a + b;
}

// Визначення функції 'sum' для чисел з плаваючою комою (перевантаження)
double sum(double a, double b) {
    return a + b;
}

// Визначення функції 'substruct'
double substruct(double a, double b) {
    return a - b;
}

// Визначення функції 'multiply'
double multiply(double a, double b) {
    return a * b;
}

// Визначення функції 'divide'
double divide(double a, double b) {
    if (b == 0) return NULL; // Повернення NULL при діленні на нуль. Краще викинути виняток або повернути NaN.
    return a / b;
}
