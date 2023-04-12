#pragma once

#include "IQueue.h"

template<class T>
class QueueList : public IQueue<T> {
private:
    size_t _size;

    struct ListNode {
        T _value;
        ListNode *_next;
    };

    ListNode *_head;

public:
    class BadQueueList;

    explicit QueueList();

    ~QueueList();

    inline bool empty() const { return _head == nullptr; }

    inline bool full() const { return _head->_next = nullptr; }

    const T &front() const;

    void pop();

    void put(const T &value);

    inline size_t capacity() const { return false; }

    inline size_t size() const { return _size; }

    void print() const; // method to output the queue for testing
};

template<class T>
void QueueList<T>::print() const {
    ListNode *node = _head;
    while (node->_next != nullptr) {
        std::cout << node->_value << ' ';
        node = node->_next;
    }
    std::cout << std::endl;
}

template<class T>
QueueList<T>::QueueList() : _size(0), _head(nullptr) {
}

template<class T>
QueueList<T>::~QueueList() {
    while (_head != nullptr) {
        ListNode *temp = _head;
        _head = _head->_next;
        delete temp;
    }
}

template<class T>
const T &QueueList<T>::front() const {
    if (empty())
        throw BadQueueList("Queue is empty, there is no front element");
    return _head->_value;
}

template<class T>
void QueueList<T>::pop() {
    if (empty())
        throw BadQueueList("Queue is empty, there is nothing to pop");
    --_size;
    ListNode *temp = _head;
    _head = _head->_next;
    delete temp;
}

template<class T>
void QueueList<T>::put(const T &value) {
    ListNode *newNode = new ListNode;
    newNode->_value = value;
    newNode->_next = nullptr;
    if (empty())
        _head = newNode;
    else {
        ListNode *temp = _head;
        while (temp->_next != nullptr)
            temp = temp->_next;
        temp->_next = newNode;
    }
    ++_size;
}

#pragma region BadQueueList Implementation

template<class T>
class QueueList<T>::BadQueueList {
private:
    std::string _problem;

public:
    BadQueueList(const std::string problem = "") : _problem(problem) {
    }

    ~BadQueueList() {
    }

    inline void exceptionMessage() const {
        std::cerr << _problem << std::endl;
    }
};

#pragma endregion
