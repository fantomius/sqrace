#include <ConsoleDriver.h>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

namespace SqRace {

const unordered_map<wstring, Direction> DirectionConvertor = {
		{ L"0", Dir::Null },
		{ L"5", Dir::Null },
		{ L"NULL", Dir::Null },
		{ L"E", Dir::E },
		{ L"6", Dir::E },
		{ L"NE", Dir::NE },
		{ L"9", Dir::NE },
		{ L"N", Dir::N },
		{ L"8", Dir::N },
		{ L"NW", Dir::NW },
		{ L"7", Dir::NW },
		{ L"W", Dir::W },
		{ L"4", Dir::W },
		{ L"SW", Dir::SW },
		{ L"1", Dir::SW },
		{ L"S", Dir::S },
		{ L"2", Dir::S },
		{ L"SE", Dir::SE },
		{ L"3", Dir::SE }
};

static Direction toDirection( wstring s )
{
	std::transform( s.begin(), s.end(), s.begin(), towupper );
	return DirectionConvertor.count( s ) > 0 ? DirectionConvertor.at( s ) : Dir::Null;
}

static int getStringPos( const Field& field, int x, int y ) {
	return y * ( field.XSize() + 1 ) + x;
}

static wstring dumpField( const Field& field, const std::vector<CarPosition>& cars, const std::vector<PowerUp>& powerups ) {
	wstringstream out;
	out << field;
	wstring result = out.str();
	for( size_t i = 0; i < cars.size(); i++ ) {
		assert( i < 10 );
		const auto& car = cars[i];
		size_t pos = getStringPos( field, car.Position.x(), car.Position.y() );
		if( 0 > pos || pos >= result.size() ) {
			continue;
		}
		result[pos] = to_wstring( i )[0];
	}

	return std::move( result );
}

Direction ConsoleDriver::MakeMove(
		const Field& field,
		const std::vector<CarPosition>& cars,
		const std::vector<PowerUp>& powerUps )
{
	wcout << dumpField( field, cars, powerUps ) << endl;
	wcout << L"Введите ваш ход: ";
	
	wstring command;
	wcin >> command;
	
	return toDirection( command );
}

} // namespace SqRace
