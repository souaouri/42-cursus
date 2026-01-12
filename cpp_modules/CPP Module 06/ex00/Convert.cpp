#include "ScalarConverte.hpp"

void	printCHAR(const std::string& str, size_t len)
{
	char c = 0;

	if (len == 1)
		c = str[0];
	else
		c = str[1];
	
	std::cout  << "char: ";
	if (!isprint(c))
		std::cout  << "Non displayable" << std::endl;
	else
		std::cout  << "'" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printINT(const std::string& str)
{
	long l = atol(str.c_str());
	std::cout  << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(l))
		std::cout  << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(l) << "'" << std::endl;

	std::cout << "int: ";
	if (l < INT_MIN || l > INT_MAX)
		std::cout  << "Non displayable" << std::endl;
	else
	 	std::cout << l << std::endl;

	std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
}

void	printFLOAT(const std::string& str)
{
	float l = atof(str.c_str());
	std::cout  << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(l))
		std::cout  << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(l) << "'" << std::endl;

	std::cout << "int: ";
	if (l < INT_MIN || l > INT_MAX)
		std::cout  << "Non displayable" << std::endl;
	else
	 	std::cout << static_cast<int>(l) << std::endl;
	std::cout << "float: ";
	long t = atof(str.c_str());
	if (l < MIN_FLOAT || l > MAX_FLOAT)
		std::cout  << "Non displayable" << std::endl;
	else
	{
		if (str.find('.') != std::string::npos && l != t)
			std::cout << l << "f" << std::endl;
		else
			std::cout << l << ".0f" << std::endl;
	}
	
	std::cout << "double: ";
	if (l < MIN_DOUBLE || l > MAX_DOUBLE)
		std::cout  << "Non displayable" << std::endl;
	else
	{
		if (l != t)
			std::cout << static_cast<double>(l) << std::endl;
		else
		 	std::cout << static_cast<double>(l) << ".0" << std::endl;
	}
}

void	printDOUBLE(const std::string& str)
{
	double l = atof(str.c_str());
	std::cout  << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(l))
		std::cout  << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(l) << "'" << std::endl;

	std::cout << "int: ";
	if (l < INT_MIN || l > INT_MAX)
		std::cout  << "Non displayable" << std::endl;
	else
	 	std::cout << static_cast<int>(l) << std::endl;
	
	std::cout << "float: ";
	long t = atof(str.c_str());
	if (l < MIN_FLOAT || l > MAX_FLOAT)
		std::cout  << "Non displayable" << std::endl;
	else
	{
		if (str.find('.') != std::string::npos && l != t)
			std::cout << static_cast<float>(l) << "f" << std::endl;
		else
			std::cout << static_cast<float>(l) << ".0f" << std::endl;
	}
	std::cout << "double: ";
	if (l < MIN_DOUBLE || l > MAX_DOUBLE)
		std::cout  << "Non displayable" << std::endl;
	else
	{
		if (l != t)
			std::cout << l << std::endl;
		else
		 	std::cout << l << ".0" << std::endl;
	}

}

void	printSPECIAL(const std::string& str)
{
	if(str == "nan" || str == "nanf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" <<std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
	else if(str == "+inf" || str == "+inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "+inff" <<std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
	else if(str == "-inf" || str == "-inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "-inff" <<std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
}

void	printINVALID(const std::string& str)
{
	(void)str;
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "impossible" <<std::endl;
		std::cout << "double: " << "impossible" << std::endl;
}

