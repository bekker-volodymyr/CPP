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

	int minIndex;
	for (int i = 0; i < size; i++) {
		minIndex = i;

		for (int j = i; j < size; j++) {
			if (arr[minIndex] > arr[j]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}

	cout << "Sorted array: ";
	for (int item : arr) {
		cout << item << " ";
	}
	cout << '\n';
}