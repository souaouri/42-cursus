# CPP Module 05 - Repetition and Exceptions

The sixth C++ module focusing on exception handling and bureaucratic form processing.

## Description

This module introduces C++ exception handling mechanisms while building a bureaucratic system with forms and bureaucrats. You'll learn to throw and catch exceptions, create custom exception classes, and implement proper error handling in object-oriented designs.

## Topics Covered

### Exception Handling
- **try/catch/throw**: Basic exception syntax
- **Exception Classes**: Creating custom exception types
- **Exception Inheritance**: Building exception hierarchies
- **RAII and Exceptions**: Resource safety with exceptions
- **Exception Safety**: Basic, strong, and no-throw guarantees

### Exception Types
- **Standard Exceptions**: std::exception and derived classes
- **Custom Exceptions**: Creating domain-specific error types
- **Exception Propagation**: How exceptions travel up the call stack
- **Nested Exceptions**: Exceptions within exception handlers
- **Exception Specifications**: Exception guarantees (deprecated in C++11)

### Design Patterns
- **Command Pattern**: Encapsulating requests as objects
- **Chain of Responsibility**: Passing requests along a chain
- **Strategy Pattern**: Interchangeable execution algorithms
- **Template Method**: Defining algorithm skeletons

### Resource Management
- **Exception-Safe Code**: Writing code that handles exceptions properly
- **RAII**: Resource Acquisition Is Initialization
- **Destructors and Exceptions**: What happens when destructors throw
- **Stack Unwinding**: Automatic cleanup during exception propagation

## Exercises

### Exercise 00: Mommy, When I Grow Up, I Want to be a Bureaucrat!
- Bureaucrat class implementation
- Grade validation with exceptions
- GradeTooHighException and GradeTooLowException
- Basic exception throwing and handling
- Getter methods and grade manipulation

### Exercise 01: Form Up, Maggots!
- Abstract Form base class
- Pure virtual execute method
- Form signing requirements
- Exception handling in form operations
- Bureaucrat and Form interaction

### Exercise 02: No, You Need Form 28B, not 28C...
- Concrete form implementations:
  - ShrubberyCreationForm (ASCII trees)
  - RobotomyRequestForm (drilling sounds)
  - PresidentialPardonForm (presidential pardons)
- File I/O operations with exception handling
- Different execution requirements and behaviors

### Exercise 03: At Least This Beats Coffee-Making (Optional)
- Intern class implementation
- Factory pattern for form creation
- Dynamic form instantiation by name
- Exception handling for unknown form types
- Polymorphic form creation system

## Key Learning Points

1. **Exception Safety**: Writing code that handles errors gracefully
2. **Custom Exceptions**: Creating domain-specific error types
3. **Resource Management**: Ensuring cleanup even when exceptions occur
4. **Error Propagation**: Understanding how exceptions travel through code
5. **Factory Pattern**: Creating objects dynamically based on parameters

## Building and Running

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o [exercise_name]
```

## Code Examples

### Custom Exception Classes
```cpp
class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low!";
        }
    };

private:
    void setGrade(int grade) {
        if (grade < 1)
            throw GradeTooHighException();
        if (grade > 150)
            throw GradeTooLowException();
        this->_grade = grade;
    }
};
```

### Exception Handling
```cpp
int main() {
    try {
        Bureaucrat bob("Bob", 0); // Will throw GradeTooHighException
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
    return 0;
}
```

### Abstract Form Class
```cpp
class Form {
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    virtual ~Form();

    // Pure virtual function
    virtual void execute(const Bureaucrat& executor) const = 0;

    void beSigned(const Bureaucrat& bureaucrat);
    
    // Exception classes
    class GradeTooHighException : public std::exception { /* ... */ };
    class GradeTooLowException : public std::exception { /* ... */ };
    class FormNotSignedException : public std::exception { /* ... */ };
};
```

### Factory Pattern (Exercise 03)
```cpp
class Intern {
public:
    Form* makeForm(const std::string& formName, const std::string& target);
    
    class FormNotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Form not found!";
        }
    };
};
```

## Exception Safety Guidelines

1. **Basic Guarantee**: No resource leaks, objects remain in valid state
2. **Strong Guarantee**: Either complete success or no change to program state  
3. **No-throw Guarantee**: Function never throws exceptions
4. **Always catch exceptions by const reference**
5. **Use RAII for automatic resource cleanup**
6. **Don't throw exceptions in destructors**

## Best Practices

- Create meaningful exception hierarchies
- Use standard exceptions when appropriate
- Catch specific exceptions before general ones
- Always catch exceptions by const reference
- Document what exceptions your functions might throw
- Use RAII to ensure resource cleanup
- Test exception handling paths thoroughly

This module establishes solid foundations for error handling in C++ and prepares you for writing robust, exception-safe code.