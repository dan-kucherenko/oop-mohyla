//
// Developed by Daniil Kucherenko on 11.04.23
//
#pragma once

#include "Array.h"
#include "IQueue.h"

template <class T>
class QueueSizedArray : public IQueue<T>
{
private:
	size_t _size;
	Array<T>* _arr;

	// unused methods
	QueueSizedArray(const QueueSizedArray&);

	QueueSizedArray& operator=(const QueueSizedArray&);

public:
	class BadQueueSizedArray;

	explicit QueueSizedArray(const size_t capacity);

	~QueueSizedArray();

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
void QueueSizedArray<T>::print() const
{
	for (size_t i = 0; i < size(); i++)
		std::cout << (*_arr)[i] << ' ';
	std::cout << std::endl;
}

#pragma region Constructor/Destructor
template <class T>
QueueSizedArray<T>::QueueSizedArray(const size_t capacity) : _size(0), _arr(new Array<T>(capacity))
{
}

template <class T>
QueueSizedArray<T>::~QueueSizedArray()
{
	delete _arr;
}
#pragma endregion

#pragma region Class methods
template <class T>
const T& QueueSizedArray<T>::front() const
{
	if (empty())
		throw BadQueueSizedArray("Queue is empty, there is no front");
	return (*_arr)[0];
}

template <class T>
void QueueSizedArray<T>::pop()
{
	if (empty())
		throw BadQueueSizedArray("Queue is empty, there is nothing to pop");
	--_size;
	for (size_t i = 0; i < _size; ++i)
		(*_arr)[i] = (*_arr)[i + 1];
}

template <class T>
void QueueSizedArray<T>::put(const T& value)
{
	if (full())
		throw BadQueueSizedArray("Queue is already full");
	(*_arr)[_size++] = value;
}
#pragma endregion

#pragma region BadQueueArray Implementation

template <class T>
class QueueSizedArray<T>::BadQueueSizedArray
{
private:
	std::string _problem;

public:
	explicit BadQueueSizedArray(const std::string problem = "") : _problem(problem)
	{
	}

	~BadQueueSizedArray()
	{
	}

	void exceptionMessage() const
	{
		std::cerr << _problem << std::endl;
	}
};

#pragma endregion
