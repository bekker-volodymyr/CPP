#include <iostream>
#include "point.h"
using namespace std;

Point readPoint() {
	Point p;
	
	cout << "Введіть X: ";
	cin >> p.x;

	cout << "Введіть Y: ";
	cin >> p.y;
	
	return p;
}

void printPoint(const Point& p) {
	printf("P( x = %.3f, y = %.3f )", p.x, p.y);
}

double calcDistance(const Point& p1, const Point& p2) {
	double temp1 = p2.x - p1.x;
	double temp2 = p2.y - p1.y;

	return sqrt(pow(temp1, 2) + pow(temp2, 2));
}

Point midPoint(const Point& p1, const Point& p2) {
	Point midpoint;
	midpoint.x = (p1.x + p2.x) / 2.0;
	midpoint.y = (p1.y + p2.y) / 2.0;
	return midpoint;
}