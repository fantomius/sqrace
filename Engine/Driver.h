#pragma once

#include <Direction.h>
#include <Field.h>
#include <Car.h>
#include <PowerUp.h>

#define interface struct

namespace SqRace {

interface IDriver {
	virtual ~IDriver() {}

	virtual std::wstring Name() const = 0;
	virtual Direction MakeMove( const Field&, std::vector<CarPosition>&, std::vector<PowerUp>& ) = 0;

};

}
