class DynamicArray
{
private:
    int *data;
    int size;

public:
    DynamicArray(int size);
    DynamicArray(const DynamicArray &other);
    DynamicArray &operator=(const DynamicArray &other);
    ~DynamicArray();
};
