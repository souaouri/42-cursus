#pragma once

#include <iostream>
#include "Data.hpp"

class  Serialize{
	private:
		Serialize();
		Serialize(const  Serialize&);
		Serialize&	operator=(const  Serialize&);
		~Serialize();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};