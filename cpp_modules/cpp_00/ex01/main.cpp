#include "PhoneBook.hpp"

int main ()
{
    PhoneBook obj;
    int count = 0;
	obj.set_isfull(0);
    while (true)
    {
        obj.print("ENTRE (ADD & SEARCH & EXIT) : ", "PURPLE");
        std::string line;
        getline(std::cin, line);
		if (std::cin.eof())
			exit(1);
		if (count >= 8)
		{
			obj.set_isfull(1);
			count = count % 8;
		}
        if (line == "ADD")
        {
            obj.contact_init(count);
            count ++;
        }
        else if (line == "SEARCH")
        {
            obj.searchcontact(count);
        }
        else if (line  == "EXIT")
            break ;
		else
		{
		 	obj.print("bad input !", "RED");
			std::cout << std::endl;
		}
    }
}