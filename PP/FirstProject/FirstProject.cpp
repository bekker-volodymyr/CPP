#include <iostream>

using namespace std;

enum Color { Red = 5, Green = 10, Blue = 15 };

int main()
{
    int x = 5;
    int y = x++;  // x = 6, y = 5

    cout << y;
}
