#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> vec;
        vec.push_back(0);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        vec.push_back(6);
        vec.push_back(7);
        vec.push_back(8);
        vec.push_back(9);
        vec.push_back(10);
        vec.push_back(11);
        vec.push_back(12);

        std::vector<int>::iterator it_vec = easyfind(vec, 11);

        //std::vector<int>::iterator it_vec = easyfind(vec, 111); exception !!!
        
        std::cout << "element found : " << *it_vec << std::endl;
    
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception : " << e.what() << std::endl;
    }
    
}