# get_next_line

A function that reads and returns lines from file descriptors, one line at a time.

## Description

This project implements a function that reads from a file descriptor and returns each line sequentially, handling multiple file descriptors simultaneously and managing memory efficiently.

## Files

### Mandatory Part
- [`get_next_line.h`](get_next_line.h) - Header file with function prototypes
- [`get_next_line.c`](get_next_line.c) - Main get_next_line implementation
- [`get_next_line_utils.c`](get_next_line_utils.c) - Utility functions

### Bonus Part
- [`get_next_line_bonus.h`](get_next_line_bonus.h) - Bonus header with multiple FD support
- [`get_next_line_bonus.c`](get_next_line_bonus.c) - Bonus implementation
- [`get_next_line_utils_bonus.c`](get_next_line_utils_bonus.c) - Bonus utility functions

## Function Prototype

```c
char *get_next_line(int fd);
```

## Features

- Reads one line at a time from any file descriptor
- Handles multiple file descriptors simultaneously (bonus)
- Efficient memory management
- Configurable buffer size via BUFFER_SIZE macro
- Works with files, standard input, and network connections

## Usage

```c
#include "get_next_line.h"

int main() {
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## Compilation

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```