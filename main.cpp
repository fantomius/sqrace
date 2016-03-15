#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

#include <RaceGame.h>
#include <ConsoleDriver.h>

using namespace std;
using namespace SqRace;

void setUnicodeConsole()
{
	_setmode( _fileno( stdout ), _O_U16TEXT );
}

int main()
{
	setUnicodeConsole();

	RaceGame game( string( "../Resource/map.txt" ) );
	auto driver = make_shared<ConsoleDriver>( L"TestPlayer" );

	game.AddDriver( driver );

	game.Start();

	wcout << L"Победитель: " << game.GetWinner().Name() << endl;

	return 0;
}
