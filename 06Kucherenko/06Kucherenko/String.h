#pragma once
#include <iostream>
#include <string>

class String
{
private:
	size_t _length;
	char* _string;

public:
	class BadString;
	String();
	String(const char);
	String(const char*);
	String(const std::string&);
	String(const String&);
	String(String&&) noexcept;
	~String();

	inline char*& getString() { return _string; }
	inline const char* getString() const { return _string; }
	inline size_t length() const { return _length; }
	inline size_t& length() { return _length; }
	inline size_t empty() const { return _length == 0; }
	inline void clear() { *this = String(); }

	operator std::string() const;
	operator const char*() const;

	String& operator=(const String&);
	String& operator=(String&&) & noexcept;

	char& operator[](const size_t);
	const char& operator[](const size_t) const;
};

bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);
const String operator+(const String&, const String&);
String& operator+=(String&, const String&);

std::ostream& operator<<(std::ostream&, const String&);

class String::BadString
{
private:
	std::string _error;
	size_t _num;

public:
	BadString(std::string err = "", size_t num = 0) :
		_error(err), _num(num)
	{
	};

	~BadString()
	{
	};

	void badString() const
	{
		std::cerr << _error;
		if (_num != 0)
			std::cerr << ' ' << _num;
		std::cerr << std::endl;
	}
};
