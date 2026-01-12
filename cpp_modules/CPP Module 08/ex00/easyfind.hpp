#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class NotFound : public std::exception
{
    public:
        virtual const char *what() const throw(); 
};

const char *NotFound::what() const throw()
{
    return "element not found";
}

template <typename T>

typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it;

    it = find(container.begin(), container.end(), n);
    
    if (it == container.end())
        throw NotFound();
    
    return it;    
}    

