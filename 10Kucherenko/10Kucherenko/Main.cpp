#include <iostream>

#include "QueueArray.h"
#include "QueueSizedArray.h"

using namespace std;

int main(void)
{
	QueueSizedArray<int> q(3);
	QueueArray<char> q2;
	{
		cout << "Sized queue based on array testing: " << endl;
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
