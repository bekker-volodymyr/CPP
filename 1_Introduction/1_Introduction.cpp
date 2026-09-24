#include <iostream> // Preprocessor directive: add iostream library
#include <Windows.h> // add WinApi library

using namespace std;

namespace MyNamespace {
    int intVar = 10;
    char charVar = 'C';
    const float floatConst = 12.5;
}

int main() // main function - entry point to our code
{
    SetConsoleCP(1251); // Set encoding for input to 1251
    SetConsoleOutputCP(1251); // Set encoding for output to 1251

    int number; // Create variable without initialization
    number = 12; // Set variable value to 12
    number = 14; // Set new value to variable

    bool boolean = true; // Create and initialize variable 

    const int constant = 12;
    constant = 15; // ERROR: Can't change value of const

    cout << "Forget semicolon\n"

    std::cout << "Hello World!\n";

    std::cout << 10 + 12 << '\n';
}