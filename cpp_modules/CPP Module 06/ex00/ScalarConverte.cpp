#include "ScalarConverte.hpp"

ScalarConverte::ScalarConverte()
{

}

ScalarConverte::ScalarConverte(const ScalarConverte& other)
{
	*this = other;
}

ScalarConverte& ScalarConverte::operator=(const ScalarConverte& other)
{
	(void)other;
	return *this;
}

ScalarConverte::~ScalarConverte()
{

}


void	ScalarConverte::convert(const std::string& str)
{
	size_t len = str.length();
	e_type Type = whichType(str, len);

	switch (Type) {
		case CHAR:
			printCHAR(str, len);
			break;
		case INT:
			printINT(str);
			break;
		case FLOAT:
			printFLOAT(str);
			break;
		case DOUBLE:
			printDOUBLE(str);
			break;
		case SPECIAL:
			printSPECIAL(str);
			break;
		case INVALID:
			printINVALID(str);
			break;
	}
}
