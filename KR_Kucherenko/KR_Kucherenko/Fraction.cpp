//
// Developed by Daniil Kucherenko on 18.04.2023
//

#include "Fraction.h"

#include <iostream>

#pragma region Helper Functions
void Fraction::fillFraction(int numerator, int denominator)
{
	if (denominator <= 0)
		throw BadFraction("Invalid input data");
	const int divisor = gcd(numerator, denominator);
	numerator /= divisor;
	denominator /= divisor;

	_p = numerator;
	_q = denominator;
}

int Fraction::gcd(const int a, const unsigned int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
#pragma endregion

#pragma region Constructor/Destructor
Fraction::Fraction(const int numerator, const int denominator) : _p(numerator), _q(denominator)
{
	fillFraction(numerator, denominator);
#ifndef NDEBUG
	std::cout << "Fraction created" << std::endl;
#endif
}

Fraction::~Fraction()
{
#ifndef NDEBUG
	std::cout << "Fraction deleted" << std::endl;
#endif
}

Fraction::Fraction(const Fraction& f) : _p(f.numerator()), _q(f.denominator())
{
#ifndef NDEBUG
	std::cout << "Fraction copied" << std::endl;
#endif
}

#pragma endregion

Fraction& Fraction::operator=(const Fraction& f)
{
	_p = f.numerator();
	_q = f.denominator();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
	return os << f.numerator() << '/' << f.denominator();
}
