#include "Quad.h"

Quad::Quad(Point satrt, Point end, int np)
{
	n_points = np;
	for (int i = 0; i < 4; i++) {
		child[i] = nullptr;
	}
	rectangle = new Rectangle(satrt, end, np);

}

Quad::~Quad()
{
	if (rectangle != nullptr) {
		delete rectangle;
	}
	for (int i = 0; i < 4; i++) {
		if (child[i] != nullptr)
			delete child[i];
	}
}

bool Quad::insertPoint(Point p)
{
	bool states = true;
	if (!inRectangle(p) || exitsPoint(p)) {
		return false;
	}

	if (!isLeaf()) {
		if (rectangle->inCenterMidPoint(p) || rectangle->inVertucalUpLine(p) || rectangle->inHorizontalLeftLine(p)) {
			states = child[0]->insertPoint(p);
		}
		else if (rectangle->inHorizontalRightLine(p)) {
			states = child[1]->insertPoint(p);
		}
		else if (rectangle->inVertucalDownLine(p)) {
			states = child[2]->insertPoint(p);
		}
		else {
			for (int i = 0; i < 4; i++) {
				if (child[i]->inRectangle(p)) {
					states = child[i]->insertPoint(p);
					break;
				}
			}
		}
		
	}
	else if (rectangle->full()) {
		child[0] = new Quad(Point(rectangle->getStartPoint()), Point(rectangle->getCenterMidPoint()), n_points);
		child[1] = new Quad(Point(rectangle->getUpLineMidPoint()), Point(rectangle->getRightLineMidPoint()), n_points);
		child[2] = new Quad(Point(rectangle->getLeftLineMidPoint()), Point(rectangle->getDownLineMidPoint()), n_points);
		child[3] = new Quad(Point(rectangle->getCenterMidPoint()), Point(rectangle->getEndPoint()), n_points);
		for (int i = 0; i < n_points; i++) {
			if (rectangle->inCenterMidPoint(rectangle->getPoint(i)) || rectangle->inVertucalUpLine(rectangle->getPoint(i)) || rectangle->inHorizontalLeftLine(rectangle->getPoint(i))) {
				states = child[0]->insertPoint(rectangle->getPoint(i));
			}
			else if (rectangle->inHorizontalRightLine(rectangle->getPoint(i))) {
				states = child[1]->insertPoint(rectangle->getPoint(i));
			}
			else if (rectangle->inVertucalDownLine(rectangle->getPoint(i))) {
				states = child[2]->insertPoint(rectangle->getPoint(i));
			}
			else {
				for (int j = 0; j < 4; j++) {
					if (child[j]->inRectangle(rectangle->getPoint(i))) {
						states = child[j]->insertPoint(rectangle->getPoint(i));
						break;
					}
				}
			}
		}
		states = insertPoint(p);
	}
	else {
		rectangle->addPoint(p);
		return true;
	}
	return states;
}

bool Quad::searchPoint(Point p, double d)
{
	return searchLoop(this, p, d);
}

bool Quad::searchLoop(Quad* quad, Point p, double d)
{
	if (quad->rectangle->empty()) {
		return false;
	}

	if (!quad->isLeaf()) {
		for (int i = 0; i < 4; i++) {
			if (quad->child[i]->searchLoop(quad->child[i], p, d)) {
				return true;
			}
		}
	}
	else {
		if (quad->rectangle->searchDistancePoint(p, d))
			return true;
	}
	return false;
}

bool Quad::nearestPoint(Point p, Point& fidP)
{
	return nearestLoop(this, p, fidP);
}

bool Quad::nearestLoop(Quad* quad, Point p, Point& fidP)
{
	bool find_p = false;
	if (quad->rectangle->empty())
		return false;
	if (!quad->isLeaf()) {
		for (int i = 0; i < 4; i++) {
			find_p |= child[i]->nearestLoop(child[i], p, fidP);
		}
	}
	else {
		if (!quad->rectangle->empty()) {
			Point findp = quad->rectangle->findNearestPoint(p);
			if (p.getDistance(findp) < p.getDistance(fidP)) {
				fidP = findp;
				find_p = true;
			}
		}			
	}
	return find_p;
}

Point* Quad::range(Point startp, Point endp, int& count)
{
	Point* ap = nullptr;
	Rectangle rect(startp, endp, 0);
	count = 0;
	return rangeLoop(this, rect, ap, count);
}

Point* Quad::rangeLoop(Quad* quad, Rectangle& rect, Point* allp, int& count)
{
	if (!quad->isLeaf()) {
		for (int i = 0; i < 4; i++)
		{
			if (child[i]->inOccure(rect)) {
				allp = child[i]->rangeLoop(child[i], rect, allp, count);
			}
		}
	}
	else if (!quad->inOccure(rect)) {
		return allp;
	}
	else {
		int n = 0, i;
		Point* ap = nullptr, * tmp = nullptr;
		ap = quad->rectangle->pointInRect(rect, n);
		if (ap != nullptr) {
			tmp = new Point[count + n];
			for (i = 0; i < count; i++) {
				tmp[i] = allp[i];
			}
			for (i = 0; i < n; i++) {
				tmp[i + count] = ap[i];
			}
			if (allp != nullptr)
				delete[] allp;
			allp = tmp;
			count += n;
			delete[] ap;
		}
	}
	return allp;
}

bool Quad::inOccure(Rectangle& rect)
{
	return rectangle->inOccure(rect);
}

int Quad::num()
{
	return numLoop(this);
}

int Quad::numLoop(Quad* quad)
{
	int sum = 0;
	if (quad->rectangle->empty()) {
		return 0;
	}
	if (!quad->isLeaf()) {
		for (int i = 0; i < 4; i++) {
			sum += quad->child[i]->numLoop(quad->child[i]);
		}
	}
	else {
		sum = quad->rectangle->getPointCount();
	}
	return sum;
}

bool Quad::inRectangle(Point p)
{
	return rectangle->inRectangle(p);
}

bool Quad::exitsPoint(Point p)
{
	for (int i = 0; i < n_points; i++) {
		if (rectangle->getPoint(i) == p) {
			return true;
		}
	}
	return false;
}

bool Quad::isLeaf()
{
	return child[0] == nullptr;
}
