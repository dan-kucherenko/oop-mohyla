#include <iostream>

#include "String.h"
using namespace std;

int main(void)
{
	{
		cout << "Constructors:" << endl;
		String s1;
		String s2('D');
		String s3("Hello123");
		string s("World");
		String s4(s);
		String s5(s3);
		s1 = s5;
		cout << "--------------------------------------" << endl;
	}
	{
		cout << endl << "Operator=" << endl;
		String s1("2");
		String s2("s2 string");
		s1 = s2;
		cout << s1 << endl;
		string s3("stl string");
		s1 = s3;
		cout << s1 << endl;
		char* s4 = new char[]{"c-type string"};
		s1 = s4;
		cout << s1 << endl;
		cout << "--------------------------------------" << endl;
	}
	{
		cout << endl << "Operator[]" << endl;
		String s1("Hello");
		cout << "Char at the 3rd positions is: " << s1[2] << endl;
		s1[2] = 'e';
		cout << "Modified string using operator[]: " << s1 << endl;
		cout << "--------------------------------------" << endl;
	}
	{
		cout << endl << "Operator+/+=" << endl;
		String s1;
		string s2("stl string");
		char* p = new char[]{"p c-type string"};
		cout << (s1 += s2) << endl;
		cout << s1 + s2 << endl;
		cout << s2 + s1 << endl;
		cout << p + s1 << endl;
		cout << (s1 += p) << endl;
		cout << "--------------------------------------" << endl;
	}
	{
	 	cout << endl << "Operator==/!=" << endl;
	 	String s1("Hello World");
	 	string s2("Hello World");
	 	cout << "Strings are identical: " << boolalpha << (s1 == s2) << endl;
	 	cout << "Strings are different: " << boolalpha << (s1 != s2) << endl;
	 	cout << "--------------------------------------" << endl;
	 }
	return 0;
}
