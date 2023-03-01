#include "Triangle.h"


Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3,
                   const double y3) : _a(x1, y1), _b(x2, y2), _c(x3, y3), _ab(nullptr), _bc(nullptr), _ca(nullptr),
                                      _median_a(nullptr),
                                      _median_b(nullptr), _median_c(nullptr)
{
#ifndef NDEBUG
	cout << "Triangle using coordinates:" << *this << endl;
#endif
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : _a(a), _b(b), _c(c), _ab(nullptr), _bc(nullptr),
                                                                     _ca(nullptr), _median_a(nullptr),
                                                                     _median_b(nullptr), _median_c(nullptr)
{
#ifndef NDEBUG
	cout << "Triangle using points:" << *this << endl;
#endif
}

Triangle::Triangle(const Triangle& t) : _a(t._a), _b(t._b), _c(t._c), _ab(nullptr), _bc(nullptr), _ca(nullptr),
                                        _median_a(nullptr),
                                        _median_b(nullptr), _median_c(nullptr)
{
#ifndef NDEBUG
	cout << "Triangle using copy:" << *this << endl;
#endif
}

Triangle& Triangle::operator=(const Triangle& t)
{
	if (this == &t)
		return *this;
	_a = t._a;
	_b = t._b;
	_c = t._c;
	delete _ab;
	delete _bc;
	delete _ca;
	delete _median_a;
	delete _median_b;
	delete _median_c;
	return *this;
}

Triangle::~Triangle()
{
	delete _ab;
	delete _bc;
	delete _ca;
	delete _median_a;
	delete _median_b;
	delete _median_c;
#ifndef NDEBUG
	cout << "Successfully deleted the triangle: " << *this << endl;
#endif
}

const Triangle::Segment& Triangle::sideA()
{
	if (_bc == nullptr)
		_bc = new Segment(_b, _c);
	return *_bc;
}

const Triangle::Segment& Triangle::sideB()
{
	if (_ca == nullptr)
		_ca = new Segment(_c, _a);
	return *_ca;
}

const Triangle::Segment& Triangle::sideC()
{
	if (_ab == nullptr)
		_ab = new Segment(_a, _b);
	return *_ab;
}

const Point Triangle::findMiddle(const Point& p1, const Point&p2)
{
	return { (p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2 };
}

const Triangle::Segment& Triangle::median_a()
{
	if (_median_a == nullptr)
		_median_a = new Segment(_a, findMiddle(_b, _c));
	return *_median_a;
}

const Triangle::Segment& Triangle::median_b()
{
	if (_median_b == nullptr)
		_median_b = new Segment(_b, findMiddle(_a, _c));
	return *_median_b;
}

const Triangle::Segment& Triangle::median_c()
{
	if (_median_c == nullptr)
		_median_c = new Segment(_c, findMiddle(_a, _b));
	return *_median_c;
}

ostream& operator<<(ostream& os, const Triangle& t)
{
	return os << '(' << t.apexA() << ", " << t.apexB() << ", " << t.apexC() << ')';
}

ostream& operator<<(ostream& os, const Triangle::Segment& ts)
{
	return os << '(' << ts.start() << ", " << ts.end() << ')';
}

Triangle::Segment::Segment(const Point& a, const Point& b) : _a(a), _b(b)
{
#ifndef NDEBUG
	cout << "Segment created:" << *this << endl;
#endif
}

Triangle::Segment::Segment(const Segment& s) : Segment(s._a, s._b)
{
}

Triangle::Segment::~Segment()
{
#ifndef NDEBUG
	cout << "Deleted Segment:" << *this << endl;
#endif
}

double Triangle::Segment::length() const
{
	return sqrt(pow(_b.x() - _a.x(), 2) + pow(_b.y() - _a.y(), 2));
}
