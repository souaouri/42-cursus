
#pragma once

#include <string>
#include <iostream>

class Contact{
    private:
        int index;
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;
    public:
        void    set_index(int indx);
        void    set_firtname(std::string f_n);
        void    set_lastname(std::string l_n);
        void    set_nickname(std::string n_n);
        void    set_phone_number(std::string ph_num);
        void    set_darkest_secret(std::string d_s);
        int     get_index();
        std::string get_firstname();
        std::string get_lastname();
        std::string get_nickname();
        std::string get_phone_number();
        std::string get_darkest_secret();
};