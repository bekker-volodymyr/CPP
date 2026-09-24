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

	int index = -1;
	for (int i = 0; i < size; i++) {
		if (searchArr[i] == value) {
			index = i;
			cout << "Value " << value << " was found. Index: " << index << ".";
			break;
		}
	}

	if (index == -1) {
		cout << "Value " << value << " was not found.";
	}

	cout << '\n';
}