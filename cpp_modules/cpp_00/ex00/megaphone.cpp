#include <iostream>

void	mega(char **argv)
{
	std::string str;
	int i = 1;

	while (argv[i])
	{
		str = argv[i];
		for (size_t i = 0; i < str.length(); i++) {
			str[i] = std::toupper(str[i]);
		}
		std::cout << str;
		i++;
	}
	std::cout << std::endl;
}

int main (int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		mega(argv);
}