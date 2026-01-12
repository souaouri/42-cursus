#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> a;
        std::cout << "a.size() = " << a.size() << std::endl;

        Array<int>  b(5);
        std::cout << "b.size() = " << b.size() << std::endl;

		
        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = (i + 1) * 10;

		// std::cout << b[10] << std::endl; excrption

        std::cout << "b elements: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        const Array<int> c(b);
        std::cout << "c (copied from b): ";
        for (unsigned int i = 0; i < c.size(); i++)
            std::cout << c[i] << " ";
        std::cout << std::endl;

		Array<int> d;
        d = b;
        std::cout << "d (assigned from b): ";
        for (unsigned int i = 0; i < d.size(); i++)
            std::cout << d[i] << " ";
        std::cout << std::endl;
	}
	catch (const std::exception &e) {
        std::cout << "Exception : " << e.what() << std::endl;
    }
}