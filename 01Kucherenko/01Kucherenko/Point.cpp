//
//Developed by Daniil Kucherenko on 31.01.2023
//

#include <iostream>
#include "Point.h"

int Point::_freeID = 0;

Point::Point(double x, double y) : _pointID(++_freeID), _x(x), _y(y)
{
#ifndef NDEBUG
	cout << "Constructor created point " << *this << endl;
#endif
	return;
}

Point::Point(const Point& p) : _pointID(++_freeID), _x(p._x), _y(p._y)
{
#ifndef NDEBUG
	cout << "Copy-constructor created point " << *this << endl;
#endif
	return;
}

Point::~Point()
{
#ifndef NDEBUG
	cout << "Point " << *this << " has been deleted" << endl;
#endif
}

Point& Point::operator=(const Point& p)
{
	if (this == &p)
		return *this;
	_x = p.x();
	_y = p.y();
	return *this;
}

double& Point::x() { return _x; }

double& Point::y() { return _y; }

const double& Point::x() const { return _x; }

const double& Point::y() const { return _y; }

const int Point::getID() const
{
	return _pointID;
}

int Point::amount()
{
	return _freeID;
}

ostream& operator<<(ostream& os, const Point& p)
{
	return os << "(id=" << p.getID() << ", x=" << p.x() << ", y=" << p.y() << ")";
}

const Point operator+(const Point& u, const Point& v)
{
	return {
		u.x() + v.x(),
		u.y() + v.y()
	};
}

Point& operator+=(Point& u, const Point& v)
{
	return u = u + v;
}

bool operator==(const Point& u, const Point& v)
{
	return u.x() == v.x() && u.y() == v.y();
}

bool operator!=(const Point& u, const Point& v)
{
	return !(u == v);
}
