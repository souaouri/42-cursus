
#pragma once

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

# define GREEN  "\033[1;32m";
# define RED  "\033[1;31m";
# define YELLOW  "\033[1;33m";
# define PURPLE  "\033[1;35m";
# define REST  "\033[0;m";

class PhoneBook{
    private:
        Contact book[8];
		int is_full;
    public:
		void	set_isfull(int i_f);
		int		get_isfull();
    	void	addcontact(std::string f_n, std::string l_n, std::string n_n, std::string ph_num, std::string d_s, int cout);
		void	print(std::string msg, std::string color);
		int		is_input_valide(std::string input);
		int		is_phonenum_valide(std::string input);
		void	contact_init(int count);
    	void	searchcontact(int count);
		int		convert_string_to_int(std::string input);
};
