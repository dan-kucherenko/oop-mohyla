#pragma once
#include <iostream>

using namespace std;

class Screen
{
private:
	static const size_t _maxHeight;
	static const size_t _maxWidth;
	static const char _filler;

	size_t _width;
	size_t _height;
	char* _ñontent;
	mutable size_t _cursor;

	Screen(const Screen&);
	Screen& operator= (const Screen&);
public:
	Screen(const size_t, const size_t, char* pc = 0);
	~Screen();

	const int& width() const { return _width; }
	const int& height() const { return _height; }
	const char* content() const { return _ñontent; }

	char get() const;

	const Screen& set(char) const;
	Screen& set(char);

	const Screen& home() const;
	Screen& home();

	const Screen& moveOneRight() const;
	Screen& moveOneRight();

	const Screen& moveOneLeft() const;
	Screen& moveOneLeft();

	const Screen& show() const;
	Screen& show();

	const Screen& move(const size_t, const size_t) const;
	Screen& move(const size_t, const size_t);

	const Screen& clearScreen() const;
	Screen& clearScreen();

	const Screen& showCurrent() const;
	Screen& showCurrent();
};

	ostream& operator<<(ostream&, const Screen&);

	typedef const Screen& (Screen::* const ConstAction) () const;
	typedef Screen& (Screen::* const NonConstAction) ();

	void doActionConst(const Screen&, ConstAction, size_t);
	void doActionNonConst(Screen&, NonConstAction, size_t);
