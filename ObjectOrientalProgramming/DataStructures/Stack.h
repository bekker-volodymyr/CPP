#pragma once

#include <iostream>

template <typename T>
class Stack
{
private:
    T *data;        // Динамічний масив для зберігання елементів
    int capacity;   // Поточна ємність стека
    int top;        // Індекс верхнього елемента
public:
    Stack(int initCapacity = 10) : capacity(initCapacity), top(-1)
    {
        data = new T[capacity]; // Виділяємо пам'ять для масиву
    }
    ~Stack()
    {
        delete[] data; // Звільняємо пам'ять
    }

    void push(const T &value);
    T pop();
    T peek() const;

    void resize(int newCapacity);

    bool isEmpty() const
    {
        return top == -1; // Перевіряємо, чи стек порожній
    }
    int size() const
    {
        return top + 1; // Повертаємо кількість елементів у стеці
    }
    void clear()
    {
        top = -1; // Очищаємо стек, встановлюючи індекс верхнього елемента на -1
    }
    
};

template <typename T>
void Stack<T>::resize(int newCapacity)
{
    T *newData = new T[newCapacity]; // Виділяємо нову пам'ять
    for (int i = 0; i <= top; i++)
    {
        newData[i] = data[i]; // Копіюємо старі елементи
    }
    delete[] data; // Звільняємо стару пам'ять
    data = newData; // Перенаправляємо вказівник на новий масив
    capacity = newCapacity; // Оновлюємо ємність
}

template <typename T>
void Stack<T>::push(const T &value)
{
    if (top + 1 >= capacity) // Якщо стек заповнений
    {
        resize(capacity * 2); // Подвоюємо ємність
    }
    data[++top] = value; // Додаємо новий елемент
}

template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        std::cerr << "Stack underflow: Cannot pop from an empty stack.\n";
        throw std::out_of_range("Stack is empty"); // Викидаємо виключення, якщо стек порожній
    }
    return data[top--]; // Повертаємо верхній елемент і зменшуємо індекс
}

template <typename T>
T Stack<T>::peek() const
{
    if (isEmpty())
    {
        std::cerr << "Stack is empty: Cannot peek.\n";
        throw std::out_of_range("Stack is empty"); // Викидаємо виключення, якщо стек порожній
    }
    return data[top]; // Повертаємо верхній елемент без видалення
}