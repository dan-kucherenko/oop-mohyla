#pragma once

#include "Sequence.h"

struct City
{
	std::string _name;
	unsigned int _population;
};

std::ostream& operator<<(std::ostream&, const City&);

class Cities
{
private:
	size_t _size;
	Sequence<City>* _cities;

public:
	class BadCities;
	Cities();
	~Cities();

	Cities& operator=(const Cities&);

	const City& operator[](const size_t) const;
	City& operator[](const size_t);

	inline size_t size() const { return _size; }

	Cities& addCity(const City&);
	Cities& addCity(const std::string&, const unsigned int);
};

std::ostream& operator<<(std::ostream&, const Cities&);

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
