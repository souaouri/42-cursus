# Libft

A custom C library containing implementations of standard library functions and additional utility functions.

## Description

This project creates a personal library of useful C functions that will be used throughout the 42 curriculum. It includes recreations of standard library functions and additional utility functions for string manipulation, memory management, and linked lists.

## Categories

### Standard Library Functions
- **String functions**: `ft_strlen`, `ft_strcpy`, `ft_strdup`, `ft_strcmp`, etc.
- **Memory functions**: `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memcmp`, etc.
- **Character functions**: `ft_isalpha`, `ft_isdigit`, `ft_toupper`, `ft_tolower`, etc.
- **Conversion functions**: `ft_atoi`, `ft_itoa`

### Additional Functions
- **String utilities**: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
- **File I/O**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Bonus: Linked List Functions
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`
- `ft_lstsize`, `ft_lstlast`
- `ft_lstdelone`, `ft_lstclear`
- `ft_lstiter`, `ft_lstmap`

## Usage

Include the library in your project:

```c
#include "libft.h"
```

## Building

```bash
make        # Build mandatory functions
make bonus  # Build with bonus functions
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Rebuild everything
```

This will generate `libft.a` which can be linked to your projects.