#pragma once
struct Point
{
	double x;
	double y;

	Point(double key1, double key2);
	Point() : x(0), y(0) {};
	Point operator=(const Point& other);
};

class Line
{
	Point* arr;
	size_t size_of;

public:
	Line() :arr(nullptr), size_of(0) {}
	Line(size_t count) : arr(new Point[count]), size_of(count) {}
	Line(const Line& p);
	~Line();
	Line operator=(const Line& other);
	Point& operator[](size_t index);
	Line operator+=(const Point& point);
	Line operator+=(const Line& other);
	Line operator+(const Point& point);
	Line operator+(const Line& other);
	friend Line operator+(const Point& point, const Line& other);
	size_t size();
	double lenght();

private:
	double distance(const Point& point1, const Point& point2);
	void checkIndex(size_t index);
};

