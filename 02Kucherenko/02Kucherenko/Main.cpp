//
//Developed by Daniil Kucherenko on 13.02.2022
//

#include <iostream>
#include "Segment.h"

using namespace std;

int main(void)
{
	{
		cout << "Constructors:" << endl;
		Segment s1(3, 4, 5, 8); // default constructor

		Point start_p1(3, 4), end_p1(10, 15);
		Segment s2(start_p1, end_p1); // point-based constructor

		Segment s3(s1); // copy constuctor
		cout << "----------------------------------------" << endl;
	}
	{
		cout << endl << "Selectors and modificators:" << endl;
		Segment s1(3, 4, 5, 8);
		const Segment s2(8, 9, 9, 10);
		cout << "Start of segment s1: " << s1.start() << endl;
		cout << "StartX of segment s1: " << s1.startX() << endl;
		cout << "StartY of segment s1 : " << s1.startY() << endl;
		cout << "End of segment s1: " << s1.end() << endl;
		cout << "EndX of segment s1: " << s1.endX() << endl;
		cout << "EndY of segment s1 : " << s1.endY() << endl;
		cout << "Start of segment s2: " << s2.start() << endl;
		cout << "StartX of segment s2: " << s2.startX() << endl;
		cout << "StartY of segment s2 : " << s2.startY() << endl;
		cout << "End of segment s2: " << s2.end() << endl;
		cout << "EndX of segment s2: " << s2.endX() << endl;
		cout << "EndY of segment s2 : " << s2.endY() << endl;
		s1.startX() = 1;
		s1.startY() = 0;
		s1.endX() = 4;
		s1.endY() = 5;
		cout << "Updated segment using coordinates s1:" << s1 << endl;
		const Point new_start_s1(20, 30);
		const Point new_end_s1(-20, -30);
		s1.start() = new_start_s1;
		s1.end() = new_end_s1;
		cout << "Updated segment using points s1:" << s1 << endl;
		cout << "Id of s1: " << s1.getID() << endl;
		cout << "----------------------------------------" << endl;
	}
	{
		cout << endl << "Length and distance to point methods:" << endl;
		Segment s1(3, 4, 5, 8);
		Point p1(4, 6);
		cout << "Length of segment: " << s1.length() << endl;
		cout << "Distance from " << s1 << " to point " << p1 << " is " << s1.distance(p1) << endl;
		cout << "----------------------------------------" << endl;
	}
	return 0;
}
