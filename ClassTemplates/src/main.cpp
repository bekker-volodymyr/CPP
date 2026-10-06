#include <iostream>

#include "Box.h"
#include "PairBox.h"
#include "Array.h"

int main()
{
    {
        Box<int> intBox(42);
        std::cout << "Box contains: " << intBox.getValue() << '\n';

        Box<std::string> stringBox;
        stringBox.setValue("Hello");
        std::cout << "Box contains: " << stringBox.getValue() << '\n';
    }

    {
        PairBox<int, std::string> user(1, "Admin");
        PairBox<double, double> coordinates(46.48, 30.73);
    }

    {
        Array<int> intArray(5);
        for (int i = 0; i < intArray.getSize(); ++i)
        {
            intArray[i] = i * 2;
        }
        intArray.print();

        Array<double> doubleArray(3);
        for (int i = 0; i < doubleArray.getSize(); ++i)
        {
            doubleArray[i] = i * 1.5;
        }
        doubleArray.print();
    }

    return 0;
}