# CPP Module 08 - Templated Containers, Iterators, Algorithms

The ninth C++ module exploring the Standard Template Library (STL) and advanced template usage with containers and algorithms.

## Description

This module introduces the Standard Template Library (STL), focusing on containers, iterators, and algorithms. You'll learn to work with existing STL containers and create your own templated container classes that integrate seamlessly with STL algorithms.

## Topics Covered

### STL Containers
- **Sequence Containers**: vector, list, deque
- **Associative Containers**: set, map, multiset, multimap
- **Container Adapters**: stack, queue, priority_queue
- **Container Requirements**: What makes a valid STL container

### Iterators
- **Iterator Categories**: input, output, forward, bidirectional, random access
- **Iterator Operations**: ++, --, *, ->, ==, !=
- **Iterator Traits**: type information about iterators
- **Custom Iterators**: Creating your own iterator classes

### Algorithms
- **Non-modifying Algorithms**: find, count, for_each, equal
- **Modifying Algorithms**: copy, transform, replace, remove
- **Sorting Algorithms**: sort, stable_sort, partial_sort
- **Binary Search**: lower_bound, upper_bound, binary_search

### Algorithm Customization
- **Function Objects**: Functors and their usage
- **Predicates**: Boolean functions for algorithm customization
- **Lambda Functions**: Anonymous functions (C++11 preview)
- **Custom Comparators**: Defining ordering for algorithms

## Exercises

### Exercise 00: Easy Find
- **easyfind**: Template function to find value in container
- Working with STL containers (vector, list, deque)
- Iterator-based searching
- Exception handling for element not found
- Generic algorithm that works with any container

### Exercise 01: Span
- **Span**: Template class storing a range of integers
- Iterator support for STL compatibility
- Exception handling for invalid operations
- Custom container that works with STL algorithms
- Shortest span and longest span calculations

### Exercise 02: Mutated Abomination
- **MutantStack**: Stack container with iterator support
- Inheriting from std::stack
- Adding iterator functionality to existing container
- Making non-iterable containers iterable
- STL algorithm compatibility

## Key Learning Points

1. **STL Integration**: Creating containers that work with STL algorithms
2. **Iterator Design**: Understanding and implementing iterator patterns
3. **Generic Algorithms**: Writing algorithms that work with any container
4. **Container Requirements**: What makes a proper STL-compatible container
5. **Exception Safety**: Handling errors in generic container operations

## Building and Running

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o [exercise_name]
```

## Code Examples

### Generic Find Algorithm (Exercise 00)
```cpp
#include <algorithm>
#include <iterator>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::exception();
    }
    return it;
}

// Usage example
#include <vector>
#include <list>
#include <iostream>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Element not found" << std::endl;
    }
    
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    
    try {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Element not found" << std::endl;
    }
    
    return 0;
}
```

### Custom Container with Iterators (Exercise 01)
```cpp
#include <vector>
#include <algorithm>
#include <exception>

class Span {
private:
    std::vector<int> _numbers;
    unsigned int _maxSize;

public:
    Span(unsigned int N) : _maxSize(N) {
        _numbers.reserve(N);
    }
    
    void addNumber(int number) {
        if (_numbers.size() >= _maxSize) {
            throw std::exception();
        }
        _numbers.push_back(number);
    }
    
    template <typename InputIterator>
    void addNumbers(InputIterator first, InputIterator last) {
        while (first != last && _numbers.size() < _maxSize) {
            _numbers.push_back(*first);
            ++first;
        }
        if (first != last) {
            throw std::exception(); // Not enough space
        }
    }
    
    int shortestSpan() const {
        if (_numbers.size() < 2) {
            throw std::exception();
        }
        
        std::vector<int> sorted = _numbers;
        std::sort(sorted.begin(), sorted.end());
        
        int minSpan = sorted[1] - sorted[0];
        for (size_t i = 2; i < sorted.size(); ++i) {
            int span = sorted[i] - sorted[i-1];
            if (span < minSpan) {
                minSpan = span;
            }
        }
        return minSpan;
    }
    
    int longestSpan() const {
        if (_numbers.size() < 2) {
            throw std::exception();
        }
        
        std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
        std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
        
        return *maxIt - *minIt;
    }
    
    // Iterator support
    typedef std::vector<int>::iterator iterator;
    typedef std::vector<int>::const_iterator const_iterator;
    
    iterator begin() { return _numbers.begin(); }
    iterator end() { return _numbers.end(); }
    const_iterator begin() const { return _numbers.begin(); }
    const_iterator end() const { return _numbers.end(); }
};

// Usage
int main() {
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    // Using STL algorithms with our container
    std::for_each(sp.begin(), sp.end(), [](int n) {
        std::cout << n << " ";
    });
    std::cout << std::endl;
    
    return 0;
}
```

### Mutant Stack (Exercise 02)
```cpp
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() {}
    MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
    MutantStack<T>& operator=(const MutantStack<T>& other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }
    ~MutantStack() {}
    
    // Iterator typedefs
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    
    // Iterator functions
    iterator begin() {
        return this->c.begin();
    }
    
    iterator end() {
        return this->c.end();
    }
    
    const_iterator begin() const {
        return this->c.begin();
    }
    
    const_iterator end() const {
        return this->c.end();
    }
    
    reverse_iterator rbegin() {
        return this->c.rbegin();
    }
    
    reverse_iterator rend() {
        return this->c.rend();
    }
    
    const_reverse_iterator rbegin() const {
        return this->c.rbegin();
    }
    
    const_reverse_iterator rend() const {
        return this->c.rend();
    }
};

// Usage
#include <iostream>
#include <algorithm>

int main() {
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    // Now we can iterate through our stack!
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    // Use STL algorithms
    std::for_each(mstack.begin(), mstack.end(), [](int n) {
        std::cout << n << " ";
    });
    
    return 0;
}
```

## STL Best Practices

### Container Choice
- **vector**: Default choice for sequences, random access needed
- **list**: Frequent insertions/deletions in middle
- **deque**: Random access with efficient front/back operations
- **set/map**: Unique sorted elements, fast lookups
- **stack/queue**: LIFO/FIFO semantics

### Iterator Usage
- Always use iterators for container traversal
- Prefer pre-increment (++it) over post-increment (it++) for efficiency
- Be careful about iterator invalidation after container modifications
- Use const_iterator when not modifying elements

### Algorithm Usage
- Prefer STL algorithms over hand-written loops
- Use function objects and predicates for customization
- Understand algorithm complexity guarantees
- Choose appropriate algorithm variants (stable_sort vs sort)

## Common STL Patterns

### RAII with STL Containers
```cpp
class ResourceManager {
    std::vector<Resource*> resources;
public:
    ~ResourceManager() {
        std::for_each(resources.begin(), resources.end(), 
                     [](Resource* r) { delete r; });
    }
};
```

### Custom Predicates
```cpp
struct IsEven {
    bool operator()(int n) const {
        return n % 2 == 0;
    }
};

// Usage
std::vector<int> numbers;
int evenCount = std::count_if(numbers.begin(), numbers.end(), IsEven());
```

This module provides essential knowledge for effective STL usage and prepares you for advanced C++ programming with standard containers and algorithms.