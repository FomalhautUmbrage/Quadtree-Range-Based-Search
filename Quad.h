#pragma once
#include "Rectangle.h"
class Quad
{
private:
	int n_points;		//max points number
	Rectangle* rectangle;
	Quad* child[4];			//lu,ru,ld,rd
private:
	bool searchLoop(Quad* quad, Point p, double d);
	bool nearestLoop(Quad* quad, Point p, Point& fidP);
	Point* rangeLoop(Quad* quad, Rectangle& rect, Point* allp, int& count);
	bool inOccure(Rectangle& rect);
	int numLoop(Quad* quad);


	bool inRectangle(Point p);
	bool exitsPoint(Point p);
	bool isLeaf();

public:
	Quad(Point satrt, Point end, int np);
	~Quad();
	bool insertPoint(Point p);
	bool searchPoint(Point p, double d);
	bool nearestPoint(Point p, Point& fidP);
	Point* range(Point startp, Point endp, int& count);
	int num();
	
	
};

