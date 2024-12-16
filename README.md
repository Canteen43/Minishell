# Minishell

Minishell is a simple shell implementation project for the 42 School curriculum. The goal is to replicate core functionalities of a Unix shell while adhering to strict coding standards and deepening our understanding of low-level programming in C.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Supported Builtins](#supported-builtins)
- [Error Handling](#error-handling)
- [Code Structure](#code-structure)
- [Challenges](#challenges)
- [Future Improvements](#future-improvements)
- [Acknowledgements](#acknowledgements)

---

## Overview

Minishell is a project where we develop a functional, interactive shell program from scratch. This exercise focuses on understanding the inner workings of shell behavior, system calls, and process management while maintaining strict adherence to the 42 coding norms.

Key learning objectives include:
- Mastering process creation and management using `fork`, `exec`, and `wait`.
- Understanding and implementing signal handling.
- Managing memory efficiently and preventing leaks.
- Building a garbage collector for effective resource management.
- Handling pipes and redirections to allow complex command execution.

---

## Features

- **Prompt display**: A custom prompt to interact with the user.
- **Command execution**: Support for executing system commands with absolute paths and `$PATH` resolution.
- **Environment variables**: Access and manipulate environment variables using `env` and `export`.
- **Built-in commands**: Implement core built-in shell commands.
- **Redirections**: Handle input and output redirections (`>`, `<`, `>>`).
- **Pipes**: Support for pipes (`|`) to chain commands.
- **Signal handling**: Gracefully manage signals like `Ctrl+C`, `Ctrl+D`, and `Ctrl+\`.
- **Error handling**: Detect and display appropriate error messages for invalid inputs or operations.
- **Memory management**: Use of a custom garbage collector to ensure no memory leaks.

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/minishell.git
   cd minishell
   ```

2. Build the project:
   ```bash
   make
   ```

3. Run Minishell:
   ```bash
   ./minishell
   ```

---

## Usage

Start Minishell by running the binary. You will see a custom prompt where you can type commands as you would in a regular Unix shell.

```bash
minishell > ls -la
minishell > echo "Hello, World!"
minishell > export MYVAR=42
minishell > echo $MYVAR
```

To exit the shell, type `exit`.

---

## Supported Builtins

The following built-in commands are supported:

- `echo`: Print arguments to the terminal.
- `cd`: Change the current directory.
- `pwd`: Print the current working directory.
- `export`: Set environment variables.
- `unset`: Unset environment variables.
- `env`: Display all environment variables.
- `exit`: Exit the shell.

---

## Error Handling

Minishell handles errors gracefully, providing feedback without crashing. Common error scenarios include:

- Command not found.
- Invalid file or directory for redirections.
- Syntax errors in pipes or redirections.
- Exceeding resource limits (e.g., maximum number of open file descriptors).

---

## Code Structure

The project is organized into modular components for clarity:

- **main.c**: Entry point for the shell.
- **parsing/**: Functions to parse user input and build command structures.
- **execution/**: Handles execution of commands, built-ins, pipes, and redirections.
- **signals/**: Manages signal behavior for a smooth user experience.
- **memory/**: Implements custom garbage collection to manage allocated resources.
- **utils/**: Helper functions for common tasks like string manipulation and error handling.

---

## Challenges

1. **Pipes and Redirections**:
   Implementing multiple pipes and handling complex redirection cases was challenging due to the reliance on low-level system calls.

2. **Signal Handling**:
   Ensuring the shell responds appropriately to signals without interfering with user input or ongoing processes required careful signal masking and restoration.

3. **Memory Management**:
   Avoiding memory leaks while dynamically allocating resources involved building a custom garbage collector tailored to Minishell's architecture.

---

## Future Improvements

- Add support for advanced shell features like wildcard expansion (`*`), subshells, and logical operators (`&&`, `||`).
- Enhance the parser to support more complex input scenarios.
- Improve error messages for better user feedback.
- Optimize memory usage for handling very large commands or pipelines.

---

## Acknowledgements

This project was developed as part of the 42 School curriculum. Special thanks to peers and instructors who provided feedback and guidance throughout the development process.

---

Minishell demonstrates the power and complexity of building a shell from scratch. It’s a foundational project that strengthens understanding of system programming and provides a solid base for more advanced projects. Happy coding!

