#include "MutantStack.hpp"

int main()
{
    std::cout << "\n\n-----------------------------------------------first test---------------------------------------------------------\n\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);


    std::cout << "\n\n-----------------------------------------------second test---------------------------------------------------------\n\n";
    MutantStack<std::string> mstack_string;
	mstack_string.push("one");
	mstack_string.push("two");
	mstack_string.pop();
	mstack_string.push("Three");
	mstack_string.push("four");

    MutantStack<std::string>::iterator it_string = mstack_string.begin();
    MutantStack<std::string>::iterator ite_string = mstack_string.end();

    while (it_string != ite_string)
    {
        std::cout << *it_string << std::endl;
        ++it_string;
    }

    return 0;
}