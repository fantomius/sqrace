#pragma once

#include <Driver.h>
#include <string>

namespace SqRace {

class ConsoleDriver : public IDriver {
public:
	ConsoleDriver( const std::wstring& _name ) : name( _name ) {}

	virtual std::wstring Name() const { return name; }
	virtual Direction MakeMove( const Field&, std::vector<CarPosition>&, std::vector<PowerUp>& );

private:
	std::wstring name;
};

} // namespace SqRace
