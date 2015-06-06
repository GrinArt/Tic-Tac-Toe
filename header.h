#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int selectOptions();
void mainPart();
void resetBoard();
char getWinner();
char singlePlayer();
bool checkerOfWin( char );
void printBoard();
int getMove();
int logic();
void quit();

void chooseFont( int size = 12 );
void chooseColor( char board[], int i );
void SetColor( int text, int background = 7);

#ifndef _COLOR_LIST_

  #define _COLOR_LIST_

  enum ConsoleColor
  {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
  };

#endif