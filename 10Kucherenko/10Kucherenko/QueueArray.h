//
// Developed by Daniil Kucherenko on 11.04.23
//

#pragma once

#include "Array.h"
#include "IQueue.h"

template <class T>
class QueueArray : public IQueue<T>
{
private:
	size_t _size;
	static const size_t _defaultSize = 0;
	Array<T>* _arr;

	void enlarge(const size_t times = 2);

	//unused methods
	QueueArray(const QueueArray&);

	QueueArray& operator=(const QueueArray&);

public:
	class BadQueueArray;

	explicit QueueArray(const size_t capacity = _defaultSize);

	~QueueArray();

	inline bool empty() const { return size() == 0; }

	inline bool full() const { return size() == capacity(); }

	const T& front() const;

	void pop();

	void put(const T& value);

	inline size_t capacity() const { return _arr->size(); }

	inline size_t size() const { return _size; }

	void print() const; // method to output the queue for testing
};

template <class T>
void QueueArray<T>::print() const
{
	for (size_t i = 0; i < size(); i++)
		std::cout << (*_arr)[i] << ' ';
	std::cout << std::endl;
}

template <class T>
void QueueArray<T>::enlarge(const size_t times)
{
	const size_t newSize = capacity() * times + 1;
	Array<T>* newArr = new Array<T>(newSize);
	for (size_t i = 0; i < _size; ++i)
		(*newArr)[i] = (*_arr)[i];
	delete _arr;
	_arr = newArr;
}

template <class T>
QueueArray<T>::QueueArray(const size_t capacity) : _size(0), _arr(new Array<T>(capacity))
{
}

template <class T>
QueueArray<T>::~QueueArray()
{
	delete _arr;
}

template <class T>
inline const T& QueueArray<T>::front() const
{
	if (empty())
		throw BadQueueArray("Queue is empty, there is no front");
	return (*_arr)[0];
}

template <class T>
void QueueArray<T>::pop()
{
	if (empty())
		throw BadQueueArray("Queue is empty, there is nothing to pop");
	--_size;
	for (size_t i = 0; i < _size; ++i)
		(*_arr)[i] = (*_arr)[i + 1];
}

template <class T>
void QueueArray<T>::put(const T& value)
{
	if (size() + 1 > capacity())
		enlarge();
	(*_arr)[_size++] = value;
}

#pragma region BadQueueList Implementation

template <class T>
class QueueArray<T>::BadQueueArray
{
private:
	std::string _problem;

public:
	BadQueueArray(const std::string problem = "") : _problem(problem)
	{
	}

	~BadQueueArray()
	{
	}

	inline void exceptionMessage() const
	{
		std::cerr << _problem << std::endl;
	}
};

#pragma endregion
