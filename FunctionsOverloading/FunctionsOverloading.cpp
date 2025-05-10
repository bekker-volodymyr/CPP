#include <iostream>
#include <Windows.h>

using namespace std;

// Прототипи перевантажених функцій
long sum(long, long);
int sum(int, int);
float sum(float, float);
double sum(double, double);

int findMax(int, int);
int findMax(int, int, int);
int findMax(int[], int);
double findMax(double, double);
double findMax(double[], int);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Використання перевантажених функцій
    cout << "Сума long:" << sum(34521L, 223423423543L) << '\n';
    cout << "Сума int:" << sum(1, 2) << '\n';
    cout << "Сума float:" << sum(1.32f, 3.45f) << '\n';
    cout << "Сума double:" << sum(1.645435345, 2.532124213411234) << '\n';
}

// Реалізація перевантажених функцій
long sum(long a, long b) {
    return a + b;
}

int sum(int a, int b) {
    return a + b;
}

float sum(float a, float b) {
    return a + b;
}

double sum(double a, double b) {
    return a + b;
}

int findMax(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

int findMax(int num1, int num2, int num3) {
    return num1 > num2 ? 
        (num1 > num3 ? num1 : num3) : 
        (num2 > num3 ? num2 : num3);
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

double findMax(double num1, double num2) {
    return num1 > num2 ? num1 : num2;
}

double findMax(double arr[], int size) {
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}