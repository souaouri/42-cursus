#include "PhoneBook.hpp"

void	PhoneBook::print(std::string msg, std::string color)
{
	if (color == "GREEN")
	{
		std::cout << GREEN;
		std::cout << msg << REST;
	}
	if (color == "RED")
	{
		std::cout << RED;
		std::cout << msg << REST;
	}
	if (color == "YELLOW")
	{
		std::cout << YELLOW;
		std::cout << msg << REST;
	}
	if (color == "PURPLE")
	{
		std::cout << PURPLE;
		std::cout << msg << REST;
	}
}

int	PhoneBook::is_input_valide(std::string input)
{
	if (input.empty())
		return (1);
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!std::isprint(input[i]))
			return(1);
	}
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!std::isspace(input[i]))
			return(0);
	}
	return (1);
}

int	PhoneBook::is_phonenum_valide(std::string input)
{
	if (is_input_valide(input))
		return (1);
	for (size_t i = 0; i < input.size(); i++){
		if (!std::isdigit(input[i]))
			return (1);
	}
	return (0);
}

void    PhoneBook::contact_init(int count)
{
    std::string lines;
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
	while (true)
	{
		print("ENTER FIRST NAME : ", "YELLOW");
		getline(std::cin, first_name);
		if (std::cin.eof())
			exit(1);
		if (!is_input_valide(first_name))
			break ;
		print ("bad input", "RED");
		std::cout << std::endl;
	}
	while (true)
	{
		print("ENTER LAST NAME : ", "YELLOW");
		getline(std::cin, last_name);
		if (std::cin.eof())
			exit(1);
		if (!is_input_valide(last_name))
			break ;
		print ("bad input", "RED");
		std::cout << std::endl;
	}
	while (true)
	{
  		print("ENTER NICK NAME : ", "YELLOW");
		getline(std::cin, nick_name);
   		if (std::cin.eof())
			exit(1);
		if (!is_input_valide(nick_name))
			break ;
		print ("bad input", "RED");
		std::cout << std::endl;
	}
	while (true)
	{
		print("ENTER PHONE NUMBER : ", "YELLOW");
		getline(std::cin, phone_number);
		if (std::cin.eof())
			exit(1);
		if (!is_phonenum_valide(phone_number))
			break ;
		print ("bad input", "RED");
		std::cout << std::endl;
	}
	while (true)
	{
    	print("ENTER DARKEST SECRET : ", "YELLOW");
		getline(std::cin, darkest_secret);
    	if (std::cin.eof())
			exit(1);
		if (!is_input_valide(darkest_secret))
			break ;
		print ("bad input", "RED");
		std::cout << std::endl;
	}
    addcontact(first_name, last_name, nick_name, phone_number, darkest_secret, count);
}

void    PhoneBook::addcontact(std::string f_n, std::string l_n, std::string n_n, std::string ph_num, std::string d_s, int count)
{
    Contact obj;

    obj.set_index(count);
    obj.set_firtname(f_n);
    obj.set_lastname(l_n);
    obj.set_nickname(n_n);
    obj.set_phone_number(ph_num);
    obj.set_darkest_secret(d_s);
    book[count] = obj;
}

std::string	check_len(std::string input)
{
	if (input.size() > 10)
	{
		input = input.substr(0, 10);
		input[9] = '.';
	}
	return (input);
}

void PhoneBook::searchcontact(int count)
{
	std::string line;
	int	storge;

	count--;
	if (is_full == 1)
		count = 7;
	storge = count;
	print ("index     |first name| last name| nick name", "GREEN");
	std::cout << std::endl;
	print ("============================================", "RED");
	std::cout << std::endl;
	while (count >= 0)
	{
		std::cout <<  std::right << std::setw(10) << PhoneBook::book[count].get_index() <<"|";
		std::cout <<  std::right << std::setw(10) << check_len(PhoneBook::book[count].get_firstname()) <<"|";
		std::cout <<  std::right << std::setw(10) << check_len(PhoneBook::book[count].get_lastname()) <<"|";
		std::cout <<  std::right << std::setw(10) << check_len(PhoneBook::book[count].get_nickname()) <<"|";
		std::cout << std::endl;
		count--;
	}
	int i;
	i = convert_string_to_int(line);
	if (storge == -1)
		return ;
	while (true)
	{
		print ("choose a contact : ", "GREEN");
		getline(std::cin, line);
		if (std::cin.eof())
			exit (1);
		i = convert_string_to_int(line);// compare char to the input
		if (!is_input_valide(line) && (line[0] >= '0' && line[0] <= '7') && line.size() == 1 && i <= storge)
			break;
		print("bad input !", "RED");
		std::cout << std::endl;
	}
	std::cout << "first name     : " << book[i].get_firstname() << std::endl;
	std::cout << "last name      : " << book[i].get_lastname() << std::endl;
	std::cout << "nick name      : " << book[i].get_nickname() << std::endl;
	std::cout << "phone number   : " << book[i].get_phone_number() << std::endl;
	std::cout << "darkest secret : " << book[i].get_darkest_secret() << std::endl;
}

void	PhoneBook::set_isfull(int i_f)
{
	is_full = i_f;
}

int	PhoneBook::get_isfull(void)
{
	return (is_full);
}

int		PhoneBook::convert_string_to_int(std::string input)
{
	std::string arr = "01234567";
	int res = 0;
	if (input.size() != 1 || input[0] < '0' || input[0] > '7')
		return (-1);
	for (int i = 0; arr[i] != input[0]; i++)
		res = i + 1;
	return (res);
}