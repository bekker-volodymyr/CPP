#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    srand(time(NULL));

    // Створення динамічного двовимірного масиву
    int size_x = 3, size_y = 5;

    int** arr_3x5 = new int* [size_x]; // Виділення пам'яті для масиву покажчиків

    for (int i = 0; i < size_x; i++) 
    {
        arr_3x5[i] = new int[size_y]; // Виділення пам'яті для внутрішнього масиву
        for (int j = 0; j < size_y; j++) 
        {
            arr_3x5[i][j] = rand() % 10; // Ініціалізація випадковим числом
            cout << arr_3x5[i][j] << " "; // Вивід на екран
        }
        cout << endl;
    }

    // Очищуємо пам'ять
    for (int i = 0; i < size_x; i++)
    {
        delete[] arr_3x5[i];
    }
    delete[] arr_3x5;

    cout << endl << endl;

    // Створення зубчатого (рваного) масиву
    int size_A;
    cout << "Введіть кількість масивів: " << endl;
    cin >> size_A;

    int** A = new int* [size_A]; // масив покажчиків на масиви
    int* sizes = new int[size_A]; // масив розмірів інших масивів

    for (int i = 0; i < size_A; i++) {
        int temp_size;
        cout << "Введіть розмір " << i << " масиву: ";
        cin >> temp_size;
        A[i] = new int[temp_size]; // виділяємо пам'ять під масив
        sizes[i] = temp_size;   // зберігаємо розмір масиву
        for (int j = 0; j < temp_size; j++) {
            // заповнюємо масив значеннями
            int temp_value;
            cout << "Введіть  значення " << j << " елементу " << i << " масиву: ";
            cin >> temp_value;
            A[i][j] = temp_value;
        }
    }

    // Виводимо масиви
    for (int i = 0; i < size_A; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Очистка пам'яті
    for (int i = 0; i < size_A; i++) {
        // Очистити кожен внутрішній масив
        delete[] A[i];
    }
    delete[] A; // Очистити масив покажчиків

    cout << endl << endl;

    // Тривимірний динамічний масив
    
    cout << endl << "Тривимірний динамічний масив" << endl;

    int size_i= 4, size_j = 2, size_z = 3;

    // Покажчик на масив покажчиків на покажчик :)
    int*** arr_4x2x3 = new int** [size_i]; 

    for (int i = 0; i < size_i; i++) 
    {
        arr_4x2x3[i] = new int* [size_j]; // Масив покажчиків
        for (int j = 0; j < size_j; j++) 
        {
            arr_4x2x3[i][j] = new int[size_z]; // Масив чисел
            // Заповнюємо та виводимо
            for (int z = 0; z < size_z; z++) 
            {
                arr_4x2x3[i][j][z] = rand() % 10;
                cout << arr_4x2x3[i][j][z] << " ";
            }
            cout << endl;
        }
        cout << "--------" << endl;
    }
    
    // Звільнення пам'яті
    for (int i = 0; i < size_i; i++) {
        for (int j = 0; j < size_j; j++) {
            delete[] arr_4x2x3[i][j];
        }
        delete[] arr_4x2x3[i];
    }
    delete[] arr_4x2x3;

}
