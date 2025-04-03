#include <iostream>
#include <Windows.h>

#define SQR(X) ((X) * (X))
#define CUBE(X) (SQR(X) * (X))

using namespace std;

inline int add(int a, int b) { return a + b; }

template <typename T> T Multiply(T left, T right) {
	return left * right;
}

int factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

int fibonacci(int n) {
	if (n <= 1) return n; // Базові випадки
	return fibonacci(n - 1) + fibonacci(n - 2); // Рекурсивний виклик
}

int main()
{
	SetConsoleOutputCP(1251);

	Multiply(10, 12);
	Multiply(10.5, 14.6);
	Multiply('3', 'y');
	Multiply(true, false);

	add(10, 12);

	cout << SQR(10) - CUBE(5) << endl;

	cout << "Число Фібоначчі " << 6 << " = " << fibonacci(6) << endl;
}