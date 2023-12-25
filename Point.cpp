#include "Point.h"

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& p)
{
	this->x = p.x;
	this->y = p.y;
}

Point::~Point()
{
}

double Point::getX()
{
	return x;
}

void Point::setX(double x)
{
	this->x = x;
}

double Point::getY()
{
	return y;
}

void Point::setY(double y)
{
	this->y = y;
}

Point& Point::operator=(const Point& b)
{
	x = b.x;
	y = b.y;
	return *this;
}

double Point::getDistance(Point p)
{
	return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
}

bool operator==(const Point& a, const Point& b)
{
	return a.x == b.x && a.y == b.y;
}

ostream& operator<<(ostream& out, const Point& a)
{
	out << a.x << " " << a.y;
	return out;
}

istream& operator>>(istream& in, Point& a)
{
	in >> a.x >> a.y;
	return in;
}

