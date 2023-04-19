//
// Developed by Daniil Kucherenko on 18.04.2023
//

#include "Cities.h"

#include <algorithm>

#pragma region Constructor/Destructor
Cities::Cities() : _size(0), _cities(new Sequence<City>)
{
#ifndef NDEBUG
	std::cout << "Cities table created" << std::endl;
#endif
}

Cities::~Cities()
{
	delete _cities;
#ifndef NDEBUG
	std::cout << "Cities table deleted" << std::endl;
#endif
}
#pragma endregion

Cities& Cities::operator=(const Cities& city)
{
	if (this == &city)
		return *this;
	_size = city.size();
	_cities->clear();
	for (int i = 0; i < size(); ++i)
		_cities->add(city[i]);
	return *this;
}

#pragma region Operator[]
const City& Cities::operator[](const size_t index) const
{
	if (index >= size())
		throw BadCities("Index is out of bounds");
	return (*_cities)[index];
}

City& Cities::operator[](const size_t index)
{
	if (index >= size())
		throw BadCities("Index is out of bounds");
	return (*_cities)[index];
}
#pragma endregion

#pragma region AddOperator
Cities& Cities::addCity(const City& city)
{
	std::string cityNameUpper = city._name;
	std::transform(cityNameUpper.begin(), cityNameUpper.end(), cityNameUpper.begin(), toupper);
	const City tmpCity(cityNameUpper, city._population);
	size_t index = 0;
	while (index < _cities->size() && tmpCity > (*_cities)[index])
		index++;
	_cities->insert(city, index);
	_size++;
	return *this;
}

Cities& Cities::addCity(const std::string& cityName, const unsigned int population)
{
	addCity({cityName, population});
	return *this;
}
#pragma endregion

#pragma region Sorting
Cities& Cities::sortByPopulationAscending()
{
	for (size_t i = 1; i < _cities->size(); ++i)
	{
		City key = (*_cities)[i];
		int left = 0;
		int right = i - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if ((*_cities)[mid]._population < key._population)
				left = mid + 1;
			else
				right = mid - 1;
		}
		for (int j = i - 1; j >= left; --j)
			(*_cities)[j + 1] = (*_cities)[j];
		(*_cities)[left] = key;
	}
	return *this;
}

Cities& Cities::sortByPopulationDescending()
{
	for (size_t i = 1; i < _cities->size(); ++i)
	{
		City key = (*_cities)[i];
		int left = 0;
		int right = i - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if ((*_cities)[mid]._population > key._population)
				left = mid + 1;
			else
				right = mid - 1;
		}
		for (int j = i - 1; j >= left; --j)
			(*_cities)[j + 1] = (*_cities)[j];
		(*_cities)[left] = key;
	}
	return *this;
}

Cities& Cities::rollbackSorting()
{
	for (size_t i = 1; i < _cities->size(); i++)
	{
		City current = (*_cities)[i];
		size_t j = i;
		while (j > 0 && (*_cities)[j - 1] > current)
		{
			(*_cities)[j] = (*_cities)[j - 1];
			j--;
		}
		(*_cities)[j] = current;
	}
	return *this;
}
#pragma endregion

#pragma region Output
std::ostream& operator<<(std::ostream& os, const City& city)
{
	return os << city._name << " - " << city._population;
}

std::ostream& operator<<(std::ostream& os, const Cities& cities)
{
	os << '[' << std::endl;
	for (int i = 0; i < cities.size(); i++)
		os << cities[i] << std::endl;
	return os << ']';
}
#pragma endregion
