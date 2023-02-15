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
	_a = s._a;
	_b = s._b;
	return *this;
}

double Segment::length() const
{
	return sqrt(pow(_b.x() - _a.x(), 2) + pow(_b.y() - _a.y(), 2));
}

double Segment::distance(const Point& p) const
{
	// Vector from Point _a to Point _b
	double vec_abx = _b.x() - _a.x();
	double vec_aby = _b.y() - _a.y();

	// Vector from Point _a to Point p
	double vec_pax = p.x() - _a.x();
	double vec_pay = p.y() - _a.y();

	// Vector from Point _b to Point p
	double vec_bpx = p.x() - _b.x();
	double vec_bpy = p.y() - _b.y();

	double scalar_m_ab_ap = vec_pax * vec_abx + vec_pay * vec_aby; // scalar multiplication of AB and AP vector
	double scalar_m_ab = pow(vec_abx, 2) + pow(vec_aby, 2); // scalar multiplication of AB by itself

	if (scalar_m_ab_ap <= 0.0) // point is closer to the start of segment
		return sqrt(pow(vec_pax, 2) + pow(vec_pay, 2));
	if (scalar_m_ab_ap >= scalar_m_ab) // point is closer to the end of segment
		return sqrt(pow(vec_bpx, 2) + pow(vec_bpy, 2));
	return fabs(vec_pax * vec_pay - vec_aby * vec_pax) / sqrt(scalar_m_ab); // point can be projected on the segment
}

ostream& operator<<(ostream& os, const Segment& s)
{
	return os << '(' << s.start() << ", " << s.end() << ')';
}
