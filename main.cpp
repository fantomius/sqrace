#include <iostream>
#include <RaceGame.h>
#include <ConsoleDriver.h>

using namespace std;
using namespace SqRace;

int main()
{
	std::locale current_locale("");
	std::locale::global(current_locale);

	RaceGame game( std::string( "../Resource/map.txt" ) );
	auto driver = make_shared<ConsoleDriver>( L"TestPlayer" );

	game.AddDriver( driver );

	game.Start();

	wcout << L"Победитель: " << game.GetWinner().Name() << endl;

	return 0;
}
