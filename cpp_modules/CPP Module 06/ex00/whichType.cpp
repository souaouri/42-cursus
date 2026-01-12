#include "ScalarConverte.hpp"

int	isSpecial(const std::string& str)
{
	if (str == "-inf" || str == "+inf" || str == "nan" || str == "-inff" || str == "+inff" || str == "nanf")
		return 1;
	return 0;
}

int isChar(const std::string& str, size_t len)
{
	if (len == 1 && !isdigit(str[0]))
		return 1;
	if (len == 3 && str[0] == '\'' && str[3] == '\'')
		return 1;
	return 0;
}

int isInt(const std::string& str, size_t len)
{
	int i = 0;
	bool flag = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		flag = 1;
	}
	while ((str[i] && flag && len > 0 && len < 12) || (str[i] && !flag && len > 0 && len < 11))
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

int isFloat(const std::string& str, size_t len, size_t dot, size_t f)
{
	size_t i = 0;

	while (i < dot)
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
	}
	i = dot + 1;
	if (f != len - 1)
		return 0;
	while (i < len - 1)
	{ 
		if (!isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

int isDouble(const std::string& str, size_t len)
{
	int i = 0;

	if (str[0] == '.' || str[len - 1] == '.')
		return 0;
	while (str[i])
	{
		if (!isdigit(str[i]) && str[i] != '.')
			return 0;
		i++;
	}
	return 1;
}

e_type	whichType(const std::string& str, size_t len)
{
	size_t dot = str.find('.');
	size_t f = str.find('f');

	if (dot == std::string::npos)
	{
		if (isSpecial(str))
			return SPECIAL;
		if (isChar(str, len))
			return CHAR;
		if (isInt(str, len))
			return INT;
	}
	if (dot != std::string::npos && f != std::string::npos)
	{
		if (isFloat(str, len, dot, f))
			return FLOAT;
	}
	if (dot != std::string::npos && f ==  std::string::npos)
	{
		if (isDouble(str, len))
			return DOUBLE;
	}
	return INVALID;
}