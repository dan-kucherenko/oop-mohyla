//
// Developed by Daniil Kucherenko on 18.04.2023
//

#pragma once

#include "DoubleList.h"
#include "Sequence.h"


class Cities
{
public:
	struct City
	{
		std::string _name;
		unsigned int _population;
		auto operator<=>(const City&) const = default;
	};

	class BadCities;
	Cities();
	~Cities();

	Cities& operator=(const Cities&);

	const City& operator[](const size_t) const;
	City& operator[](const size_t);

	inline size_t size() const { return _size; }

	Cities& addCity(const City&);
	Cities& addCity(const std::string&, const unsigned int);

	Cities& sortByPopulationAscending();
	Cities& sortByPopulationDescending();
	Cities& rollbackSorting();

private:
	size_t _size;
	Sequence<City>* _cities;
};

std::ostream& operator<<(std::ostream&, const Cities&);
std::ostream& operator<<(std::ostream&, const Cities::City&);

class Cities::BadCities
{
private:
	std::string _reason;

public:
	BadCities(const std::string reason = "") : _reason(reason)
	{
	}

	~BadCities()
	{
	}

	void exceptionMessage() const
	{
		std::cerr << _reason << std::endl;
	}
};
