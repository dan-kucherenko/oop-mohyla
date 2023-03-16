#include "String.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

void copyString(char* target, const char* source, size_t length)
{
	for (size_t i = 0; i < length; ++i)
		target[i] = source[i];
	target[length] = '\0';
}

#pragma region Default constructors
String::String() : _length(0), _string(new char[1]{'\0'})
{
#ifndef NDEBUG
	cout << "String created: " << *this << endl;
#endif
}

String::String(const char character) : _length(1), _string(new char[2]{character, '\0'})
{
#ifndef NDEBUG
	cout << "String created with a char: " << *this << endl;
#endif
}

String::String(const char* characters) : _length(strlen(characters)), _string(new char[_length + 1])
{
	if (characters == nullptr)
		throw BadString("Bad string: string is null");
	for (size_t i = 0; i < _length; i++)
		_string[i] = characters[i];
	_string[_length] = '\0';
#ifndef NDEBUG
	cout << "String created from char arr: " << *this << endl;
#endif
}

String::String(const std::string& s) : _length(s.length()), _string(new char[_length + 1])
{
	for (size_t i = 0; i < _length; i++)
		_string[i] = s[i];
#ifndef NDEBUG
	cout << "String created from STL string: " << *this << endl;
#endif
}
#pragma endregion

#pragma region Copy/Move constructors
String::String(const String& s) : _length(s._length), _string(new char[_length + 1])
{
	for (size_t i = 0; i < _length; ++i)
		_string[i] = s._string[i];
	_string[_length] = '\0';
#ifndef NDEBUG
	cout << "String copied: " << *this << endl;
#endif
}

String::String(String&& s) noexcept : _length(s._length), _string(s._string)
{
	s._length = 0;
	s._string = nullptr;
#ifndef NDEBUG
	cout << "String moved: " << *this << endl;
#endif
}
#pragma endregion

String::~String()
{
#ifndef NDEBUG
	cout << "String deleted: " << *this << endl;
#endif
	delete[]_string;
}

#pragma region Cast operators
String::operator std::string() const
{
	return std::string(_string);
}

String::operator const char*() const
{
	return _string;
}
#pragma endregion

#pragma region Operator=
String& String::operator=(const String& s)
{
	if (this == &s)
		return *this;
	delete[] getString();
	length() = s.length();
	getString() = new char[length() + 1];
	copyString(getString(), s.getString(), length());
	return *this;
}

String& String::operator=(String&& s) & noexcept
{
	if (this != &s)
	{
		delete[] getString();
		length() = s.length();
		getString() = s.getString();
		s.length() = 0;
		s.getString() = nullptr;
	}
	return *this;
}
#pragma endregion

#pragma region Operator[]
char& String::operator[](const size_t index)
{
	if (index < 0 || length() <= index)
		throw BadString("Bad string: index out of range: ", index);
	return getString()[index];
}

const char& String::operator[](const size_t index) const
{
	if (length() <= index)
		throw BadString("Bad string: index out of range: ", index);
	return getString()[index];
}
#pragma endregion

#pragma region Operator+, +=
const String operator+(const String& s1, const String& s2)
{
	String res(s1);
	return res += s2;
}

String& operator+=(String& s1, const String& s2)
{
	size_t len = s1.length() + s2.length();
	char* newString = new char[len + 1];
	copyString(newString, s1.getString(), s1.length());
	delete[] s1.getString();
	s1.getString() = newString;
	copyString(s1.getString() + s1.length(), s2.getString(), s2.length());
	s1.length() = len;
	return s1;
}
#pragma endregion

#pragma region Operator==, !=
bool operator==(const String&s1, const String& s2)
{
	bool equal = s1.length() == s2.length();
	for (unsigned int i = 0; i < s1.length() && equal; i++)
		equal = s1.getString()[i] == s2.getString()[i];
	return equal;
}

bool operator!=(const String& s1, const String& s2)
{
	return !(s1 == s2);
}
#pragma endregion

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (size_t i = 0; i < s.length(); i++)
		os << s[i];
	return os;
}
