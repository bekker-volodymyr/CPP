#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);

    // Оголошення масиву
    // тип ідентифікатор[кількість_елементів]
    int intArr[5];          // масив що може зберігати 5 цілих чисел
    char charArr[4];        // масив що може зберігати 4 символи
    double doubleArr[10];   // масив що може зберігати 10 дробних чисел

    intArr[0] = 10;     // записуємо в перший елемент масиву число 10
    //cout << intArr[0];  // виводимо на екран перший елемент масиву

    charArr[1] = 'A';   // записуємо в другий елемент масиву символ А

    int arr[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    
    arr[3] = 4; // помилка при спробі запису (режим Debug). Немає помилки в режимі Release!
    cout << arr[3] << endl; // Вивід сміттєвого значення - неініціалізованої пам'яті

    const int size = 3; // Оголошуємо константу для розміру масиву
    double br[size];    // Оголошуємо масив на 3 елементи

    const int arr_size = 3; // Оголошуємо розмір масиву
    int ints[arr_size] = { 2, 10, -1 }; // Створюємо масив та одразу записуємо значення
    bool booleans[] = { true, false, true }; // Компілятор визначає кількість елементів сам

    int floats[5] = { 1, 3, 4 }; // Елементи без ініціалізації будуть містити сміття
    
    // Ініціалізація за допмогою циклу    
    const int size_arr = 5;
    int numbers[size_arr];

    for (int i = 0; i < size_arr; ++i) {
        numbers[i] = i + 1;
    }

    // Підрахунок суми
    const int s = 5;
    int nums[s] = { 10, -11, 43, 0, -10 };
    int sum = 0;

    for (int i = 0; i < s; i++) {
        sum += nums[i];
    }
    cout << endl;
}
