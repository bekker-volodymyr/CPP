#include <iostream>

class StringBuffer
{
private:
    char *buffer;
    int capacity;

public:
    explicit StringBuffer(int size)
    {
        capacity = size;
        buffer = new char[capacity];
        std::cout << "Buffer created with size: " << capacity << '\n';
    }

    ~StringBuffer()
    {
        delete[] buffer;
    }
};

void processBuffer(const StringBuffer &buf)
{
    std::cout << "Processing buffer...\n";
}

int main()
{
    StringBuffer myBuf(100);
    processBuffer(myBuf);

    // processBuffer(20);

    return 0;
}