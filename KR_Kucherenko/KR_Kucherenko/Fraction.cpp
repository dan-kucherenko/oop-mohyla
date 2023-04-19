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
Fraction::Fraction(const int numerator, const int denominator)
{
	fillFraction(numerator, denominator);
#ifndef NDEBUG
	std::cout << "Fraction created" << std::endl;
#endif
}

Fraction::Fraction(double decimalFraction)
{
	const int sign = decimalFraction >= 0 ? 1 : -1;
	decimalFraction = std::fabs(decimalFraction);
	int integer_part = static_cast<int>(decimalFraction);
	const double fractional_part = std::modf(decimalFraction, &decimalFraction);
	int numerator = static_cast<int>(fractional_part * 1000 + 0.5);
	const int denominator = 1000;
	if (numerator == 1000)
	{
		numerator = 0;
		integer_part++;
	}
	numerator = sign * (integer_part * denominator + numerator);
	fillFraction(numerator, denominator);
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

#pragma region Converting
Fraction::operator double() const
{
	return static_cast<double>(numerator()) / denominator();
}
#pragma endregion

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
	return os << f.numerator() << '/' << f.denominator();
}

#pragma region Operators
const Fraction operator+(const Fraction& f1, const Fraction& f2)
{
	return {
		static_cast<int>(f1.numerator() * f2.denominator() + f2.numerator() * f1.denominator()),
		static_cast<int>(f1.denominator() * f2.denominator())
	};
}

const Fraction operator-(const Fraction& f1, const Fraction& f2)
{
	return {
		static_cast<int>(f1.numerator() * f2.denominator() - f2.numerator() * f1.denominator()),
		static_cast<int>(f1.denominator() * f2.denominator())
	};
}

const Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return {
		f1.numerator() * f2.numerator(),
		static_cast<int>(f1.denominator() * f2.denominator())
	};
}

const Fraction operator/(const Fraction& f1, const Fraction& f2)
{
	return {
		static_cast<int>(f1.numerator() * f2.denominator()),
		static_cast<int>(f1.denominator() * f2.numerator())
	};
}

Fraction& operator+=(Fraction& f1, const Fraction& f2)
{
	return f1 = f1 + f2;
}

Fraction& operator-=(Fraction& f1, const Fraction& f2)
{
	return f1 = f1 - f2;
}

Fraction& operator*=(Fraction& f1, const Fraction& f2)
{
	return f1 = f1 * f2;
}

Fraction& operator/=(Fraction& f1, const Fraction& f2)
{
	return f1 = f1 / f2;
}
#pragma endregion
