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

    // Заповнення масиву випадковими значеннями
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }

    // 🔷 Сортування вибором
    cout << "Масив до сортування (вибором): ";
    for (int item : arr) cout << item << " ";
    cout << endl;

    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i; j < size; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }

    cout << "Масив після сортування (вибором): ";
    for (int item : arr) cout << item << " ";
    cout << endl;

    // 🔷 Перезаповнення масиву
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }

    // 🔷 Бульбашкове сортування
    cout << "\nМасив до сортування (бульбашкою): ";
    for (int item : arr) cout << item << " ";
    cout << endl;

    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
            }
        }
    }

    cout << "Масив після сортування (бульбашкою): ";
    for (int item : arr) cout << item << " ";
    cout << endl;

    // 🔷 Перезаповнення масиву
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }

    // 🔷 Сортування вставками
    cout << "\nМасив до сортування (вставками): ";
    for (int item : arr) cout << item << " ";
    cout << endl;

    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    cout << "Масив після сортування (вставками): ";
    for (int item : arr) cout << item << " ";
    cout << endl;

    // 🔍 Лінійний пошук
    int searchArr[size] = { 2, -1, 6, 5, 0 };
    cout << "\nМасив для пошуку: ";
    for (int item : searchArr) cout << item << " ";
    cout << endl;

    int value;
    cout << "Введіть значення для пошуку (лінійний): ";
    cin >> value;

    int index = -1;
    for (int i = 0; i < size; i++) {
        if (searchArr[i] == value) {
            index = i;
            cout << "Значення " << value << " знайдено за індексом " << index << ".\n";
            break;
        }
    }
    if (index == -1) {
        cout << "Значення " << value << " не знайдено.\n";
    }

    // 🔍 Бінарний пошук (масив спочатку сортується)
    cout << "\nВведіть значення для пошуку (бінарний): ";
    cin >> value;

    // Сортуємо масив вставками
    for (int i = 1; i < size; i++) {
        int temp = searchArr[i];
        int j = i - 1;
        while (j >= 0 && searchArr[j] > temp) {
            searchArr[j + 1] = searchArr[j];
            j--;
        }
        searchArr[j + 1] = temp;
    }

    int left = 0, right = size - 1;
    index = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (searchArr[mid] == value) {
            index = mid;
            break;
        } else if (searchArr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (index != -1) {
        cout << "Значення " << value << " знайдено за індексом " << index << ".\n";
    } else {
        cout << "Значення " << value << " не знайдено.\n";
    }

    return 0;
}
