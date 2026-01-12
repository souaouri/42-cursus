#include "iter.hpp"


int main()
{
	std::cout << "-------------- first test --------------\n\n";
	size_t len = 10;
	int array[] = {0,1,2,3,4,5,6,7,8,9};
	::iter(array, len, print);

	std::cout << "\n\n-------------- second test --------------\n\n";
	int len_2 = 16;
	char array_2[] = "test iter func !";
	::iter(array_2, len_2, toUpper);

	for (int i = 0; i < len_2; i++)
		std::cout << array_2[i];
	std::cout << std::endl;

	std::cout << "\n\n-------------- third test --------------\n\n";
	int len_3 = 16;
	const char array_3[] = "test iter func !";
	::iter(array_3, len_3, toUpper);
}