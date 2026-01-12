# CPP Module 07 - C++ Templates

The eighth C++ module introducing template programming and generic programming concepts in C++.

## Description

This module explores C++ templates, enabling you to write generic code that works with multiple types. You'll learn function templates, class templates, template specialization, and how to create reusable, type-safe generic algorithms.

## Topics Covered

### Function Templates
- **Template Syntax**: Basic template declaration and definition
- **Type Deduction**: Automatic type inference from arguments
- **Template Parameters**: Type and non-type parameters
- **Template Instantiation**: How templates become concrete functions
- **Overload Resolution**: How templates interact with function overloading

### Class Templates
- **Template Classes**: Generic class definitions
- **Member Function Templates**: Templated methods within classes
- **Template Specialization**: Providing specific implementations
- **Partial Specialization**: Specializing subsets of template parameters
- **Default Template Arguments**: Providing default types

### Advanced Templates
- **Template Metaprogramming**: Compile-time computation
- **SFINAE**: Substitution Failure Is Not An Error
- **Template Recursion**: Recursive template definitions
- **Variadic Templates**: Variable number of template arguments (C++11 preview)

### Generic Programming
- **Algorithms**: Writing type-independent algorithms
- **Iterators**: Generic access to container elements
- **Containers**: Template-based data structures
- **Type Traits**: Compile-time type information

## Exercises

### Exercise 00: Start with a Few Functions
- Generic function templates implementation
- **swap**: Template function to swap two values of any type
- **min**: Template function returning smaller of two values
- **max**: Template function returning larger of two values
- Type deduction demonstration
- Template instantiation with different types

### Exercise 01: Iter
- **iter**: Template function that applies a function to array elements
- Function pointer parameters
- Generic array processing
- Template function with function parameters
- Working with arrays of different types

### Exercise 02: Array
- **Array**: Template class implementing a generic array
- Template class with size parameter
- Exception handling in templates
- Member function implementation in template classes
- Iterator-like functionality
- Bounds checking and safety

## Key Learning Points

1. **Generic Programming**: Writing code that works with multiple types
2. **Type Safety**: Maintaining type safety while being generic
3. **Code Reuse**: Eliminating code duplication through templates
4. **Template Syntax**: Understanding template declaration and definition
5. **Specialization**: Providing specific implementations when needed

## Building and Running

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o [exercise_name]
```

## Code Examples

### Function Templates (Exercise 00)
```cpp
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T const& min(T const& a, T const& b) {
    return (b <= a) ? b : a;
}

template <typename T>
T const& max(T const& a, T const& b) {
    return (a <= b) ? b : a;
}

// Usage
int main() {
    int a = 2, b = 3;
    swap<int>(a, b);        // Explicit instantiation
    swap(a, b);             // Automatic type deduction
    
    std::cout << "min(a, b) = " << min(a, b) << std::endl;
    std::cout << "max(a, b) = " << max(a, b) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    swap(c, d);
    
    return 0;
}
```

### Template with Function Parameters (Exercise 01)
```cpp
template <typename T>
void iter(T* array, size_t length, void (*f)(T&)) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

template <typename T>
void iter(T* array, size_t length, void (*f)(const T&)) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

// Example usage functions
template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

template <typename T>
void increment(T& x) {
    ++x;
}

// Usage
int main() {
    int array[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(array) / sizeof(array[0]);
    
    iter(array, length, print<int>);
    std::cout << std::endl;
    
    iter(array, length, increment<int>);
    iter(array, length, print<int>);
    
    return 0;
}
```

### Template Class (Exercise 02)
```cpp
template <typename T, unsigned int N>
class Array {
private:
    T* _elements;
    unsigned int _size;

public:
    Array() : _elements(new T[N]()), _size(N) {}
    
    Array(const Array& other) : _elements(new T[N]), _size(N) {
        for (unsigned int i = 0; i < _size; i++) {
            _elements[i] = other._elements[i];
        }
    }
    
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _elements;
            _elements = new T[N];
            _size = N;
            for (unsigned int i = 0; i < _size; i++) {
                _elements[i] = other._elements[i];
            }
        }
        return *this;
    }
    
    ~Array() {
        delete[] _elements;
    }
    
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }
    
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }
    
    unsigned int size() const {
        return _size;
    }
    
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Array index out of bounds";
        }
    };
};

// Usage
int main() {
    Array<int, 10> intArray;
    Array<std::string, 5> stringArray;
    
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 2;
    }
    
    try {
        std::cout << intArray[15] << std::endl; // Will throw exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
```

## Template Best Practices

### Function Templates
- Use meaningful template parameter names (T, U, V or descriptive names)
- Provide clear documentation about type requirements
- Consider const-correctness in template parameters
- Use template specialization for specific type behavior

### Class Templates
- Follow the Rule of Three/Five for resource management
- Provide appropriate exception safety guarantees
- Use template parameters for both types and values when appropriate
- Consider providing type aliases for common instantiations

### General Guidelines
- Keep template definitions in header files
- Use explicit instantiation to reduce compile times when appropriate
- Avoid deep template recursion (compiler limits)
- Test templates with various types including built-in and user-defined types

## Common Template Patterns

### RAII with Templates
```cpp
template <typename T>
class unique_ptr {
private:
    T* ptr;
public:
    explicit unique_ptr(T* p = nullptr) : ptr(p) {}
    ~unique_ptr() { delete ptr; }
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    // ... copy prevention, move semantics, etc.
};
```

### Template Specialization
```cpp
// General template
template <typename T>
class Vector { /* general implementation */ };

// Specialization for bool
template <>
class Vector<bool> { /* space-optimized implementation */ };
```

This module introduces the power of generic programming in C++ and prepares you for advanced template metaprogramming and the Standard Template Library (STL).