#include <iostream>

#include "Triangle.h"

using namespace std;

int main(void)
{
	{
		cout << "Constructors:" << endl;
		Point p1(2, 4), p2(5, 6), p3(7, 8);
		Triangle t1(p1, p2, p3); // point based constructor
		Triangle t2(3, 5, 6, 7, 9, 10); // coordinates based constructor
		cout << "------------------------------------------------" << endl;
	}
	{
		cout << endl << "Selectors and modifiers:" << endl;
		Triangle t(3, 5, 6, 7, 9, 10);
		cout << "Apex A: " << t.apexA() << endl; // apex A selector
		cout << "Apex B: " << t.apexB() << endl;
		cout << "Apex C: " << t.apexC() << endl;
		cout << "Side A(BC): " << t.sideA() << endl; // BC side selector
		cout << "Side B(CA): " << t.sideB() << endl;
		cout << "Side C(AB): " << t.sideC() << endl;

		t.apexA() = Point(12, 15);
		cout << "Modified apex A: " << t.apexA() << endl; // apex A modifier
		cout << "Modified side B(CA): " << t.sideB() << endl;
		cout << "Modified side C(AB): " << t.sideC() << endl;
		cout << "------------------------------------------------" << endl;
	}
	{
		cout << endl << "Medians: " << endl;
		//Triangle t(3, 5, 6, 7, 9, 10);
		Triangle t(Point(7, 2), Point(1, 10), Point(3, 2));
		cout << "Median A: " << t.median_a() << ", length:" << t.median_a().length() << endl; // median for 
		cout << "Median B: " << t.median_b() << ", length:" << t.median_b().length() << endl;
		cout << "Median C: " << t.median_c() << ", length:" << t.median_c().length() << endl;
		cout << "------------------------------------------------" << endl;
	}
	return 0;
}
