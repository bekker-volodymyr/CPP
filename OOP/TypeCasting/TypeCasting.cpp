#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

#include "Animal.h"
#include "ZooWorker.h"

using namespace std;

struct Point {
	int x, y;
};

class Book {
private:
	string title;
	string author;
public:
	Book(const string& title, const string& author) : title(title), author(author) {}
	string getTitle() const { return title; }
	string getAuthor() const { return author; }
};

class Base { };
class Derived : public Base {};

class BasePolymorphic { virtual void foo() {} };
class DerivedPolymorphic : public BasePolymorphic {};

template<typename T>
class MyTemplate {
private:
		T value;
public:
	MyTemplate(T val) : value(val) {}
	T getValue() const { return value; }
};

void printAndChange(const int* ptr) {
	int* modifiable = const_cast<int*>(ptr);
	*modifiable = 42;
	std::cout << *modifiable << "\n";
}

int main()
{
    #ifdef _WIN32
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
    #endif

    {
		cout << "typeid зі звичайними типами" << '\n';
		int a = 10;
		cout << "ім'я типу змінної а: " << typeid(a).name() << '\n';
		cout << "ім'я типу у виразі (a + 5.5): " << typeid(a + 5.5).name() << '\n';
		float* f = new float(3.14f);
		cout << "ім'я типу вказівника f: " << typeid(f).name() << '\n';
		cout << "ім'я типу, на який вказує f: " << typeid(*f).name() << '\n';
		delete f;
		Point p1 = { 1, 2 };
		cout << "ім'я типу змінної p1 (структура Point): " << typeid(p1).name() << '\n';
		Book book("Холодний Яр", "Юрій Горліс-Горський");
		cout << "ім'я типу змінної book (клас Book): " << typeid(book).name() << '\n';
    }

	{
		cout << "\ntypeid з поліморфними типами (ті, що містять віртуальні функції)" << '\n';
		BasePolymorphic* basePtr = new BasePolymorphic();
		DerivedPolymorphic* derivedPtr = new DerivedPolymorphic();
		BasePolymorphic* polymorphicPtr = derivedPtr;
		cout << "ім'я типу, на який вказує basePtr: " << typeid(*basePtr).name() << '\n';
		cout << "ім'я типу, на який вказує derivedPtr: " << typeid(*derivedPtr).name() << '\n';
		// Тут polymorphicPtr вказує на DerivedPolymorphic, тому typeid поверне DerivedPolymorphic
		cout << "ім'я типу, на який вказує polymorphicPtr: " << typeid(*polymorphicPtr).name() << '\n';
		delete basePtr;
		delete derivedPtr;
	}

	{
		cout << "\ntypeid з не поліморфними типами (ті, що не містять віртуальних функцій" << '\n';
		Base* basePtr = new Base();
		Derived* derivedPtr = new Derived();
		Base* polymorphicPtr = derivedPtr;
		cout << "ім'я типу, на який вказує basePtr: " << typeid(*basePtr).name() << '\n';
		cout << "ім'я типу, на який вказує derivedPtr: " << typeid(*derivedPtr).name() << '\n';
		// Тут polymorphicPtr вказує на Derived, але typeid поверне Base, оскільки Base не є поліморфним
		cout << "ім'я типу, на який вказує polymorphicPtr: " << typeid(*polymorphicPtr).name() << '\n';
		delete basePtr;
		delete derivedPtr;
	}

	{
		cout << "\ntypeid з шаблонним типом\n";
		MyTemplate<int> intTemplate(42);
		MyTemplate<double> doubleTemplate(3.14);
		cout << "ім'я типу intTemplate: " << typeid(intTemplate).name() << '\n';
		cout << "ім'я типу doubleTemplate: " << typeid(doubleTemplate).name() << '\n';
	}

	{
		cout << "\nГодування тварин у зоопарку\n";
		Animal* monkey = new Monkey("Мавпочка", 5);
		Animal* elephant = new Elephant("Слоненя", 10);
		ZooWorker worker("Іван", 1500.0);
		worker.feedAnimal(*monkey);
		worker.feedAnimal(*elephant);
		delete monkey;
		delete elephant;
	}

	{
		cout << "\nstatic_cast\n";
		
		// перетворення звичайних типів
		int i = 42;
		double d = static_cast<double>(i); // i -> 42.0

		Monkey monkey("Чобіток", 5);

		Animal* animalPtr = static_cast<Animal*>(&monkey); // upcast: безпечно
		animalPtr->makeSound();

		// Downcast – дозволено, але небезпечно без перевірки (typeid)
		Monkey* monkeyPtr = static_cast<Monkey*>(animalPtr);
		monkeyPtr->makeSound();

		// Перетворення покажчиків
		void* ptr = new int(100);

		int* iptr = static_cast<int*>(ptr);
		std::cout << *iptr << "\n"; // 100

		delete iptr;
	}

	{
		cout << "\nstatic_cast та C-style cast\n";

		int i = 10;
		int* p = &i;
		double* d = (double*)p; // C-style дозволить, але це undefined behavior

		// double* d2 = static_cast<double*>(p); // помилка: static_cast забороняє
	}

	{
		cout << "\ndynamic_cast\n";

		Animal* animalPtr1 = new Monkey("Абу", 7);

		Monkey* monkeyPtr1 = dynamic_cast<Monkey*>(animalPtr1); // ок, a вказує на Dog
		if (monkeyPtr1) {
			monkeyPtr1->makeSound(); // У-А-А!
		}

		Animal* animalPtr2 = new Elephant("Наш Слін", 10);
		Monkey* monkeyPtr2 = dynamic_cast<Monkey*>(animalPtr2); // не ок, поверне nullptr
		if (!monkeyPtr2) {
			cout << "animalPtr2 не Monkey\n";
		}

		delete animalPtr1, animalPtr2;

		Monkey monkey("Коко", 3);
		Animal& a = monkey;

		try {
			Elephant& m = dynamic_cast<Elephant&>(a);
			m.makeSound();
		}
		catch (const std::bad_cast& e) {
			std::cout << "Не Elephant: " << e.what() << "\n";
		}
	}

	{
		cout << "\nconst_cast\n";

		int x = 10;
		printAndChange(&x); // виведе 42

		const int y = 20;
		printAndChange(&y); // небезпечно, потенційно undefined behavior
	}

	{
		cout << "\nreinterpret_cast\n";
		int a = 65; // ASCII код для 'A'
		char* c = reinterpret_cast<char*>(&a); // перетворення int в char*
		cout << "reinterpret_cast: " << *c << "\n"; // виведе 'A' або інший символ в залежності від системи
	}
}