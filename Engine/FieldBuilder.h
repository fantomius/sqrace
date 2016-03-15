//
// Created by fantomius on 14.03.16.
//

#pragma once

#include <string>
#include <Field.h>

namespace SqRace {

class FieldBuilder {
public:
	static Field Construct( const std::string& file );

private:
	static std::wstring getContent( std::wifstream& stream, const std::string& file );
};

}