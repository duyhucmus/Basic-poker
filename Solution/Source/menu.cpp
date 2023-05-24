#include"function.h"

//0 = Black       8 = Gray
//1 = Blue        9 = Light Blue
//2 = Green       A = Light Green  10
//3 = Aqua        B = Light Aqua   11
//4 = Red         C = Light Red    12
//5 = Purple      D = Light Purple 13
//6 = Yellow      E = Light Yellow 14
//7 = White       F = Bright White 15


void setWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT windowSize;
	windowSize.Top = 0;
	windowSize.Left = 0;
	windowSize.Right = width;
	windowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &windowSize);
}

void setColor(int code)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}

void menu()
{
	setColor(12);
	setWindowSize(65, 40);
	cout << endl << endl;
	cout << "               ----------- P0KER GAME -----------                               " << endl;
	cout << "                              $$$$                                              " << endl << endl;
	cout << "                >Press number to start the game:                                " << endl;
	cout << "                >Choice :                                                       " << endl;
	setColor(10);
	cout << "                 -> Number 1: TEST CARD.                                        " << endl;
	setColor(15);
	cout << "                 -> Number 2: PLAY EASY.                                        " << endl;
	setColor(9);
	cout << "                 -> Number 3: PLAY MEDIUM.                                      " << endl;
	setColor(12);
	cout << "                 -> Number 4: PLAY HARD.                                        " << endl;
	setColor(13);
	cout << "                 -> Number 0: EXIT GAME.                                        " << endl;
	setColor(4);
	cout << "                         ------------                                           " << endl;
	setColor(11);
}



