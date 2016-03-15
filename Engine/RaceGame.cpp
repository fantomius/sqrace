#include <RaceGame.h>
#include <FieldBuilder.h>
#include <GameLoop.h>

namespace SqRace {

RaceGame::RaceGame( std::string & fieldPath ) :
	field( FieldBuilder::Construct( fieldPath ) ),
	winner( 0 )
{
}

void RaceGame::AddDriver( std::shared_ptr<IDriver> driver )
{
	Racer racer;
	racer.driver = driver;
	racer.carPos = CarPosition();
	racers.emplace_back( std::move( racer ) );
}

void RaceGame::Start()
{
	GameLoop loop( field, racers );

	while( !loop.IsOver() ) {
		loop.NextMove();
	}
	winner = loop.Winner().driver.get();
}

const IDriver& RaceGame::GetWinner() const
{
	assert( winner != 0 );
	return *winner;
}

}