#include <iostream>
#include <Windows.h>

using namespace std;

void SetUkrEncoding();

void ChangeValue(int* value);

template <typename T> void SwapValues(T* value1, T* value2);

int main()
{
	SetUkrEncoding();

	int x = 100;

	cout << "Адреса змінної 'x' у пам'яті: " << &x << endl;

	int* ptrx = &x;

	cout << "Покажчик 'ptrx' зберігає адресу: " << ptrx << endl;

	cout << "За адресою, що зберігає покажчик 'ptrx' знаходиться значення: " << *ptrx << endl;

	*ptrx = 150;

	cout << "Значення змінної 'x' тепер дорівнює: " << x << endl;

	*ptrx -= 15;

	cout << "Значення змінної 'x' тепер дорівнює: " << x << endl;

	int a = -1;

	ptrx = &a;

	cout << "Покажчик 'ptrx' тепер вказує на ділянку за адресою: " << ptrx << endl;
	cout << "За адресою, що зберігає покажчик 'ptrx' знаходиться значення: " << *ptrx << endl;

	cout << endl;

	int value = 15;

	int* ptr1 = &value;
	int* ptr2 = &value;

	cout << "Адреса у 'ptr1': " << ptr1 << endl;
	cout << "Адреса у 'ptr2': " << ptr2 << endl;

	int arr[] = { 1, 2, 3, 4, 5 };

	int* arrPtr = &arr[0];

	for (int i = 0; i < 5; i++) {
		cout << i << " елемент масиву: " << *(arrPtr + i) << " знаходиться за адресою: " << arrPtr + i << endl;
	}

	int value1 = 10;
	int value2 = 12;

	cout << "Значення до зміни місцями: " << endl;
	cout << "\tvalue1: " << value1 << endl;
	cout << "\tvalue2: " << value2 << endl;

	SwapValues(&value1, &value2);

	cout << "Значення після зміни місцями: " << endl;
	cout << "\tvalue1: " << value1 << endl;
	cout << "\tvalue2: " << value2 << endl;

	int number = 10;

	cout << "'number' дорівнює: " << number << endl;
	ChangeValue(&number);
	cout << "'number' дорівнює: " << number << endl;

	double* ptrD = 0;
	ptrD = NULL; // Спосіб з C - замість NULL підставляється 0
	ptrD = nullptr; // Спосіб С++

	cout << ptrD << endl; 
}

template <typename T> void SwapValues(T* value1, T* value2) 
{
	T temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

void ChangeValue(int* value) {
	*value += 10;
}

void SetUkrEncoding() 
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
}
