#include <iostream>

class Box {
private:
    int width;
public:
    Box(int w) : width(w) {
        std::cout << "Box created with width: " << width << '\n';
    }
    // Оголошення дружньої функції
    friend void printWidth(const Box& b);
};

// Реалізація дружньої функції
// Дружня функція для доступу до приватного члена width
void printWidth(const Box& b) {
    std::cout << "Width of box: " << b.width << '\n';
}