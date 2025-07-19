#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T> void SwapValues(T& left, T& right);

int& rmax(int arr[], int size);

void addToArr(int*& arr, int& size, int elem);
void printArr(int* arr, const int& size);

int main()
{
	SetConsoleOutputCP(1251);

	int count = 5;
	int* arrDyn = new int[count] {10, 1, 6, -1, 0};

	printArr(arrDyn, count);
	addToArr(arrDyn, count, 100);
	printArr(arrDyn, count);


	int const constVal = 10;

	const int* ptrC = &constVal;


	int a = 10, b = 12;
	
	int* const ptr = &a; // Константний покажчик

	*ptr = 23;

	cout << a << endl; // Вивід: 23

	const int* ptrToConst;

	ptrToConst = &a;

	//*ptrToConst = 25; // Помилка!!

	ptrToConst = &b;

	//*ptrToConst = 1; // Помилка

	// ptr = &b; // Помилка!!

	int number = 0;

	const int* const cPtrToC = &number;

	cout << cPtrToC << " --- " << *cPtrToC << endl;

	//cPtrToC = &a; // Помилка!!
	//*cPtrToC = 10; // Помилка!!

	int value = 1234;		// Змінній присвоєно значення
	int* valPtr = &value;	// Покажчику присвоєна адреса змінної value
	int& valRef = value;	// Посилання асоційоване з value
	int* p = &valRef;		// Покажчику присвоєно адресу iref.
	cout << "value = " << value << "\n";	 // Вивід: 1234
	cout << "*valPtr = " << *valPtr << "\n"; // Вивід: 1234
	cout << "valRef = " << valRef << "\n";	 // Вивід: 1234
	cout << "*p = " << *p << "\n";			 // Вивід: 1234

	double one = 2.4, two = 3.5;

	double& ref = one;
	cout << one << endl; // Вивід: 2.4
	cout << two << endl; // Вивід: 3.5
	cout << ref << endl; // Вивід: 2.4
	
	ref = two;
	cout << one << endl; // Вивід: 3.5
	cout << two << endl; // Вивід: 3.5
	cout << ref << endl; // Вивід: 3.5


	int left = 10, right = 12;
	cout << "left: " << left << " --- right: " << right << endl;
	SwapValues(left, right);
	cout << "left: " << left << " --- right: " << right << endl;

	int* ptr2;
	int*& ptrRef = ptr2;

	int const size = 5;
	int arr[size] = { 10, 4, 15, -9, 0 };

	int& maxElem = rmax(arr, size);

	cout << maxElem << endl; // Вивід: 15
	maxElem = 0; // Змінюємо максимальний елемент на 0
	cout << arr[2] << endl; // Вивід: 0

	// Виділення пам'яті в купі - оператор new поверне адресу в пам'ті.
	float* fptr = new float(3.5);
	int* iptr = new int(6);
	char* cptr = new char('I');

	delete fptr, iptr, cptr;
	

	srand(time(NULL));

	int s;
	cout << "Введіть розмір масиву: ";
	cin >> s;

	double* dArr = new double[s]; // Виділення пам'яті під масив

	for (int i = 0; i < s; i++) {
		dArr[i] = rand() % 100;
		cout << dArr[i] << "\t";
	}

	delete[] dArr;
}

void addToArr(int*& arr, int& size, int elem) {
	int* tempPtr = new int[++size];
	for (int i = 0; i < size - 1; i++) {
		tempPtr[i] = arr[i];
	}
	tempPtr[size - 1] = elem;
	delete[] arr;
	arr = tempPtr;
}

void printArr(int* arr, const int& size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int& rmax(int arr[], int size) {
	int im = 0;
	for (int i = 1; i < size; i++) {
		im = arr[im] > arr[i] ? im : i;
	}
	return arr[im];
}

template <typename T> void SwapValues(T& left, T& right) {
	T temp = left;
	left = right;
	right = temp;
}