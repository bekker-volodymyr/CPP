#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <io.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "Приклади роботи з файлами інструментами бібліотеки stdio\n";

    {
        cout << '\n';
        // Покажчик на файлову структуру
        FILE* f;
        // Відкриття файлу
        errno_t err = fopen_s(&f, "test.bin", "wb");

        // Перевірка успішності відкриття файлу
        if (err) {
            cout << "Не вийшло відкрити файл\n";
        }
        else {
            cout << "Записуємо в файл...\n";

            char str[] = "some text that will be written to the file";
            // Запис інформації до файлу
            fwrite(&str, sizeof(char), strlen(str), f);

            cout << "Запис пройшов успішно!\n";
            // Закриття файлу
            fclose(f);
        }
        cout << '\n';
    }

    {
        cout << '\n';

        FILE* f;
        auto err = fopen_s(&f, "test.txt", "a");

        int i = 123;
        double d = 43.567;

        if (err) {
            cout << "Не вийшло відкрити файл\n";
        }
        else {

            fprintf_s(f, "\n");
            fprintf_s(f, "integer: %d", i);
            fprintf_s(f, "\n");
            fprintf_s(f, "double: %.2f", d);

            fclose(f);
        }

        cout << '\n';
    }

    {
        cout << '\n';

        FILE* f;
        auto err = fopen_s(&f, "test.txt", "r"); // відкриваємо для читання

        if (err || !f) {
            cout << "Не вийшло відкрити файл для читання\n";
        }
        else {
            int i;
            double d;

            fscanf_s(f, "integer: %d\n", &i);
            fscanf_s(f, "double: %lf\n", &d);

            cout << "Зчитане число: " << i << '\n';
            cout << "Зчитане дробове: " << d << '\n';

            fclose(f);
        }

        cout << '\n';
    }

    {
        cout << "\n";

        FILE* f;
        auto err = fopen_s(&f, "test.txt", "r");

        if (err) {
            cout << "Не вдалось відкрити файл\n";
        }
        else {

            while (!feof(f)) {

                int i;
                double d;

                fscanf_s(f, "integer: %d\n", &i);
                fscanf_s(f, "double: %lf\n", &d);

                cout << "Зчитане число: " << i << '\n';
                cout << "Зчитане дробове: " << d << '\n';

            }

            fclose(f);
        }

        cout << "\n";
    }

    {
        struct Player {
            int health;
            int level;
            char nickname[10];
        };

        Player p = { 100, 2, "bear2004" };

        FILE* f;
        
        fopen_s(&f, "player.txt", "w");

        if (!f) {
            cout << "Не вийшло відкрити файл\n";
        }
        else {

            fprintf_s(f, "%d : %d : %s", p.health, p.level, p.nickname);

            fclose(f);

            fopen_s(&f, "player.txt", "r");

            if (!f) {
                cout << "Не вийшло відкрити файл\n";
            }
            else {
                Player pl;

                fscanf_s(f, "%d : %d : %s", &pl.health, &pl .level, &pl.nickname, sizeof(pl.nickname));

                fclose(f);

                cout << "Прочитано:\n";
                cout << "Health: " << pl.health << "\n";
                cout << "Level: " << pl.level << "\n";
                cout << "Nickname: " << pl.nickname << "\n";
            }
        }
    }

    {
        cout << '\n';
        // Покажчик на файлову структуру
        FILE* f;
        // Відкриття файлу
        auto err = fopen_s(&f, "cbyc.txt", "w"); // відкриваємо для запису

        // Перевірка успішності відкриття файлу
        if (err) {
            cout << "Не вийшло відкрити файл\n";
        }
        else {
            cout << "Записуємо в файл...\n";

            char str[] = "some text that will be written to the file";
            // Запис інформації до файлу
            for (int i = 0; i < strlen(str); i++) {
                fputc(str[i], f);
            }

            cout << "Запис пройшов успішно!\n";
            // Закриття файлу
            fclose(f);
        }
        cout << '\n';
    }
    
    {
        cout << '\n';
        // Покажчик на файлову структуру
        FILE* f;
        // Відкриття файлу
        auto err = fopen_s(&f, "cbyc.txt", "r"); // відкриваємо для читання

        // Перевірка успішності відкриття файлу
        if (err) {
            cout << "Не вийшло відкрити файл\n";
        }
        else {
            // Посимвольне читання
            while (!feof(f)) {
                cout << (char)fgetc(f);
            }

            // Закриття файлу
            fclose(f);
        }
        cout << '\n';
    }

    {
        cout << '\n';
        // Покажчик на файлову структуру
        FILE* f;
        // Відкриття файлу
        auto err = fopen_s(&f, "sbys.txt", "w"); // відкриваємо для запису

        // Перевірка успішності відкриття файлу
        if (err) {
            cout << "Не вийшло відкрити файл\n";
        }
        else {
            cout << "Записуємо в файл...\n";

            char str[] = "some text that will be written to the file\n";
            char str2[] = "another line of text\n";
            char str3[] = "and another one line for writing into file\n";
            
            fputs(str, f);
            fputs(str2, f);
            fputs(str3, f);

            cout << "Запис пройшов успішно!\n";
            // Закриття файлу
            fclose(f);
        }
        cout << '\n';
    }

    {
        cout << '\n';
        // Покажчик на файлову структуру
        FILE* f;
        // Відкриття файлу
        auto err = fopen_s(&f, "sbys.txt", "r"); // відкриваємо для читання

        // Перевірка успішності відкриття файлу
        if (err) {
            cout << "Не вийшло відкрити файл\n";
        }
        else {
            char buffer[50];

            // Порядкове читання
            while (fgets(buffer, sizeof(buffer), f)) {
                cout << buffer;
            }

            // Закриття файлу
            fclose(f);
        }
        cout << '\n';
    }

    {
        cout << '\n';

        // Масив для запису
        int arr[] = { 10, 20, 30, 40, 50 };
        int size = sizeof(arr) / sizeof(arr[0]);

        FILE* f;
        fopen_s(&f, "array.bin", "wb"); // відкриваємо файл у бінарному режимі для запису

        if (!f) {
            cout << "Не вдалося відкрити файл для запису.\n";
        }
        else {
            // Записуємо масив у файл
            fwrite(arr, sizeof(int), size, f);

            // Закриття файлу
            fclose(f);

            cout << "Масив записано в бінарний файл.\n";
        }
        cout << '\n';
    }

    {
        cout << '\n';
        int arr[5];  // Масив для зчитування
        int size = sizeof(arr) / sizeof(arr[0]);

        FILE* f;
        fopen_s(&f, "array.bin", "rb"); // відкриваємо файл у бінарному режимі для читання

        if (!f) {
            cout << "Не вдалося відкрити файл для читання.\n";
        }
        else {
            // Читання масиву з файлу
            fread(arr, sizeof(int), size, f);

            // Закриття файлу
            fclose(f);

            cout << "Масив прочитано з бінарного файлу:\n";
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
        }
        cout << '\n';
    }

    {
        cout << '\n';
        FILE* f;

        auto err = fopen_s(&f, "test.bin", "r");

        if (!err) {
            // Зчитуємо перший символ
            char ch = fgetc(f);
            cout << "Перший символ: " << ch << endl;

            // Отримуємо поточну позицію за допомогою fgetpos
            fpos_t pos;
            fgetpos(f, &pos);
            cout << "Позиція після першого символу: " << pos << endl;

            // Переміщуємося назад на початок файлу
            fseek(f, 0, SEEK_SET);
            cout << "Позиція після переміщення назад: 0" << endl;

            // Зчитуємо другий символ
            ch = fgetc(f);
            cout << "Другий символ: " << ch << endl;

            // Повертаємося на збережену позицію
            fsetpos(f, &pos);
            ch = fgetc(f);
            cout << "Символ після повернення до збереженої позиції: " << ch << endl;

            fclose(f);
        }
        cout << '\n';
    }

    {
        struct _finddata_t myfileinfo;
        long done = _findfirst("*.cpp", &myfileinfo);
        cout << myfileinfo.name << '\n';
    }

    {
        struct _finddata_t info;
        char path[255];
        char mask[20];

        cout << "Введіть шлях: ";
        cin >> path;
        cin.ignore(); // очистити вхідний буфер після cin >> path

        cout << "Введіть маску (наприклад, *.txt): ";
        cin.getline(mask, 20);

        strcat_s(path, mask); // з'єднуємо шлях з маскою

        auto handle = _findfirst(path, &info);
        if (handle == -1) {
            cout << "Файли не знайдено.\n";
        }
        else {
            do {
                cout << info.name << '\n';
            } while (_findnext(handle, &info) == 0);
            _findclose(handle);
        }
    }
}