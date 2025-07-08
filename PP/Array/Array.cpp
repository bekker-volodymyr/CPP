#include <iostream>
#include <Windows.h>
#include <cstdlib> // Для rand(), srand()
#include <ctime>   // Для time()

using namespace std;

int main() {
    SetConsoleOutputCP(1251); // Для виводу українських символів

    // 📌 Оголошення масивів різних типів
    int intArr[5];
    char charArr[4];
    double doubleArr[10];

    intArr[0] = 10;
    charArr[1] = 'A';

    int arr[3] = {1, 2, 3};

    // ❗ Увага: доступ до arr[3] — вихід за межі, undefined behavior
    cout << "arr[3]: " << arr[3] << endl;

    // Масив з фіксованим розміром
    const int size = 3;
    double br[size];

    // Ініціалізація при створенні
    int ints[] = { 2, 10, -1 };
    bool booleans[] = { true, false, true };
    int floats[5] = { 1, 3, 4 }; // Інші два значення — сміття

    // 🔄 Заповнення масиву за допомогою циклу
    const int size_arr = 5;
    int numbers[size_arr];
    for (int i = 0; i < size_arr; ++i) {
        numbers[i] = i + 1;
    }

    // 🔢 Обчислення суми елементів
    int nums[] = { 10, -11, 43, 0, -10 };
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += nums[i];
    }
    cout << "\nСума: " << sum << endl;

    // 🔁 Вивід через range-based for
    for (auto item : nums) {
        cout << item << " ";
    }
    cout << endl;

    // 🎲 Генерація випадкових чисел
    srand(time(nullptr)); // Установка seed

    int r = rand(); // Випадкове число (0 до RAND_MAX)
    cout << "rand(): " << r << endl;

    // Генерація числа в межах
    r = rand() % 100;        // 0–99
    int r2 = rand() % 100 + 1; // 1–100
    int min = 10, max = 200;
    int r3 = rand() % (max - min + 1) + min; // В межах [min, max]

    // 🧮 Двовимірний масив (матриця)
    int matrix[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    matrix[0][1] = -2;
    cout << "matrix[2][3]: " << matrix[2][3] << endl;

    // 🔁 Вивід усієї матриці
    cout << "\nМатриця:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 🔄 Ініціалізація матриці випадковими числами
    cout << "\nРандомна матриця:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = rand() % 10;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
