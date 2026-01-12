# CPP Module 09 - STL

The final C++ module focusing on advanced STL usage, complex data structures, and real-world algorithm implementations.

## Description

This final module challenges you to apply all your C++ and STL knowledge to solve complex problems. You'll work with advanced STL containers, implement sophisticated algorithms, and create efficient data processing solutions using STL components.

## Topics Covered

### Advanced STL Usage
- **Complex Data Structures**: Nested containers and composite structures
- **Algorithm Composition**: Combining multiple STL algorithms
- **Performance Optimization**: Choosing optimal containers and algorithms
- **Memory Management**: Efficient resource usage with STL

### Real-World Applications
- **Data Processing**: Reading, parsing, and manipulating large datasets
- **Financial Calculations**: Implementing trading and calculation algorithms
- **String Processing**: Advanced text manipulation and parsing
- **Graph Algorithms**: Using STL for graph-like data structures

### Algorithm Design
- **Problem Decomposition**: Breaking complex problems into manageable parts
- **Data Structure Selection**: Choosing appropriate STL containers
- **Algorithmic Complexity**: Understanding and optimizing time/space complexity
- **Error Handling**: Robust error handling in complex algorithms

### Design Patterns with STL
- **Strategy Pattern**: Using function objects for algorithm customization
- **Observer Pattern**: Event-driven programming with STL
- **Composite Pattern**: Building complex structures with STL containers
- **Factory Pattern**: Creating objects based on STL-processed input

## Exercises

### Exercise 00: Bitcoin Exchange
- **btc**: Program to calculate Bitcoin values on specific dates
- CSV file parsing and processing
- Date validation and formatting
- std::map for date-value storage
- Exchange rate calculations with boundary conditions
- Error handling for invalid dates and values

### Exercise 01: Reverse Polish Notation
- **RPN**: Calculator using Reverse Polish Notation
- std::stack for operand management
- Mathematical expression evaluation
- Operator precedence and validation
- Error handling for invalid expressions
- Support for basic arithmetic operations (+, -, *, /)

### Exercise 02: PmergeMe
- **PmergeMe**: Advanced sorting algorithm comparison
- Ford-Johnson merge-insertion sort implementation
- Performance comparison between std::vector and std::deque
- Large dataset sorting optimization
- Time measurement and performance analysis
- Handling edge cases and memory efficiency

## Key Learning Points

1. **STL Mastery**: Advanced usage of STL containers and algorithms
2. **Algorithm Implementation**: Implementing complex algorithms efficiently
3. **Performance Analysis**: Measuring and comparing algorithm performance
4. **Real-World Problem Solving**: Applying C++ to practical problems
5. **Code Organization**: Structuring complex C++ projects effectively

## Building and Running

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o [exercise_name]
```

## Code Examples

### Bitcoin Exchange (Exercise 00)
```cpp
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

class BitcoinExchange {
private:
    std::map<std::string, double> _exchangeRates;
    
    bool isValidDate(const std::string& date) const {
        // Date validation logic (YYYY-MM-DD format)
        if (date.length() != 10) return false;
        if (date[4] != '-' || date[7] != '-') return false;
        
        // Extract year, month, day and validate ranges
        int year = std::atoi(date.substr(0, 4).c_str());
        int month = std::atoi(date.substr(5, 2).c_str());
        int day = std::atoi(date.substr(8, 2).c_str());
        
        return (year >= 2009 && year <= 2023 && 
                month >= 1 && month <= 12 && 
                day >= 1 && day <= 31);
    }
    
    double findExchangeRate(const std::string& date) const {
        std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);
        if (it == _exchangeRates.begin() && it->first > date) {
            throw std::runtime_error("No data available for this date");
        }
        if (it == _exchangeRates.end() || it->first > date) {
            --it;
        }
        return it->second;
    }

