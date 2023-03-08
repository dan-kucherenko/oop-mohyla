#include <iostream>

#include "TComplex.h"
#include "AComplex.h"

TComplex::TComplex(double ro, double phi) : _ro(ro), _phi(phi)
{
#ifndef NDEBUG
	std::cout << "TComplex created: " << *this << std::endl;
#endif
}

TComplex::TComplex(const TComplex& tc) : _ro(tc._ro), _phi(tc._phi)
{
#ifndef NDEBUG
	std::cout << "TComplex created a copy: " << *this << std::endl;
#endif
}

TComplex::TComplex(const AComplex& ac) : _ro(ac.mod()), _phi(ac.arg())
{
#ifndef NDEBUG
	std::cout << "Converted AComplex created: " << *this << std::endl;
#endif
}

TComplex::~TComplex()
{
#ifndef NDEBUG
	std::cout << "TComplex deleted: " << *this << std::endl;
#endif
}

TComplex& TComplex::operator=(const TComplex& tc)
{
	_ro = tc._ro;
	_phi = tc._phi;
	return *this;
}

double TComplex::real() const
{
	return cos(arg()) * mod();
}

double TComplex::imag() const
{
	return sin(arg()) * mod();
}

const TComplex operator*(const TComplex& tc_a, const TComplex& tc_b)
{
	TComplex tc_c = tc_a;
	return tc_c *= tc_b;
}

const TComplex operator/(const TComplex& tc_a, const TComplex& tc_b)
{
	TComplex tc_c = tc_a;
	return tc_c /= tc_b;
}

TComplex& operator*=(TComplex& tc_a, const TComplex& tc_b)
{
	tc_a.mod() *= tc_b.mod();
	tc_a.arg() += tc_b.arg();
	return tc_a;
}

TComplex& operator/=(TComplex& tc_a, const TComplex& tc_b)
{
	tc_a.mod() /= tc_b.mod();
	tc_a.arg() -= tc_b.arg();
	return tc_a;
}

std::ostream& operator<<(std::ostream& os, const TComplex& tc)
{
	return os << tc.mod() << "(cos(" << tc.arg() << ")" << " + sin(" << tc.arg() << ")i)";
}
