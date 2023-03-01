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

// ���� ������
class Segment
{
private:
	// ������ ���������� ������
	static int _freeID;
	const int _myId;
	// ����� ������� ������
	Point _a;
	// ����� ���� ������
	Point _b;

public:
	// ������������ ������
	// 1) �� ������������ ���� �����
	Segment(const double x1 = 0, const double y1 = 0,
	        const double x2 = 1, const double y2 = 0);
	// 2) �� ������� ������� � ����
	Segment(const Point& start, const Point& end);
	// 3) ����������� �����������
	Segment(const Segment&);
	// ����������
	~Segment();

	// ���������
	Segment& operator=(const Segment&);
	// ���������  �����
	inline const Point& start() const { return _a; }
	inline const Point& end() const { return _b; }
	// ���������-������������ �����
	inline Point& start() { return _a; }
	inline Point& end() { return _b; }
	// ��������� ��������� �����
	inline const double& startX() const { return _a.x(); }
	inline const double& startY() const { return _a.y(); }
	inline const double& endX() const { return _b.x(); }
	inline const double& endY() const { return _b.y(); }
	// ���������-������������ ��������� �����
	inline double& startX() { return _a.x(); }
	inline double& startY() { return _a.y(); }
	inline double& endX() { return _b.x(); }
	inline double& endY() { return _b.y(); }
	// ���������� ������� ������
	double length() const;
	// ���������� ������ �� ������ �� �����
	double distance(const Point&) const;
	// �������� ID
	inline const int getID() const { return _myId; }
};

ostream& operator<<(ostream&, const Segment&);