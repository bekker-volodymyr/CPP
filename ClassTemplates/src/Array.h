#pragma once

template <typename T>
class Array
{
private:
    T *arr;
    int size;

public:
    Array(int s);
    Array(const Array<T> &other);
    Array<T> &operator=(const Array<T> &other);
    Array(Array<T> &&other) noexcept;
    Array<T> &operator=(Array<T> &&other) noexcept;

    ~Array();

    T operator[](int index) const;
    T &operator[](int index);

    void pushBack(T value);
    void popBack();

    int getSize() const { return size; }
    void print() const;
};

template <typename T>
Array<T>::Array(int s) : size(s)
{
    arr = new T[size];
}

template <typename T>
Array<T>::Array(const Array<T> &other) : size(other.size)
{
    arr = new T[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        delete[] arr;
        size = other.size;
        arr = new T[size];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::Array(Array<T> &&other) noexcept : arr(other.arr), size(other.size)
{
    other.arr = nullptr;
    other.size = 0;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> &&other) noexcept
{
    if (this != &other)
    {
        delete[] arr;
        arr = other.arr;
        size = other.size;

        other.arr = nullptr;
        other.size = 0;
    }

    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}

template <typename T>
T Array<T>::operator[](int index) const
{
    return arr[index];
}

template <typename T>
T &Array<T>::operator[](int index)
{
    return arr[index];
}

template <typename T>
void Array<T>::print() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Array<T>::pushBack(T value)
{
    // 1. Виділяємо пам'ять під новий масив більшого розміру
    T *newArr = new T[size + 1];

    // 2. Копіюємо старі елементи
    for (int i = 0; i < size; ++i)
    {
        newArr[i] = arr[i];
    }

    // 3. Додаємо новий елемент в кінець
    newArr[size] = value;

    // 4. Звільняємо стару пам'ять
    delete[] arr;

    // 5. Оновлюємо вказівник та розмір
    arr = newArr;
    size++;
}

template <typename T>
void Array<T>::popBack()
{
    // Захист: нічого не робимо, якщо масив вже порожній
    if (size == 0)
        return;

    // 1. Створюємо вказівник для нового масиву
    T *newArr = nullptr;

    // 2. Якщо в масиві залишиться хоча б один елемент, виділяємо пам'ять і копіюємо
    if (size > 1)
    {
        newArr = new T[size - 1];
        for (int i = 0; i < size - 1; ++i)
        {
            newArr[i] = arr[i];
        }
    }

    // 3. Звільняємо стару пам'ять
    delete[] arr;

    // 4. Оновлюємо вказівник та розмір (якщо size був 1, arr стане nullptr)
    arr = newArr;
    size--;
}