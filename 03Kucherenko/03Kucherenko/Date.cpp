#include "Date.h"

string Date::monthNames[] = {
	"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November",
	"December"
};

bool Date::defaultSet = false;
Date Date::defaultDate;

Date::Date(int d, Month m, int y)
{
	fillDate(d, m, y);
#ifndef NDEBUG
	cout << "Date created: " << *this << endl;
#endif
	return;
}

Date::Date(int d, int m, int y): Date(d, Month(m), y)
{
}

Date::Date(const Date& d) : _day(d._day), _month(d._month), _year(d._year)
{
#ifndef NDEBUG
	cout << "Date created: " << *this << " using copy-constructor" << endl;
#endif
	return;
}

Date& Date::operator=(const Date& d)
{
	_day = d._day;
	_month = d._month;
	_year = d._year;
	return *this;
}

Date::~Date()
{
#ifndef NDEBUG
	cout << "Date deleted: " << *this << endl;
#endif
}

void Date::setDefault(int d, Month m, int y)
{
	defaultDate = Date(d, m, y);
	defaultSet = true;
}

void Date::setDefault()
{
	time_t now = time(0);
	tm* ltm = new tm;
	localtime_s(ltm, &now);
	defaultDate._day = ltm->tm_mday;
	defaultDate._month = ltm->tm_mon + 1;
	defaultDate._year = ltm->tm_year += 1900;
	defaultSet = true;
	delete ltm;
}

void Date::showDefault()
{
	cout << "Default date: " << defaultDate << endl;
}

Date& Date::operator+=(int num)
{
	_day = day() + num;
	do
	{
		int daysInMonth;
		switch (month())
		{
		case 2:
			daysInMonth = 28 + leapYear(year());
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			daysInMonth = 30;
			break;
		default:
			daysInMonth = 31;
			break;
		}
		if (day() <= daysInMonth)
			break;
		_day = day() - daysInMonth;
		_month = month() + 1;
		if (month() > 12)
		{
			_month = month() - 12;
			_year = year() + 1;
		}
	}
	while (true);
	return *this;
}

Date& Date::operator-=(int n)
{
	_day -= n;
	while (_day < 1)
	{
		if (_month == 1)
		{
			_year--;
			_month = 12;
		}
		else
		{
			_month--;
			if (_month == 2)
			{
				if (leapYear(year()))
				{
					_day += 29;
				}
				else
				{
					_day += 28;
				}
			}
			else if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
			{
				_day += 30;
			}
			else
			{
				_day += 31;
			}
		}
	}
	return *this;
}


const Date Date::operator++(int)
{
	Date temp(*this);
	*this += 1;
	return temp;
}

const Date& Date::operator++()
{
	return *this += 1;
}

const Date Date::operator--(int)
{
	Date temp(*this);
	*this -= 1;
	return temp;
}

const Date& Date::operator--()
{
	return *this -= 1;
}

void Date::fillDate(int d, Month m, int y)
{
	try
	{
		if (!defaultSet)
			setDefault();
		else
		{
			int maxDays;
			switch (month())
			{
			case 2:
				maxDays = 28 + leapYear(year());
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				maxDays = 30;
				break;
			default:
				maxDays = 31;
				break;
			}

			if (d > maxDays || d > 31 || d < 0 || m == Month(0) || y < 0)
				throw BadDate(d, m, y);
			_day = d ? d : defaultDate.day();
			_month = m ? m : defaultDate.month();
			_year = y ? y : defaultDate.year();
		}
	}
	catch (const BadDate& bd)
	{
		cout << bd << endl;
	}
}

bool leapYear(int y)
{
	return !(y % 4);
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '[' << d.day() << '/' << d.getMonthName() << '/' << d.year() << ']';
}

ostream& operator<<(ostream& os, const Date::BadDate& bd)
{
	return os << "Invalid date: " << '[' << bd._day << '/' << bd._month << '/' << bd._year << ']';
}
