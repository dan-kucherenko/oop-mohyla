//
//Developed by Daniil Kucherenko on 31.01.2023
//

#pragma once

#include <iostream>
using namespace std;

//*******************************************

//Every point posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a point created or resp. deleted
//Version 1.0

//*******************************************

class Point
{
private:
	static int _freeID;
	const int _pointID;
	double _x;
	double _y;

public:
	Point(double x = 0, double y = 0);
	Point(const Point&);
	~Point();
	Point& operator=(const Point&);
	inline double& x() { return _x; }
	inline double& y() { return _y; }
	inline const double& x() const { return _x; }
	inline const double& y() const { return _y; }
	inline const int getID() const { return _pointID; }
	inline static int amount() { return _freeID; }
};

ostream& operator<<(ostream&, const Point&);
const Point operator+(const Point& u, const Point& v);
Point& operator+=(Point&, const Point&);
bool operator==(const Point& u, const Point& v);
bool operator!=(const Point& u, const Point& v);
