#include <GameLoop.h>
#include <assert.h>
#include <algorithm>
#include <Racer.h>
#include <PowerUp.h>

namespace SqRace {

const Racer& GameLoop::Winner() const
{
	assert( isOver );
	return *winner;
}

void GameLoop::NextMove()
{
	std::vector<PowerUp> powerups;
	std::vector<CarPosition> cars( racers.size() );
	std::transform( racers.begin(), racers.end(), cars.begin(),
		[]( const Racer& r ) { return r.carPos; } );
	
	std::vector<Direction> moves( racers.size() );
	std::transform( racers.begin(), racers.end(), moves.begin(),
		[this, &cars, &powerups]( const Racer& r ) { return r.driver->MakeMove( field, cars, powerups ); } );
}

}
