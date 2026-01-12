#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span{
    private:
        std::vector<int> vec;
        unsigned int _size;
        unsigned int _element;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void    addNumber(int n);
        void    addNumber(unsigned int range, time_t time);
        unsigned int getSize();
        int    longestSpan();
        int    shortestSpan();

        class ArrayFullException : public std::exception
        {
            public:
                virtual const char *what() const throw(); 
        };

        class NoSpanCanBeFound : public std::exception
        {
            public:
                virtual const char *what() const throw(); 
        };

};