#pragma once
#include "Point.h"

class Triangle
{
public:
	class Segment;
	// constructors and destructors
	Triangle(const double x1 = 0, const double y1 = 0, const double x2 = 1,
	         const double y2 = 0, const double x3 = 0, const double y3 = 1);
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);
	Triangle& operator=(const Triangle&);
	~Triangle();

	// selectors
	inline const Point& apexA() const { return _a; }
	inline const Point& apexB() const { return _b; }
	inline const Point& apexC() const { return _c; }

	const Segment& sideA();
	const Segment& sideB();
	const Segment& sideC();

	//modifiers
	inline Point& apexA() { return _a; }
	inline Point& apexB() { return _b; }
	inline Point& apexC() { return _c; }

	// medians
	const Segment& median_a();
	const Segment& median_b();
	const Segment& median_c();

private:
	Point _a, _b, _c;
	Segment *_ab, *_bc, *_ca;
	Segment *_median_a, *_median_b, *_median_c;
	static const Point findMiddle(const Point& p1, const Point& p2);
};

ostream& operator<<(ostream&, const Triangle&);

class Triangle::Segment
{
private:
	const Point &_a, &_b;

public:
	Segment(const Point& a, const Point& b);
	Segment(const Segment&);
	~Segment();
	Segment& operator=(const Segment&) = delete;
	// point selectors
	inline const Point& start() const { return _a; }
	inline const Point& end() const { return _b; }
	double length() const;
};

ostream& operator<<(ostream&, const Triangle::Segment&);
