#pragma once
#include <ostream>

class TComplex;

class AComplex
{
private:
	double _re, _im;

public:
	AComplex(double re = 0, double im = 0);
	AComplex(const AComplex&);
	AComplex(const TComplex&);
	~AComplex();
	AComplex& operator=(const AComplex&);

	inline const double& real() const { return _re; }
	inline const double& imag() const { return _im; }

	inline double& real() { return _re; }
	inline double& imag() { return _im; }

	double mod() const;
	double arg() const;
};

const AComplex operator+(const AComplex&, const AComplex&);
const AComplex operator-(const AComplex&, const AComplex&);
AComplex& operator+=(AComplex&, const AComplex&);
AComplex& operator-=(AComplex&, const AComplex&);

std::ostream& operator<<(std::ostream&, const AComplex&);
