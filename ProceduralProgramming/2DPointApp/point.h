#pragma once

struct Point {
	double x;
	double y;
};

// Зчитує точку у користувача
Point readPoint();

// Виводить точку в консоль в форматі P( x = [0.000], y = [0.000] )
void printPoint(const Point&);

// Розраховує відстань між двома точками
double calcDistance(const Point&, const Point&);

// Розраховує середню точку між двома точками
Point midPoint(const Point&, const Point&);