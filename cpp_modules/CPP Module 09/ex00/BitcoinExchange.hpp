#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <limits>
#include <cfloat>
#include <vector>
#include <cmath>


#define max_year 2024
#define min_year 2009
#define max_month 12
#define min_month 1
#define max_day 31
#define min_day 1


#define April 4
#define February 2
#define June 6
#define September 9
#define November 11


void    parce_input(char *file);
int     parceValue(std::string value, std::string line);
int     parceDate(std::string date, std::string line);


// exeption

class CannotOpenFile : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class Error : public std::exception
{
    public:
        virtual const char* what() const throw();
};