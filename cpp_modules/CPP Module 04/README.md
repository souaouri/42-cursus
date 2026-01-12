# CPP Module 04 - Subtype Polymorphism, Abstract Classes, Interfaces

The fifth C++ module exploring advanced polymorphism concepts and abstract class design.

## Description

This module delves deep into polymorphism, abstract classes, and interfaces. You'll learn to create flexible, extensible designs using pure virtual functions, understand deep vs shallow copying in inheritance hierarchies, and implement proper polymorphic behavior.

## Topics Covered

### Polymorphism
- **Runtime Polymorphism**: Virtual function dispatch
- **Pure Virtual Functions**: Abstract methods that must be implemented
- **Abstract Classes**: Classes that cannot be instantiated
- **Interface Design**: Creating contracts for derived classes

### Advanced Inheritance
- **Deep vs Shallow Copy**: Copying objects with polymorphic members
- **Virtual Function Tables**: Understanding vtables
- **Object Slicing**: Problems and solutions
- **Polymorphic Arrays**: Collections of different derived types

### Memory Management
- **Polymorphic Deletion**: Proper cleanup through base pointers
- **Virtual Destructors**: Ensuring proper cleanup in inheritance
- **RAII with Polymorphism**: Resource management in hierarchies
- **Smart Pointers**: Introduction to safer memory management

### Design Patterns
- **Strategy Pattern**: Interchangeable algorithms
- **Template Method Pattern**: Defining algorithm skeletons
- **Factory Pattern**: Creating objects polymorphically
- **Composition vs Inheritance**: When to use which

## Exercises

### Exercise 00: Polymorphism
- Animal base class with pure virtual functions
- Dog and Cat derived classes
- Polymorphic behavior demonstration
- Virtual destructor implementation
- Array of polymorphic objects

### Exercise 01: I Don't Want to Set the World on Fire
- Brain class implementation
- Deep copying in polymorphic hierarchies
- Copy constructor and assignment operator in inheritance
- Memory management with composed objects
- Avoiding shallow copy problems

### Exercise 02: Abstract Class
- Pure abstract Animal class
- Concrete Dog and Cat implementations
- Ideas system for animal thoughts
- Abstract method enforcement
- Interface compliance verification

### Exercise 03: Interface & Recap (Optional)
- Multiple interface implementation
- ICharacter and IMateriaSource interfaces
- Materia system with Ice and Cure
- Complex polymorphic interactions
- Memory management in advanced hierarchies

## Key Learning Points

1. **Abstract Classes**: Classes that define interfaces but cannot be instantiated
2. **Pure Virtual Functions**: Methods that must be implemented by derived classes
3. **Polymorphic Copying**: Deep copying objects with virtual functions
4. **Interface Design**: Creating contracts for class behavior
5. **Memory Safety**: Proper cleanup in polymorphic hierarchies

## Building and Running

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o [exercise_name]
```

## Code Examples

### Abstract Base Class
```cpp
class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    // Pure virtual functions (abstract methods)
    virtual void makeSound() const = 0;
    virtual std::string getType() const;
};
```

### Polymorphic Usage
```cpp
int main() {
    const Animal* animals[4] = {
        new Dog(),
        new Cat(),
        new Dog(),
        new Cat()
    };

    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound(); // Calls appropriate derived version
        delete animals[i];       // Calls virtual destructor
    }

    return 0;
}
```

### Deep Copy Implementation
```cpp
class Dog : public Animal {
private:
    Brain* brain;

public:
    Dog();
    Dog(const Dog& other);              // Deep copy constructor
    Dog& operator=(const Dog& other);   // Deep copy assignment
    virtual ~Dog();

    virtual void makeSound() const;
};

// Deep copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
    this->brain = new Brain(*other.brain); // Deep copy
}
```

## Design Principles

- Use pure virtual functions to enforce interface contracts
- Always provide virtual destructors in base classes
- Implement proper deep copying for polymorphic classes
- Prefer composition over inheritance for complex relationships
- Design interfaces that are stable and minimal
- Use abstract classes to prevent instantiation of incomplete types

## Common Patterns

### Interface Definition
```cpp
class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
```

### Factory Pattern
```cpp
class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};
```

This module establishes advanced object-oriented programming skills and prepares you for complex system design using polymorphism and abstraction.