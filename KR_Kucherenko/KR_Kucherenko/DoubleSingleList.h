#pragma once
#include "DoubleList.h"
#include "DoubleSingleList.h"

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
	Node* _back;

public:
	class BadDoubleSingleList;
	DoubleSingleList();
	~DoubleSingleList() override;

	const T& front() const override;
	const T& back() const override;

	DoubleSingleList& addFront(const T&) override;
	DoubleSingleList& addBack(const T&) override;
	DoubleSingleList& removeFront() override;
	DoubleSingleList& removeBack() override;

	DoubleSingleList& insert(const size_t , const T& ) override;
	DoubleSingleList& remove(const size_t) override;

	const T& operator[](const size_t) const override;
	T& operator[](const size_t) override;

	size_t size() const override;
	bool empty() const override;
	void clear() override;

	void showList() override;
};

#pragma region Constructor/Destructor
template <class T>
inline DoubleSingleList<T>::DoubleSingleList() : _size(0), _head(nullptr), _back(nullptr)
{
}

template <class T>
inline DoubleSingleList<T>::~DoubleSingleList()
{
	while (_head != nullptr)
	{
		Node* temp = _head;
		_head = _head->_next;
		delete temp;
	}
}
#pragma endregion

template <class T>
inline const T& DoubleSingleList<T>::front() const
{
	if (empty())
		throw BadDoubleSingleList("List is empty, there is no front element");
	return _head->_value;
}

template <class T>
inline const T& DoubleSingleList<T>::back() const
{
	if (empty())
		throw BadDoubleSingleList("List is empty, there is no back element");
	return _back->_value;
}

#pragma region Add/Remove methods
template <class T>
inline DoubleSingleList<T>& DoubleSingleList<T>::addFront(const T& value)
{
	Node* newNode = new Node{value, _head, nullptr};
	if (_head != nullptr)
		_head->_prev = newNode;
	_head = newNode;
	if (_back == nullptr)
		_back = _head;
	++_size;
	return *this;
}

template <class T>
inline DoubleSingleList<T>& DoubleSingleList<T>::addBack(const T& value)
{
	Node* newNode = new Node{value, nullptr, _back};
	if (_back != nullptr)
		_back->_next = newNode;
	_back = newNode;
	if (_head == nullptr)
		_head = _back;
	++_size;
	return *this;
}

template <class T>
inline DoubleSingleList<T>& DoubleSingleList<T>::removeFront()
{
	if (empty())
		throw BadDoubleSingleList("List is empty, nothing to remove from front");
	Node* node = _head;
	_head = _head->_next;
	if (_head != nullptr)
		_head->_prev = nullptr;
	else
		_back = nullptr;
	delete node;
	--_size;
	return *this;
}

template <class T>
inline DoubleSingleList<T>& DoubleSingleList<T>::removeBack()
{
	if (empty())
		throw BadDoubleSingleList("List is empty, nothing to remove from back");
	Node* node = _back;
	_back = _back->_prev;
	if (_back != nullptr)
		_back->_next = nullptr;
	else
		_head = nullptr;
	delete node;
	--_size;
	return *this;
}

template<class T>
inline DoubleSingleList<T>& DoubleSingleList<T>::insert(const size_t index, const T& value)
{
	if (index > _size)
		throw BadDoubleSingleList("Index is out of bounds");
	if (index == 0)
		addFront(value);
	else if (index == _size)
		addBack(value);
	else {
		Node* newNode = new Node{ value, nullptr, nullptr };
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
inline DoubleSingleList<T>& DoubleSingleList<T>::remove(const size_t index)
{
	if (empty())
		throw BadDoubleSingleList("List is empty, nothing to remove");
	if (index == 0)
		removeFront();
	else if (index == _size - 1)
		removeBack();
	else
	{
		Node* nodeToRemove = _head;
		for (size_t i = 0; i < index; i++)
			nodeToRemove = nodeToRemove->_next;
		nodeToRemove->_prev->_next = nodeToRemove->_next;
		nodeToRemove->_next->_prev = nodeToRemove->_prev;
		delete nodeToRemove;
		_size--;
	}
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
		removeFront();
}
#pragma endregion

template <class T>
inline void DoubleSingleList<T>::showList()
{
	for (int i = 0; i < size(); i++)
		std::cout << (*this)[i] << ' ';
	std::cout << std::endl;
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
