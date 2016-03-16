#pragma once

#include <Point.h>
#include <map>

namespace SqRace {

typedef Point Direction;

namespace Dir {

const Direction Null = { 0, 0 };
const Direction E = { 1, 0 };
const Direction NE = { 1, -1 };
const Direction N = { 0, -1 };
const Direction NW = { -1, -1 };
const Direction W = { -1, 0 };
const Direction SW = { -1, 1 };
const Direction S = { 0, 1 };
const Direction SE = { 1, 1 };

inline wchar_t ToWchar( Direction dir )
{
	static std::map<Direction, wchar_t, boost::geometry::less<Direction> > conv = {
			{ Null, L'∎' },
			{ E,    L'→' },
			{ NE,   L'↗' },
			{ N,    L'↑' },
			{ NW,   L'↖' },
			{ W,    L'←' },
			{ SW,   L'↙' },
			{ S,    L'↓' },
			{ SE,   L'↘' }
	};
	return conv.at( dir );
}

inline bool IsOpposite( Direction d1, Direction d2 )
{
	boost::geometry::add_point( d1, d2 );
	return boost::geometry::distance( d1, Null ) == 0;
}

}

}
