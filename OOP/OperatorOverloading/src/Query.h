#pragma once
#include <iostream>
#include <string>

class Query
{
private:
    std::string condition;

public:
    // Конструктор
    Query(const std::string &cond) : condition(cond) {}

    // Перевантаження логічного AND (&&)
    Query operator&&(const Query &other) const
    {
        return Query("(" + condition + " AND " + other.condition + ")");
    }

    // Перевантаження логічного OR (||)
    Query operator||(const Query &other) const
    {
        return Query("(" + condition + " OR " + other.condition + ")");
    }

    // Вивід результату
    void print() const
    {
        std::cout << "SQL WHERE " << condition << "\n";
    }
};