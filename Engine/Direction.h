#pragma once

#include <Point.h>

namespace SqRace {

enum class Direction {
	Null = 0,
	E,
	NE,
	N,
	NW,
	W,
	SW,
	S,
	SE
};

namespace Dir {

inline wchar_t ToWchar( Direction dir )
{
	static wchar_t* conversion = L"∎→↗↑↖←↙↓↘";
	return conversion[static_cast<size_t>( dir )];
}

inline bool IsOpposite( Direction d1, Direction d2 )
{
	int val1 = static_cast<int>( d1 );
	int val2 = static_cast<int>( d2 );
	
	return val1 != 0
		&& val2 != 0
		&& abs( val2 - val1 ) == 4;
}

inline Point ToPoint( Direction dir )
{
	static Point conversion[9] = {
		{ 0, 0 },
		{ 1, 0 },
		{ 1, -1 },
		{ 0, -1 },
		{ -1, -1 },
		{ -1, 0 },
		{ -1, 1 },
		{ 0, 1 },
		{ 1, 1 }
	};
	return conversion[static_cast<size_t>( dir )];
}

}

}
