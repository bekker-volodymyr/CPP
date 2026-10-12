#include <iostream>
#include <vector>

class SecuritySettings
{
private:
    bool twoFactorAuth;
    std::string ipWhitelist;

public:
    SecuritySettings(bool tfa, const std::string &ip)
        : twoFactorAuth(tfa), ipWhitelist(ip) {}

    void display() const
    {
        std::cout << "2FA: " << (twoFactorAuth ? "On." : "Off.")
                  << ", Trusted IP: " << ipWhitelist << '\n';
    }
};

class UserProfile
{
private:
    std::string username;
    SecuritySettings settings;

public:
    UserProfile(const std::string &name, bool tfa, const std::string &ip)
        : username(name), settings(tfa, ip)
    {
        std::cout << "[User] User " << username << " created.\n";
    }

    void showProfile() const
    {
        std::cout << "User: " << username << " | ";
        settings.display();
    }
};

class Student
{
public:
    std::string name;
    Student(std::string n) : name(n) {}
};

class University
{
private:
    std::string name;
    std::vector<Student *> students;

public:
    University(std::string n) : name(n) {}

    void addStudent(Student *s)
    {
        students.push_back(s);
    }

    void show()
    {
        std::cout << name << " має студентів: ";
        for (auto s : students)
            std::cout << s->name << " ";
        std::cout << '\n';
    }
};

class Document
{
public:
    void print() { std::cout << "Printing document...\n"; }
};

class Printer
{
public:
    void printDocument(Document &doc)
    {
        doc.print();
    }
};

int main(int argc, char **argv)
{
    std::cout << "hello world!" << std::endl;
    return 0;
}
