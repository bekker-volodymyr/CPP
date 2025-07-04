/* Статичні члени класу (Static members) */

// Статичні члени класу - це члени, які спільні для всіх об'єктів класу.
// Вони зберігаються в пам'яті лише один раз, незалежно від кількості об'єктів класу.
// Існує два типи статичних членів: 
// - статичні змінні
// - статичні методи.

#include <iostream>
#include <Windows.h>

// Клас зі статичним полем
class User {
private:
	int id;   // Унікальний ідентифікатор користувача
    char* name;
public:
	// public тільки для перевірки адреси статичного поля
    static int nextId; // Статичне поле для зберігання наступного ID

    User(const char* name) : 
        id(nextId++), // Ініціалізуємо id та збільшуємо лічильник
        name(new char[strlen(name) + 1]) {
        strcpy_s(this->name, strlen(name) + 1, name);
	}
    ~User() {
        delete[] name; // Звільняємо пам'ять
	}

    void ShowInfo() const {
        std::cout << "ID: " << id << ", Ім'я: " << name << std::endl;
	}

    // Статичний метод для отримання наступного ID
    static int GetNextId() {
        //std::cout << this.name // Статичний метод не може використовувати this

		return nextId; 
    }
};



// Ініціалізація статичного поля4
int User::nextId = 1; 

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    {
        // Створення двох користувачів
        User user1("VibeCoder3000");
		std::cout << "User 1:\n";
		user1.ShowInfo(); // Виводимо інформацію про першого користувача
        
		std::cout << "Наступний ID: " << User::GetNextId() << '\n'; // Виводимо наступний ID

        User user2("Джокер ДНР");
		std::cout << "User 2:\n";
		user2.ShowInfo(); // Виводимо інформацію про другого користувача

        std::cout << "Наступний ID: " << User::GetNextId() << '\n'; // Виводимо наступний ID

		// Звернення до статичного поля через об'єкт
		std::cout << "Доступ через об'єкт user1: " << user1.GetNextId() << '\n';
		std::cout << "Доступ через об'єкт user2: " << user2.GetNextId() << '\n';

		// Адреса статичного поля при доступі через об'єкт - адреса однакова
        std::cout << "Адреса через об'єкт user1: " << &(user1.nextId) << '\n';
        std::cout << "Адреса через об'єкт user2: " << &(user2.nextId) << '\n';
    }
}