# CPP Module 06 - C++ Casts

The seventh C++ module exploring the different types of casting in C++ and type conversion mechanisms.

## Description

This module focuses on C++ casting operators and type conversion. You'll learn about the four main cast types in C++, understand when to use each one, explore serialization concepts, and work with type identification and conversion between different data types.

## Topics Covered

### C++ Cast Types
- **static_cast**: Compile-time type conversion
- **dynamic_cast**: Runtime type checking and conversion
- **const_cast**: Adding or removing const/volatile qualifiers
- **reinterpret_cast**: Low-level reinterpreting of bit patterns

### Type Conversion
- **Implicit Conversion**: Automatic type conversions
- **Explicit Conversion**: Manual type conversions
- **User-Defined Conversions**: Custom conversion operators
- **Type Promotion**: Automatic widening conversions

### Serialization
- **Data Serialization**: Converting objects to byte streams
- **Deserialization**: Reconstructing objects from byte streams
- **Type Identification**: Runtime type information (RTTI)
- **Pointer Arithmetic**: Low-level memory manipulation

### Runtime Type Information (RTTI)
- **typeid Operator**: Getting type information at runtime
- **type_info Class**: Representing type information
- **Dynamic Type Checking**: Verifying types before casting
- **Polymorphic Type Detection**: Identifying actual object types

## Exercises

### Exercise 00: Conversion of Scalar Types
- ScalarConverter class implementation
- String to numeric type conversion
- Type detection and validation
- Special value handling (inf, nan, non-displayable chars)
- Display formatting for different types
- Error handling for invalid conversions

### Exercise 01: Serialization
- Data class with private members
- Serialize function (object to raw bytes)
- Deserialize function (raw bytes to object)
- uintptr_t for pointer arithmetic
- reinterpret_cast for low-level conversion
- Data integrity verification

### Exercise 02: Identify Real Type
- Base class with virtual functions
- A, B, C derived classes
- generate() function returning random Base pointer
- identify() functions using references and pointers
- dynamic_cast for safe downcasting
- Runtime type identification without exceptions

## Key Learning Points

1. **Cast Safety**: Understanding when each cast type is appropriate
2. **Type Conversion**: Converting between different data types safely
3. **Serialization**: Converting objects to and from byte representations
4. **RTTI**: Using runtime type information for dynamic behavior
5. **Memory Layout**: Understanding how objects are represented in memory

## Building and Running

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o [exercise_name]
```

## Code Examples

### Static Cast (Exercise 00)
```cpp
class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
};

// Usage example
void ScalarConverter::convert(const std::string& literal) {
    double value = std::strtod(literal.c_str(), NULL);
    
    printChar(static_cast<char>(value));
    printInt(static_cast<int>(value));
    printFloat(static_cast<float>(value));
    printDouble(value);
}
```

### Reinterpret Cast (Exercise 01)
```cpp
struct Data {
    int value;
    std::string name;
};

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

// Usage
Data original;
uintptr_t serialized = serialize(&original);
Data* deserialized = deserialize(serialized);
// deserialized should equal &original
```

### Dynamic Cast (Exercise 02)
```cpp
class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    std::cout << "C" << std::endl;
}
```

## Cast Usage Guidelines

### static_cast
- **Use for**: Related type conversions, numeric conversions
- **Examples**: int to float, base to derived (if you're sure)
- **Safety**: Compile-time checked, no runtime overhead

### dynamic_cast  
- **Use for**: Safe downcasting in polymorphic hierarchies
- **Examples**: Base* to Derived*, checking actual object type
- **Safety**: Runtime checked, returns nullptr/throws on failure

### const_cast
- **Use for**: Adding or removing const/volatile qualifiers
- **Examples**: Passing const data to legacy non-const APIs
- **Safety**: Use with extreme caution, can lead to undefined behavior

### reinterpret_cast
- **Use for**: Low-level bit reinterpretation
- **Examples**: Pointer to integer, serialization
- **Safety**: Most dangerous, implementation-dependent

## Best Practices

- Prefer static_cast for most conversions
- Use dynamic_cast for safe polymorphic downcasting
- Avoid const_cast unless absolutely necessary
- Use reinterpret_cast only for low-level operations
- Always check dynamic_cast results for nullptr
- Prefer C++ casts over C-style casts for clarity
- Document why you need each cast

## Common Pitfalls

- Using C-style casts instead of specific C++ casts
- Not checking dynamic_cast results
- Using reinterpret_cast when static_cast would suffice
- Casting away const and then modifying (undefined behavior)
- Assuming pointer arithmetic works across all platforms

This module provides essential knowledge for safe type conversion and low-level programming in C++, preparing you for advanced system programming concepts.