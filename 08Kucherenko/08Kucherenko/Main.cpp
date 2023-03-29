#include <iostream>

#include "AComplex.h"
#include "Array.h"
#include "Point.h"

using namespace std;

int main(void)
{
	{
		Array<5, int> intArr;
		cout << "Empty int array: " << intArr << endl;
		intArr[0] = 1;
		intArr[1] = 2;
		intArr[2] = 3;
		intArr[3] = 4;
		intArr[4] = 5;
		cout << "Filled int array: " << intArr << endl;
		Array<5, char> charArr;
		cout << endl << "Empty char array: " << charArr << endl;
		charArr[0] = 'h';
		charArr[1] = 'e';
		charArr[2] = 'l';
		charArr[3] = 'l';
		charArr[4] = 'o';
		cout << "Filled char array: " << charArr << endl;
		Array<3, string> stringArr;
		cout << endl << "Empty string array: " << stringArr << endl;
		stringArr[0] = "Hello";
		stringArr[1] = "World";
		stringArr[2] = "!";
		cout << "Filled string array: " << stringArr << endl << endl;
		Array<3, Point> pointsArr;
		cout << "Empty points array: " << pointsArr << endl;
		pointsArr[0] = Point(0, 1);
		pointsArr[1] = Point(1, 2);
		pointsArr[2] = Point(2, 3);
		cout << "Filled points array: " << pointsArr << endl;
		Array<3, AComplex> complexArr;
		cout << "Empty points array: " << complexArr << endl;
		complexArr[0] = AComplex(0, 1);
		complexArr[1] = AComplex(1, 2);
		complexArr[2] = AComplex(2, 3);
		cout << "Filled arithmetic complex array: " << complexArr << endl;
		cout << "----------------------------------------" << endl;
	}
	{
		cout << "Copying arrays: " << endl;
		Array<3, int> arr1;
		for (int i = 0; i < arr1.size(); ++i)
			arr1[i] = i + 1;
		cout << "arr1: " << arr1 << endl;
		Array<3, int> arr2(arr1);
		cout << "arr2: " << arr2 << endl;
		Array<3, int> arr3;
		arr3 = arr2;
		cout << "arr3: " << arr3 << endl;
		arr3 = arr3;
		cout << "arr3: " << arr3 << endl;
		cout << "----------------------------------------" << endl;
	}
	{
		cout << endl << "Exceptions testing: " << endl;
		Array<2, int> intArr4Exceptions;
		cout << intArr4Exceptions << endl;
		intArr4Exceptions[0] = 1;
		intArr4Exceptions[1] = 2;
		try
		{
			intArr4Exceptions[2] = 3;
		}
		catch (const Array<2, int>::BadArray& e)
		{
			e.exceptionMessage();
		}
		try
		{
			int integerAtIndexThree = intArr4Exceptions[3];
		}
		catch (const Array<2, int>::BadArray& e)
		{
			e.exceptionMessage();
		}
		cout << intArr4Exceptions << endl;
	}
	return 0;
}
