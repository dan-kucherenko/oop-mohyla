#pragma once
#include "Array.h"
#include "IQueue.h"
#include "QueueArray.h"

template <class T>
class QueueArray : public IQueue<T>
{
private:
	size_t _size;
	Array<T>* _arr;

	// unused functions
	QueueArray(const QueueArray&);
	QueueArray& operator=(const QueueArray&);

public:
	class BadQueueArray
	{
	private:
		std::string _problem;

	public:
		explicit BadQueueArray(const std::string& problem);

		~BadQueueArray()
		{
		}

		void exceptionMessage() const;
	};

	explicit QueueArray(const size_t capacity);
	~QueueArray() override;
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
std::ostream& operator<<(std::ostream& os, const QueueArray<T>& q);

#pragma region Constructor/Destructor
template <class T>
QueueArray<T>::QueueArray(const size_t capacity) : _size(0), _arr(new Array<T>(capacity))
{
}

template <class T>
QueueArray<T>::~QueueArray()
{
	delete _arr;
}
#pragma endregion

#pragma region Class methods
template <class T>
const T& QueueArray<T>::front() const
{
	if (!empty())
		return (*_arr)[0];
}

template <class T>
void QueueArray<T>::pop()
{
	if (empty())
		throw BadQueueArray("Queue is empty, there is nothing to pop");
	--_size;
	for (size_t i = size(); i <= _size && i > 0; ++i)
		(*_arr)[i - 1] = (*_arr)[i];
}

template <class T>
void QueueArray<T>::put(const T& value)
{
	if (full())
		throw BadQueueArray("Queue is already full");
	(*_arr)[_size++] = value;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const QueueArray<T>& q)
{
	os << '[';
	if (!q.empty())
		os << q._arr;
	return os << ']';
}
#pragma endregion

#pragma region BadQueueArray Implementation
template <class T>
QueueArray<T>::BadQueueArray::BadQueueArray(const std::string& problem) : _problem(problem)
{
}

template <class T>
void QueueArray<T>::BadQueueArray::exceptionMessage() const
{
	std::cout << _problem << std::endl;
}

#pragma endregion
