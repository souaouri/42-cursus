# Pipex

A program that simulates the shell pipe mechanism, reproducing the behavior of shell pipes in C.

## Description

This project recreates the functionality of shell pipes, allowing you to execute two commands where the output of the first command becomes the input of the second command, just like the Unix pipe operator `|`.

## Functionality

The program mimics the following shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

Which is equivalent to:
```bash
./pipex file1 cmd1 cmd2 file2
```

## Features

- File redirection (input and output)
- Command execution with arguments
- Pipe creation and management
- Process forking and synchronization
- Error handling for various edge cases
- PATH environment variable support

## Usage

```bash
make
./pipex infile "command1" "command2" outfile
```

### Example
```bash
# Equivalent to: < input.txt grep "hello" | wc -l > output.txt
./pipex input.txt "grep hello" "wc -l" output.txt

# Equivalent to: < /etc/passwd cut -d: -f1 | sort > users.txt
./pipex /etc/passwd "cut -d: -f1" "sort" users.txt
```

## Implementation Details

- Uses `fork()` to create child processes
- Uses `pipe()` to create communication channels
- Uses `dup2()` for file descriptor redirection
- Uses `execve()` to execute commands
- Handles PATH resolution for command lookup
- Proper error handling and cleanup

## Error Handling

The program handles various error conditions:
- Invalid file permissions
- Non-existent commands
- Invalid arguments
- System call failures

## Building

```bash
make        # Build the program
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Rebuild everything
```