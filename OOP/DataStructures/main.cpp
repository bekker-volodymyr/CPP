#include <iostream>

#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

template <typename T>
void printNode(T &node)
{
    cout << node << " ";
}

int main()
{

    {
        // Приклад масиву
        int arr[] = {1, 2, 3, 4, 5};

        // Приклад динамічного масиву
        int size;
        cout << "Enter the size of the dynamic array: ";
        cin >> size;
        int *dynamicArr = new int[size];

        for (int i = 0; i < size; i++)
        {
            dynamicArr[i] = rand() % 10; // Заповнення динамічного масиву
        }

        // Швидке отримання елементу за індексом
        cout << arr[3] << '\n';

        // Додавання елементу вимагає перерозподілу пам'яті
        int *temp = new int[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = dynamicArr[i];
        }
        temp[size] = 6;      // Додавання нового елементу
        delete[] dynamicArr; // Звільнення старого масиву
        dynamicArr = temp;   // Перенаправлення вказівника на новий масив
        size++;              // Збільшення розміру масиву
    }

    {
        LinkedList<int> list; // Створення зв'язного списку
        // Додавання елементів до зв'язного списку
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);
        cout << "Linked List Size: " << list.getSize() << '\n';
        cout << "Head: " << list.getHead()->data << '\n'; // Виведення голови списку
        cout << "Tail: " << list.getTail()->data << '\n'; // Виведення хвоста списку
        // Перебір елементів зв'язного списку
        Node<int> *current = list.getHead();
        cout << "Linked List Elements: ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << '\n';
        // Видалення елементів зі зв'язного списку
        list.removeAt(2);               // Видалення елементу за індексом
        list.insertAt(2, 6);            // Вставка елементу на індекс 2
        Node<int> *node = list.find(4); // Пошук елементу зі значенням 4
        int val = list.getAt(1);        // Отримання елементу за індексом 1

        cout << "Linked List Elements: ";
        list.forEach(printNode<int>); // Виклик функції для кожного елементу списку
        cout<<'\n';
    }

    {
        // Приклад використання стеку
        Stack<int> stack; // Створення стеку
        stack.push(1);    // Додавання елементу до стеку
        stack.push(2);    // Додавання ще одного елементу
        stack.push(3);    // Додавання третього елементу
        cout << "Stack Size: " << stack.size() << '\n'; // Виведення розміру стеку
        cout << "Top Element: " << stack.peek() << '\n'; // Виведення верхнього елементу стеку
        cout << "Popping elements from stack: ";
        while (!stack.isEmpty())
        {
            cout << stack.pop() << " "; // Виведення та видалення верхнього елементу стеку
        }
        cout << '\n';
    }

    {
        // Приклад використання черги
        Queue<int> queue; // Створення черги
        queue.enqueue(1); // Додавання елементу до черги
        queue.enqueue(2); // Додавання ще одного елементу
        queue.enqueue(3); // Додавання третього елементу
        cout << "Queue Size: " << queue.getSize() << '\n'; // Виведення розміру черги
        cout << "Front Element: " << queue.peek() << '\n'; // Виведення переднього елементу черги
        cout << "Dequeuing elements from queue: ";
        while (!queue.isEmpty())
        {
            cout << queue.dequeue() << " "; // Виведення та видалення переднього елементу черги
        }
        cout << '\n';
    }

    return 0;
}