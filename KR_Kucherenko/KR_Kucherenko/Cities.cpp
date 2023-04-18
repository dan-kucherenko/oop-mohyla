#include "Cities.h"

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

//Cities& Cities::operator=(const Cities&)
//{
//	// TODO: insert return statement here
//}

#pragma region Operator[]
const City& Cities::operator[](const size_t index) const
{
	/*try
	{
		if (index > size())
			throw BadCities("Index is out of bounds");*/
	return (*_cities)[index];
	/*}
catch (const BadCities& bc)
{
	bc.exceptionMessage();
}*/
}

City& Cities::operator[](const size_t index)
{
	/*try
	{
		if (index > size())
			throw BadCities("Index is out of bounds");*/
	return (*_cities)[index];
	/*}
	catch (const Sequence<City>::BadSeq& bs)
	{
		bs.exceptionMessage();
		return nullptr;
	}*/
}
#pragma endregion

#pragma region AddOperator
Cities& Cities::addCity(const City& city)
{
	_cities->add(city);
	size_t index = 0;
	while (index < _cities->size() && toupper((*_cities)[index]._name[0]) < toupper(city._name[0]))
		index++;
	_cities->insert(city, index);
	_size++;
	return *this;
}

Cities& Cities::addCity(const std::string& cityName, const unsigned int population)
{
	addCity({ cityName, population });
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

