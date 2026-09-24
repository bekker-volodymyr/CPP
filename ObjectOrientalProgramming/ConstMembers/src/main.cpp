#include <iostream>

class Cat
{
private:
    char *nickname;
    int age;
    mutable int clickCounter = 0;

public:
    Cat(const char *name, int catAge)
    {
        age = catAge;
        int length = strlen(name) + 1;
        nickname = new char[length];
        strcpy(nickname, name);
    }
    ~Cat()
    {
        delete[] nickname;
    }

    const char *getNickname() const
    {
        clickCounter++;
        return nickname;
    }
    int getAge() const
    {
        return age;
    }
};

int main()
{
    Cat myCat("Barsik", 3);

    std::cout << "Name: " << myCat.getNickname() << '\n';
    std::cout << "Age: " << myCat.getAge() << '\n';

    return 0;
}