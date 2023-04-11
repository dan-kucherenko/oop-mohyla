#pragma once
#include "Array.h"
#include "IQueue.h"
#include "QueueArray.h"

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
	~QueueSizedArray() override;
	inline bool empty() const override { return size() == 0; }
	inline bool full() const override { return size() == capacity(); }
	const T& front() const override;
	void pop() override;
	void put(const T& value) override;
	inline size_t capacity() const override { return _arr->size(); }
	inline size_t size() const override { return _size; }

	inline void print() const
	{
		std::cout << "Printing queue:" << std::endl; // друк повідомлення перед виводом черги
		for (size_t i = 0; i < size(); i++)
		{
			std::cout << (*_arr)[i] << " ";
		}
		std::cout << std::endl;
	}
};

template <class T>
std::ostream& operator<<(std::ostream& os, const QueueSizedArray<T>& q);

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
		(*_arr)[i] = (*_arr)[i+1];
}

template <class T>
void QueueSizedArray<T>::put(const T& value)
{
	if (full())
		throw BadQueueSizedArray("Queue is already full");
	(*_arr)[_size++] = value;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const QueueSizedArray<T>& q)
{
	os << '[';
	if (!q.empty())
		os << q._arr;
	return os << ']';
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
