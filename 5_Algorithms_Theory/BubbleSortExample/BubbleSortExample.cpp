#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));

	// Create initial data
	const int size = 5;
	int arr[size];
	int min = -10, max = 10;

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min + 1) + min;
	}

	cout << "Unsorted array: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << '\n';

	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j > i; j--) {
			if (arr[j - 1] > arr[j]) {
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout << "Sorted array: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << '\n';
}