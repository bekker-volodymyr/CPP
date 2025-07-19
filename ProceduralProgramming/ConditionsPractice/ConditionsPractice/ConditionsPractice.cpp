#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Task 8
    int number;
    int power;

    cout << "Ââåä³òü ÷èñëî: ";
    cin >> number;
    cout << "Ââåä³òü ñòóï³íü: ";
    cin >> power;

    int result;
    switch (power) {
    case 0: result = 1; break;
    case 1: result = number; break;
    case 2: result = number * number; break;
    case 3: result = number * number * number; break;
    case 4: result = number * number * number * number; break;
    case 5: result = number * number * number * number * number; break;
    case 6: result = number * number * number * number * number * number; break;
    case 7: result = number * number * number * number * number * number * number; break;
    default: result = -1; break;
    }

    if (result == -1) {
        cout << "Ââåäåíî ñòóï³íü, ùî íå ï³äòğèìóºòüñÿ" << endl;
    }
    else {
        cout << "Ğåçóëüòàò äîğ³âíşº: " << result << endl;
    }

    // cout << "Ğåçóëüòàò äîğ³âíşº: " << pow(number, power);

    return 0;
}