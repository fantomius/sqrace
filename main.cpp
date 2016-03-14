#include <iostream>
#include <Field.h>
#include <FieldBuilder.h>

using namespace std;

int main()
{
	Field fld = FieldBuilder::Construct( "../Resource/map.txt" );
	wcout << fld;
	return 0;
}