#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

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
		cout << "Vector size: " << numbers.size() << endl;
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

		numbers.pop_back(); // Видалення останнього елемента

		numbers.erase(numbers.begin() + 1); // Видалення елемента за індексом

		numbers.clear(); // Очищення вектору

		// Перевірка, чи вектор порожній
		if(numbers.empty()) {
			cout << "\nVector is empty after clear." << endl;
		} else {
			cout << "\nVector is not empty." << endl;
		}
	}

	{
		// Приклад використання ітераторів
		vector<int> numbers = { 13, 2, 23, -4, 8 };
		list<int> numberList = { 13, 2, 23, -4, 8 };

		// Сортування вектору та списку
		// sort використовує ітератори для доступу до елементів
		// Одна функція - різні типи контейнерів
		sort(numbers.begin(), numbers.end());
		sort(numberList.begin(), numberList.end());
	}
}