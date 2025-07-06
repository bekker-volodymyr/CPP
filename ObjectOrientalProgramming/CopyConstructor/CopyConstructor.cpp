#include <iostream>
#include <Windows.h>
#include <cstring> // для strlen и strcpy_s

// Класс "Point" — описує точку на площині
class Point {
private:
    double x, y;

public:
    // Конструктор з параметрами (або за замовчуванням)
    Point(double x = 0, double y = 0) : x(x), y(y) {
        std::cout << "Викликано конструктор Point: (" << x << ", " << y << ")\n";
    }

    // Конструктор копіювання
    Point(const Point& other) : x(other.x), y(other.y) {
        std::cout << "Копіювання Point: (" << x << ", " << y << ")\n";
    }

    // Метод виводу координат
    void Print() const {
        std::cout << "Point(" << x << ", " << y << ")\n";
    }
};

// Клас "Person" — описує людину з ім’ям та віком
class Person {
private:
    char* name;
    int age;

public:
    // Конструктор за замовчуванням
    Person() : name(nullptr), age(0) {
        std::cout << "Викликано конструктор Person за замовчуванням\n";
    }

    // Конструктор з параметрами
    Person(const char* name, int age) : age(age) {
        std::cout << "Викликано конструктор Person з параметрами: " << name << ", " << age << "\n";
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
    }

    // Конструктор копіювання
    Person(const Person& other) : age(other.age) {
        std::cout << "Копіювання Person для: " << other.name << "\n";
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy_s(name, strlen(other.name) + 1, other.name);
        } else {
            name = nullptr;
        }
    }

    // Деструктор
    ~Person() {
        if (name) {
            std::cout << "Звільнено пам’ять для: " << name << "\n";
            delete[] name;
        }
    }

    // Метод виводу інформації
    void Print() const {
        if (name) {
            std::cout << "Person: " << name << ", Age: " << age << "\n";
        } else {
            std::cout << "Person: [невідоме ім’я], Age: " << age << "\n";
        }
    }
};

int main() {
    SetConsoleOutputCP(1251); // Для підтримки кирилиці в консолі Windows

    std::cout << "=== Тест класу Point ===\n";
    {
        Point p1(3.0, 4.0);   // Конструктор
        Point p2(p1);         // Копіювання
        Point p3 = p1;        // Ще одне копіювання

        std::cout << "p1: "; p1.Print();
        std::cout << "p2: "; p2.Print();
    }

    std::cout << "\n=== Тест класу Person ===\n";
    {
        Person person1("Аліса", 30);
        Person person2 = person1;

        person1.Print();
        person2.Print();
    }

    return 0;
}
