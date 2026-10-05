#include <iostream>
#include <string>
#include <fcntl.h> // Для _O_U16TEXT
#include <io.h>    // Для _setmode і _fileno

int main()
{
    {
        // Basics
        std::string str = "Hello, World!";
        std::cout << str << '\n';

        std::cout << "String length: " << str.length() << '\n';
        std::cout << "String size: " << str.size() << '\n';
        std::cout << "String capacity: " << str.capacity() << '\n';
    }

    {
        // Indexing
        std::string str = "Hello, World!";

        std::cout << "First symbol: " << str[0] << '\n';
        std::cout << "Last symbol: " << str[str.length() - 1] << '\n';

        std::cout << str.at(0) << '\n';
        std::cout << str.at(str.length() - 1) << '\n';

        // Undefiened behavoiur
        std::cout << str[100] << '\n';

        // out_of_range exception
        // std::cout << str.at(100) << '\n';

        str[3] = 'h';
        std::cout << str << '\n';

        str.at(3) = 'r';
        std::cout << str << '\n';
    }

    {
        // Concatenation
        std::string firstName = "John";
        std::string lastName = "Doe";

        std::string fullName = firstName + " " + lastName;

        std::string greeting = "Hello";
        greeting += ", ";
        greeting += "World!";

        std::string text = "Error: ";
        std::string details = "File not found in the directory.";

        text.append("Code 404. ");
        text.append(details, 0, 14);
        text.append(3, '!');
    }

    {
        // Empty string
        std::string str = "";

        if (str.empty())
            std::cout << "String is empty\n";
        else
            std::cout << "String is not empty\n";
    }

    {
        // Comparison
        std::string str1 = "apple";
        std::string str2 = "APPLE";

        auto result = (str1 <=> str2);

        if (result > 0)
            std::cout << str1 << " greater then " << str2 << '\n';
        else if (result < 0)
            std::cout << str1 << " less then " << str2 << '\n';
        else
            std::cout << str1 << " equals " << str2 << '\n';
    }

    {
        // Search
        std::string str = "Hello, World";
        size_t pos = str.find("World");

        if (pos != std::string::npos)
            std::cout << "Found 'World'. Index: " << pos << '\n';
        else
            std::cout << "'World' not found\n";

        std::string subStr = str.substr(0, 5);
        std::cout << "Substring: " << subStr << '\n';
    }

    {
        // Modifications
        std::string str = "I love JavaScript";
        str.replace(7, 10, "C++");

        str = "Hello, World!";
        str.insert(5, " Beautiful");
        std::cout << str << '\n';

        str.erase(5, 10);
        std::cout << str << '\n';
    }

    {
        // Type casting
        std::string strInt = "12345";
        int number = std::stoi(strInt);

        std::string strDouble = "123.45";
        double dNumber = std::stod(strDouble);

        std::string intStr = std::to_string(number);
        std::string doubleStr = std::to_string(dNumber);
        std::cout << intStr << ' ' << strDouble << '\n';
    }

    {
        // Input string
        int age;
        std::cin >> age;

        std::cin.ignore();

        std::string name;
        std::getline(std::cin, name);
        std::cout << age << ' ' << name << '\n';
    }

    {
        std::string name = "John";
        int age = 30;

        std::string result = std::format("User {} is {} years old.", name, age);
    }

    {
        // string and Encoding

        std::string str = "Привіт";

        std::cout << str.length() << '\n'; // 12
    }

    {
        // wstring
        // _setmode(_fileno(stdout), _O_U16TEXT);

        // std::wstring text = L"Привіт";

        // std::wcout << text << L'\n';
    }

    {
        std::u8string jsonMessage = u8"{\"status\": \"Успіх 🚀\"}";

        std::u16string winWindowName = u"Моя програма для Windows";

        std::u32string exactText = U"Текст для посимвольного аналізу 🧑‍💻";
        size_t count = exactText.length();
    }

    return 0;
}