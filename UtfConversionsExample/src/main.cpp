#include <iostream>
#include <string>
#include <Windows.h>

std::wstring utf8_to_utf16(const std::string &utf8Str)
{
    if (utf8Str.empty())
        return L"";

    int size = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, nullptr, 0);
    std::wstring result(size, 0);

    MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, &result[0], size);
    return result;
}

int main(int argc, char **argv)
{
    std::string message = "Привіт! Це повідомлення українською.";
    std::string title = "Успішна конвертація";

    std::wstring wMessage = utf8_to_utf16(message);
    std::wstring wTitle = utf8_to_utf16(title);

    MessageBoxW(nullptr, wMessage.c_str(), wTitle.c_str(), MB_OK | MB_ICONINFORMATION);
    return 0;
}
