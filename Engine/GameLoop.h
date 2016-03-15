#pragma once

#include <vector>

namespace SqRace {

class Field;
class Racer;

class GameLoop {
public:
	GameLoop( const Field& f, std::vector<Racer>& rs ) :
		field( f ),
		racers( rs ),
		winner( 0 ),
		isOver( false )
	{}

	bool IsOver() const { return isOver; }
	const Racer& Winner() const;

	void NextMove();

private:
	const Field& field;
	std::vector<Racer>& racers;
	const Racer* winner;
	bool isOver;
};

}
