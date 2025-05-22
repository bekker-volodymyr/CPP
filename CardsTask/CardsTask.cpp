#include <iostream>

enum Suits {
    Spades = 1,
    Hearths,
    Dimonds,
    Clubs
};

enum Ranks {
    Ace = 14, King = 13, Queen = 12, Jack = 11
};

void PrintCard(Suits suit, Ranks rank) {
    // тут малюємо карту
}

int main()
{
    std::cout << "Hello World!\n";
}