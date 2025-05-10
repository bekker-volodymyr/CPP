#include <iostream>
#include <Windows.h>

using namespace std;

// Створення макровизначень
// Вирази, що будуть підставлені в місце використання етапі обробки препроцесором
#define SQR(X) ((X) * (X))
#define CUBE(X) (SQR(X) * (X))

// Оголошення вбудованої функції - буде підставлена в місце виклику під час компіляції
inline int add(int a, int b) { return a + b; }

// Шаблонна функція
template <typename T> T Multiply(T left, T right) {
	return left * right;
}

// Рекурсія - розрахунок факторіалу
int factorial(int n) {
	if (n == 0) return 1;			// базовий випадок
	return n * factorial(n - 1);	// рекурсивний виклик
}

// Рекурсія - числа Фібоначчі
int fibonacci(int n) {
	if (n <= 1) return n;						// базовий випадок
	return fibonacci(n - 1) + fibonacci(n - 2); // рекурсивний виклик
}

int main()
{
	SetConsoleOutputCP(1251);

	// Використання inline-функції
	add(10, 12);

	// Використання макровизначень
	cout << SQR(10) - CUBE(5) << endl;

	// Використання шаблонної функції
	Multiply(10, 12);		// int
	Multiply(10.5, 14.6);	// double
	Multiply('3', 'y');		// char
	Multiply(true, false);	// bool

	// Числа Фібоначчі - початок рекурсії
	cout << "Число Фібоначчі " << 6 << " = " << fibonacci(6) << '\n';
}