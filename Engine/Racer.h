#pragma once

#include <Driver.h>
#include <Car.h>

namespace SqRace {

class Racer {
public:
//private:
	std::shared_ptr<IDriver> driver;
	CarPosition carPos;
};

}