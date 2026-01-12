# CPP Module 00 - Introduction to C++

The first module introducing basic C++ concepts and the transition from C to C++.

## Description

This module covers the fundamentals of C++ programming, introducing object-oriented concepts, classes, and basic C++ syntax. It serves as a bridge between C programming and object-oriented programming in C++.

## Topics Covered

### Basic C++ Concepts
- **Namespaces**: Organizing code and avoiding naming conflicts
- **Classes and Objects**: Basic class definition and instantiation
- **Member Functions**: Methods that operate on class data
- **Encapsulation**: Private and public access specifiers

### C++ Specific Features
- **iostream**: Input/output streams (`std::cin`, `std::cout`)
- **std::string**: C++ string class vs C-style strings
- **Initialization Lists**: Efficient member initialization
- **const Correctness**: Proper use of const keyword

### Memory and References
- **new/delete**: Dynamic memory allocation in C++
- **References**: Alternative to pointers for aliasing
- **Static Members**: Class-level variables and functions

## Exercises

### Exercise 00: Megaphone
- Basic program structure in C++
- Command-line argument processing
- String manipulation with std::string
- Output formatting with std::cout

### Exercise 01: My Awesome PhoneBook
- First complete class implementation
- Interactive program with menu system
- Data storage and retrieval
- Input validation and formatting
- Array of objects management

### Exercise 02: The Job Of Your Dreams (Optional)
- File recreation exercise
- Understanding class structure
- Header and implementation file organization

## Key Learning Points

1. **Class Design**: How to structure a class with appropriate members
2. **Encapsulation**: Keeping data private and providing controlled access
3. **User Interface**: Creating interactive console applications
4. **Data Management**: Storing and manipulating object data
5. **C++ Syntax**: Getting comfortable with C++ specific features

## Building and Running

Each exercise has its own compilation requirements:

```bash
# Exercise 00
c++ -Wall -Wextra -Werror -std=c++98 megaphone.cpp -o megaphone

# Exercise 01
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o phonebook
```

## Usage Examples

```bash
# Megaphone
./megaphone "hello world"
./megaphone hello world how are you

# PhoneBook
./phonebook
# Follow interactive prompts
```

This module establishes the foundation for all subsequent C++ modules and introduces the mindset shift from procedural to object-oriented programming.