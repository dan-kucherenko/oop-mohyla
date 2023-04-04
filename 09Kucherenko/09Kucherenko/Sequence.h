//
// Developed by Daniil Kucherenko on 04.04.2023
//

#pragma once
#include <ostream>
#include "Array.h"

template <class T>
class Sequence
{
private:
	size_t _size;
	Array* _array;
	static const size_t _defaultSize;
	void enlarge(const size_t times = 2);
	Sequence& insert(const T elem, const size_t index);
	Sequence& remove(const size_t index);

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

template <int n, class T>
std::ostream& operator<<(std::ostream& os, const Sequence<n, T>& seq);

#pragma region Constructor/Destructor
template <class T>
Sequence<T>::Sequence(const size_t capacity) : _size(0), _array(new Array<capacity, T>)
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
	delete[] _array;
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

template <class T>
inline const T& Sequence<T>::operator[](const size_t index) const
{
	// TODO: insert return statement here
}

template <class T>
inline T& Sequence<T>::operator[](const size_t index)
{
	// TODO: insert return statement here
}

template <class T>
inline Sequence& Sequence<T>::add(const T& elem)
{
	// TODO: insert return statement here
}

template <class T>
inline Sequence& Sequence<T>::insert(const T& elem, const size_t index)
{
	// TODO: insert return statement here
}

template <class T>
inline Sequence& Sequence<T>::cut()
{
	// TODO: insert return statement here
}

template <class T>
inline Sequence& Sequence<T>::remove(const size_t index)
{
	// TODO: insert return statement here
}

template <int n, class T>
inline std::ostream& operator<<(std::ostream& os, const Sequence<n, T>& seq)
{
	// TODO: insert return statement here
}
