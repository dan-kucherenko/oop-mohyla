//
// Developed by Daniil Kucherenko on 04.04.2023
//

#pragma once
#include <cassert>
#include <ostream>
#include "Array.h"

template <class T>
class Sequence
{
private:
	size_t _size;
	static const size_t _defaultSize = 0;
	Array<T>* _array;
	void enlarge(const size_t times = 2);
	Sequence& makeInsert(const T elem, const size_t index);
	Sequence& makeRemove(const size_t index);

	// unused functions
	Sequence(const Sequence&);
	Sequence& operator=(const Sequence&);

public:
	class BadSeq;
	explicit Sequence(const size_t capacity = _defaultSize);
	~Sequence();
	inline size_t capacity() const { return _array->size(); }
	inline size_t size() const { return _size; }
	bool empty() const { return size() == 0; }
	bool full() const { return size() == capacity(); }
	Sequence& clear();

	bool contains(T element) const;


	const T& operator[](const size_t index) const;
	T& operator[](const size_t index);

	Sequence& add(const T& elem); // adds new element after the last one
	Sequence& insert(const T& elem, const size_t index);

	Sequence& cut(); // deletes last element
	Sequence& remove(const size_t index);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Sequence<T>& seq);

#pragma region Constructor/Destructor
template <class T>
Sequence<T>::Sequence(const size_t capacity) : _size(0), _array(new Array<T>(capacity))
{
#ifndef NDEBUG
	std::cout << "Sequence created with capacity " << capacity << std::endl;
#endif
}

template <class T>
Sequence<T>::~Sequence()
{
#ifndef NDEBUG
	std::cout << "Sequence deleted" << std::endl;
#endif
	delete _array;
}
#pragma endregion

template <class T>
Sequence<T>& Sequence<T>::clear()
{
	_size = 0;
	return *this;
}

template <class T>
bool Sequence<T>::contains(T element) const
{
	for (size_t i = 0; i < _size; i++)
	{
		if (element == (*_array)[i])
			return true;
	}
	return false;
}

#pragma region Operator[]
template <class T>
const T& Sequence<T>::operator[](const size_t index) const
{
	return const_cast<Sequence&>(*this)[index];
}

template <class T>
T& Sequence<T>::operator[](const size_t index)
{
	if (empty())
		throw BadSeq("The sequence is empty.");
	if (index >= _size)
		throw BadSeq("The index is bigger than the size.");
	return (*_array)[index];
}
#pragma endregion

#pragma region Add/Delete Element
template <class T>
Sequence<T>& Sequence<T>::add(const T& elem)
{
	return makeInsert(elem, _size);
}

template <class T>
Sequence<T>& Sequence<T>::insert(const T& elem, const size_t index)
{
	if (size() < index)
		throw BadSeq("The index is out of bounds for sequences with size");
	return makeInsert(elem, index);
}

template <class T>
Sequence<T>& Sequence<T>::cut()
{
	return makeRemove(_size);
}

template <class T>
Sequence<T>& Sequence<T>::remove(const size_t index)
{
	if (_size < index || index == 0)
		throw BadSeq("The index is out of bounds for sequences with size");
	return makeRemove(index);
}
#pragma endregion


template <class T>
std::ostream& operator<<(std::ostream& os, const Sequence<T>& seq)
{
	os << '[';
	if (!seq.empty())
	{
		for (size_t i = 0; i < seq.size(); ++i)
			os << seq[i] << (i != seq.size() - 1 ? ", " : "");
	}
	return os << ']';
}

template <class T>
class Sequence<T>::BadSeq
{
private:
	std::string _reason;

public:
	BadSeq(const std::string reason = "") : _reason(reason)
	{
	}

	~BadSeq()
	{
	}

	void exceptionMessage() const
	{
		std::cerr << _reason << std::endl;
	}
};

#pragma region HelperFuncs
template <class T>
void Sequence<T>::enlarge(const size_t times)
{
	const size_t newSize = capacity() * times + 1;
	Array<T>* newArray = new Array<T>(newSize);
	for (size_t i = 0; i < _size; ++i)
		(*newArray)[i] = (*_array)[i];
	delete _array;
	_array = newArray;
}

template <class T>
Sequence<T>& Sequence<T>::makeInsert(const T elem, const size_t index)
{
	assert(index <= _size);
	if (_size + 1 > capacity())
		enlarge();
	_size++;
	for (size_t i = _size - 1; i > index; --i)
		(*this)[i] = (*this)[i - 1];
	(*_array)[index] = elem;
	return *this;
}

template <class T>
Sequence<T>& Sequence<T>::makeRemove(const size_t index)
{
	assert(index <= _size);
	if (empty())
		throw BadSeq("The sequence is empty.");
	--_size;
	for (size_t i = index; i <= _size && i > 0; ++i)
		(*_array)[i - 1] = (*_array)[i];
	return *this;
}
#pragma endregion
