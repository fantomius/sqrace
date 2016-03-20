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
	virtual Direction MakeMove( const Field&, const std::vector<CarPosition>&, const std::vector<PowerUp>& ) = 0;

};

}
