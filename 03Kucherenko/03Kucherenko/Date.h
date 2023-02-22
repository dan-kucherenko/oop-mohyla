#pragma once
#include <iostream>

#include "Date.h"
using namespace std;

class Date
{
public:
	struct BadDate;
	// to avoid problem 7.2.2002 7 feb or jul 2?
	enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
	Date(int d = 0, Month m = Month(0), int y = 0);
	Date(int d, int m, int y);
	Date(const Date&);
	Date& operator=(const Date&);
	~Date();

	static void setDefault(int, Month, int);
	static void setDefault();
	static void showDefault();

	inline int day() const { return _day; }
	inline Month month() const { return static_cast<Month>(_month); }
	inline int year() const { return _year; }
	inline const string getMonthName() const { return monthNames[_month - 1]; }
	inline void setDay(int d) { fillDate(d, Month(_month), _year); }
	inline void setMonth(int m) { fillDate(_day, Month(m), _year); }
	inline void setDYear(int y) { fillDate(_day, Month(_month), y); }

	//	Arithmetics
	Date& operator+=(int);
	Date& operator-=(int);
	const Date operator++(int);
	const Date& operator++();
	const Date operator--(int);
	const Date& operator--();

private:
	int _day, _month, _year;
	void fillDate(int d, Month m, int y);
	static string monthNames[12];
	static bool defaultSet;
	static Date defaultDate;
};

bool leapYear(int y);
ostream& operator<<(ostream& os, const Date& d);

struct Date::BadDate
{
	int _day, _month, _year;

	BadDate(int d, int m, int y) : _day(d), _month(m), _year(y) {}
};

ostream& operator<<(ostream& os, const Date::BadDate& bd);
