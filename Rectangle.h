#pragma once
#include "Point.h"
class Rectangle
{
private:
	Point start_point;
	Point end_point;
	Point* points;			
	int now_count;			
	int max_count;			
public:
	Rectangle(Point s, Point e, int count);		
	~Rectangle();
	bool full();		
	bool empty();		
	void addPoint(Point p);		
	bool inRectangle(Point p);
	bool inRangeRectangle(Point p);
	Point getPoint(int index);
	void freeRectangle();	
	int getPointCount();
	Point getStartPoint();
	Point getEndPoint();
	Point getCenterMidPoint();
	Point getUpLineMidPoint();
	Point getLeftLineMidPoint();
	Point getDownLineMidPoint();
	Point getRightLineMidPoint();
	bool inVertucalUpLine(Point p);
	bool inVertucalDownLine(Point p);
	bool inHorizontalLeftLine(Point p);
	bool inHorizontalRightLine(Point p);
	bool inCenterMidPoint(Point p);

	bool searchDistancePoint(Point p, double d);
	Point findNearestPoint(Point p);
	Point genertAnOutsidePoint();

	bool inOccure(Rectangle& rect);
	Point* pointInRect(Rectangle& rect, int& count);
};

