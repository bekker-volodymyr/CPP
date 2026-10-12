#pragma once

#include <iostream>

// Структура вузла
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList();

    void append(const T& value);

    Node<T>* find(const T& value) const;

    void insertAt(int index, const T& value);
    void removeAt(int index);

    void forEach(void (*func)(T&));

    T getAt(int index) const;

    int getSize() const
    {
        return size;
    }
    Node<T>* getHead() const
    {
        return head;
    }
    Node<T>* getTail() const
    {
        return tail;
    }
    
};

template <typename T>
void LinkedList<T>::append(const T& value)
{
    // Створюємо новий вузол
    Node<T> *newNode = new Node<T>(value);
    if (tail == nullptr) // Якщо список порожній
    {
        // Встановлюємо head і tail на новий вузол
        head = tail = newNode;
    }
    else // Якщо список не порожній
    {
        // Додаємо новий вузол в кінець списку
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
T LinkedList<T>::getAt(int index) const
{
    if (index < 0 || index >= size)
    {
        std::cerr << "Index out of bounds\n";
        return head->data; // Повертаємо значення за замовчуванням
    }
    // Шукаємо вузол за індексом
    Node<T> *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    // Звільняємо пам'ять, видаляючи всі вузли
    Node<T> *current = head;
    while (current != nullptr)
    {
        Node<T> *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
Node<T>* LinkedList<T>::find(const T& value) const
{
    // Шукаємо вузол з заданим значенням
    Node<T> *current = head;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            return current; // Повертаємо знайдений вузол
        }
        current = current->next;
    }
    return nullptr; // Якщо вузол не знайдено, повертаємо nullptr
}

template <typename T>
void LinkedList<T>::insertAt(int index, const T& value)
{
    if (index < 0 || index > size)
    {
        std::cerr << "Index out of bounds\n";
        return;
    }
    Node<T> *newNode = new Node<T>(value);
    if (index == 0) // Вставка на початок
    {
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) // Якщо список був порожній
        {
            tail = newNode;
        }
    }
    else if (index == size) // Вставка в кінець
    {
        tail->next = newNode;
        tail = newNode;
    }
    else // Вставка в середину
    {
        Node<T> *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= size)
    {
        std::cerr << "Index out of bounds\n";
        return;
    }
    Node<T> *toDelete = nullptr;
    if (index == 0) // Видалення з початку
    {
        toDelete = head;
        head = head->next;
        if (head == nullptr) // Якщо список став порожнім
        {
            tail = nullptr;
        }
    }
    else // Видалення з середини або кінця
    {
        Node<T> *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete == tail) // Якщо видаляємо хвіст
        {
            tail = current;
        }
    }
    delete toDelete; // Звільняємо пам'ять
    size--;
}

template <typename T>
void LinkedList<T>::forEach(void (*func)(T&))
{
    // Перебираємо всі вузли і викликаємо функцію для кожного
    Node<T> *current = head;
    while (current != nullptr)
    {
        func(current->data);
        current = current->next;
    }
}