# CPP Module 01 - Memory Allocation, Pointers, References, Switch Statement

The second C++ module focusing on memory management and advanced pointer/reference concepts.

## Description

This module dives deeper into C++ memory management, exploring the differences between stack and heap allocation, references vs pointers, and alternatives to switch statements. It emphasizes proper resource management and modern C++ practices.

## Topics Covered

### Memory Management
- **new/delete**: Dynamic memory allocation and deallocation
- **Stack vs Heap**: Understanding memory allocation strategies
- **Memory Leaks**: Prevention and detection
- **Resource Management**: RAII principles introduction

### References and Pointers
- **References**: Aliases to existing variables
- **Pointer vs Reference**: When to use each
- **Pointer to Members**: Function pointers and member function pointers
- **Reference Parameters**: Efficient parameter passing

### Advanced Concepts
- **File I/O**: Reading and writing files with fstream
- **String Manipulation**: Advanced string operations
- **Function Pointers**: Storing and calling functions dynamically
- **Switch Alternatives**: Object-oriented approaches to conditional logic

## Exercises

### Exercise 00: BraiiiiiiinnnzzzZ
- Dynamic memory allocation with `new`/`delete`
- Proper constructor/destructor implementation
- Stack vs heap object creation
- Memory management best practices

### Exercise 01: Moar Brainz!
- Dynamic array allocation
- Proper cleanup of allocated resources
- Understanding object lifetime
- Constructor/destructor call order

### Exercise 02: HI THIS IS BRAIN
- Reference vs pointer demonstration
- Memory address manipulation
- Understanding aliases and indirection
- When to use references vs pointers

### Exercise 03: Unnecessary Violence
- Class design with multiple member functions
- Reference parameters for efficiency
- Object interaction and method chaining
- Weapon and character modeling

### Exercise 04: Sed is for Losers
- File input/output operations
- String search and replace algorithms
- Command-line argument processing
- Error handling for file operations

### Exercise 05: Harl 2.0
- Function pointers and member function pointers
- Alternative to switch statements using arrays
- Dynamic function dispatch
- Logging system implementation

### Exercise 06: Harl Filter
- Command-line argument processing
- Function pointer arrays
- Filtering and logging levels
- Switch statement alternatives

## Key Learning Points

1. **Memory Management**: Proper use of new/delete and avoiding leaks
2. **References**: When and how to use references effectively
3. **File Operations**: Reading from and writing to files
4. **Function Pointers**: Dynamic function calling mechanisms
5. **Resource Management**: Ensuring proper cleanup of resources

## Building and Running

Compile each exercise with C++98 standard:

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o [exercise_name]
```

## Usage Examples

```bash
# Exercise 04 - File replacement
./sed_is_for_losers filename "search" "replace"

# Exercise 05 - Harl logging
./harl "DEBUG"
./harl "ERROR"

# Exercise 06 - Harl filter
./harlFilter "WARNING"
```

## Memory Management Guidelines

- Always match `new` with `delete`
- Always match `new[]` with `delete[]`
- Initialize pointers to NULL when not immediately assigned
- Check for NULL before dereferencing pointers
- Prefer references over pointers when possible
- Use RAII principles for automatic resource management

This module prepares you for more advanced memory management concepts and establishes good practices for resource handling in C++.