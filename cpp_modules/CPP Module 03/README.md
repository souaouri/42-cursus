# CPP Module 03 - Inheritance

The fourth C++ module introducing inheritance, the foundation of object-oriented programming.

## Description

This module explores inheritance in C++, teaching you how to create class hierarchies, understand the relationship between base and derived classes, and implement proper inheritance patterns. You'll learn about virtual functions, protected access, and the basics of polymorphism.

## Topics Covered

### Inheritance Fundamentals
- **Base and Derived Classes**: Creating class hierarchies
- **Access Specifiers**: public, protected, private inheritance
- **Constructor/Destructor Chain**: Order of construction and destruction
- **Member Access**: Accessing base class members from derived classes

### Virtual Functions
- **Virtual Keyword**: Enabling runtime polymorphism
- **Virtual Destructors**: Proper cleanup in inheritance hierarchies
- **Override Behavior**: Redefining base class functionality
- **Pure Virtual Functions**: Abstract classes introduction

### Inheritance Patterns
- **Single Inheritance**: One base class
- **Multiple Inheritance**: Multiple base classes (introduction)
- **Diamond Problem**: Understanding inheritance ambiguity
- **Virtual Inheritance**: Solving diamond problem

### Object-Oriented Design
- **Is-A Relationship**: When to use inheritance
- **Code Reuse**: Leveraging base class functionality
- **Specialization**: Adding specific behavior to derived classes
- **Polymorphic Behavior**: Objects behaving according to their actual type

## Exercises

### Exercise 00: Aaaaand... OPEN!
- Basic inheritance implementation
- ClapTrap base class creation
- Constructor and destructor messages
- Member function inheritance
- Attack, repair, and damage mechanics

### Exercise 01: Serena, My Love!
- Single inheritance with ScavTrap
- Constructor chaining and initialization
- Method overriding and specialization
- Adding new functionality to derived class
- Special attack implementation

### Exercise 02: Repetitive Work
- FragTrap class implementation
- Multiple derived classes from same base
- Different specializations of base functionality
- High five attack implementation
- Understanding class relationships

### Exercise 03: Now It's Weird! (Optional)
- DiamondTrap class creation
- Multiple inheritance implementation
- Diamond problem demonstration
- Virtual inheritance usage
- Complex constructor chaining
- Name resolution in multiple inheritance

## Key Learning Points

1. **Class Hierarchies**: Organizing related classes in inheritance trees
2. **Code Reuse**: Leveraging existing functionality through inheritance
3. **Polymorphism**: Objects behaving according to their actual type
4. **Virtual Functions**: Enabling runtime method resolution
5. **Constructor Chains**: Understanding initialization order in inheritance

## Building and Running

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o [exercise_name]
```

## Inheritance Hierarchy Example

```
    ClapTrap (base)
    /       \
ScavTrap   FragTrap
    \       /
    DiamondTrap
```

## Code Examples

### Basic Inheritance
```cpp
class ClapTrap {
protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
    ClapTrap(const std::string& name);
    virtual ~ClapTrap();
    
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

class ScavTrap : public ClapTrap {
public:
    ScavTrap(const std::string& name);
    ~ScavTrap();
    
    void attack(const std::string& target); // Override
    void guardGate(); // New functionality
};
```

### Virtual Inheritance (Exercise 03)
```cpp
class FragTrap : virtual public ClapTrap { /* ... */ };
class ScavTrap : virtual public ClapTrap { /* ... */ };
class DiamondTrap : public FragTrap, public ScavTrap { /* ... */ };
```

## Design Principles

- Use inheritance for "is-a" relationships
- Prefer composition over inheritance when appropriate
- Always use virtual destructors in base classes
- Keep base class interfaces simple and focused
- Use protected for members that derived classes need access to
- Consider the Liskov Substitution Principle

## Common Pitfalls

- Forgetting virtual destructors in base classes
- Using private inheritance when public is intended
- Creating overly complex inheritance hierarchies
- Diamond problem without virtual inheritance
- Slicing when passing derived objects as base class values

This module prepares you for advanced polymorphism concepts and establishes the foundation for designing extensible object-oriented systems.