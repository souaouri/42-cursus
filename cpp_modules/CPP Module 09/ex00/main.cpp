#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	try{

		if (argc == 2)
		{
			parce_input(argv[1]);
		}
		else
			std::cout << "bad input !!" << std::endl;
	}
	catch (std::exception& e){
		std::cerr << "exception : " << e.what() << std::endl;
	}
}