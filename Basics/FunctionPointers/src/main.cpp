#include <iostream>
#include <Windows.h>

void Foo()
{
    // some function
}

int sum(int, int);

double sum(double, double);
double substruct(double, double);
double multiply(double, double);
double divide(double, double);

typedef int (*MapCallback)(int);

void map(const int *src, int *dest, size_t size, MapCallback callback)
{
    for (size_t i = 0; i < size; i++)
    {
        dest[i] = callback(src[i]);
    }
}

int multiply_by_two(int n)
{
    return n * 2;
}

int square(int n)
{
    return n * n;
}

int main()
{
    std::cout << "Address of Foo: " << Foo << '\n';

    int (*sumptr)(int, int) = sum;

    std::cout << sumptr(10, 12) << '\n';

    double (*calcptr[])(double, double) = {sum, substruct, multiply, divide};

    double a, b;
    int choice;

    std::cout << "Enter number a: ";
    std::cin >> a;
    std::cout << "Enter number b: ";
    std::cin >> b;

    std::cout << "Choose operation:\n";
    std::cout << "1. Sum\n";
    std::cout << "2. Subtruct\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "Result: ";
    std::cin >> choice;

    std::cout << (*calcptr[choice - 1])(a, b) << "\n";
}

int sum(int a, int b)
{
    return a + b;
}

double sum(double a, double b)
{
    return a + b;
}

double substruct(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0)
        return NULL;
    return a / b;
}
