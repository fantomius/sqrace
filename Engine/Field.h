//
// Created by fantomius on 14.03.16.
//

#ifndef SQRACE_MAP_H
#define SQRACE_MAP_H

#include <vector>
#include <iosfwd>

// Типы клеток поля
enum class Cell {
	Road,
	Wall,

	Count
};

// Поле
class Field {
public:
	Cell Get( int x, int y ) const { return cells[ getCellIndex ( x, y ) ]; }

	int XSize() const { return xSize; }

	int YSize() const { return ySize; }

private:
	std::vector<Cell> cells;
	int xSize;
	int ySize;

	Field( int _xSize, int _ySize ) : xSize ( _xSize ), ySize ( _ySize ) { }

	int getCellIndex( int x, int y ) const { return y * xSize + x; }

	void setCell( int x, int y, Cell cell ) { cells[ getCellIndex ( x, y ) ] = cell; }

	friend class FieldBuilder;
};

std::wostream& operator << ( std::wostream& os, const Field& field );

#endif //SQRACE_MAP_H
