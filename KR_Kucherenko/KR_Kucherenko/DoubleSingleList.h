//
// Developed by Daniil Kucherenko on 19.04.2023
//

#pragma once
#include "DoubleList.h"
#include "DoubleSingleList.h"
#include <iostream>

template <class T>
class DoubleSingleList : public DoubleList<T>
{
protected:
	struct Node
	{
		T _value;
		Node* _next;
		Node* _prev;
	};

private:
	size_t _size;
	Node* _head;

public:
	class BadDoubleSingleList;
	DoubleSingleList();
	~DoubleSingleList() override;

	DoubleSingleList& addBack(const T&);
	DoubleSingleList& removeBack();

	DoubleSingleList& insert(const size_t, const T&) override;
	DoubleSingleList& remove(const size_t) override;

	const T& operator[](const size_t) const override;
	T& operator[](const size_t) override;

	size_t size() const override;
	bool empty() const override;
	void clear() override;
};

#pragma region Constructor/Destructor
template <class T>
inline DoubleSingleList<T>::DoubleSingleList() : _size(0), _head(nullptr)
{
}

template <class T>
inline DoubleSingleList<T>::~DoubleSingleList()
{
	clear();
}
#pragma endregion

#pragma region Add/Remove methods
template <class T>
inline DoubleSingleList<T>& DoubleSingleList<T>::insert(const size_t index, const T& value)
{
	if (index > _size)
		throw BadDoubleSingleList("Index is out of bounds");
	Node* newNode = new Node{value, nullptr, nullptr};
	if (_head == nullptr)
		_head = newNode;
	else if (index == 0)
	{
		newNode->_next = _head;
		_head = newNode;
	}
	else
	{
		Node* nodeBefore = _head;
		for (size_t i = 0; i < index - 1; i++)
			nodeBefore = nodeBefore->_next;
		Node* nodeAfter = nodeBefore->_next;
		nodeBefore->_next = newNode;
		newNode->_prev = nodeBefore;
		newNode->_next = nodeAfter;
		if (nodeAfter != nullptr)
			nodeAfter->_prev = newNode;
	}
	_size++;
	return *this;
}

template <class T>
inline DoubleSingleList<T>& DoubleSingleList<T>::addBack(const T& value)
{
	insert(size(), value);
	return *this;
}

template <class T>
inline DoubleSingleList<T>& DoubleSingleList<T>::remove(const size_t index)
{
	if (empty())
		throw BadDoubleSingleList("List is empty");
	if (index >= _size)
		throw BadDoubleSingleList("Index is out of bounds");
	Node* nodeToRemove = _head;
	if (index == 0)
	{
		_head = _head->_next;
		if (_head != nullptr)
			_head->_prev = nullptr;
	}
	else
	{
		for (size_t i = 0; i < index; i++)
			nodeToRemove = nodeToRemove->_next;
		nodeToRemove->_prev->_next = nullptr;
		if (nodeToRemove->_next != nullptr)
			nodeToRemove->_next->_prev = nodeToRemove->_prev;
	}
	delete nodeToRemove;
	_size--;
	return *this;
}

template <class T>
inline DoubleSingleList<T>& DoubleSingleList<T>::removeBack()
{
	remove(size() - 1);
	return *this;
}
#pragma endregion

#pragma region Operator[]
template <class T>
inline const T& DoubleSingleList<T>::operator[](const size_t index) const
{
	if (index >= size())
		throw BadDoubleSingleList("Index is out of bounds");
	Node* node = _head;
	for (size_t i = 0; i < index; ++i)
		node = node->_next;
	return node->_value;
}

template <class T>
inline T& DoubleSingleList<T>::operator[](const size_t index)
{
	if (index >= size())
		throw BadDoubleSingleList("Index is out of bounds");
	Node* node = _head;
	for (size_t i = 0; i < index; ++i)
		node = node->_next;
	return node->_value;
}
#pragma endregion

#pragma region Size methods
template <class T>
size_t DoubleSingleList<T>::size() const
{
	return _size;
}

template <class T>
bool DoubleSingleList<T>::empty() const
{
	return _size == 0;
}

template <class T>
void DoubleSingleList<T>::clear()
{
	while (!empty())
		remove(size() - 1);
	_head = nullptr;
}
#pragma endregion

template <class T>
inline std::ostream& operator<<(std::ostream& os, const DoubleSingleList<T>& dsl)
{
	for (int i = 0; i < dsl.size(); i++)
		os << dsl[i] << ' ';
	return os;
}

template <class T>
class DoubleSingleList<T>::BadDoubleSingleList
{
private:
	std::string _reason;

public:
	inline BadDoubleSingleList(const std::string reason = "") : _reason(reason)
	{
	}

	~BadDoubleSingleList()
	{
	}

	inline void exceptionMessage() const
	{
		std::cerr << _reason << std::endl;
	}
};
