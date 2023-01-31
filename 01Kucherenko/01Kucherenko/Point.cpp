#include <iostream>
#include "Point.h"

int Point::_freeID;

Point::Point(double x, double y) : _pointID(++_freeID), _x(x), _y(y)
{
#ifndef NDEBUG
	cout << "Constructor has been called" << endl;
#endif
	cout << "Point " << *this << " has been created" << endl;
	return;
}

Point::Point(const Point& p): _pointID(++_freeID), _x(p.x()), _y(p.y())
{
#ifndef NDEBUG
	cout << "Copy-constructor has been called" << endl;
#endif
	cout << "Point " << *this << " has been copied" << endl;
	return;
}

Point::~Point()
{
#ifndef NDEBUG
	cout << "Destructor has been called" << endl;
#endif
	cout << "Point " << *this << " has been deleted" << endl;
}

Point& Point::operator=(const Point& p)
{
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
	return os << "(pointID= " << p.getID() << ", x= " << p.x() << ", y= " << p.y() << ")";
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
