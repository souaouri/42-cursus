#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>

class OperatoeNeedTwoNum : public std::exception{
	public :
		virtual const char *what() const throw();
};

class BadInput : public std::exception{
	public :
		virtual const char *what() const throw();
};

class NumMoreThenOperators : public std::exception{
	public :
		virtual const char *what() const throw();
};

int	isoperator(char c);
void calculate(std::stack<float> *stack, char op);