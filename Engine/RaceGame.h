#pragma once

#include <Field.h>
#include <Racer.h>
#include <functional>

namespace SqRace {

class RaceGame {
public:
	RaceGame( std::string& fieldPath );

	void AddDriver( std::shared_ptr<IDriver> driver );
	void Start();
	const IDriver& GetWinner() const;

private:
	Field field;
	std::vector<Racer> racers;
	const IDriver* winner;
};

}
