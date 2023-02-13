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
		Segment s1(3, 4, 5, 8);								// default constructor

		Point start_p1(3, 4), end_p1(10,15);
		Segment s2(start_p1, end_p1);						// point-based constructor

		Segment s3(s1);										// copy constuctor
		cout << "----------------------------------------" << endl;
	}
	{
		cout << endl << "Selectors and modificators:" << endl;
		Segment s1(3, 4, 5, 8);
		cout << "----------------------------------------" << endl;

	}
	{
		cout << endl << "Length and distance to point methods:" << endl;
		cout << "----------------------------------------" << endl;
	}
	return 0;
}
