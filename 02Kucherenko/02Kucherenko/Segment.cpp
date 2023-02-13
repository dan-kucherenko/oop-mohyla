//
//Developed by Daniil Kucherenko on 13.02.2022
//

#include "Segment.h"

int Segment::_freeID = 0;

Segment::Segment(const double x1, const double y1, const double x2, const double y2) : _myId(++_freeID), _a(x1, y1),
	_b(x2, y2)
{
#ifndef NDEBUG
	cout << _myId << ":constructor Segment:" << *this << endl;
#endif
	return;
}

Segment::Segment(const Point& start, const Point& end) : _myId(++_freeID), _a(start), _b(end)
{
#ifndef NDEBUG
	cout << _myId << ":point-constructor Segment:" << *this << endl;
#endif
	return;
}

Segment::Segment(const Segment& s) : _myId(++_freeID), _a(s._a), _b(s._b)
{
#ifndef NDEBUG
	cout << _myId << ":copy-constructor Segment:" << *this << endl;
#endif
	return;
}

Segment::~Segment()
{
#ifndef NDEBUG
	cout << "Deleted Segment:" << *this << endl;
#endif
}

Segment& Segment::operator=(const Segment& s)
{
	this->_a = s._a;
	this->_b = s._b;
	return *this;
}

double Segment::length() const
{
	return sqrt(pow(this->_b.x() - this->_a.x(), 2) + pow(this->_b.y() - this->_a.y(), 2));
}

double Segment::distance(const Point&) const
{
	return 0.0; // TODO: finish method
}

ostream& operator<<(ostream& os, const Segment& s)
{
	return os << "(start_p=" << s.start() << ", end_p=" << s.end();
}
