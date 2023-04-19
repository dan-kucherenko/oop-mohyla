#include <iostream>

#include "Cities.h"
#include "Fraction.h"

using namespace std;

int main(void)
{
	{
		cout << "Cities: " << endl << endl;
		Cities cities;
		cities.addCity({"Chernihiv", 3}).addCity({"Lviv", 3}).addCity("Odesa", 4)
		      .addCity({"Kyiv", 4})
		      .addCity("Volovets", 1);
		cout << "Size of cities table: " << cities.size() << endl << cities << endl;
		cout << "Sorted by population ascending: " << endl << cities.sortByPopulationAscending() << endl;
		cout << "Sorted by population descending: " << endl << cities.sortByPopulationDescending() << endl;
		cout << "Rollback all sorting: " << endl << cities.rollbackSorting() << endl;
		cout << "City at index 2 is " << cities[2] << endl;
		try
		{
			cout << "City at index 7 is " << cities[7] << endl;
		}
		catch (const Cities::BadCities& bc)
		{
			bc.exceptionMessage();
		}
		cities[2] = {"Kharkiv", 5};
		cout << "Modified cities" << cities << endl;

		Cities citiesCopy;
		citiesCopy = cities;
		cout << "Cities copy: " << citiesCopy << endl;
		cout << "-------------------------------------------------" << endl;
	}
	{
		cout << endl << "Fractions: " << endl << endl;
		try
		{
			Fraction f1(4, -8);
		}
		catch (const Fraction::BadFraction& bf)
		{
			bf.exceptionMessage();
		}
		Fraction f1(4, 8);
		cout << "Fraction f1 " << f1 << " in decimal form " << double(f1) << endl;
		f1.setNumerator(6);
		cout << f1 << endl;
		f1.setDenominator(9);
		cout << f1 << endl;
		const double decimacFraction = 0.4;
		cout << "Decimal fraction: " << decimacFraction << ", converted to default fraction: " <<
			Fraction(decimacFraction) << endl;
		try
		{
			cout << "Operator+" << endl;
			cout << "2 + " << f1 << " = " << 2 + f1 << endl;
			cout << f1 << " + 2 = " << f1 + 2 << endl;
			cout << f1 << " + " << f1 << " = " << f1 + f1 << endl;

			cout << "Operator+=" << endl;
			cout << f1 << " += " << 2 << " = " << (f1 += 2) << endl;
			cout << f1 << " += " << f1 << " = " << (f1 += f1) << endl;

			cout << "Operator-" << endl;
			cout << 2 << " - " << f1 << " = " << 2 - f1 << endl;
			cout << f1 << " - " << 2 << " = " << f1 - 2 << endl;
			cout << f1 << " - " << f1 << " = " << f1 - f1 << endl;

			cout << "Operator-=" << endl;
			cout << f1 << " -= " << 2 << " = " << (f1 -= 2) << endl;
			cout << f1 << " -= " << f1 << " = " << (f1 -= f1) << endl;


			Fraction f2(-3, 4);
			cout << "Operator*" << endl;
			cout << 2 << " * " << f2 << " = " << 2 * f2 << endl;
			cout << f2 << " * " << 2 << " = " << f2 * 2 << endl;
			cout << f2 << " * " << f2 << " = " << f2 * f2 << endl;

			cout << "Operator*=" << endl;
			cout << f2 << " *= " << 2 << " = " << (f2 *= 2) << endl;
			cout << f2 << " *= " << f2 << " = " << (f2 *= f2) << endl;

			cout << "Operator/" << endl;
			cout << 2 << " / " << f2 << " = " << 2 / f2 << endl;
			cout << f2 << " / " << 2 << " = " << f2 / 2 << endl;
			cout << f2 << " / " << f2 << " = " << f2 / f2 << endl;

			cout << "Operator/=" << endl;
			cout << f2 << " /= " << 2 << " = " << (f2 /= 2) << endl;
			cout << f2 << " /= " << f2 << " = " << (f2 /= f2) << endl;
		}
		catch (const Fraction::BadFraction& bf)
		{
			bf.exceptionMessage();
		}

		cout << "-------------------------------------------------" << endl;
	}
	{
		cout << endl << "DoubleLists: " << endl << endl;
	}
	return 0;
}
