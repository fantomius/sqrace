#pragma once

#include <Driver.h>
#include <string>

namespace SqRace {

class ConsoleDriver : public IDriver {
public:
	ConsoleDriver( const std::wstring& _name ) : name( _name ) {}

	virtual std::wstring Name() const override { return name; }
	virtual Direction MakeMove( const Field&, const std::vector<CarPosition>&, const std::vector<PowerUp>& ) override;

private:
	std::wstring name;
};

} // namespace SqRace
