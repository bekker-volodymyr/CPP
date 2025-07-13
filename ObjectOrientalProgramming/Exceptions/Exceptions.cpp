/*
  * Винятки — спеціальні об'єкти, що генеруються у разі виняткової ситуації в коді (помилки).
*/

#include <iostream>
#ifdef _WIN32 // Підключаємо Windows API тільки для Windows
#include <Windows.h>
#endif

#include "MyException.h"
#include "Printer.h"

using namespace std;

float Divide(float a, float b);

void lowLevelTask(int a, int b);
void midLevelWrapper(int a, int b);

int main()
{
#ifdef _WIN32 // Встановлюємо кодування тільки на Windows
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    {
		// Базовий приклад синтаксису try-catch для обробки винятків
        try {
            // Блок коду, який може викликати виняток

            throw "Сталась помилка!"; // Генерація винятку
        }
        catch (const char* e) {
            // Блок коду для обробки винятку
			cerr << e << '\n'; // Виведення повідомлення про помилку
        }
    }

    {
        // Генерація винятку
        
        // Спроба доступу до елемента, який не існує
		// Без обробки винятків -> аварійне завершення програми
        // cout << str.at(4) << '\n';

        string str = "four";

        try {
			cout << str.at(4) << '\n'; // Спроба доступу до елемента, який не існує
        }
        catch (...) // Блок catch для обробки будь-якого винятку
        {
            cout << "Виключення!" << endl;
		}
    }

    {
		// Відловлювання декількох типів винятків
        try {
            switch (rand() % 3)
            {
                case 0:
                    // Генерація винятку типу int
					throw 101; 
				case 1:
                    // Генерація винятку типу const char*
					throw "Помилка!";
				case 2:
                    // Генерація винятку типу runtime_error
					throw runtime_error("Помилка виконання!"); 
            default:
				throw exception(); // Генерація загального винятку
            }
        }
        catch(int e) {
            // Обробка винятку типу int
            cout << "Виняток типу int: " << e << endl;
        }
        catch (const char* e) {
            // Обробка винятку типу const char*
            cout << "Виняток типу const char*: " << e << endl;
        }
        catch (const runtime_error& e) {
            // Обробка винятку типу runtime_error
            cout << "Виняток типу runtime_error: " << e.what() << endl;
		}
        catch(...) {
            // Обробка будь-якого іншого винятку
            cout << "Виник виняток невідомого типу!" << endl;
		}
    }

    {
        try {
            switch (rand() % 3)
            {
            case 0:
                // Генерація винятку типу int
                throw out_of_range("Out of range exception");
            case 1:
                // Генерація винятку типу const char*
                throw logic_error("Logic error exception");
            default:
                throw exception(); // Генерація загального винятку
            }
        }
        catch(out_of_range& e) {
            // Обробка винятку out_of_range
            cout << "Виняток out_of_range: " << e.what() << endl;
        }
        catch (logic_error& e) {
			// Обробка винятку logic_error
			cout << "Виняток logic_error: " << e.what() << endl;
        }
        catch (exception& e) {
            // Обробка загального винятку
            cout << "Виняток: " << e.what() << endl;
        }
    }

    {
        try {
			Divide(10, 0); // Спроба ділення на нуль
        }
        catch(const domain_error& e) {
            // Обробка винятку domain_error
            cout << "Виняток domain_error: " << e.what() << endl;
        }
    }

    {
        try
        {
            midLevelWrapper(10, 0);
        }
        catch (const exception& e)
        {
            cerr << "[main] Остаточна обробка: " << e.what() << '\n';
        }
    }

    {
		// Використання власного винятку MyException
        try {
            throw MyException(); // Генерація власного винятку
        }
        catch (const MyException& e) {
            // Обробка власного винятку
            cout << "Виняток MyException: " << e.what() << endl;
		}
    }

    {
		Printer printer("HP LaserJet", 5); // Створення об'єкта принтера з 5 аркушами паперу
        try {
            printer.print("Hello, world!"); // Друк документа
            printer.print("Це великий документ для якого потрібно багато паперу.");
        }
        catch (const PrinterException& e) {
            // Обробка винятку PrinterException
            cerr << "Помилка друку: " << e.what() << endl;
        }
    }
}

float Divide(float a, float b) {
    if (b == 0) {
        throw domain_error("Ділення на нуль!"); // Генерація винятку
    }
    return a / b; // Повернення результату ділення
}

void lowLevelTask(int a, int b) {
    if (b == 0)
        throw runtime_error("Ділення на 0");
    cout << "Результат: " << a / b << '\n';
}

void midLevelWrapper(int a, int b) {
    try
    {
        lowLevelTask(a, b);
    }
    catch (const exception& e)
    {
        cerr << "[mid] Логую: " << e.what() << '\n';
        throw; // повторно кидаємо тому, хто вище
    }
}