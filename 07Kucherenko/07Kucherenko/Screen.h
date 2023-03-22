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
	Screen& operator=(const Screen&);

public:
	Screen(const size_t, const size_t, char* pc = 0);
	~Screen();

	const int& width() const { return _width; }
	const int& height() const { return _height; }
	const char* content() const { return _ñontent; }

	char get() const;
	const Screen& set(char) const;
	Screen& set(char);

	const Screen& home() const; // get on the start of the screen
	Screen& home();

	const Screen& moveOneRight() const; // get one cursor to the right
	Screen& moveOneRight();

	const Screen& moveOneLeft() const; // get one cursor to the left
	Screen& moveOneLeft();

	const Screen& show() const; // show the screen with content
	Screen& show();

	const Screen& move(const size_t, const size_t) const; // move to the particular point on screen
	Screen& move(const size_t, const size_t);

	const Screen& clearScreen() const; // clear the whole screen
	Screen& clearScreen();

	const Screen& showCurrent() const; // show the char, which is currently "on" the cursor
	Screen& showCurrent();
};

ostream& operator<<(ostream&, const Screen&);

typedef const Screen& (Screen::* const ConstAction)() const;
typedef Screen& (Screen::* const NonConstAction)();

void doActionConst(const Screen&, ConstAction, size_t);
void doActionNonConst(Screen&, NonConstAction, size_t);
