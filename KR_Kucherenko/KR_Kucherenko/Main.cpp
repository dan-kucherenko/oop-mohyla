#include <iostream>

#include "Cities.h"

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
	
	return 0;
}
