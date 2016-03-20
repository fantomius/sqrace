//
// Created by fantomius on 14.03.16.
//

#pragma once

#include <vector>
#include <iosfwd>

namespace SqRace {

// Типы клеток поля
enum class Cell {
	Road,
	Wall,

	Count
};

// Поле
class Field {
public:
	// копирование по-умолчанию устраивает
	Field( const Field& ) = default;
	Field( Field&& ) = default;

	Cell Get( int x, int y ) const
	{
		return cells[getCellIndex( x, y )];
	}

	int XSize() const
	{
		return xSize;
	}

	int YSize() const
	{
		return ySize;
	}

private:
	std::vector<Cell> cells;
	int xSize;
	int ySize;

	// создаёт FieldBuilder
	Field( int _xSize, int _ySize ) : xSize( _xSize ), ySize( _ySize )
	{
	}

	int getCellIndex( int x, int y ) const
	{
		return y * xSize + x;
	}

	void setCell( int x, int y, Cell cell )
	{
		cells[getCellIndex( x, y )] = cell;
	}

	friend class FieldBuilder;
};

} // namespace SqRace

std::wostream& operator << ( std::wostream& os, const SqRace::Field& field );
