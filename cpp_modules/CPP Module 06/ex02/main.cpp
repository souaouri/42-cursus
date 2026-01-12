#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base *ptr = generate();
	Base &ref = *ptr;

	identify(ptr);
	identify(ref);

	
	delete ptr;
}