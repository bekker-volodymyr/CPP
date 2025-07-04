/* Покажчик this */

#include <iostream>

class Student {
private:
    char* name;
    char* groupName;
    int age;
public:
	Student() : name(nullptr), groupName(nullptr), age(0) {}

    Student(const char* name, const char* groupName, int age)
    {
		// Використання 'this' для доступу до членів класу
		this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
        this->groupName = new char[strlen(groupName) + 1];
        strcpy_s(this->groupName, strlen(groupName) + 1, groupName);
		this->age = age;
    }

    //void setThis(Student student) {
		//this = &student; // Це не коректно, 'this' не може бути змінено
    //}

    Student& SetAge(int age) {
		// Використання 'this' для доступу до членів класу - вирішення конфлікту імен
        this->age = age;
		return *this; // Повертаємо посилання на поточний об'єкт
	}
    Student& SetName(const char* name) {
        // Використання 'this' для доступу до членів класу
        if (this->name) {
            delete[] this->name;
        }
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
		return *this; // Повертаємо посилання на поточний об'єкт
	}
    Student& SetGroupName(const char* groupName) {
        // Використання 'this' для доступу до членів класу
        if (this->groupName) {
            delete[] this->groupName;
        }
        this->groupName = new char[strlen(groupName) + 1];
        strcpy_s(this->groupName, strlen(groupName) + 1, groupName);
		return *this; // Повертаємо посилання на поточний об'єкт
	}

    void print() {
        std::cout << "Name: " << name << ", Group: " << groupName << ", Age: " << age << std::endl;
    }
};

int main()
{
	Student student;

    student.SetName("John Doe").SetGroupName("CS101").SetAge(20);

	student.print();


}
