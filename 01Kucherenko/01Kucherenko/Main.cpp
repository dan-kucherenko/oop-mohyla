#include <iostream>
#include "Point.h"

using namespace std;

int main(void)
{
	Point p1(3, 4); // default constructor
	Point p2(p1); // copy constuctor
	Point p3 = p2; // operator=
	cout << endl << "Points p2 and p1 have same cordinates: "
		<< boolalpha << (p2 == p1) << endl;
	cout << "Points p2 and p1 have different cordinates: "
		<< boolalpha << (p2 != p1) << endl;
	p2.x() = 7; // method to set x of Point p2
	p2.y() = 20; // method to set y of Point p2
	cout << "X of p3: " << p2.x() << endl; // method to get x of Point
	cout << "Y of p3: " << p2.y() << endl; // method to get y of Point
	cout << "ID of p2: " << p1.getID() << endl;
	Point p4 = p1 + p2;
	cout << "Point p1:" << p1 << "\nPoint p2" << p2 << "\nPoint p4(p1+p2):" << p4 << endl;
	Point p5(1, 3);
	cout << "Point p5(upd.):" << (p5 += p3) << endl;
	return 0;
}