public:
    BitcoinExchange() {}
    
    void loadDatabase(const std::string& filename) {
        std::ifstream file(filename.c_str());
        if (!file.is_open()) {
            throw std::runtime_error("Could not open database file");
        }
        
        std::string line;
        std::getline(file, line); // Skip header
        
        while (std::getline(file, line)) {
            size_t commaPos = line.find(',');
            if (commaPos != std::string::npos) {
                std::string date = line.substr(0, commaPos);
                double rate = std::atof(line.substr(commaPos + 1).c_str());
                _exchangeRates[date] = rate;
            }
        }
    }
    
    void processInputFile(const std::string& filename) {
        std::ifstream file(filename.c_str());
        if (!file.is_open()) {
            throw std::runtime_error("Could not open input file");
        }
        
        std::string line;
        std::getline(file, line); // Skip header
        
        while (std::getline(file, line)) {
            try {
                size_t pipePos = line.find(" | ");
                if (pipePos == std::string::npos) {
                    std::cerr << "Error: bad input => " << line << std::endl;
                    continue;
                }
                
                std::string date = line.substr(0, pipePos);
                std::string valueStr = line.substr(pipePos + 3);
                
                if (!isValidDate(date)) {
                    std::cerr << "Error: invalid date => " << date << std::endl;
                    continue;
                }
                
                double value = std::atof(valueStr.c_str());
                if (value < 0) {
                    std::cerr << "Error: not a positive number." << std::endl;
                    continue;
                }
                if (value > 1000) {
                    std::cerr << "Error: too large a number." << std::endl;
                    continue;
                }
                
                double rate = findExchangeRate(date);
                std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
                
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
};

// Usage
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    
    try {
        BitcoinExchange exchange;
        exchange.loadDatabase("data.csv");
        exchange.processInputFile(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
```

### RPN Calculator (Exercise 01)
```cpp
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

class RPNCalculator {
private:
    std::stack<double> _operands;
    
    bool isOperator(const std::string& token) const {
        return (token == "+" || token == "-" || token == "*" || token == "/");
    }
    
    bool isNumber(const std::string& token) const {
        char* endptr;
        std::strtod(token.c_str(), &endptr);
        return (*endptr == '\0' && !token.empty());
    }
    
    void performOperation(const std::string& op) {
        if (_operands.size() < 2) {
            throw std::runtime_error("Insufficient operands for operation");
        }
        
        double b = _operands.top(); _operands.pop();
        double a = _operands.top(); _operands.pop();
        double result;
        
        if (op == "+") {
            result = a + b;
        } else if (op == "-") {
            result = a - b;
        } else if (op == "*") {
            result = a * b;
        } else if (op == "/") {
            if (b == 0) {
                throw std::runtime_error("Division by zero");
            }
            result = a / b;
        } else {
            throw std::runtime_error("Unknown operator: " + op);
        }
        
        _operands.push(result);
    }

public:
    double evaluate(const std::string& expression) {
        _operands = std::stack<double>(); // Clear stack
        
        std::istringstream iss(expression);
        std::string token;
        
        while (iss >> token) {
            if (isNumber(token)) {
                _operands.push(std::atof(token.c_str()));
            } else if (isOperator(token)) {
                performOperation(token);
            } else {
                throw std::runtime_error("Invalid token: " + token);
            }
        }
        
        if (_operands.size() != 1) {
            throw std::runtime_error("Invalid expression: incorrect number of operands");
        }
        
        return _operands.top();
    }
};

// Usage
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " \"<RPN expression>\"" << std::endl;
        return 1;
    }
    
    try {
        RPNCalculator calculator;
        double result = calculator.evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
```

### PmergeMe Sorting (Exercise 02)
```cpp
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>

template <typename Container>
class PmergeMe {
private:
    static void insertionSort(Container& container, size_t left, size_t right) {
        for (size_t i = left + 1; i <= right; ++i) {
            typename Container::value_type key = container[i];
            size_t j = i;
            while (j > left && container[j - 1] > key) {
                container[j] = container[j - 1];
                --j;
            }
            container[j] = key;
        }
    }
    
    static void merge(Container& container, size_t left, size_t mid, size_t right) {
        Container leftPart(container.begin() + left, container.begin() + mid + 1);
        Container rightPart(container.begin() + mid + 1, container.begin() + right + 1);
        
        size_t i = 0, j = 0, k = left;
        
        while (i < leftPart.size() && j < rightPart.size()) {
            if (leftPart[i] <= rightPart[j]) {
                container[k++] = leftPart[i++];
            } else {
                container[k++] = rightPart[j++];
            }
        }
        
        while (i < leftPart.size()) {
            container[k++] = leftPart[i++];
        }
        
        while (j < rightPart.size()) {
            container[k++] = rightPart[j++];
        }
    }
    
    static void fordJohnsonSort(Container& container, size_t left, size_t right) {
        if (right - left < 10) {
            insertionSort(container, left, right);
            return;
        }
        
        size_t mid = left + (right - left) / 2;
        fordJohnsonSort(container, left, mid);
        fordJohnsonSort(container, mid + 1, right);
        merge(container, left, mid, right);
    }

public:
    static double sort(Container& container) {
        if (container.empty()) return 0.0;
        
        clock_t start = clock();
        fordJohnsonSort(container, 0, container.size() - 1);
        clock_t end = clock();
        
        return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // microseconds
    }
};

// Usage
int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive integers...>" << std::endl;
        return 1;
    }
    
    std::vector<int> vec;
    std::deque<int> deq;
    
    // Parse input
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: Only positive integers allowed" << std::endl;
            return 1;
        }
        vec.push_back(num);
        deq.push_back(num);
    }
    
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    
    // Sort with vector
    double vecTime = PmergeMe<std::vector<int> >::sort(vec);
    
    // Sort with deque
    double deqTime = PmergeMe<std::deque<int> >::sort(deq);
    
    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector: " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque:  " << deqTime << " us" << std::endl;
    
    return 0;
}
```

## Advanced STL Patterns

### Container Selection Strategy
```cpp
// Choose container based on usage patterns
template <typename T, typename Access>
struct ContainerSelector;

template <typename T>
struct ContainerSelector<T, RandomAccess> {
    typedef std::vector<T> type;
};

template <typename T>
struct ContainerSelector<T, SequentialAccess> {
    typedef std::list<T> type;
};
```

### Algorithm Composition
```cpp
// Combine multiple STL algorithms
template <typename Container, typename Predicate, typename Transform>
void processData(Container& data, Predicate pred, Transform trans) {
    // Remove unwanted elements
    data.erase(std::remove_if(data.begin(), data.end(), pred), data.end());
    
    // Transform remaining elements
    std::transform(data.begin(), data.end(), data.begin(), trans);
    
    // Sort the results
    std::sort(data.begin(), data.end());
}
```

## Performance Considerations

- **Vector vs Deque**: Vector for random access, deque for front/back operations
- **List vs Vector**: List for frequent insertions/deletions, vector for cache efficiency
- **Set vs Unordered_set**: Set for sorted data, unordered_set for faster lookups
- **Memory Usage**: Consider memory overhead of different containers
- **Algorithm Complexity**: Understand Big O notation for STL algorithms

This final module demonstrates mastery of C++ and STL programming, preparing you for professional C++ development and complex system design.