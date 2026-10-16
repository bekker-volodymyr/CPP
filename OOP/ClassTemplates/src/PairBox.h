template <typename T, typename U>
class PairBox
{
private:
    T first;
    U second;

public:
    PairBox(T f, U s) : first(f), second(s) {}

    void printInfo() const
    {
        std::cout << "First: " << first << ", Second: " << second << '\n';
    }
};