#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
	try{
		if (argc >= 2)
		{
			std::list<int> list;
			std::deque<int> deque;
			for (int i = 1; i < argc; i++)
			{
				containerInit(list, deque, argv[i]);
			}
			Start(list, deque);
		}
		else
			std::cerr << "bad input !!" << std::endl;
	}
	catch(std::exception& e){
		std::cerr << "exception : " << e.what() << std::endl;
	}
}