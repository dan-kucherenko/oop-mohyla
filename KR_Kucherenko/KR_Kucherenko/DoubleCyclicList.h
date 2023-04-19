//
// Developed by Daniil Kucherenko on 19.04.2023
//

#pragma once
#include "DoubleList.h"

template <class T>
class DoubleCyclicList : public DoubleList<T>
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
	Node* _back;

public:
	class BadDoubleCyclicList;
	DoubleCyclicList();
	~DoubleCyclicList() override;

	const T& front() const;
	const T& back() const;

	DoubleCyclicList& addFront(const T&);
	DoubleCyclicList& addBack(const T&);
	DoubleCyclicList& removeFront();
	DoubleCyclicList& removeBack();

	DoubleCyclicList& insert(const size_t, const T&) override;
	DoubleCyclicList& remove(const size_t) override;

	const T& operator[](const size_t) const override;
	T& operator[](const size_t) override;

	size_t size() const override;
	bool empty() const override;
	void clear() override;
};

#pragma region Constructor/Destructor
template <class T>
inline DoubleCyclicList<T>::DoubleCyclicList() : _size(0), _head(nullptr), _back(nullptr)
{
}

template <class T>
inline DoubleCyclicList<T>::~DoubleCyclicList()
{
	clear();
}
#pragma endregion

template <class T>
inline const T& DoubleCyclicList<T>::front() const
{
	if (empty())
		throw BadDoubleCyclicList("List is empty, there is no front element");
	return _head->_value;
}

template <class T>
inline const T& DoubleCyclicList<T>::back() const
{
	if (empty())
		throw BadDoubleCyclicList("List is empty, there is no back element");
	return _back->_value;
}

#pragma region Add/Remove Methods
template <class T>
inline DoubleCyclicList<T>& DoubleCyclicList<T>::addFront(const T& value)
{
	Node* newNode = new Node{value, _head, _back};
	if (_head != nullptr)
		_head->_prev = newNode;
	_head = newNode;
	if (_back == nullptr)
		_back = _head;
	_back->_next = _head;
	++_size;
	return *this;
}

template <class T>
inline DoubleCyclicList<T>& DoubleCyclicList<T>::addBack(const T& value)
{
	Node* newNode = new Node{value, _head, _back};
	if (_back != nullptr)
		_back->_next = newNode;
	_back = newNode;
	if (_head == nullptr)
		_head = _back;
	_head->_prev = _back;
	++_size;
	return *this;
}

template <class T>
inline DoubleCyclicList<T>& DoubleCyclicList<T>::removeFront()
{
	if (empty())
		throw BadDoubleCyclicList("Cyclic list is empty, nothing to remove");
	Node* nodeToRemove = _head;
	_head = nodeToRemove->_next;
	if (_head != nullptr)
		_head->_prev = _back;
	else
		_back = nullptr;
	_size--;
	delete nodeToRemove;
	return *this;
}

template <class T>
inline DoubleCyclicList<T>& DoubleCyclicList<T>::removeBack()
{
	if (empty())
		throw BadDoubleCyclicList("Cyclic list is empty, nothing to remove");
	Node* nodeToRemove = _back;
	_back = nodeToRemove->_prev;
	if (_back != nullptr)
		_back->_next = _head;
	else
		_head = nullptr;
	_size--;
	delete nodeToRemove;
	return *this;
}

template <class T>
inline DoubleCyclicList<T>& DoubleCyclicList<T>::insert(const size_t index, const T& value)
{
	if (index > _size)
		throw BadDoubleCyclicList("Index is out of bounds");
	if (index == 0)
		addFront(value);
	else if (index == _size)
		addBack(value);
	else
	{
		Node* newNode = new Node{value, nullptr, nullptr};
		Node* nodeBefore = _head;
		for (size_t i = 0; i < index - 1; i++)
			nodeBefore = nodeBefore->_next;
		Node* nodeAfter = nodeBefore->_next;
		newNode->_prev = nodeBefore;
		newNode->_next = nodeAfter;
		nodeBefore->_next = newNode;
		nodeAfter->_prev = newNode;
		_size++;
	}
	return *this;
}

template <class T>
inline DoubleCyclicList<T>& DoubleCyclicList<T>::remove(const size_t index)
{
	if (empty())
		throw BadDoubleCyclicList("Cyclic list is empty, nothing to remove");
	if (index >= _size)
		throw BadDoubleCyclicList("Index is out of bounds");
	if (index == 0)
		removeFront();
	else if (index == _size - 1)
		removeBack();
	Node* nodeToRemove = _head;
	for (size_t i = 0; i < index; i++)
		nodeToRemove = nodeToRemove->_next;
	nodeToRemove->_prev->_next = nodeToRemove->_next;
	nodeToRemove->_next->_prev = nodeToRemove->_prev;
	delete nodeToRemove;
	--_size;
	return *this;
}
#pragma endregion

#pragma region Operator[]
template <class T>
inline const T& DoubleCyclicList<T>::operator[](const size_t index) const
{
	if (index >= size())
		throw BadDoubleCyclicList("Index is out of bounds");
	Node* node = _head;
	for (size_t i = 0; i < index; ++i)
		node = node->_next;
	return node->_value;
}

template <class T>
inline T& DoubleCyclicList<T>::operator[](const size_t index)
{
	if (index >= size())
		throw BadDoubleCyclicList("Index is out of bounds");
	Node* node = _head;
	for (size_t i = 0; i < index; ++i)
		node = node->_next;
	return node->_value;
}
#pragma endregion

#pragma region Size methods
template <class T>
inline size_t DoubleCyclicList<T>::size() const
{
	return _size;
}

template <class T>
inline bool DoubleCyclicList<T>::empty() const
{
	return _size == 0;
}

template <class T>
inline void DoubleCyclicList<T>::clear()
{
	while (!empty())
		removeFront();
	_head = _back = nullptr;
}
#pragma endregion

template <class T>
inline std::ostream& operator<<(std::ostream& os, const DoubleCyclicList<T>& dñl)
{
	for (int i = 0; i < dñl.size(); i++)
		os << dñl[i] << ' ';
	return os;
}

template <class T>
class DoubleCyclicList<T>::BadDoubleCyclicList
{
private:
	std::string _reason;

public:
	inline BadDoubleCyclicList(const std::string reason = "") : _reason(reason)
	{
	}

	~BadDoubleCyclicList()
	{
	}

	inline void exceptionMessage() const
	{
		std::cerr << _reason << std::endl;
	}
};
