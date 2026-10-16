#include <iostream>
#include <windows.h>
#include <io.h>    // Для _setmode
#include <fcntl.h> // Для _O_U16TEXT
#include <string>
#include <codecvt>
#include <locale>

#include "main.h"

int main(int argc, char **argv)
{
    // ChangeConsoleEncoding();
    // CharTypeExample();
    // WideCharExample();
    // Char8Example();
    // Char16Example();
    // Char32Example();

    // CharArrayExample();

    // char str[] = "some string";
    // std::cout << MyStrlen(str) << '\n';

    // CinInputStrExample();
    // CinGetlineExample();

    char buffer[256];

    std::cout << "Enter your username: ";
    std::cin.getline(buffer, 256);

    int size = MyStrlen(buffer) + 1;
    char *username = new char[size];

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        username[i] = buffer[i];
    }
    username[size - 1] = '\0';

    std::cout << username << '\n';

    delete[] username;

    return 0;
}

void CinGetlineExample()
{
    char fullName[50];
    std::cout << "Enter your full name (max 50 symbols): ";
    std::cin.getline(fullName, 50);
    std::cin.clear();

    std::cout << "Hello, " << fullName << '\n';

    char birthDate[11];
    std::cout << "Enter your birth date (dd.mm.yyyy): ";
    std::cin.getline(birthDate, 11);
    std::cin.clear();

    std::cout << "Your birth date is: " << birthDate << '\n';
}

void CinInputStrExample()
{
    char fullName[50];
    std::cout << "Enter your full name: ";
    std::cin >> fullName;

    std::cout << "Hello, " << fullName << '\n';

    char birthDate[11];
    std::cout << "Enter your birth date (dd.mm.yyyy): ";
    std::cin >> birthDate;

    std::cout << "Your birth date is: " << birthDate << '\n';
}

int MyStrlen(const char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        len++;

    // for (char *ptr = str; *ptr != '\0'; ptr++)
    //     len++;

    return len;
}

void CharArrayExample()
{
    std::cout << "Cat" << '\n';

    char name[] = "Anton";
    std::cout << name << '\n';
    std::cout << name[3] << '\n';
    std::cout << (int)name[5] << "\n";
}

void Char32Example()
{
    SetConsoleOutputCP(CP_UTF8);

    char32_t emoji = U'🍕';

    // 1. Стандартні потоки не вміють виводити char32_t напряму.
    // Тому ми обгортаємо цей один символ у рядок std::u32string
    std::u32string u32_str(1, emoji);

    // 2. Створюємо конвертер, який перетворить UTF-32 на UTF-8
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;

    // 3. Виконуємо конвертацію. Один 4-байтовий char32_t
    // перетворюється на масив зі звичайних char (байти UTF-8)
    std::string utf8_str = converter.to_bytes(u32_str);

    // 4. Тепер cout бачить звичайний рядок і без проблем його виводить
    std::cout << "Ось наш символ: " << utf8_str << std::endl;
}

void Char16Example()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    char16_t letter = u'Ї';
    // Кастуємо char16_t у wchar_t (бо вони обидва по 2 байти на Windows)
    std::wcout << static_cast<wchar_t>(letter) << std::endl;
}

void Char8Example()
{
    char8_t letter = u8'A';
    // Кастуємо до char, щоб cout зрозумів, що це літера, а не число
    std::cout << static_cast<char>(letter) << std::endl;
}

void WideCharExample()
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    wchar_t letter = L'Ї';
    std::wcout << letter << '\n';
}

void CharTypeExample()
{
    char symbol = 'U';
    std::cout << symbol << '\n';
    std::cout << (int)symbol << '\n';
    std::cout << sizeof(char) << '\n';
}

void ChangeConsoleEncoding()
{
    // Підключення кириличної таблиці
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Альтернатива: перемикаємо на UTF-8 (найкраща практика для сучасного C++)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    SetConsoleOutputCP(65000);
    SetConsoleCP(65000);
}
