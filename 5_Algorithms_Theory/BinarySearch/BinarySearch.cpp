#include <iostream>

using namespace std;

int main()
{
	const int size = 5;
	int searchArr[size] = { 2, -1, 6, 5, 0 };

	cout << "Array for search: ";
	for (int item : searchArr) {
		cout << item << " ";
	}
	cout << '\n';

	int value;
	cout << "Enter number: ";
	cin >> value;

	// Sort array
	for (int i = 1; i < size; i++) {
		int temp = searchArr[i];
		int j = i - 1;

		while (j >= 0 && searchArr[j] > temp) {
			searchArr[j + 1] = searchArr[j];
			j--;
		}

		searchArr[j + 1] = temp;
	}

	int left = 0;
	int right = size - 1;
	int index = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (searchArr[mid] == value) {
			index = mid;
			break;
		}
		else if (searchArr[mid] < value) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	if (index == -1) {
		cout << "Value " << value << " not found.";
	}
	else {
		cout << "Value " << value << " found. Index: " << index << ".";
	}
}