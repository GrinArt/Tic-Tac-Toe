#include "header.h"

int main()
{
  chooseFont( 24 );
  SetColor( Black, LightGray );
  system( "mode 44, 22" );

  void ( *menu[2] )() = { mainPart, quit };
  
  while( true ) ( *menu[ selectOptions() ] )();

  

	return 0;
}