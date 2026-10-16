#include <iostream>

#include "IntArray.h"

// Функція-фабрика, яка генерує масив і повертає його по значенню.
// Результат цієї функції є тимчасовим об'єктом (rvalue).
IntArray createFilledArray(size_t size)
{
    IntArray temp(size);
    for (size_t i = 0; i < size; ++i)
    {
        temp[i] = (i + 1) * 10;
    }
    return temp;
}

int main()
{
    std::cout << "--- 1. Move Constructor ---\n";
    IntArray arr1(5);
    for (size_t i = 0; i < 5; ++i)
        arr1[i] = i;

    IntArray arr2 = std::move(arr1);

    std::cout << "Size of arr2 after move: " << arr2.getSize() << "\n";
    std::cout << "Size of arr1 (donor) after move: " << arr1.getSize() << "\n\n";

    std::cout << "--- 2. Move Assignment Operator ---\n";
    IntArray arr3(3);

    arr3 = createFilledArray(10);

    std::cout << "New size of arr3: " << arr3.getSize() << "\n";
    std::cout << "First element of arr3: " << arr3[0] << "\n\n";

    std::cout << "--- 3. Explicit move on assignment ---\n";
    IntArray arr4(2);

    arr4 = std::move(arr2);

    std::cout << "Size of arr4: " << arr4.getSize() << "\n";
    std::cout << "Size of arr2 (donor): " << arr2.getSize() << "\n";

    return 0;
}
