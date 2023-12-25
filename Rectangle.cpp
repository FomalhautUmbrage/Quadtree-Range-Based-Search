#include "Rectangle.h"

Rectangle::Rectangle(Point s, Point e, int count)
{
	this->start_point = s;
	this->end_point = e;
	max_count = count;
	now_count = 0;
	points = new Point[count];
}

Rectangle::~Rectangle()
{
	freeRectangle();
}

bool Rectangle::full()
{
	return points == nullptr || now_count >= max_count;
}

bool Rectangle::empty()
{
	return now_count == 0;
}

void Rectangle::addPoint(Point p)
{
	if (!full())
		points[now_count++] = p;
}

bool Rectangle::inRectangle(Point p)
{
	return p.getX() >= start_point.getX() && p.getX() <= end_point.getX() && p.getY() >= start_point.getY() && p.getY() <= end_point.getY();
}

bool Rectangle::inRangeRectangle(Point p)
{
	return p.getX() > start_point.getX() && p.getX() < end_point.getX() && p.getY() > start_point.getY() && p.getY() < end_point.getY();
}

Point Rectangle::getPoint(int index)
{
	if (index >= now_count || index < 0)
		return Point();
	return points[index];
}

void Rectangle::freeRectangle()
{
	now_count = max_count = 0;
	if (points != nullptr)
		delete[] points;
	points = nullptr;
}

int Rectangle::getPointCount()
{
	return now_count;
}

Point Rectangle::getStartPoint()
{
	return start_point;
}

Point Rectangle::getEndPoint()
{
	return end_point;
}

Point Rectangle::getCenterMidPoint()
{
	return Point(start_point.getX() + (end_point.getX() - start_point.getX()) / 2, start_point.getY() + (end_point.getY() - start_point.getY()) / 2);
}

Point Rectangle::getUpLineMidPoint()
{
	return Point(start_point.getX() + (end_point.getX() - start_point.getX()) / 2, start_point.getY());
}

Point Rectangle::getLeftLineMidPoint()
{
	return Point(start_point.getX(), start_point.getY() + (end_point.getY() - start_point.getY()) / 2);
}

Point Rectangle::getDownLineMidPoint()
{
	return Point(start_point.getX() + (end_point.getX() - start_point.getX()) / 2, end_point.getY());
}

Point Rectangle::getRightLineMidPoint()
{
	return Point(end_point.getX(), start_point.getY() + (end_point.getY() - start_point.getY()) / 2);
}

bool Rectangle::inVertucalUpLine(Point p)
{
	Point pstart = getUpLineMidPoint();
	Point pend = getCenterMidPoint();
	if (p.getX() == pstart.getX() && p.getY() >= pstart.getY() && p.getY() <= pend.getY())
		return true;
	return false;
}

bool Rectangle::inVertucalDownLine(Point p)
{
	Point pstart = getCenterMidPoint();
	Point pend = getDownLineMidPoint();
	if (p.getX() == pstart.getX() && p.getY() >= pstart.getY() && p.getY() <= pend.getY())
		return true;
	return false;
}

bool Rectangle::inHorizontalLeftLine(Point p)
{
	Point pstart = getLeftLineMidPoint();
	Point pend = getCenterMidPoint();
	if (p.getY() == pstart.getY() && p.getX() >= pstart.getX() && p.getX() <= pend.getX())
		return true;
	return false;
}

bool Rectangle::inHorizontalRightLine(Point p)
{
	Point pstart = getCenterMidPoint();
	Point pend = getRightLineMidPoint();
	if (p.getY() == pstart.getY() && p.getX() >= pstart.getX() && p.getX() <= pend.getX())
		return true;
	return false;
}

bool Rectangle::inCenterMidPoint(Point p)
{
	return p == getCenterMidPoint();
}

bool Rectangle::searchDistancePoint(Point p, double d)
{
	for (int i = 0; i < now_count; i++) {
		if (points[i].getDistance(p) < d) {
			return true;
		}
	}
	return false;
}

Point Rectangle::findNearestPoint(Point p)
{
	double max_distance = DBL_MAX;
	Point fp;
	for (int i = 0; i < now_count; i++) {
		if (points[i].getDistance(p) < max_distance) {
			fp = points[i];
			max_distance = points[i].getDistance(p);
		}
	}
	return fp;
}

Point Rectangle::genertAnOutsidePoint()
{
	double dis = start_point.getDistance(end_point);
	return Point(start_point.getX() - dis, start_point.getY() - dis);
}

bool Rectangle::inOccure(Rectangle& rect)
{
	if (rect.getEndPoint().getX() < start_point.getX() || 
		end_point.getX() < rect.getStartPoint().getX() || 
		rect.getEndPoint().getY() < start_point.getY() || 
		end_point.getY() < rect.getStartPoint().getY()) {
		return false;
	}
	return true;
}

Point* Rectangle::pointInRect(Rectangle& rect, int& count)
{
	Point* ap = nullptr;
	count = 0;
	for (int i = 0; i < now_count; i++) {
		if (rect.inRangeRectangle(points[i])) {
			count += 1;
		}
	}
	if (count == 0)
		return nullptr;
	ap = new Point[count];
	int index = 0;
	for (int i = 0; i < now_count; i++) {
		if (rect.inRangeRectangle(points[i])) {
			ap[index++] = points[i];
		}
	}
	return ap;
}

