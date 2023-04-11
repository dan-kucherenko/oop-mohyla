#pragma once
#include <iostream>

template <typename T>
class IQueue
{
public:
	IQueue()
	{
#ifndef NDEBUG
		std::cout << "Queue created" << std::endl;
#endif
	}

	virtual  ~IQueue()
	{
#ifndef NDEBUG
		std::cout << "Queue deleted" << std::endl;
#endif
	}

	virtual bool empty() const = 0;
	virtual bool full() const = 0;
	virtual const T& front() const = 0;
	virtual void pop() = 0;
	virtual void put(const T& value) = 0;
	virtual size_t capacity() const = 0;
	virtual size_t size() const = 0;
};
