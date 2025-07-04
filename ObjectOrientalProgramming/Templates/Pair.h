#pragma once

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 f, T2 s) : first(f), second(s) {}

    void print() const {
        std::cout << "(" << first << ", " << second << ")\n";
    }
};