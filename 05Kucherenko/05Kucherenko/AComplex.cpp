#include <iostream>

#include "AComplex.h"
#include "TComplex.h"

AComplex::AComplex(double re, double im) : _re(re), _im(im) {
#ifndef NDEBUG
    std::cout << "AComplex created: " << *this << std::endl;
#endif
}

AComplex::AComplex(const AComplex &ac) : _re(ac._re), _im(ac._im) {
#ifndef NDEBUG
    std::cout << "AComplex created a copy: " << *this << std::endl;
#endif
}

AComplex::AComplex(const TComplex &tc) : _re(tc.real()), _im(tc.imag()) {
#ifndef NDEBUG
    std::cout << "Converted TComplex created: " << *this << std::endl;
#endif
}

AComplex::~AComplex() {
#ifndef NDEBUG
    std::cout << "AComplex deleted: " << *this << std::endl;
#endif
}

AComplex &AComplex::operator=(const AComplex &ac) {
    _re = ac.real();
    _im = ac.imag();
    return *this;
}

double AComplex::mod() const {
    return sqrt(real() * real() + imag() * imag());
}

double AComplex::arg() const {
    return atan(imag() / real());
}

const AComplex operator+(const AComplex &ac_a, const AComplex &ac_b) {
    AComplex c = ac_a;
    return c += ac_b;
}

const AComplex operator-(const AComplex &ac_a, const AComplex &ac_b) {
    AComplex c = ac_a;
    return c -= ac_b;
}

AComplex &operator+=(AComplex &ac_a, const AComplex &ac_b) {
    ac_a.real() += ac_b.real();
    ac_a.imag() += ac_b.imag();
    return ac_a;
}

AComplex &operator-=(AComplex &ac_a, const AComplex &ac_b) {
    ac_a.real() -= ac_b.real();
    ac_a.imag() -= ac_b.imag();
    return ac_a;
}

AComplex &operator*=(AComplex &a, const AComplex &b) {
    return a = a * b;
}

AComplex &operator/=(AComplex &a, const AComplex &b) {
    return a = a / b;
}


std::ostream &operator<<(std::ostream &os, const AComplex &ac) {
    return os << '(' << ac.real() << '+' << ac.imag() << "i)";
}
