#include "Span.hpp"

int main()
{
    try
    {
        std::cout << "-------------------first test---------------------\n";
        
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "sp shortestSpan :" << sp.shortestSpan() << std::endl;
        std::cout << "sp longestSpan  :" << sp.longestSpan() << std::endl;


        std::cout << "-------------------second test---------------------\n";

        unsigned int range = 11111;
        Span sp_2(range);

        sp_2.addNumber(range, time(NULL));

        std::cout << "sp_2 shortestSpan :" << sp_2.shortestSpan() << std::endl;
        std::cout << "sp_2 longestSpan  :" << sp_2.longestSpan() << std::endl;

        return 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "exeption : " << e.what() << '\n';
    }
}