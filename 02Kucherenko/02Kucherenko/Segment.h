//
//Developed by Daniil Kucherenko on 13.02.2022
//

#pragma once
//*******************************************
//Every segment posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a segment created or resp. deleted
//Version 1.0

//*******************************************

#include "Point.h"

// Клас відрізків
class Segment
{
private:
	// Засоби облікування відрізків
	static int _freeID;
	const int _myId;
	// Точка початку відрізку
	Point _a;
	// Точка кінця відрізку
	Point _b;

public:
	// Конструктори відрізків
	// 1) за координатами його кінців
	Segment(const double x1 = 0, const double y1 = 0,
	        const double x2 = 1, const double y2 = 0);
	// 2) за точками початку і кінця
	Segment(const Point& start, const Point& end);
	// 3) копіювальний конструктор
	Segment(const Segment&);
	// Деструктор
	~Segment();

	// Присвоєння
	Segment& operator=(const Segment&);
	// Селектори  точок
	inline const Point& start() const { return _a; }
	inline const Point& end() const { return _b; }
	// Селектори-модифікатори точок
	inline Point& start() { return _a; }
	inline Point& end() { return _b; }
	// Селектори координат точок
	inline const double& startX() const { return _a.x(); }
	inline const double& startY() const { return _a.y(); }
	inline const double& endX() const { return _b.x(); }
	inline const double& endY() const { return _b.y(); }
	// Селектори-модифікатори координат точок
	inline double& startX() { return _a.x(); }
	inline double& startY() { return _a.y(); }
	inline double& endX() { return _b.x(); }
	inline double& endY() { return _b.y(); }
	// Обчислення довжини відрізка
	double length() const;
	// Обчислення відстані від відрізка до точки
	double distance(const Point&) const;
	// Селектор ID
	inline const int getID() const { return _myId; }
};

ostream& operator<<(ostream&, const Segment&);