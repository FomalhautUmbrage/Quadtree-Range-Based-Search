#pragma once
#include <cmath>
#include <iostream>
#include <float.h>
using namespace std;
class Point
{
private:
	double x;
	double y;
public:
	Point(double x = 0, double y = 0);
	Point(const Point& p);			//Point a;  b.setX(a.getX());b.setY(a.getY());  Point b(a);
	~Point();
	double getX();
	void setX(double x);
	double getY();
	void setY(double y);	
	friend bool operator==(const Point& a, const Point& b);
	friend ostream& operator<<(ostream& out, const Point& a);	//cout<<a.getX()<<" "<<a.getY()<<endl;  cout<<a;
	friend istream& operator>>(istream& in, Point& a);			//cin>>x>>y; a.setX(x);a.setY(y); cin>>a;
	Point& operator=(const Point& b);		//Point a,b;  b=a;
	double getDistance(Point p);		//

};

