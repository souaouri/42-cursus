#include "PhoneBook.hpp"

void    Contact::set_index(int indx)
{
    index = indx;
}

void    Contact::set_firtname(std::string f_n)
{
    first_name = f_n;
}

void    Contact::set_lastname(std::string l_n)
{
    last_name = l_n;
}

void    Contact::set_nickname(std::string n_n)
{
    nick_name = n_n;
}

void    Contact::set_phone_number(std::string ph_num)
{
    phone_number = ph_num;
}

void    Contact::set_darkest_secret(std::string d_s)
{
    darkest_secret = d_s;
}

int Contact::get_index(void)
{
    return (index);
}

 std::string Contact::get_firstname(void)
{
    return (first_name);
}

std::string Contact::get_lastname(void)
{
    return (last_name);
}

std::string Contact::get_nickname(void)
{
    return (nick_name);
}

std::string Contact::get_phone_number(void)
{
    return (phone_number);
}

std::string Contact::get_darkest_secret(void)
{
    return (darkest_secret);
}
