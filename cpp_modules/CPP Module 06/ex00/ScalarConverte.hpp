#pragma once

#include <iostream>
#include <limits>


# define MIN_INT std::numeric_limits<int>::min()
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()

enum    e_type
{
    SPECIAL = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
    INVALID = -1
};

class ScalarConverte{
	public :
		ScalarConverte();
		ScalarConverte(const ScalarConverte& other);
		ScalarConverte& operator=(const ScalarConverte& other);
		~ScalarConverte();

		static	void	convert(const std::string&);
};

e_type	whichType(const std::string&, size_t len);

void	printCHAR(const std::string& str, size_t len);
void	printINT(const std::string& str);
void	printFLOAT(const std::string& str);
void	printDOUBLE(const std::string& str);
void	printSPECIAL(const std::string& str);
void	printINVALID(const std::string& str);