#pragma once
#include <string>

class String
{
private:
	size_t _length;
	char* _string;
	void copyString(char*, const char*, size_t);
public:
	String();
	String(const char);
	explicit String(const char*);
	explicit  String(const std::string&);
	String(const String&);
	String(String&&) noexcept;
	~String();

	inline const char* string() const { return _string; }
	inline size_t length() const { return _length; }
	inline size_t empty() const { return _length == 0; }
	inline void clear() { *this = String(); }

	operator std::string();
	operator char* () const;

	String& operator=(const String&);
	String& operator=(const String&&) &;
	String& operator=(const std::string&);
	String& operator=(const char*);
	String& operator=(const char);

	char& operator[](const size_t);
	const char& operator[](const size_t) const;

	String operator+(const String&) const;
	String operator+(const std::string&) const;

	String& operator+=(const String&);
	String& operator+=(const std::string&);
	String& operator+=(const char*);

	bool operator==(const String&) const;
	bool operator==(const std::string&) const;

	bool operator!=(const String&) const;
	bool operator!=(const std::string&) const;
};

std::ostream& operator<<(std::ostream&, const String&);
