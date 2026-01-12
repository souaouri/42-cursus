# C++ Modules

A series of C++ exercises designed to learn object-oriented programming concepts and C++ language features progressively.

## Description

These modules cover fundamental to advanced C++ concepts, starting from basic syntax and progressing through object-oriented programming, operator overloading, inheritance, polymorphism, templates, and STL containers.

## Module Structure

### [CPP 00](cpp_00/) - Introduction to C++
- Namespaces, classes, member functions
- stdio streams, initialization lists
- static, const, and other basic concepts
- Your first class implementations

### CPP 01 - Memory Management
- Memory allocation, references vs pointers
- File streams, string replacement
- Member function pointers
- Switch statements alternatives

### CPP 02 - Operator Overloading
- Orthodox canonical class form
- Fixed-point arithmetic class
- Operator overloading fundamentals
- Copy constructors and assignment operators

### CPP 03 - Inheritance
- Class inheritance basics
- Virtual functions introduction
- Diamond problem awareness
- Multiple inheritance concepts

### CPP 04 - Polymorphism
- Virtual functions deep dive
- Abstract classes and interfaces
- Pure virtual functions
- Runtime polymorphism

### CPP 05 - Exceptions
- Exception handling mechanisms
- Try, catch, throw statements
- Custom exception classes
- Resource management with exceptions

### CPP 06 - Type Casting
- Static, dynamic, const, and reinterpret casts
- Type conversion and casting operators
- Serialization concepts
- Type safety in C++

### CPP 07 - Templates
- Function templates
- Class templates
- Template specialization
- Generic programming basics

### CPP 08 - STL Containers
- Standard Template Library introduction
- Iterators and algorithms
- Container types and usage
- STL best practices

### CPP 09 - Advanced Containers
- Advanced STL usage
- Container adapters
- Performance considerations
- Real-world applications

## Learning Objectives

Each module builds upon the previous ones:
- **Modules 00-02**: C++ basics and class design
- **Modules 03-04**: Object-oriented programming
- **Modules 05-06**: Advanced language features
- **Modules 07-09**: Generic programming and STL

## Building

Each module contains its own exercises with individual Makefiles:

```bash
cd cpp_XX/exXX
make
```

## Coding Standards

All projects follow the 42 C++ coding standard:
- Orthodox canonical form for classes
- No memory leaks
- Proper exception safety
- STL usage where appropriate (later modules)