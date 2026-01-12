#include "Span.hpp"

Span::Span() : _size(0), _element(0)
{

}

Span::Span(unsigned int N) : _size(N), _element(0)
{
    vec.reserve(N);
}

Span::Span(const Span& other) : _size(other._size), _element(other._element)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _element = other._element;
        _size = other._size;
        vec = other.vec;
    }
    return *this;
}

Span::~Span()
{

}


void    Span::addNumber(int n)
{
    if (_element + 1 > _size)
        throw Span::ArrayFullException();
    _element++;
    vec.push_back(n);
}

void    Span::addNumber(unsigned int range, time_t time)
{
    srand(time);

    for (unsigned int i = 0; i < range; i++)
    {
        try{
            addNumber(std::rand());
        }
        catch(const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

int    Span::longestSpan()
{
    if (_element <= 1 || vec.size() == 1)
        throw Span::NoSpanCanBeFound();
    int maxVal = *std::max_element(vec.begin(), vec.end());
    int minVal = *std::min_element(vec.begin(), vec.end());
    return maxVal - minVal;
}

int    Span::shortestSpan()
{
    if (_element <= 1 || vec.size() == 1)
        throw Span::NoSpanCanBeFound();
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    std::vector<int>::iterator it = vec.begin();
    std::vector<int>::iterator it_next = vec.begin() + 1;
    unsigned int shortSpan = UINT_MAX;
    while (it_next != vec.end())
    {
        if(static_cast<unsigned int>(*it - *it_next) < shortSpan)
            shortSpan = (*it - *it_next);
        it++;
        it_next++;
    }
    return shortSpan;
}

const char *Span::ArrayFullException::what() const throw()
{
    return "array is full";
}

const char *Span::NoSpanCanBeFound::what() const throw()
{
    return "no span Can be found";
}