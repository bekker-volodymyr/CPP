#pragma once

#include <iostream>

template <typename T>
class Queue
{
private:
    T *data;      // Динамічний масив для зберігання елементів
    int capacity; // Поточна ємність черги
    int front;    // Індекс переднього елемента
    int last;     // Індекс заднього елемента
    int size;     // Кількість елементів у черзі
public:
    Queue(int initCapacity = 10) : capacity(initCapacity), front(0), last(-1), size(0)
    {
        data = new T[capacity]; // Виділяємо пам'ять для масиву
    }
    ~Queue()
    {
        delete[] data; // Звільняємо пам'ять
    }

    void enqueue(const T &value);
    T dequeue();
    T peek() const;

    void resize(int newCapacity);

    bool isEmpty() const
    {
        return size == 0; // Перевіряємо, чи черга порожня
    }
    int getSize() const
    {
        return size; // Повертаємо кількість елементів у черзі
    }
    void clear()
    {
        front = 0;
        last = -1;
        size = 0; // Очищаємо чергу, встановлюючи індекси та розмір на початкові значення
    }
};

template <typename T>
void Queue<T>::resize(int newCapacity)
{
    T *newData = new T[newCapacity]; // Виділяємо нову пам'ять
    for (int i = 0; i < size; i++)
    {
        newData[i] = data[(front + i) % capacity]; // Копіюємо старі елементи
    }
    delete[] data; // Звільняємо стару пам'ять
    data = newData; // Перенаправляємо вказівник на новий масив
    front = 0; // Встановлюємо front на початок нового масиву
    last = size - 1; // Оновлюємо індекс останнього елемента
    capacity = newCapacity; // Оновлюємо ємність
}

template <typename T>
void Queue<T>::enqueue(const T &value)
{
    if (size >= capacity) // Якщо черга заповнена
    {
        resize(capacity * 2); // Подвоюємо ємність
    }
    last = (last + 1) % capacity; // Оновлюємо індекс останнього елемента
    data[last] = value; // Додаємо новий елемент
    size++; // Збільшуємо розмір черги
}

template <typename T>
T Queue<T>::dequeue()
{
    if (isEmpty()) // Якщо черга порожня
    {
        std::cerr << "Queue is empty, cannot dequeue.\n";
        throw std::out_of_range("Queue is empty");
    }
    T value = data[front]; // Зберігаємо значення переднього елемента
    front = (front + 1) % capacity; // Оновлюємо індекс переднього елемента
    size--; // Зменшуємо розмір черги
    return value; // Повертаємо значення
}

template <typename T>
T Queue<T>::peek() const
{
    if (isEmpty()) // Якщо черга порожня
    {
        std::cerr << "Queue is empty, cannot peek.\n";
        throw std::out_of_range("Queue is empty");
    }
    return data[front]; // Повертаємо значення переднього елемента
}