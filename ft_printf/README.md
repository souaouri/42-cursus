# ft_printf

A custom implementation of the printf function from the C standard library.

## Description

This project recreates the behavior of the standard printf function, handling various format specifiers and providing formatted output capabilities.

## Files

- [`ft_printf.h`](ft_printf.h) - Header file with function prototypes
- [`ft_printf.c`](ft_printf.c) - Main printf implementation
- [`print_character.c`](print_character.c) - Character printing functions
- [`print_digit.c`](print_digit.c) - Integer printing functions
- [`print_format.c`](print_format.c) - Format specifier handling
- [`print_hex_lower.c`](print_hex_lower.c) - Lowercase hexadecimal printing
- [`print_hex_upper.c`](print_hex_upper.c) - Uppercase hexadecimal printing
- [`print_string.c`](print_string.c) - String printing functions
- [`print_unsigned_int.c`](print_unsigned_int.c) - Unsigned integer printing
- [`Makefile`](Makefile) - Build configuration

## Supported Format Specifiers

- `%c` - Character
- `%s` - String
- `%d` - Signed decimal integer
- `%i` - Signed decimal integer
- `%u` - Unsigned decimal integer
- `%x` - Lowercase hexadecimal
- `%X` - Uppercase hexadecimal
- `%p` - Pointer address
- `%%` - Literal percent sign

## Usage

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello %s! Number: %d\n", "World", 42);
    return 0;
}
```

## Building

```bash
make
```