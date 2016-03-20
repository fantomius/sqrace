//
// Created by fantomius on 14.03.16.
//

#include <FieldBuilder.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <assert.h>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace SqRace;

static Cell cellFromWChar( wchar_t sym )
{
	static_assert( static_cast<int>( Cell::Count ) == 2, "Invalid Cell count" );

	switch( sym ) {
		case L'#':
			return Cell::Wall;
		case L'.':
			return Cell::Road;
		default:
			assert( false );
	}
	return Cell::Count;
}

Field FieldBuilder::Construct( const std::string& file )
{
	wifstream stream( file );

	size_t width = 0;
	size_t height = 0;
	stream >> width >> height;

	wstring content = getContent( stream, file );
	assert( content.size() == width * height );

	Field field( width, height );
	transform( content.begin(), content.end(), back_inserter( field.cells ), cellFromWChar );
	return field;
}

std::wstring FieldBuilder::getContent( wifstream& stream, const std::string& file )
{
	wstring result;
	copy_if( istreambuf_iterator<wchar_t>( stream ), istreambuf_iterator<wchar_t>(), back_inserter( result ),
		boost::is_any_of<wchar_t*>( L"*#." ) );
	return result;
}
