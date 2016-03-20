#include <iostream>
#include <RaceGame.h>
#include <ConsoleDriver.h>

#ifdef WINDOWS

#include <Windows.h>
#include <io.h>
#include <fcntl.h>

void setupUnicodeConsole()
{
	_setmode( _fileno( stdout ), _O_U16TEXT );
}

#else

void setupUnicodeConsole()
{
	try {
		std::locale::global( std::locale( "en_US.UTF-8" ) );
	} catch( std::exception e ) {
		std::cout << e.what();
	}
}

#endif

using namespace std;
using namespace SqRace;

int main()
{
	setupUnicodeConsole();
	RaceGame game( std::string( "../Resource/map.txt" ) );
	auto driver = make_shared<ConsoleDriver>( L"TestPlayer" );

	game.AddDriver( driver );
	game.Start();

	wcout << L"Победитель: " << game.GetWinner().Name() << endl;

	return 0;
}
