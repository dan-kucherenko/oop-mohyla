#include <iostream>
#include "Date.h"

using namespace std;

int main(void)
{
	{
		cout << "Constructors:" << endl;
		Date d1(12, Date::Month(4), 2015);
		Date d2(28, 12, 2042);
		Date d3(d2);
		Date::showDefault();
		Date::setDefault(1, Date::Month(2), 2023);
		Date::showDefault();
		cout << "------------------------------" << endl;
	}
	{
		cout << endl << "Selectors and modificators:" << endl;
		Date d(2, 7, 2008);

		cout << "Modify date's day from " << d.day() << " to 6" << endl;
		d.setDay(6);
		cout << "Modify date's month from " << d.getMonthName() << " to September (9)" << endl;
		d.setMonth(9);
		cout << "Modify date's year from " << d.year() << " to 2009" << endl;
		d.setDYear(2009);
		cout << "Modified date: " << d << endl;
		cout << "------------------------------" << endl;
	}
	{
		cout << endl << "Arithmetics:" << endl;
		Date d1(6, 12, 2003);
		Date d2(27, 2, 2003);
		Date d3(29, 2, 2000);

		cout << "Date-- " << d1-- << endl;
		cout << "Updated date: " << d1 << endl;
		cout << "--Date " << --d1 << endl;
		cout << "Date++ " << d2++ << endl;
		cout << "Updated date: " << d2 << endl;
		cout << "++Date " << ++d2 << endl;
		cout << endl << "\"Decrease\" " << d1 << " date for 8 days" << endl;
		cout << "Updated d1: " << (d1 -= 8) << endl;
		cout << "\"Increase\" " << d2 << " for 6 days" << endl;
		cout << "Updated d2: " << (d2 += 6) << endl;
		cout << "Updated d3: " << (d3 += 1) << endl;
		cout << "Updated d3: " << (d3-=1) << endl;
		cout << "------------------------------" << endl;
	}
	return 0;
}
