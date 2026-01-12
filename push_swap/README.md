# push_swap

An efficient sorting algorithm implementation using two stacks and a limited set of operations.

## Description

This project challenges you to sort integers using two stacks (A and B) with a restricted set of operations. The goal is to sort the numbers in stack A in ascending order using the minimum number of operations possible.

## Available Operations

### Push Operations
- `pa` - Push the top element from stack B to stack A
- `pb` - Push the top element from stack A to stack B

### Swap Operations
- `sa` - Swap the top two elements of stack A
- `sb` - Swap the top two elements of stack B
- `ss` - Perform `sa` and `sb` simultaneously

### Rotate Operations
- `ra` - Rotate stack A upward (first element becomes last)
- `rb` - Rotate stack B upward (first element becomes last)
- `rr` - Perform `ra` and `rb` simultaneously

### Reverse Rotate Operations
- `rra` - Rotate stack A downward (last element becomes first)
- `rrb` - Rotate stack B downward (last element becomes first)
- `rrr` - Perform `rra` and `rrb` simultaneously

## Usage

```bash
make
./push_swap [list of integers]
```

### Examples
```bash
./push_swap 4 67 3 87 23        # Sort these 5 numbers
./push_swap 2 1 3 6 5 8         # Sort these 6 numbers
./push_swap "4 67 3 87 23"      # Alternative format with quotes
```

## Checker (Bonus)

The project includes a checker program to validate the sorting:

```bash
make bonus
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

## Algorithm Optimization

The challenge is to minimize the number of operations:
- 3 numbers: maximum 3 operations
- 5 numbers: maximum 12 operations
- 100 numbers: less than 700 operations for top grade
- 500 numbers: less than 5500 operations for top grade

## Features

- Input validation and error handling
- Efficient sorting algorithms
- Operation optimization
- Duplicate detection
- Integer overflow protection

## Building

```bash
make        # Build push_swap
make bonus  # Build checker
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Rebuild everything
```