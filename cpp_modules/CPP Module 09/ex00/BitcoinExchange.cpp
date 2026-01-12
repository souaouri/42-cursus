#include "BitcoinExchange.hpp"

int isInt(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

int my_atoi(std::string str)
{
    if (str[0] == '0')
        str.erase(0,1);
    return atoi(str.c_str());
}

int parceDay(std::string day, std::string month, std::string year)
{
    int day_int = my_atoi(day);
    int month_int = my_atoi(month);
    int year_int = my_atoi(year);
    int range = max_day;

    
    if (day.size() == 3 && day[2] == ' ')
        day.erase(2, 3); 
    if (!isInt(day))
        return 0;
    if (month_int == April || month_int == June || month_int == September || month_int == November)
    {
        range = 30;
    }
    if (month_int == February)
    {
        range = 28;
        if (year_int % 4 == 0)
        {
            range = 29;
            if ((year_int % 100 == 0 && year_int % 400 != 0))
                range = 28;
        }
    }

    if (day_int > range || day_int < min_day)
        return 0;
    return 1;
}

int parceMonth(std::string month)
{
    int month_int = my_atoi(month);
    int range = max_month;
    if (!isInt(month))
        return 0;
    if (month_int > range || month_int < min_month)
        return 0;
    return 1;
}

int parceYear(std::string year)
{
    int year_int = my_atoi(year);
    int range = max_year;
    if (!isInt(year))
        return 0;
    if (year_int > range || year_int < min_year)
        return 0;
    return 1;
}

int     parceDate(std::string date, std::string line)
{
    std::string year;
    std::string month;
    std::string day;

    
    std::stringstream ss(date);
	if (date[date.size() - 1] == ' ')
		date.erase(date.size() - 1, 1);
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: bad input => " << line << std::endl;
        return 0;
	}
    if (!std::getline(ss, year, '-'))
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return 0;
    }
    if (!std::getline(ss, month, '-'))
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return 0;
    }
    if (!std::getline(ss, day, '-'))
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return 0;
    }
    if (!parceYear(year) || !parceMonth(month) || !parceDay(day, month, year))
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return 0;
    }
    return 1;
}


int parceValue(std::string value, std::string line)
{
    int countnum = 0;
    int isfloat = 0;
    if (value[1] == '-')
    {
        std::cout << "Error: not a positive number." << std::endl;
        return 0;
    }
    if (value[1] == '.' || value[value.size() - 1] == '.')
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return 0;
    }
    for(size_t i = 1; i < value.size(); i++)
    {
        if ((value[i] < '0' || value[i] > '9') && value[i] != '.')
        {
            std::cout << "Error: bad input => " << line << std::endl;
            return 0;
        }
        if (value[i] >= '0' || value[i] <= '9')
            countnum++;
        if(value[i] == '.')
            isfloat++;
    }
    if (!countnum || isfloat > 1)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return 0; 
    }
    double num = atof(value.c_str());
	if (num > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
        return 0;
	}
    if (!isfloat && (value.size() > 10 ||  num > INT_MAX))
    {
            std::cout << "Error: too large a number." << std::endl;
            return 0;
    }
    if (isfloat && num > FLT_MAX)
    {
            std::cout << "Error: too large a number." << std::endl;
            return 0;
    }
    return 1;
}

std::multimap<std::string, double>  getData()
{
    std::ifstream FILE("data.csv");
    if (!FILE.is_open())
        throw  CannotOpenFile();
    
    std::multimap<std::string, double> map;
    std::string line;
    while (std::getline(FILE, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;
        if (!std::getline(ss, date, ',')) continue;
        if (!std::getline(ss, valueStr, ',')) continue;
        double value = (double)atof(valueStr.c_str());
        map.insert(std::make_pair(date, value));
    }
    FILE.close();

    return map;
}

double theVale(std::map<int,double>::iterator begin, std::map<int,double>::iterator end, int mixDate)
{
    std::map<int,double>::iterator closestIt = end;
    unsigned int shortSpan = UINT_MAX;

    for (std::map<int,double>::iterator it = begin; it != end; ++it)
    {
        if (it->first == mixDate)
            return it->second;

        unsigned int diff = (it->first > mixDate) ? (it->first - mixDate) : (mixDate - it->first);

        if (diff < shortSpan && it->first <= mixDate)
        {
            shortSpan = diff;
            closestIt = it;
        }
    }

    return closestIt->second;
}


double getValue(std::multimap<std::string, double> map, std::string date)
{
    date.erase(4,1);
    date.erase(6,1);
    int mixDate = atoi(date.c_str());

    std::map<int, double> dateMap;

    for (std::multimap<std::string, double>::iterator it = map.begin(); it != map.end(); ++it)
    {
        if (it->first.size() == 10)
        {
            std::string d = it->first;
            d.erase(4,1);
            d.erase(6,1);
            int intDate = atoi(d.c_str());
            dateMap[intDate] = it->second;
        }
    }
    double Value = theVale(dateMap.begin(), dateMap.end(), mixDate);
    return Value;
}


void    parce_input(char *fileName)
{
    std::ifstream FILE(fileName);
    if (!FILE.is_open())
        throw  CannotOpenFile();
    
    std::string line;
    std::multimap<std::string, double> map = getData();
	std::getline(FILE, line);
	if (line != "date | value")
		throw Error();
    while (std::getline(FILE, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;
		if (line.empty())
			continue;
        if (!std::getline(ss, date, '|'))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!std::getline(ss, valueStr, '|'))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (valueStr == " ")
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!parceValue(valueStr, line))
            continue;
        if (!parceDate(date, line))
            continue;
		
        double val = (atof(valueStr.c_str()) * getValue(map, date));

		// std::cout << "-----> : " << atof(valueStr.c_str()) << "\n";
        std::cout << date << " => " << valueStr <<  " = " << std::setprecision(10) << val << std::endl;
    }
    FILE.close();
}

const char* CannotOpenFile::what() const throw()
{
    return "Error: cannot open file";
}

const char* Error::what() const throw()
{
    return "Error: date | value ?!";
}