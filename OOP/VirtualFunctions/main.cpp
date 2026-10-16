#include <iostream>
#include <string>
#include "Animal.h"
#include "Spawner.h"
#include "Enemy.h"
#include "AbstractClass.h"
#include "FileHandler.h"

using namespace std;

int main() {

    cout << "Віртуальні функції" << '\n';

    cout<< "\nПеревикористання коду\n";
    {
        Frog frog("Crazy Frog");
        cout << "Лягушка " << frog.GetName() << '\n';

        Donkey donkey("Іа");
        cout << "Віслюк " << donkey.GetName() << '\n';

        Monkey monkey("King-Kong");
        cout << "Мавпа " << monkey.GetName() << '\n';
    }

    cout << "\nВиклик через покажчик на базовий клас\n";
    {
        Frog frog("Пеппе");

        cout << "Лягушка " << frog.GetName() << " каже ";
        frog.MakeSound(); // Виклик через об'єкт класу

        Animal* ptr = &frog;
        cout << "Лягушка " << ptr->GetName() << " каже ";
        ptr->MakeSound(); // Виклик через покажчик на базовий клас
    }

    cout << "\nКонкретна реалізація невідома завчасно - динамічний поліморфізм\n";
    {
        Animal* ptr = nullptr;
        srand(time(0));

        switch (rand() % 3)
        {
        case 0:
            ptr = new Donkey("Віслюк(з Шрека)");
            break;
        case 1:
            ptr = new Monkey("Цезарь");
            break;
        case 2:
            ptr = new Frog("Гіпножаба");
            break;
        default:
            //ptr = new Animal("Абстрактна тварина");
            break;
        }

        ptr->MakeSound();

        delete ptr;
    }

    cout << "\nВиклик методу для колекції елементів\n";
    {
        const int ANIMAL_COUNT = 3;
        Animal* zoo[ANIMAL_COUNT];

        zoo[0] = new Frog("Froggy");
        zoo[1] = new Donkey("Donk");
        zoo[2] = new Monkey("Mykhailo");

        for(int i = 0; i < 3; i++) {
            cout<<zoo[i]->GetName() << " каже ";
            zoo[i]->MakeSound();
        }
    }

    cout << "\nПрактичний приклад з ієрархією ворогів\n";
    {
        Spawner* spawner = new Spawner();
        Enemy* enemies[4];

        for(int i = 0; i < 4; i++) {
            enemies[i] = spawner->SpawnEnemy();
        }

        // Виклик методів атаки
        for(int i = 0; i < 4; i++) {
            enemies[i]->Attack();
        }

        for(int i = 0; i < 4; i++) {
            delete enemies[i];
        }

        delete spawner;
    }

    /*
    cout << "\nВиклик віртуальних функцій базових абстрактних сутностей\n";
    {
        // Помилка! Неможливо створити об'єкти абстрактного класу!
        Animal animal("Невідома тварина");
        animal.MakeSound();

        Enemy enemy(0, 0, "Невідомий ворог");
        enemy.Attack();
    }
    */

    cout << "\nВіртуальний конструктор\n";
    {
        Animal* ptr = new Frog("Жаба");

        delete ptr; // Виклик деструктора
    }

    cout << "\nРобота з файлом через абстрактний клас\n";
    {
        FileHandler* handler = new TextFileHandler("test.txt");
        handler->Write("Hello from text handler\n");
        handler->Read();
        delete handler;

        std::cout << "\n---\n";

        handler = new BinaryFileHandler("test.bin");
        handler->Write("Binary content");
        handler->Read();
        delete handler;
    }

    return 0;
}