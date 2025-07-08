#include <iostream>
#include <cstring>

class Student {
private:
    char* name;
    char* groupName;
    int age;

public:
    Student() : name(nullptr), groupName(nullptr), age(0) {}

    ~Student() {
        delete[] name;
        delete[] groupName;
    }

    // Метод встановлення імені
    Student& SetName(const char* name) {
        if (this->name) delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
        return *this; // Повертає посилання на поточний об'єкт
    }

    // Метод встановлення назви групи
    Student& SetGroupName(const char* groupName) {
        if (this->groupName) delete[] this->groupName;
        this->groupName = new char[strlen(groupName) + 1];
        strcpy_s(this->groupName, strlen(groupName) + 1, groupName);
        return *this;
    }

    // Метод встановлення віку
    Student& SetAge(int age) {
        this->age = age;
        return *this;
    }

    // Виведення інформації
    void print() const {
        std::cout << "Name: " << (name ? name : "Unknown")
                  << ", Group: " << (groupName ? groupName : "Unknown")
                  << ", Age: " << age << std::endl;
    }
};

int main() {
    Student student;

    student.SetName("John Doe")
           .SetGroupName("CS101")
           .SetAge(20);

    student.print();

    return 0;
}
