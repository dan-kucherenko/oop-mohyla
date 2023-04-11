#include <iostream>

#include "QueueArray.h"

using namespace std;

int main(void)
{
	QueueArray<int> q(2);
	{
		try
		{
			cout << "Queue size: " << q.size() << ". Is it empty? " << boolalpha << q.empty() << endl;
			cout << "Queue capacity: " << q.capacity() << endl;
			q.put(3);
			cout << "Queue size: " << q.size() << endl;
			q.put(2);
			cout << "Queue front: " << q.front() << endl;
			cout << "Queue size: " << q.size() << endl;
			cout << "Is the queue full with capacity " << q.capacity() << "? " << boolalpha << q.full() << endl;
			q.print();
			q.pop();
			q.print();
			cout << "Queue capacity: " << q.capacity() << endl;
			cout << "Queue size: " << q.size() << endl;
		}
		catch (const QueueArray<int>::BadQueueArray& bqa)
		{
			bqa.exceptionMessage();
		}
	}


	return 0;
}
