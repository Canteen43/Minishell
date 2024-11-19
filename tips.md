# Signals

## This is from the the subject PDF
- Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
- In interactive mode:
  - ctrl-C displays a new prompt on a new line.
  - ctrl-D exits the shell.
  - ctrl-\ does nothing.

## Explanation
- Basically, these keyboard combinations will send signals to our program.
- Ctrl-C sends SIGINT.
- Ctrl-\ sends SIGQUIT.
- Ctrl-D sends EOF.
- (EOF is not a SIGNAL. It is a special condition. function like readline will return differently when the receive EOF).
- We won't modify what the keys do or sent. What we have to modify is how our program (minishell) behaves when it receives those signals.
- Also, the terminal seems to only send signals to the current foreground process. When our shell runs another program, that program becomes the fore ground process.
- That means that we won't have to handle what signals do will other processes are running. We only have to handle signals when are Minishell is "idle". By that I mean, that it is displaying a prompt and not running a command.
- So our Minishell has to:
  - ignore SIGQUIT   
    - easy
  - close when receiving EOF
    - doable
  - display a new line when receiving SIGINT and dump anything it has read so far
    - seems trickiest


# Allowed Function Reference by Header File

This document lists the allowed functions grouped by their respective headers. Each function is accompanied by its prototype and a brief explanation.

## `<unistd.h>`
- **`char *getcwd(char buf[.size], size_t size);`**  
  Returns the absolute pathname as a string `stdout`.
  On my home-ubuntu `getcwd(NULL, 0)` worked and returned a string that contains the absolute path. After changing the directory with chdir(), getcwd() returned another path. The string has to be freed.
- **`int chdir(const char *path);`**  
  Path is the directory we want to go to. Returns 0 on success and -1 on failure.

## `<stdlib.h>`
- **`void exit(int status);`**  
  Process is terminated and int is returned to parent.