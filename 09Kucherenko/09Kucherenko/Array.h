//
// Developed by Daniil Kucherenko on 29.03.2023
//

#pragma once
#include <iostream>
#include "Array.h"

template <size_t n, class T>
class Array
{
private:
	const size_t _size;
	T* _array;
	bool operator==(const Array&) const;

public:
	class BadArray
	{
	private:
		std::string _problem;
		size_t _index;

	public:
		explicit BadArray(const std::string& problem, const size_t index);

		~BadArray()
		{
		}

		void exceptionMessage() const;
	};

	explicit Array();
	~Array();
	Array(const Array&);
	Array& operator=(const Array&);

	const T& operator[](const size_t) const;
	T& operator[](const size_t);
	size_t size() const;
};

template <size_t n, class T>
std::ostream& operator<<(std::ostream&, const Array<n, T>&);


template <size_t n, class T>
Array<n, T>::Array(const Array& source) : _size(source.size())
{
	delete[] _array;
	_array = nullptr;
	_array = new T[_size];
	for (size_t i = 0; i < _size; i++) 
		_array[i] = source[i];
}

template <size_t n, class T>
Array<n, T>& Array<n, T>::operator=(const Array& source)
{
	if (this == &source)
		return *this;
	delete[] _array;
	_array = nullptr;
	_array = new T[source.size()]();
	for (size_t i = 0; i < source.size(); i++)
		_array[i] = source[i];
	return *this;
}

template <size_t n, class T>
Array<n, T>::BadArray::BadArray(const std::string& problem, const size_t index) : _problem(problem), _index(index)
{
}

template <size_t n, class T>
void Array<n, T>::BadArray::exceptionMessage() const
{
	std::cout << _problem << " for index " << _index << std::endl;
}

template <size_t n, class T>
inline Array<n, T>::Array() : _size(n), _array(new T[_size])
{
}

template <size_t n, class T>
inline Array<n, T>::~Array()
{
	delete[] _array;
}

template <size_t n, class T>
inline const T& Array<n, T>::operator[](const size_t index) const
{
	if (index >= size())
		throw BadArray("Given index is out of bounds", index);
	return _array[index];
}

template <size_t n, class T>
inline T& Array<n, T>::operator[](const size_t index)
{
	if (index >= size())
		throw BadArray("Given index is out of bounds", index);
	return _array[index];
}

template <size_t n, class T>
inline size_t Array<n, T>::size() const
{
	return _size;
}

template <size_t n, class T>
inline std::ostream& operator<<(std::ostream& os, const Array<n, T>& arr)
{
	os << '[';
	for (size_t i = 0; i < arr.size(); i++)
		os << arr[i] << ", ";
	return os << ']';
}
