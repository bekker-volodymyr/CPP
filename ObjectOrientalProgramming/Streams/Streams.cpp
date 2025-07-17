#include <iostream>
#include <fstream>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}	

	friend ostream& operator<<(ostream& os, const Point& p) {
		os << "Point(" << p.x << ", " << p.y << ")";
		return os;
	}
	friend istream& operator>>(istream& is, Point& p) {
		is >> p.x >> p.y;
		return is;
	}
};

int main()
{
    {
		// Використання потоків введення та виведення

		cout << "Hello, World!" << endl; // Виведення на консоль
		string input;
		cin >> input; // Введення з консолі
		cerr << "Error: " << input << endl; // Виведення помилки на консоль
		clog << "Log: " << input << endl; // Виведення журналу на консоль
		
		Point p1(3, 4);
		cout << "Point p1: " << p1 << endl; // Виведення об'єкта Point
		Point p2;
		cout << "Enter coordinates for Point p2 (x y): ";
		cin >> p2; // Введення об'єкта Point
    }

	{
		// Створення потоку та зв'язування з файлом
		// режим відкриття файлу: 
		// ios_base::in - відкриття для читання
		// ios_base::out - відкриття для запису
		// ios_base::app - додавання до кінця файлу
		fstream file("example.txt", ios_base::app);
		if (!file) {
			cerr << "Error opening file!" << endl;
			return 1;
		}
		file.close(); // Закриття файлу
	}

	{
		fstream fs;

		fs.open("example.txt", ios_base::in | ios_base::out | ios_base::app);

		// працюємо з файлом

		fs.close(); // Закриття файлу
	}

	{
		ifstream is("example.txt");

		if (!is) {
			cerr << "Error opening file for reading!" << endl;
			return 1;
		}

		char* line = new char[101];
		is.read(line, 100); // Читання до 100 символів з файлу
		int readCount = is.gcount(); // Скільки реально прочитано
		line[readCount] = '\0'; // Коректно ставимо '\0' після прочитаних байтів
		cout << "Read line: " << line << endl;
		delete[] line; // Звільнення пам'яті
	}

	{
		ofstream os("output.txt");

		if(!os) {
			cerr << "Error opening file for writing!" << endl;
			return 1;
		}

		os << "Hello, file!" << endl; // Запис рядка у файл

		Point p(5, 10);
		os << p << endl; // Запис об'єкта Point у файл

		os.write("This is a test.", 14); // Запис 14 символів у файл
	}
}