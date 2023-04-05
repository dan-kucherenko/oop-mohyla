#include <iostream>

#include "Point.h"
#include "Sequence.h"

using namespace std;

int main(void)
{
	Sequence<int> seq1;
	Sequence<double> seq2(4);
	Sequence<Point> seq3(2);
	Sequence<string> seq4;

	{
		cout << "Integer sequence: " << seq1 << endl;
		cout << "Is sequence is empty? " << boolalpha << seq1.empty() << endl;
		seq1.add(1); // add to end of the sequence
		seq1.add(2);
		cout << "Integer sequence with el.: " << seq1 << endl;
		cout << "Sequence size: " << seq1.size() << endl;
		cout << "Sequence capacity: " << seq1.capacity() << endl;
		seq1.insert(3, 1); // add to particular index
		cout << "Integer sequence with inserted element on 1st index: " << seq1 << endl;
		cout << "Is sequence is full? " << boolalpha << seq1.full() << endl;
		cout << "-----------------------------------" << endl;
	}
	{
		seq2.add(2.4);
		seq2.add(2.5);
		seq2.add(2.6);
		seq2.add(2.7);
		cout << endl << "Double sequence: " << seq2 << endl;
		cout << "Sequence size: " << seq2.size() << endl;
		cout << "Sequence capacity: " << seq2.capacity() << endl;
		seq2.cut(); // delete last element of the sequence
		cout << "Double sequence with cut el: " << seq2 << endl;
		seq2.remove(1); // delete the element on particular index
		cout << "Double sequence with cut 1st el: " << seq2 << endl;
		seq2.clear();
		cout << "Cleared sequence: " << seq2 << ", it's size: " << seq2.size() << ", it's capacity:" << seq2.capacity()
			<< endl;
		cout << "-----------------------------------" << endl;
	}
	{
		seq3.add(Point(1, 2));
		seq3.add(Point(2, 3));
		seq3.add(Point(3, 4));
		cout << endl << "Points sequence: " << seq3 << endl;
		cout << "Sequence size: " << seq2.size() << endl;
		cout << "Sequence capacity: " << seq2.capacity() << endl;
		cout << "Sequence element at index 1: " << seq3[1] << endl;
		cout << "Sequence contains elements Point(1,2): " << boolalpha << seq3.contains(Point(1, 2)) << endl;
	}
	{
		try
		{
			seq4.insert("hello", 3); // exception example (index out of bounds of the sequence)
			cout << "4th element of the sequence: " << seq4[4] << endl;
		}
		catch (const Sequence<string>::BadSeq& bs)
		{
			bs.exceptionMessage();
		}
	}
	return 0;
}
