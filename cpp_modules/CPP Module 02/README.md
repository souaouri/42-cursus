# CPP Module 02 - Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Class Form

The third C++ module introducing operator overloading and proper class design patterns.

## Description

This module focuses on operator overloading, the Orthodox Canonical Class Form, and ad-hoc polymorphism. You'll learn to create classes that behave like built-in types and understand the essential components every well-designed C++ class should have.

## Topics Covered

### Orthodox Canonical Class Form
- **Default Constructor**: Parameter-less constructor
- **Copy Constructor**: Creating objects from existing objects
- **Copy Assignment Operator**: Assigning one object to another
- **Destructor**: Proper cleanup of resources

### Operator Overloading
- **Arithmetic Operators**: +, -, *, /
- **Comparison Operators**: ==, !=, <, >, <=, >=
- **Stream Operators**: << (insertion), >> (extraction)
- **Increment/Decrement**: ++, -- (prefix and postfix)
- **Assignment Operators**: =, +=, -=, *=, /=

### Ad-hoc Polymorphism
- **Function Overloading**: Multiple functions with same name
- **Operator Overloading**: Giving new meanings to operators
- **Type Conversion**: Implicit and explicit conversions

### Fixed-Point Arithmetic
- **Binary Representation**: Understanding fixed-point numbers
- **Fractional Bits**: Representing decimals in binary
- **Arithmetic Operations**: Math with fixed-point numbers

## Exercises

### Exercise 00: My First Class in Orthodox Canonical Form
- Implementation of default constructor
- Copy constructor implementation
- Copy assignment operator (operator=)
- Destructor implementation
- Basic class design principles

### Exercise 01: Towards a More Useful Fixed-Point Number Class
- Fixed-point arithmetic class implementation
- Conversion constructors (int, float)
- Conversion operators (to int, to float)
- Stream insertion operator (operator<<)
- Mathematical operator overloading

### Exercise 02: Now We're Talking
- Complete arithmetic operator set (+, -, *, /)
- Comparison operators (>, <, >=, <=, ==, !=)
- Increment/decrement operators (++, --)
- Pre-increment vs post-increment
- Static member functions (min, max)

### Exercise 03: BSP (Binary Space Partitioning) - Optional
- Practical application of Fixed class
- Point-in-triangle algorithm
- Geometric calculations with fixed-point
- Real-world usage of custom numeric types

## Key Learning Points

1. **Canonical Form**: Essential components of every C++ class
2. **Operator Overloading**: Making custom types behave like built-in types
3. **Resource Management**: Proper copying and assignment
4. **Fixed-Point Math**: Alternative to floating-point arithmetic
5. **const Correctness**: Proper use of const in member functions

## Building and Running

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o [exercise_name]
```

## Code Examples

### Orthodox Canonical Form Template
```cpp
class MyClass {
private:
    // member variables

public:
    // Default constructor
    MyClass();
    
    // Copy constructor
    MyClass(const MyClass& other);
    
    // Copy assignment operator
    MyClass& operator=(const MyClass& other);
    
    // Destructor
    ~MyClass();
};
```

### Operator Overloading Examples
```cpp
// Arithmetic operators
Fixed operator+(const Fixed& rhs) const;
Fixed operator-(const Fixed& rhs) const;

// Comparison operators
bool operator>(const Fixed& rhs) const;
bool operator<(const Fixed& rhs) const;

// Stream operators
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
```

## Best Practices

- Always implement the Big Three (constructor, copy constructor, assignment operator) together
- Make binary operators symmetric when possible
- Return references from assignment operators
- Mark comparison operators as const
- Use const references for parameters when appropriate
- Implement operators that make sense for your class semantics

This module establishes fundamental patterns for creating robust, reusable C++ classes that integrate seamlessly with the language's built-in features.