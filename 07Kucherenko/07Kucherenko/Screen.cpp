#include "Screen.h"


const size_t Screen::_maxHeight = 30;
const size_t Screen::_maxWidth = 60;
const char Screen::_filler = '*';

Screen::Screen(const size_t width, const size_t height, char* content) : _width(width > _maxWidth ? _maxWidth : width),
                                                                         _height(height > _maxHeight
	                                                                         ? _maxHeight
	                                                                         : height),
                                                                         _ñontent(new char[_height * _width + 1]),
                                                                         _cursor(0)
{
	const size_t content_length = content == 0 ? 0 : strlen(content);
	const size_t factual_length = content_length > _height * _width ? _height * _width : content_length;
	_ñontent[_height * _width] = '\0';
	size_t i = 0;
	if (content != nullptr)
	{
		for (; i < factual_length; i++)
			*(_ñontent + i) = *content++;
	}
	else
	{
		for (; i < _height * _width; i++)
			*(_ñontent + i) = _filler;
	}
}

Screen::~Screen()
{
	delete[] _ñontent;
}

#pragma region ReturnToStart
const Screen& Screen::home() const
{
	_cursor = 0;
	return *this;
}

Screen& Screen::home()
{
	_cursor = 0;
	return *this;
}
#pragma endregion

#pragma region MoveMethods
const Screen& Screen::moveOneRight() const
{
	if (++_cursor >= _width * _height)
		_cursor = 0;
	return *this;
}

Screen& Screen::moveOneRight()
{
	if (++_cursor >= _width * _height)
		_cursor = 0;
	return *this;
}

const Screen& Screen::move(const size_t x, const size_t y) const
{
	if (x >= _height || y >= _width)
		_cursor = 0;
	else
		_cursor = _width * x + y;
	return *this;
}

Screen& Screen::move(const size_t x, const size_t y)
{
	if (x >= _height || y >= _width)
		_cursor = 0;
	else
		_cursor = _width * x + y;
	return *this;
}

const Screen& Screen::moveOneLeft() const
{
	if (--_cursor < 0)
		_cursor = 0;
	return *this;
}

Screen& Screen::moveOneLeft()
{
	if (--_cursor < 0)
		_cursor = (_width * _height - 1);
	return *this;
}
#pragma endregion

#pragma region Show
const Screen& Screen::show() const
{
	cout << "Cursor: " << _cursor << endl;
	home();

	for (size_t i = 0; i < _height; i++)
	{
		for (size_t j = 0; j < _width; j++)
		{
			cout << get();
			moveOneRight();
		}
		cout << endl;
	}
	_cursor = _cursor;
	return *this;
}

Screen& Screen::show()
{
	home();
	for (size_t i = 0; i < _height; ++i)
	{
		for (size_t j = 0; j < _width; ++j)
		{
			cout << get();
			moveOneRight();
		}
		cout << endl;
	}
	return *this;
}
#pragma endregion

#pragma region ClearScreen
const Screen& Screen::clearScreen() const
{
	for (size_t i = 0; i < _height * _width; i++)
		_ñontent[i] = _filler;
	_cursor = 0;
	return *this;
}

Screen& Screen::clearScreen()
{
	for (size_t i = 0; i < _width * _height; ++i)
		_ñontent[i] = _filler;
	_cursor = 0;
	return *this;
}
#pragma endregion

#pragma region GetCharOnTheCursor
const Screen& Screen::showCurrent() const
{
	cout << "Current content: " << _ñontent[_cursor] << endl;
	return *this;
}

Screen& Screen::showCurrent()
{
	cout << "Current content: " << _ñontent[_cursor] << endl;
	return *this;
}
#pragma endregion

#pragma region Get/Set
char Screen::get() const
{
	return *(_ñontent + _cursor);
}

const Screen& Screen::set(char ch) const
{
	_ñontent[_cursor] = ch;
	return *this;
}

Screen& Screen::set(char ch)
{
	_ñontent[_cursor] = ch;
	return *this;
}
#pragma endregion

ostream& operator<<(ostream& os, const Screen& scr)
{
	return os << endl << "Width: " << scr.width() << endl << "Height: " << scr.height() << endl << "Content: " << scr.
		content();
}

void doActionConst(const Screen& s, ConstAction act, size_t n)
{
	for (size_t i = 0; i < n; i++)
		(s.*act)();
}

void doActionNonConst(Screen& s, NonConstAction act, size_t n)
{
	for (size_t i = 0; i < n; i++)
		(s.*act)();
}
