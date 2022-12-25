#include "Line.h"
#include <math.h>
#include <iostream>


Point::Point(double key1, double key2)
{
	x = key1;
	y = key2;
}


Point Point::operator=(const Point& other) {
	x = other.x;
	y = other.y;

	return *this;
}

Line::Line(const Line& other)
{
	arr = new Point[other.size_of];
	size_of = other.size_of;
	for (size_t i = 0; i < size_of; i++)
	{
		arr[i] = other.arr[i];
	}
}


Line::~Line()
{
	delete[] arr;
	size_of = 0;
}


Line Line::operator=(const Line& other) {
	if (this == &other) {
		return *this;
	}

	delete[] arr;
	size_of = other.size_of;
	arr = new Point[size_of];

	for (size_t i = 0; i < size_of; i++)
		arr[i] = other.arr[i];

	return *this;
}


Point& Line::operator[](size_t index) {
	checkIndex(index);
	return arr[index];
}


Line Line::operator+=(const Point& point) {
	Point* helpArr = new Point[size_of + 1];
	for (size_t i = 0; i < size_of; i++)
		helpArr[i] = arr[i];
	helpArr[size_of] = point;

	delete[] arr;
	size_of++;
	arr = new Point[size_of];

	for (size_t i = 0; i < size_of; i++)
		arr[i] = helpArr[i];

	delete[] helpArr;
	return *this;
}


Line Line::operator+=(const Line& other) {
	Point* helpArr = new Point[size_of + other.size_of];

	for (size_t i = 0; i < size_of; i++)
		helpArr[i] = arr[i];
	for (size_t i = size_of; i < size_of + other.size_of; i++)
		helpArr[i] = arr[i - size_of];

	delete[] arr;
	size_of += other.size_of;
	arr = new Point[size_of];

	for (size_t i = 0; i < size_of; i++)
		arr[i] = helpArr[i];

	delete[] helpArr;
	return *this;
}


Line Line::operator+(const Point& point) {
	Line NewLine(size_of + 1);

	for (size_t i = 0; i < size_of; i++)
		NewLine.arr[i] = arr[i];
	NewLine.arr[size_of] = point;

	return NewLine;
}


Line Line::operator+(const Line& other) {
	Line NewLine(size_of + other.size_of);

	for (size_t i = 0; i < size_of; i++)
		NewLine.arr[i] = arr[i];
	for (size_t i = size_of; i < size_of + other.size_of; i++)
		NewLine.arr[i] = other.arr[i - size_of];

	return NewLine;
}


Line operator+(const Point& point, const Line& other) {
	Line NewLine(other.size_of + 1);

	NewLine.arr[0] = point;
	for (size_t i = 0; i < other.size_of; i++)
		NewLine.arr[i + 1] = other.arr[i];


	return NewLine;
}


size_t Line::size() {
	return size_of;
}


double Line::lenght() {
	double len = 0;
	for (size_t i = 0; i < size_of - 1; i++) {
		len += distance(arr[i], arr[i + 1]);
	}
	return len;
}


double Line::distance(const Point& point1, const Point& point2) {
	double x = point2.x - point1.x;
	double y = point2.y - point1.y;

	return sqrt(x * x + y * y);
}


void Line::checkIndex(size_t index) {
	if (index >= size_of) {
		throw std::out_of_range("Index is greater than the number of points");
	}
}
