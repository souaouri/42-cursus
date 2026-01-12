#include "RPN.hpp"

int main(int argc, char **argv)
{
	try{
		if (argc == 2)
		{
			std::stringstream ss(argv[1]);
			std::stack<float> stack;
			std::string line;
			float num;
			int opNum = 0;
			int digNum = 0;
			while (1)
			{
				if (!std::getline(ss, line, ' '))
					break;
				if (!line.empty())
				{
					if (line.size() != 1)
						throw BadInput();
					if (isdigit(line[0]))
					{
						num = std::atoi(line.c_str());
						stack.push(num);
						digNum++;
					}
					else if (isoperator(line[0]))
					{
						calculate(&stack, line[0]);
						opNum++;
					}
					else
						throw BadInput();
				}
			}
			if ((digNum != (opNum + 1)) || opNum == 0)
				throw NumMoreThenOperators();
			std::cout << stack.top() << std::endl;
		}
		else
			std::cerr << "bad input !!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "exception : " << e.what() << std::endl;
	}
}