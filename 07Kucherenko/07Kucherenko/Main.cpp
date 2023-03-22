#include "Screen.h"

int main()
{
	const size_t size = 10;

	cout << "Constant screen menu: " << endl << endl;
	char filler1[] =
		"===============================================================================================================";
	Screen constScreen(size, size, filler1);
	const ConstAction constMenu[] = {
		&Screen::home,
		&Screen::moveOneRight,
		&Screen::moveOneLeft,
		&Screen::show,
		&Screen::showCurrent
	};

	size_t actionIndex, actionsNum;
	char ch;
	do
	{
		cout << "0 : home()" << endl;
		cout << "1 : moveOneRight()" << endl;
		cout << "2 : moveOneLeft()" << endl;
		cout << "3 : show()" << endl;
		cin >> actionIndex;
		cout << "Number of actions: ";
		cin >> actionsNum;
		doActionConst(constScreen, constMenu[actionIndex], actionsNum);
		cout << "If you want to repeat, please, press '1': ";
		cin >> ch;
	}
	while (ch == '1');


	cout << "Non-constant screen menu: " << endl << endl;
	char filler2[] = "///////";
	Screen nonConstScreen(size, size, filler2);
	const NonConstAction menu2[] = {
		&Screen::home,
		&Screen::moveOneRight,
		&Screen::moveOneLeft,
		&Screen::clearScreen
			&Screen::show
	};
	do
	{
		cout << "0 : home()" << endl;
		cout << "1 : moveOneRight()" << endl;
		cout << "2 : moveOneLeft()" << endl;
		cout << "3 : clearScreen()" << endl;
		cout << "4 : show()" << endl;
		cin >> actionIndex;
		cout << "Number of actions: ";
		cin >> actionsNum;
		doActionConst(constScreen, constMenu[actionIndex], actionsNum);
		cout << "If you want to repeat, please, press '1': ";
		cin >> ch;
	}
	while (ch == '1');
	delete[] filler1;
	delete[] filler2;
	return 0;
}
