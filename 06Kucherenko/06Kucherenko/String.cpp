#include "String.h"
#include <iostream>

using namespace std;

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

String::operator std::string()
{
	return {};
}

String::operator char* () const
{
	return nullptr;
}

#pragma region Operator=
String& String::operator=(const String& s)
{
	if (this == &s)
		return *this;
	delete[] _string;
	_length = s._length;
	_string = new char[_length + 1];
	copyString(_string, s._string, _length);
	return *this;
}

String& String::operator=(const String&&)&
{
	// TODO: insert return statement here
	return *this;
}

String& String::operator=(const std::string& s)
{
	if (*this == s)
		return *this;
	delete[] _string;
	_length = s.length();
	_string = new char[_length + 1];
	copyString(_string, s.c_str(), _length);
	return *this;
}


String& String::operator=(const char* s)
{
	if (s == nullptr)
		return *this;
	delete[] _string;
	for (_length = 0; s[_length]; _length++);
	_string = new char[_length + 1];
	copyString(_string, s, _length);
	return *this;
}

String& String::operator=(const char c)
{
	delete[] _string;
	_length = 1;
	_string = new char[2];
	_string[0] = c;
	_string[1] = '\0';
	return *this;
}
#pragma endregion

#pragma region Operator[]
char& String::operator[](const size_t index)
{
	return _string[index];
}

const char& String::operator[](const size_t index) const
{
	return _string[index];
}
#pragma endregion

#pragma region Operator+, +=
String String::operator+(const String& s) const
{
	String res(*this);
	return res += s;
}

String String::operator+(const std::string&) const
{
	return {};
}

String& String::operator+=(const String& s)
{
	size_t len = _length + s._length;
	char* newString = new char[len + 1];
	copyString(newString, _string, _length);
	delete[] _string;
	_string = newString;
	copyString(_string + _length, s._string, s._length);
	_length = len;
	return *this;
}

String& String::operator+=(const std::string&)
{
	// TODO: insert return statement here
	return *this;
}

String& String::operator+=(const char* s)
{
	if (s == nullptr)
		return *this;
	size_t len = strlen(s);
	char* newString = new char[len + _length + 1];
	copyString(newString, _string, _length);
	delete[] _string;
	_string = newString;
	copyString(_string + _length, s, _length);
	return *this;
}
#pragma endregion

#pragma region Operator==, !=
bool String::operator==(const String& s) const
{
	bool equal = _length == s._length;
	for (unsigned int i = 0; i < _length && equal; i++)
		equal = _string[i] == s[i];
	return equal;
}

bool String::operator==(const std::string& s) const
{
	bool equal = _length == s.length();
	for (unsigned int i = 0; i < _length && equal; i++)
		equal = _string[i] == s[i];
	return equal;
}

bool String::operator!=(const String& s) const
{
	return !(*this == s);
}

bool String::operator!=(const std::string& s) const
{
	return !(*this == s);
}
#pragma endregion

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (size_t i = 0; i < s.length(); i++)
		os << s[i];
	return os;
}
void String::copyString(char* target, const char* source, size_t length)
{
	for (size_t i = 0; i < length; ++i)
		target[i] = source[i];
	target[length] = '\0';
}