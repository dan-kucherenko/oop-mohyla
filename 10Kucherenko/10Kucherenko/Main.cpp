#include <iostream>

#include "QueueArray.h"
#include "QueueList.h"
#include "QueueSizedArray.h"

using namespace std;

int main(void)
{
	QueueSizedArray<int> q(3);
	QueueArray<char> q2;
	QueueList<double> q3;

	{
		cout << endl << "Sized queue based on array testing: " << endl;
		cout << "Queue size: " << q.size() << ". Is it empty? " << boolalpha << q.empty() << endl;
		cout << "Queue capacity: " << q.capacity() << endl;
		try
		{
			q.put(3);
			cout << "Queue size: " << q.size() << endl;
			q.put(2);
			q.put(5);
			cout << "Queue front: " << q.front() << endl;
			cout << "Queue size: " << q.size() << endl;
			cout << "Is the queue full with capacity " << q.capacity() << "? " << boolalpha << q.full() << endl;
			q.print();
			q.pop();
			cout << "Element popped" << endl;
			q.print();
			cout << "Queue capacity: " << q.capacity() << endl;
			cout << "Queue size: " << q.size() << endl;
		}
		catch (const QueueSizedArray<int>::BadQueueSizedArray& bqsa)
		{
			bqsa.exceptionMessage();
		}
		cout << "---------------------------------------------" << endl;
	}
	{
		cout << endl << "Queue based on list testing: " << endl;
		cout << "Queue size: " << q3.size() << ". Is it empty? " << boolalpha << q3.empty() << endl;
		cout << "Queue capacity: " << q3.capacity() << endl;
		try
		{
			q3.put(3.4);
			q3.put(3.5);
			q3.put(3.6);
			q3.put(3.7);
			q3.put(3.8);
			cout << "Queue front: " << q3.front() << endl;
			q3.print();
			cout << "Queue size: " << q3.size() << endl;
			q3.pop();
			cout << "Element popped" << endl;
			q3.print();
		}
		catch (const QueueList<double>::BadQueueList& bql)
		{
			bql.exceptionMessage();
		}
		cout << "---------------------------------------------" << endl;
	}
	{
		cout << endl << "Queue based on array testing: " << endl;
		cout << "Queue size: " << q2.size() << ". Is it empty? " << boolalpha << q2.empty() << endl;
		cout << "Queue capacity: " << q2.capacity() << endl;
		try
		{
			q2.put('n');
			cout << "Queue size: " << q2.size() << endl;
			q2.put('a');
			q2.put('u');
			q2.put('k');
			q2.put('m');
			q2.put('a');
			q2.put('a');
			cout << "Queue front: " << q2.front() << endl;
			cout << "Queue size: " << q2.size() << endl;
			cout << "Is the queue full with capacity " << q2.capacity() << "? " << boolalpha << q2.full() << endl;
			q2.print();
			q2.pop();
			cout << "Element popped" << endl;
			q2.print();
			cout << "Queue capacity: " << q2.capacity() << endl;
			cout << "Queue size: " << q2.size() << endl;
			q2.put('r');
			q2.put('r');
			q2.put('r');
			q2.put('r');
			q2.print();
		}
		catch (const QueueArray<char>::BadQueueArray& bqa)
		{
			bqa.exceptionMessage();
		}
		cout << "---------------------------------------------" << endl;
	}

	return 0;
}
