#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    ////cout << (int)'B' << endl;
    ////cout << (int)'+' << endl;

    //char16_t emoji16 = u'你';
    //char32_t emoji32 = U'😄';  // Один символ в UTF-32

    ////std::cout << "Emoji char16_t: U+" << static_cast<int>(emoji16) << std::endl;
    ////std::cout << "Emoji char32_t: U+" << static_cast<int>(emoji32) << std::endl;

    //char string[6] = "qwert";
    //char* ptr = string;

    ////cout << string[1] << endl;
    ////cout << (int)string[5] << endl;

    //char str[] = "звідки гроші в тумбочкє";
    ////cout << "Довжина рядка: " << strlen(str) << endl;

    //char str1[] = "бомбардіро", str2[] = " крокаділо";
    //size_t size = strlen(str1) + strlen(str2) + 1;
    //char* buffer = new char[size];
    //buffer[0] = '\0';

    //strcat_s(buffer, size, str1);
    //strcat_s(buffer, size, str2);

    //cout << buffer << std::endl;

    //delete[] buffer; // не забудь звільнити пам'ять

    //const char* src = "бомбардіро-крокаділо";
    //char dest[50]; // Достатньо великий буфер

    //errno_t result = strcpy_s(dest, sizeof(dest), src);

    //if (result == 0) {
    //    cout << "Копія: " << dest << std::endl;
    //}
    //else {
    //    cout << "Помилка копіювання!" << std::endl;
    //}

    //const char* a = "яблуко";
    //const char* b = "банан";

    //int result = strcmp(a, b);

    //if (result == 0) {
    //    cout << "Рядки однакові" << std::endl;
    //}
    //else if (result < 0) {
    //    cout << "\"" << a << "\" менше за \"" << b << "\"" << std::endl;
    //}
    //else {
    //    cout << "\"" << a << "\" більше за \"" << b << "\"" << std::endl;
    //}


    //const char* text = "бомбардіро-крокаділо"; // рядок, в якому шукаємо символ
    //const char target = 'к'; // символ, що шукаємо

    //const char* found = strchr(text, target); // отримуємо адресу символа, який шукаємо

    //if (found) {
    //    cout << "Знайдено символ " << target << " на позиції: " << (found - text) << endl;
    //}
    //else
    //{
    //    cout << "Символ не знайдено" << endl;
    //}

    //const char* text = "бомбардіро-крокаділо"; // рядок, в якому шукаємо символ
    //const char* target = "бардіро"; // символ, що шукаємо

    //const char* found = strstr(text, target); // отримуємо адресу символа, який шукаємо

    //if (found) {
    //    cout << "Знайдено символ " << target << " на позиції: " << (found - text) << endl;
    //}
    //else
    //{
    //    cout << "Символ не знайдено" << endl;
    //}

    /*char text[] = "BoMbArDiRo-KrOkAdILo";

    cout << "До: " << text << endl;
    errno_t result = _strlwr_s(text);
    if (!result) {
        cout << "Після: " << text << endl;
    }

    cout << "До: " << text << endl;
    result = _strupr_s(text);
    if (!result) {
        cout << "Після: " << text << endl;
    }*/

    //char text[] = "бомбардіро";

    //cout << "До: " << text << endl;
    //_strnset_s(text, '*', 5); // замінить перші 5 символів на '*'
    //cout << "Після: " << text << endl;

    //int i = 42;
    //float f = 3.1415;
    //char c = 'A';
    //char s[] = "Hello";

    //printf("Ціле: %d\n", i);           // %d — ціле число
    //printf("Дрібне: %.2f\n", f);       // %.2f — дробове з 2 знаками після коми
    //printf("Символ: %c\n", c);         // %c — символ
    //printf("Рядок: %s\n", s);          // %s — рядок
    //printf("Шістн.: %x\n", i);         // %x — шістнадцяткове
    //printf("З вирівнюванням: %10d\n", i); // ширина поля
    //printf("З нулями: %010d\n", i);    // заповнення нулями


    //char fullName[25];
    //cout << "Input your full name: ";
    //cin >> fullName;
    //cout << "Welcome, " << fullName << endl;

    //int age;
    //float height;
    //char grade;
    //char name[50];

    //printf("Введи вік: ");
    //scanf_s("%d", &age);             // ціле

    //printf("Введи зріст: ");
    //scanf_s("%f", &height);          // дробове

    //printf("Введи оцінку (символ): ");
    //scanf_s(" %c", &grade);          // символ (пробіл перед %c обов’язковий!)

    //int misChar = getchar(); // читає залишений '\n'

    //printf("Введи ім’я: ");
    //scanf_s("%s", name, sizeof(name));             // рядок (без пробілів)

    //printf("Ти: %s, %d років, %.1f см, оцінка: %c\n", name, age, height, grade);

    //char name[50];

    //printf("Введи ім’я: ");
    //fgets(name, sizeof(name), stdin);

    //printf("Привіт, %s", name); // name вже містить '\n'

    // int* arr = (int*)malloc(10 * sizeof(int));

    // int* arr = (int*)calloc(10, sizeof(int));

    /*int* arr = (int*)malloc(5 * sizeof(int));
    arr = (int*)realloc(arr, 10 * sizeof(int));*/

    int* arr = (int*)malloc(10 * sizeof(int));
    // ... використання arr
    free(arr);

}
