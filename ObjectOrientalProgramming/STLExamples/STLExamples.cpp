#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// Прототипи
bool isEven(int n);

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
#endif

	{
		// Приклад використання вектору
		vector<int> numbers = { 1, 2, 3, 4, 5 };
		cout << "Vector elements: ";
		for (const auto& num : numbers) {
			cout << num << " ";
		}
		cout << "\nVector size: " << numbers.size() << endl;
		cout << "Vector capacity: " << numbers.capacity() << endl;
		cout << "Vector element at index 2: " << numbers.at(2) << endl;

		// Додавання елементів до вектору в кінець
		numbers.push_back(6);

		// Додавання елемента на початок з використанням ітератора
		// numbers.begin() - це ітератор, який вказує на перший елемент вектора
		numbers.insert(numbers.begin() + 1, 10);

		cout << "Vector elements after modify: ";
		for (const auto& num : numbers) {
			cout << num << " ";
		}
		cout << endl;

		numbers.pop_back(); // Видалення останнього елемента

		numbers.erase(numbers.begin() + 1); // Видалення елемента за індексом

		numbers.clear(); // Очищення вектора

		// Перевірка, чи вектор порожній
		if (numbers.empty()) {
			cout << "Vector is empty after clear." << endl;
		}
		else {
			cout << "Vector is not empty." << endl;
		}
	}

	{
		// Приклад використання ітераторів
		vector<int> numbers = { 13, 2, 23, -4, 8 };
		list<int> numberList = { 13, 2, 23, -4, 8 };

		// Пошук у векторі та списку
		// find використовує ітератори для доступу до елементів
		// Одна функція — різні типи контейнерів
		auto resultVect = find(numbers.begin(), numbers.end(), 23);
		auto resultList = find(numberList.begin(), numberList.end(), 23);

		cout << "Found in vector: " << (resultVect != numbers.end() ? "Yes" : "No") << endl;
		cout << "Found in list: " << (resultList != numberList.end() ? "Yes" : "No") << endl;
	}

	{
		// Використання класу list
		list<string> names = { "Alice", "Bob", "Charlie" };

		names.push_back("David"); // Додавання елемента в кінець списку
		names.push_front("Eve"); // Додавання елемента на початок списку

		names.sort(); // Сортування списку - використовує вбудований метод sort

		cout << "List elements: ";
		// Можна використовувати range-based for loop для виведення елементів списку
		for (const auto& name : names) {
			cout << name << " ";
		}
		cout << endl;
	}

	{
		// Приклад використання map
		map<string, string> phoneBook;
		phoneBook["Alice"] = "123-456-7890";
		phoneBook["Bob"] = "987-654-3210";
		phoneBook["Charlie"] = "555-555-5555";
		phoneBook["David"] = "111-222-3333";

		phoneBook["Alice"] = "111-111-1111"; // Оновлення номера телефону для Alice

		cout << phoneBook["Alice"] << endl; // Виведення номера телефону Alice

		// Виведення номера телефону для Donald, який не існує в телефонній книзі
		// Це створить новий запис з порожнім значенням
		cout << phoneBook["Donald"] << endl;

		phoneBook.erase("Charlie"); // Видалення запису для Charlie
	}

	{
		// multimap — кілька значень на один ключ
		multimap<string, string> multiMap;
		multiMap.insert({ "apple", "зелений" });
		multiMap.insert({ "apple", "червоний" }); // не перезаписується

		cout << "\nmultimap:\n";
		for (const auto& pair : multiMap) {
			cout << pair.first << " — " << pair.second << endl;
		}
	}

	{
		 // Використання функтора
		struct Desc {
			bool operator()(int a, int b) const {
				return a > b;
			}
		};

		vector<int> numbers = { 5, 2, 8, 1 };
		sort(numbers.begin(), numbers.end(), Desc());

		for (int n : numbers) {
			cout << n << " ";
		}
	}

	{
		// Використання об'єктів функцій
		vector<int> nums = { 1, 2, 3, 4, 5, 6 };
		function<bool(int)> isEven = isEven;
		int evenCount = count_if(nums.begin(), nums.end(), isEven);

		cout << "Кількість парних: " << evenCount << endl;
	}

	{
		// Використання лямбда-функцій
		vector<int> nums = { 3, 7, 1, 9, 5 };
		auto greaterThan5 = [](int x) { return x > 5; };

		int count = count_if(nums.begin(), nums.end(), greaterThan5);
		cout << "Чисел > 5: " << count << endl;
	}
}

bool isEven(int n) {
	return n % 2 == 0;
}