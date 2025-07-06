#include <iostream>
#include <Windows.h>

using namespace std;

void printHello() 
{
    cout << "Привіт!" << endl;
}

int getRandomNumber() {
    srand(time(nullptr));

    return rand();
}

void printNumber(int number) {
    cout << number << endl;
}

int sum(int left, int right) {
    return left + right;
}

void swapVars(int a, int b) {
    int temp = a;
    a = b;
    b = a;
}

void prototypeFunction(char parameter);

void reverseArray(int arr[], int size) {
    for (int i = 0, j = size - 1; i < size / 2; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int global = 10; // Глобальна область видимості - доступна в усьому файлі

void printSymbol(char symbol = 'A') {
    cout << symbol << endl;
}

int main()
{
    printSymbol();
    printSymbol('B');

    int localMain = 15; // Локальна область видимості - доступна тільки у функції main

    if (localMain == global) {
        int localIf = 10; // Локальна область видимості - доступна тільки всередині цього if-виразу
    }

    prototypeFunction('A');

    const int size = 5;
    int arr[size] = { 10, 15,43,-10, 5 };

    printArray(arr, size);
    reverseArray(arr, size);
    printArray(arr, size);
}

void prototypeFunction(char parameter) {
    cout << "Prototype Function" << endl;
}

