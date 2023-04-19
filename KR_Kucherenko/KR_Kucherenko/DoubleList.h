//
// Developed by Daniil Kucherenko on 19.04.2023
//

#pragma once
#include <iostream>

template <class T>
class DoubleList
{
public:
	inline DoubleList()
	{
#ifndef NDEBUG
		std::cout << "List created" << std::endl;
#endif
	}

	inline virtual ~DoubleList()
	{
#ifndef NDEBUG
		std::cout << "List deleted" << std::endl;
#endif
	}

	virtual const T& front() const = 0;
	virtual const T& back() const = 0;

	virtual DoubleList& addFront(const T&) = 0;
	virtual DoubleList& addBack(const T&) = 0;
	virtual DoubleList& removeFront() = 0;
	virtual DoubleList& removeBack() = 0;

	virtual DoubleList& insert(const size_t, const T&) = 0;
	virtual DoubleList& remove(const size_t) = 0;

	virtual const T& operator[](const size_t) const = 0;
	virtual T& operator[](const size_t) = 0;

	virtual size_t size() const = 0;
	virtual bool empty() const = 0;
	virtual void clear() = 0;

	virtual void showList() = 0;
};
