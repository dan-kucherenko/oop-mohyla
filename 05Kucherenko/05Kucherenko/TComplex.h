#pragma once
#include <ostream>

class AComplex;

class TComplex
{
private:
	double _ro, _phi;

public:
	TComplex(double ro = 0, double phi = 0);
	TComplex(const TComplex&);
	TComplex(const AComplex&);
	~TComplex();
	TComplex& operator=(const TComplex&);

	inline const double& mod() const { return _ro; }
	inline const double& arg() const { return _phi; }

	inline double& mod() { return _ro; }
	inline double& arg() { return _phi; }

	double real() const;
	double imag() const;
};

const TComplex operator* (const TComplex&, const TComplex&);
const TComplex operator/ (const TComplex&, const TComplex&);
TComplex& operator*=(TComplex&, const TComplex&);
TComplex& operator/=(TComplex&, const TComplex&);
TComplex& operator += (TComplex&, const TComplex&);
TComplex& operator -= (TComplex&, const TComplex&);

std::ostream& operator<<(std::ostream&, const TComplex&);