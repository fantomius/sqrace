//
// Created by fantomius on 14.03.16.
//

#ifndef SQRACE_FIELDBUILDER_H
#define SQRACE_FIELDBUILDER_H

#include <string>
#include <Field.h>

class FieldBuilder {
public:
	static Field Construct( const std::string& file );

private:
	static std::wstring getContent( std::wifstream& stream, const std::string& file );
};

#endif //SQRACE_FIELDBUILDER_H
