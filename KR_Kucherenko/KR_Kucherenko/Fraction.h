//
// Developed by Daniil Kucherenko on 18.04.2023
//

#pragma once
#include <iostream>
#include <ostream>

class Fraction
{
private:
	int _p;
	unsigned int _q;
	void fillFraction(int, int);
	int gcd(const int, const unsigned int);

public:
	class BadFraction;
	Fraction(const int, const int);
	Fraction(const Fraction&);
	~Fraction();
	Fraction& operator=(const Fraction&);

	inline const int numerator() const { return _p; }
	inline const unsigned int denominator() const { return _q; }

	inline void setNumerator(int numerator) { fillFraction(numerator, denominator()); }
	inline void setDenominator(int denominator) { fillFraction(numerator(), denominator); }


	Fraction& operator+=(int);
	Fraction& operator-=(int);
	const Fraction operator++(int);
	const Fraction& operator++();
	const Fraction operator--(int);
	const Fraction& operator--();
};

std::ostream& operator<<(std::ostream&, const Fraction&);

class Fraction::BadFraction
{
private:
	std::string _reason;

public:
	inline BadFraction(const std::string& reason): _reason(reason)
	{
	}

	~BadFraction()
	{
	}

	inline void exceptionMessage() const { std::cerr << _reason << std::endl; }
};
