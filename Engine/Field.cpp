//
// Created by fantomius on 14.03.16.
//

#include <Field.h>
#include <iostream>
#include <assert.h>

using namespace std;

wchar_t wCharByCell( Cell cell )
{
	static_assert( static_cast<int>( Cell::Count ) == 2, "Invalid Cell count" );

	switch( cell ) {
		case Cell::Road:
			return L'.';
		case Cell::Wall:
			return L'#';
		default:
			assert( false );
	}
}

std::wostream& operator<<( std::wostream& os, const Field& field )
{
	for( int y = 0; y < field.YSize(); y++ ) {
		for( int x = 0; x < field.XSize(); x++ ) {
			os << wCharByCell( field.Get( x, y ));
		}
		os << L'\n';
	}
	return os;
}
