#include <ConsoleDriver.h>
#include <algorithm>

using namespace std;

namespace SqRace {

static Direction toDirection( wstring s )
{
	std::transform( s.begin(), s.end(), s.begin(), towupper );
	if( s == L"0" || s == L"NULL" ) {
		return Direction::Null;
	}
	if( s == L"E" ) {
		return Direction::E;
	}
	if( s == L"NE" ) {
		return Direction::NE;
	}
	if( s == L"N" ) {
		return Direction::N;
	}
	if( s == L"NW" ) {
		return Direction::NW;
	}
	if( s == L"W" ) {
		return Direction::W;
	}
	if( s == L"SW" ) {
		return Direction::SW;
	}
	if( s == L"S" ) {
		return Direction::S;
	}
	if( s == L"SE" ) {
		return Direction::SE;
	}

	return Direction::Null;
}

Direction ConsoleDriver::MakeMove(
		const Field& field,
		std::vector<CarPosition>& cars,
		std::vector<PowerUp>& powerUps )
{
	wcout << field << endl;
	wcout << L"¬ведите ваш ход: ";
	
	wstring command;
	wcin >> command;
	
	return toDirection( command );
}

} // namespace SqRace
