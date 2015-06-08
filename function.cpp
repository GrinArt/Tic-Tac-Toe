#include "header.h"

char board[9];

int selectOptions()
{
  int select = 0;

  system("cls");

  cout << "\n\n\t[1] Game" << endl;
  cout << "\n\t[2] Exit\n\t ";

  while (select < '1' || select > '2') select = _getch();

  select -= 49;

  return select;
}

void resetBoard()
{
  for (int i = 0; i < 9; i++) board[i] = '1' + i;
}

bool checkerOfWin( char player )
{
  int wins[8][3] = {
    { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 },
    { 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 },
    { 0, 4, 8 }, { 2, 4, 6 }
  };

  for ( int i = 0; i < 8; i++ )
  {
    int count = 0;

    for ( int j = 0; j < 3; j++ ) if ( board[wins[i][j]] == player ) count++;

    if (count == 3) return true;
  }

  return false;
}

void SetColor(int text, int background)
{
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void chooseColor( char board[], int i )
{
  board[i] == 'X' ? SetColor( Red ) : board[i] == 'O' ? SetColor( Blue ) : board[i] >= 49 || board[i] <= 57 ? SetColor( White ) : SetColor( Black );
  cout << board[i];
  SetColor( Black );
}
void printBoard()
{
  cout << "\n\n\t\t ";
  chooseColor( board, 0 );
  cout << " | ";
  chooseColor( board, 1 );
  cout << " | ";
  chooseColor( board, 2 );
  cout << endl;
  cout << "\t\t" << "---|---|---" << endl;
  cout << "\t\t ";
  chooseColor( board, 3 );
  cout << " | ";
  chooseColor( board, 4 );
  cout << " | ";
  chooseColor( board, 5 );
  cout << endl;
  cout << "\t\t" << "---|---|---" << endl;
  cout << "\t\t ";
  chooseColor( board, 6 );
  cout << " | ";
  chooseColor( board, 7 );
  cout << " | ";
  chooseColor( board, 8 );
  cout << endl;
}

int getMove()
{
  cout << "\n\n";
  printBoard();
  cout << "\n\n\t\tYour move: ";

  int move = _getch();
  move -= 49;

  if ( move < 0 || move > 8 || (board[move] > '9' || board[move] < '1') )
  {
    cout << "Error!" << endl;
    cout << "\n\tTap number (1 - 9) for move: ";
    while ( move < 0 || move > 8 || (board[move] > '9' || board[move] < '1') )
    {
      move = _getch();
      if ( move == 27 ) exit(0);
      move -= 49;
    }
  }

  return move;
}
char getWinner()
{
  system("cls");
  
  cout << "\n\n\tSelect game mod:" << endl;
  cout << "\n\t[1] Single Player" << endl;
  cout << "\n\t[2] Multiplayer\n\t  ";
  
  int select = _getch();
  while ( select != '1' && select != '2' ) select = _getch();
  
  if ( select == '1' ) singlePlayer();
  
  else
  {
    int turn = 1;
    int move;

    while ( !checkerOfWin('X') && !checkerOfWin('O') )
    {
      system("cls");

      if (turn % 2 != 0)
      {
        move = getMove();
        board[move] = 'X';
        
        if ( checkerOfWin('X') )
        {
          system("cls");
          cout << "\n  Congratulations player X! You have won!\n";
          return 'X';
        }
      }
      else
      {
        move = getMove();
        board[move] = 'O';
        
        if ( checkerOfWin('O') )
        {
          system("cls");
          cout << "\n  Congratulations player O! You have won!\n";
          return 'O';
        }
      }
      if (turn == 9)
      {
        system("cls");
        cout << "\n\tIt's a draw!\n";
        return 'D';
      }
      turn++;
    }
  }
}

char singlePlayer()
{
  system("cls");
  
  cout << "\n\n\tWho whill start the game:" << endl;
  cout << "\n\t[1] You" << endl;
  cout << "\n\t[2] Computer\n\t ";
  
  int turn = _getch();
  while ( turn != '1' && turn != '2' ) turn = _getch();
  
  turn -= 49;
  int turnTmp = turn;
  
  int move;
  
  while ( !checkerOfWin('X') && !checkerOfWin('O') )
  {
    system("cls");

    if ( turn % 2 == 0 )
    {
      move = getMove();
      board[move] = 'X';
      if ( checkerOfWin('X') )
      {
        system("cls");
        cout << "\n  Congratulations player X! You have won!\n";
        return 'X';
      }
    }
    else
    {      
      board[ logic() ] = 'O';
      
      if ( checkerOfWin('O') )
      {
        system("cls");
        cout << "\n  Congratulations player O! You have won!\n";
        return 'O';
      }
    }
    if ( (turnTmp == 0 && turn == 8) || (turnTmp == 1 && turn == 9) )
    {
      system("cls");
      cout << "\n\tIt's a draw!\n";
      return 'D';
    }
    turn++;
  }
}
int logic()
{
  int move;

  if (board[2] == 'O' && board[8] == 'O' && board[5] != 'X' && board[5] != 'O') move = 5;
  else if (board[0] == 'O' && board[1] == 'O' && board[2] != 'X' && board[2] != 'O') move = 2;
  else if (board[0] == 'O' && board[2] == 'O' && board[1] != 'X' && board[1] != 'O') move = 1;
  else if (board[0] == 'O' && board[3] == 'O' && board[6] != 'X' && board[6] != 'O') move = 6;
  else if (board[0] == 'O' && board[6] == 'O' && board[3] != 'X' && board[3] != 'O') move = 3;
  else if (board[1] == 'O' && board[4] == 'O' && board[7] != 'X' && board[7] != 'O') move = 7;
  else if (board[7] == 'O' && board[4] == 'O' && board[1] != 'X' && board[1] != 'O') move = 1;

  else
  {
    for (int i = 0, j = 8; i < 9; i++)
    {
      if (i == 4) i++; if (j == 4) j--;
      if (board[4] == 'O' && board[j] == 'O' && board[i] != 'X' && board[i] != 'O') return move = i;
      j--;
    }
  }

  if ( board[0] == 'X' && board[8] == 'X' && board[3] != 'X' && board[3] != 'O' ) move = 3;
  else if ( board[5] == 'X' && board[8] == 'X' && board[2] != 'X' && board[2] != 'O' ) move = 2;
  else if ( board[2] == 'X' && board[8] == 'X' && board[5] != 'X' && board[5] != 'O' ) move = 5;

  else if ( board[6] == 'X' && board[8] == 'X' && board[7] != 'X' && board[7] != 'O' ) move = 7;
  else if ( board[0] == 'X' && board[8] == 'X' && board[5] != 'X' && board[5] != 'O' ) move = 5;
  else if ( board[0] == 'X' && board[8] == 'X' && board[3] != 'X' && board[3] != 'O' ) move = 3;
  else if ( board[2] == 'X' && board[6] == 'X' && board[3] != 'X' && board[3] != 'O' ) move = 3;
  else if ( board[3] == 'X' && board[6] == 'X' && board[0] != 'X' && board[0] != 'O' ) move = 0;
  else if ( board[3] == 'X' && board[6] == 'X' && board[7] != 'X' && board[7] != 'O' ) move = 7;
  else if ( board[3] == 'X' && board[6] == 'X' && board[1] != 'X' && board[1] != 'O' ) move = 1;
  else if ( board[0] == 'X' && board[2] == 'X' && board[1] != 'X' && board[1] != 'O' ) move = 1;
  else if ( board[5] == 'X' && board[7] == 'X' && board[8] != 'X' && board[8] != 'O' ) move = 8;
  else if ( board[2] == 'X' && board[8] == 'X' && board[5] != 'X' && board[5] != 'O' ) move = 5;
  else if ( board[0] == 'X' && board[3] == 'X' && board[6] != 'X' && board[6] != 'O' ) move = 6;
  else if ( board[7] == 'X' && board[8] == 'X' && board[6] != 'X' && board[6] != 'O' ) move = 6;
  else if ( board[6] == 'X' && board[7] == 'X' && board[8] != 'X' && board[8] != 'O' ) move = 8;
  else if ( board[2] == 'X' && board[5] == 'X' && board[8] != 'X' && board[8] != 'O' ) move = 8;
  else if ( board[0] == 'X' && board[1] == 'X' && board[2] != 'X' && board[2] != 'O' ) move = 2;
  else if ( board[0] == 'X' && board[2] == 'X' && board[1] != 'X' && board[1] != 'O' ) move = 1;
  else if ( board[8] == 'X' && board[5] == 'X' && board[1] != 'X' && board[1] != 'O' ) move = 1;
  else if ( board[0] == 'X' && board[6] == 'X' && board[3] != 'X' && board[3] != 'O' ) move = 3;
  else if ( board[8] == 'X' && board[5] == 'X' && board[2] != 'X' && board[2] != 'O' ) move = 2;
  else if ( board[8] == 'X' && board[2] == 'X' && board[5] != 'X' && board[5] != 'O' ) move = 5;
  else if ( board[8] == 'X' && board[6] == 'X' && board[7] != 'X' && board[7] != 'O' ) move = 6;

  else
  {
    for (int i = 0, j = 8; i < 9; i++)
    {
      if (i == 4) i++; if (j == 4) j--;
      if (board[4] == 'X' && board[j] == 'X' && board[i] != 'X' && board[i] != 'O') return move = i;
      j--;
    }
  }
  if (board[4] != 'X' && board[4] != 'O') move = 4;
  else if (board[0] != 'X' && board[0] != 'O') move = 0;
  else if (board[2] != 'X' && board[2] != 'O') move = 2;
  else if (board[6] != 'X' && board[6] != 'O') move = 6;
  else if (board[8] != 'X' && board[8] != 'O') move = 8;
  else for (int i = 1; i < 8; i += 2) if (board[i] != 'X' && board[i] != 'O') move = i;
  
  return move;
}

void mainPart()
{
  SetColor( Black );

  char reply;
  int x_wins = 0,
      o_wins = 0,
      draws = 0;

  do
  {
    resetBoard();

    switch ( getWinner() )
    {
    case 'X':
      x_wins++;
      break;
    case 'O':
      o_wins++;
      break;
    default:
      draws++;
    }

    printBoard();

    cout << "\n\tPlayer X: " << x_wins << endl;
    cout << "\tPlayer O: " << o_wins << endl;
    cout << "\tDraws: " << draws << "\n\n";
    cout << "\n  Would you like to play again? ( Y/n ): ";

    reply = _getch();

    while ( reply != 'y' && reply != 'n' && reply != 'Y' && reply != 'N'  && reply != 13 && reply != 27 )
    {
      reply = _getch();
    }
  } while ( reply == 'y' || reply == 'Y' || reply == 13 );
}

void quit()
{
  exit(0);
}

void chooseFont( int size )
{
  HANDLE hCon = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
  if (hCon != INVALID_HANDLE_VALUE)
  {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = size;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = 400;
    wcscpy_s(cfi.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(hCon, FALSE, &cfi);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
  }
}