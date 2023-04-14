#include <iostream>

#include "AComplex.h"
#include "TComplex.h"

using namespace std;

int main(void)
{
	{
		cout << "Constructors:" << endl << endl;
		cout << "AComplex constructors:" << endl;
		TComplex tc(2, 1.04);
		AComplex ac1(3, 4);
		AComplex ac2(ac1);
		AComplex ac3(tc);
		cout << endl << "TComplex constructors:" << endl;
		AComplex ac(2, 1.04);
		TComplex tc1(3, 4);
		TComplex tc2(tc1);
		TComplex tc3(ac);
		cout << "-----------------------------------------" << endl;
	}
	{
		cout << endl << "Selectors and modifiers:" << endl << endl;
		cout << "AComplex selectors and modifiers:" << endl;
		AComplex ac(5, -6);
		cout << "AComplex real part: " << ac.real() << endl;
		cout << "AComplex imaginary part: " << ac.imag() << endl;
		ac.real() = 4;
		ac.imag() = 7;
		cout << "Modified AComplex number: " << ac << endl;
		cout << "Ro number of AComplex: " << ac.mod() << endl;
		cout << "Phi number of AComplex: " << ac.arg() << endl;
		cout << endl << "TComplex selectors and modifiers:" << endl;
		TComplex tc(5, 0.6);
		cout << "TComplex ro:" << tc.mod() << endl;
		cout << "TComplex phi angle:" << tc.arg() << endl;
		tc.mod() = 4;
		tc.arg() = 0.4;
		cout << "Modified TComplex number: " << tc << endl;
		cout << "Real part of TComplex: " << ac.real() << endl;
		cout << "Imaginary part of TComplex: " << ac.imag() << endl;
		cout << "-----------------------------------------" << endl;
	}
	{
		cout << endl << "Operators: " << endl;
		AComplex ac1(3, 4);
		AComplex ac2(ac1);
		TComplex tc1(0.7853981633974, 1);
		TComplex tc2(0.7853981633974, 1);
		double x = 5;
		cout << "-----------------------------------------" << endl;
		cout << "Operator+/-" << endl;
		cout << ac1 + ac2 << endl;
		cout << ac1 + tc1 << endl;
		cout << tc1 + ac2 << endl;
		cout << tc1 + tc1 << endl;
		cout << ac1 + x << endl;
		cout << tc1 + x << endl;
		cout << "-----------------------------------------" << endl;
		cout << "Operator-" << endl;
		cout << ac1 - ac2 << endl;
		cout << ac1 - tc1 << endl;
		cout << tc1 - ac2 << endl;
		cout << tc1 - tc1 << endl;
		cout << ac1 - x << endl;
		cout << tc1 - x << endl;
		cout << "-----------------------------------------" << endl;
		cout << "Operator+=" << endl;
		cout << (ac1 += ac2) << endl;
		cout << (ac1 += tc1) << endl;
		cout << (ac1 += x) << endl;
		cout << (tc1 += tc2) << endl;
		cout << "-----------------------------------------" << endl;
		cout << "Operator-=" << endl;
		cout << (ac1 -= ac2) << endl;
		cout << (ac1 -= tc1) << endl;
		cout << (ac1 -= x) << endl;
		cout << (tc1 -= tc2) << endl;
		cout << "-----------------------------------------" << endl;
		cout << "Operator*" << endl;
		cout << ac1 * ac2 << endl;
		cout << ac1 * tc1 << endl;
		cout << tc1 * ac2 << endl;
		cout << tc1 * tc1 << endl;
		cout << ac1 * x << endl;
		cout << tc1 * x << endl;
		cout << "-----------------------------------------" << endl;
		cout << "Operator/" << endl;
		cout << ac1 / ac2 << endl;
		cout << ac1 / tc1 << endl;
		cout << tc1 / ac2 << endl;
		cout << tc1 / tc1 << endl;
		cout << ac1 / x << endl;
		cout << tc1 / x << endl;
		cout << "-----------------------------------------" << endl;
		cout << "Operator*=" << endl;
		cout << (tc1 *= ac2) << endl;
		cout << (tc1 *= tc1) << endl;
		cout << (tc1 *= x) << endl;
		cout << (ac1 *= ac2) << endl;
		cout << "-----------------------------------------" << endl;
		cout << "Operator/=" << endl;
		cout << (tc1 /= ac2) << endl;
		cout << (tc1 /= tc1) << endl;
		cout << (tc1 /= x) << endl;
		cout << (ac1 /= ac2) << endl;
		cout << "-----------------------------------------" << endl;
	}
	return 0;
}
