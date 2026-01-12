#pragma once

#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include <iomanip>
#include <deque>




class syntaxError : public std::exception{
	public :
		virtual const char *what() const throw();
};

class InvalidInput : public std::exception{
	public :
		virtual const char *what() const throw();
};

class numDuplicate : public std::exception{
	public :
		virtual const char *what() const throw();
};

void	Start(std::list<int> &list, std::deque<int> &deque);
void	containerInit(std::list<int> &list, std::deque<int> &deque, char* line);


/*

heads* arr[100];


soulaymane

key = 1000 % 100



arr[key].push(soulaymane);

search(soulaymane);

0 1

1 2,  


*/