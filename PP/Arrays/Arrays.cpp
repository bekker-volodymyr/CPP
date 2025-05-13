#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//cout << time(NULL) << endl;

	srand(time(NULL));

	int const size = 10;
	int arr[size];

	int min = 5;
	int max = 45;

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (max - min + 1) + min;
		cout << arr[i] << " ";
	}
}
