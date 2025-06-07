#pragma once

template<typename T>
class Comparer {
public:
    // Порівняння двох значень
    static bool isEqual(const T& a, const T& b) {
        return a == b;
    }
};