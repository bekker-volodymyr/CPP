#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	srand(time(NULL));

	const int size = 5;
	int arr[size];
	int min = -10, max = 10;

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min + 1) + min;
	}

	// Сортування вибором
	cout << "Масив до сортування: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << endl;

	int minIndex; // Змінна для збереження індексу найменьшого елементу
	// Основний цикл сортування
	for (int i = 0; i < size; i++) {
		// Скидаємо значення мінімального індексу
		minIndex = i;

		// Внутрішній цикл для пошуку мінімального елементу
		for (int j = i; j < size; j++) {
			if (arr[minIndex] > arr[j]) {
				minIndex = j;
			}
		}
		// Якщо найменший елемент не дорівнює поточному - міняємо місцями.
		if (minIndex != i) {
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}

	cout << "Масив після сортування: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << endl;

	// Перезаповнюємо масив
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min + 1) + min;
	}

	// Бульбашкове сортування
	cout << endl;
	cout << "Масив до сортування: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << endl;

	// Зовнішній цикл, i - номер проходу
	for (int i = 0; i < size; i++) {
		// Внутрішній цикл - ідемо від останнього до i, всі до i вже відсортовані
		for (int j = size - 1; j > i; j--) {
			// Порівнюємо сусідні елементи та міняємо їх місцями в разі потреби
			if (arr[j - 1] > arr[j]) {
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout << "Масив після сортування: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << endl;

	// Перезаповнюємо масив
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min + 1) + min;
	}

	// Сортування вставками
	cout << endl;
	cout << "Масив до сортування: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << endl;

	// Зовнішній цикл, i - номер проходу
	for (int i = 1; i < size; i++) {
		int temp = arr[i]; // Збереження поточного елементу
		int j = i - 1;

		// Зсув елементів, які більші за temp вправо
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}

		// Вставка temp на правильне місце
		arr[j + 1] = temp;
	}

	cout << "Масив після сортування: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << endl;

	cout << endl;

	int searchArr[size] = { 2, -1, 6, 5, 0 };

	cout << "Масив для пошуку: ";
	for (int item : searchArr) {
		cout << item << " ";
	}
	cout << endl;

	// Лінійний пошук
	int value;
	cout << "Введіть значення для пошуку: ";
	cin >> value;

	int index = -1;
	for (int i = 0; i < size; i++) {
		if (searchArr[i] == value) {
			index = i;
			cout << "Значення " << value << " знайдено за індексом " << index << ".";
			break;
		}
	}
	if (index == -1) {
		cout << "Значення " << value << " не знайдено.";
	}

	cout << endl;

	// Бінарний пошук
	cout << "Введіть значення для пошуку: ";
	cin >> value;

	// Сортуємо масив
	for (int i = 1; i < size; i++) {
		int temp = searchArr[i]; // Збереження поточного елементу
		int j = i - 1;

		// Зсув елементів, які більші за temp вправо
		while (j >= 0 && searchArr[j] > temp) {
			searchArr[j + 1] = searchArr[j];
			j--;
		}

		// Вставка temp на правильне місце
		searchArr[j + 1] = temp;
	}

	int left = 0;
	int right = size - 1;
	index = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (searchArr[mid] == value) {
			index = mid; // Елемент знайдено, зберігаємо індекс
			break;
		}
		else if (searchArr[mid] < value) {
			left = mid + 1; // Шуканий елемент у правій половині
		}
		else {
			right = mid - 1; // Шуканий елемент у лівій половині
		}
	}

	if (index == -1) {
		cout << "Значення " << value << " не знайдено.";
	}
	else {
		cout << "Значення " << value << " знайдено за індексом " << index << ".";
	}
}