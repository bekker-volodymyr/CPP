#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>

int main(int argc, char **argv)
{
    // vector examples
    {
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        std::cout << "Vector elements: ";
        for (const auto &num : numbers)
        {
            std::cout << num << ' ';
        }
        std::cout << "\nVector size: " << numbers.size() << '\n';
        std::cout << "Vector capacity: " << numbers.capacity() << '\n';
        std::cout << "Vector element at index 2: " << numbers.at(2) << '\n';

        numbers.push_back(6);
        numbers.insert(numbers.begin() + 1, 10);

        std::cout << "Vector elements after modify: ";
        for (const auto &num : numbers)
        {
            std::cout << num << ' ';
        }
        std::cout << '\n';

        numbers.pop_back();
        numbers.erase(numbers.begin() + 1);
        numbers.clear();

        std::cout << (numbers.empty() ? "Vector is empty." : "Vector is not empty.") << '\n';
    }

    // array example
    {
        std::array<int, 5> numbers = {10, 20, 30, 40, 50};

        std::cout << "Array size: " << numbers.size() << '\n';

        numbers[0] = 99;
        numbers.at(1) = 88;

        std::cout << "First: " << numbers.front() << '\n';
        std::cout << "Last: " << numbers.back() << '\n';

        std::cout << "Elements: ";
        for (int num : numbers)
            std::cout << num << " ";
        std::cout << '\n';

        numbers.fill(0);
    }

    // list example
    {
        std::list<int> numbers = {20, 30, 40};

        numbers.push_front(10);
        numbers.push_back(50);

        std::cout << "First: " << numbers.front() << '\n';
        std::cout << "Last: " << numbers.back() << '\n';

        auto it = numbers.begin();
        std::advance(it, 2);
        numbers.insert(it, 99);

        numbers.remove(30);

        std::cout << "Elements: ";
        for (int num : numbers)
            std::cout << num << " ";
        std::cout << '\n';
    }

    // map and multimap
    {
        std::map<std::string, int> grades;

        grades["Alex"] = 95;
        grades["Marie"] = 88;
        grades["Alex"] = 98;

        for (const auto &[name, score] : grades)
            std::cout << name << ": " << score << '\n';

        std::multimap<std::string, std::string> notes;

        notes.insert({"work", "Fix bug #3444"});
        notes.insert({"learning", "Watch video about binary trees"});
        notes.insert({"work", "Send the report"});

        for (const auto &[category, text] : notes)
            std::cout << "[" << category << "] " << text << '\n';

        std::cout << "\nCategory 'work':\n";
        auto range = notes.equal_range("work");
        for (auto it = range.first; it != range.second; ++it)
            std::cout << "- " << it->second << '\n';
    }

    // set and multiset
    {
        std::set<std::string> tags;

        tags.insert("cpp");
        tags.insert("programming");
        tags.insert("stl");
        tags.insert("cpp");

        for (const auto &tag : tags)
            std::cout << tag << " ";
        std::cout << '\n';

        if (tags.find("stl") != tags.end())
            std::cout << "Tag 'stl' was found!\n";

        std::multiset<int> diceRolls;

        diceRolls.insert(4);
        diceRolls.insert(6);
        diceRolls.insert(4);
        diceRolls.insert(2);
        diceRolls.insert(4);

        for (int roll : diceRolls)
            std::cout << roll << " ";
        std::cout << '\n';

        std::cout << "Count of 4: " << diceRolls.count(4) << '\n';
    }

    // stack
    {
        std::stack<std::string> browserHistory;

        browserHistory.push("google.com");
        browserHistory.push("github.com");
        browserHistory.push("stackoverflow.com");

        std::cout << "Current page: " << browserHistory.top() << '\n';
        std::cout << "Pages visited: " << browserHistory.size() << '\n';
        browserHistory.pop();

        std::cout << "Current page: " << browserHistory.top() << '\n';

        std::cout << "\nClear history:\n";
        while (!browserHistory.empty())
        {
            std::cout << "Close: " << browserHistory.top() << '\n';
            browserHistory.pop();
        }

        std::cout << (browserHistory.empty() ? "History cleared" : "History not cleared") << '\n';
    }

    // queue
    {
        std::queue<std::string> printQueue;

        printQueue.push("Document_1.pdf");
        printQueue.push("Photo_Vacation.png");
        printQueue.push("Report_Q3.docx");

        std::cout << "Next to print: " << printQueue.front() << '\n';
        std::cout << "Last to print: " << printQueue.back() << '\n';
        std::cout << "Queue count: " << printQueue.size() << '\n';

        printQueue.pop();

        std::cout << "Next to print: " << printQueue.front() << '\n';

        while (!printQueue.empty())
        {
            std::cout << "Printing: " << printQueue.front() << '\n';
            printQueue.pop();
        }

        std::cout << (printQueue.empty() ? "All files printed" : "Print queue not empty") << '\n';
    }

    // deque
    {
        std::deque<int> d = {20, 30};

        d.push_back(40);
        d.push_front(10);

        std::cout << "Element with index 2: " << d[2] << '\n';

        d.pop_front();
        d.pop_back();

        std::cout << "Left: ";
        for (int x : d)
        {
            std::cout << x << " ";
        }
        std::cout << '\n';
    }

    // hash-tables
    {
        std::unordered_map<std::string, std::string> phoneBook;

        phoneBook["Alex"] = "+380501112233";
        phoneBook["Marie"] = "+380674445566";

        std::string name = "Marie";
        if (phoneBook.find(name) != phoneBook.end())
        {
            std::cout << name << " phone: " << phoneBook[name] << '\n';
        }

        std::unordered_set<int> uniqueIds = {105, 42, 89, 42};

        if (uniqueIds.contains(89))
        {
            std::cout << "ID 89 was found!\n";
        }
    }

    // priority queue
    {
        std::priority_queue<int> pq;

        pq.push(10);
        pq.push(50);
        pq.push(20);
        pq.push(30);

        std::cout << "Top priority: " << pq.top() << '\n';

        while (!pq.empty())
        {
            std::cout << pq.top() << " ";
            pq.pop();
        }
        std::cout << '\n';
    }
}
