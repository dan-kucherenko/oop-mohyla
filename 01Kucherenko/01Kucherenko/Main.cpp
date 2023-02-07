//
//Developed by Daniil Kucherenko on 31.01.2023
//

#include <iostream>
#include "Point.h"

using namespace std;

int main(void)
{
	{
		cout << "Constructors:" << endl;
		Point p1(3, 4);					// default constructor
		Point p2(p1);						// copy constuctor
		cout << "Number of created points: " << Point::amount() << endl;
		cout << "----------------------------------------" << endl;
	}

	{
		cout << endl << "Equality of the Point objects:" << endl;
		Point p1(5, 8), p2(p1);
		cout << "Points p2 and p1 have same coordinates: "
			<< boolalpha << (p2 == p1) << endl;
		cout << "Points p2 and p1 have different coordinates: "
			<< boolalpha << (p2 != p1) << endl;
		cout << "Number of created points: " << Point::amount() << endl;
		cout << "----------------------------------------" << endl;
	}

	{
		cout << endl << "Selector and modificator:" << endl;
		Point p1(8, 20);
		cout << "ID of p1: " << p1.getID() << endl;			// selector to get pointId
		cout << "X of p1: " << p1.x() << endl;				// selector to get x
		cout << "Y of p1: " << p1.y() << endl;				// selector to get y
		p1.x() = 7;											// method to set x
		p1.y() = 13;										// method to set y
		cout << "Updated coordinates of the point:" << p1 << endl;
		cout << "Number of created points: " << Point::amount() << endl;
		cout << "----------------------------------------" << endl;
	}

	{
		cout << endl << "Ops(=,+,+=):" << endl;
		Point p1, p2(4, 10), p3;
		cout << "New p1 coordinates:" << (p1 = p2) << endl;									// operator=
		cout << "Point p1+p2:" << p1 + p2 << endl;											// operator+
		cout << "Point p3:" << p3 << endl << "Point p3(upd. p3+p2):" << (p3 += p2) << endl; // operator+=
		cout << "Number of created points: " << Point::amount() << endl;
		cout << "----------------------------------------" << endl;
	}
	return 0;
}
