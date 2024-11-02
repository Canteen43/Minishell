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


# Allowed Functions

This document lists the allowed functions grouped by their respective headers. Each function is accompanied by its prototype and a brief explanation of its purpose.

## Header: <readline/readline.h>

### `char *readline(const char *prompt);`
Prompts the user for input, displaying the specified prompt, and returns a dynamically allocated string containing the input.

### `void rl_clear_history(void);`
Clears the command history maintained by the readline library.

### `void rl_on_new_line(void);`
Indicates that a new line has been started, allowing readline to manage line editing properly.

### `void rl_replace_line(const char *text, int clear_undo);`
Replaces the current line with the specified text. If `clear_undo` is non-zero, it clears the undo history for the line.

### `void rl_redisplay(void);`
Redraws the current command line in the readline interface.

### `int add_history(const char *line);`
Adds a specified line to the history list maintained by readline.

## Header: <stdio.h>

### `int printf(const char *format, ...);`
Formats and prints data to the standard output stream, allowing for various types of formatted output.

## Header: <stdlib.h>

### `void *malloc(size_t size);`
Allocates a specified number of bytes and returns a pointer to the allocated memory. Returns `NULL` if allocation fails.

### `void free(void *ptr);`
Deallocates memory previously allocated by `malloc`, `calloc`, or `realloc`.

## Header: <unistd.h>

### `ssize_t write(int fd, const void *buf, size_t count);`
Writes up to `count` bytes from the buffer pointed to by `buf` to the file descriptor `fd`.

### `int access(const char *pathname, int mode);`
Checks the calling process's ability to access a file specified by `pathname` with given permissions (`mode`).

### `int open(const char *pathname, int flags, mode_t mode);`
Opens a file and returns a file descriptor. The flags parameter determines how the file is opened.

### `ssize_t read(int fd, void *buf, size_t count);`
Reads up to `count` bytes from the file descriptor `fd` into the buffer pointed to by `buf`.

### `int close(int fd);`
Closes a file descriptor, releasing any resources associated with it.

## Header: <sys/types.h> and <sys/wait.h>

### `pid_t fork(void);`
Creates a new process by duplicating the calling process. Returns the child's PID to the parent and 0 to the child.

### `int wait(int *status);`
Waits for state changes in a child process and retrieves its exit status.

### `pid_t waitpid(pid_t pid, int *status, int options);`
Waits for a specific child process (specified by `pid`) to change state and retrieves its exit status.

### `int wait3(int *status, int options, struct rusage *rusage);`
Waits for any child process to change state and retrieves its exit status along with resource usage information.

### `int wait4(pid_t pid, int *status, int options, struct rusage *rusage);`
Waits for a specific child process and retrieves both its exit status and resource usage information.

## Header: <signal.h>

### `void signal(int signum, void (*handler)(int));`
Sets up a signal handler for the specified signal number (`signum`).

### `int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);`
Examines or changes the action associated with a specific signal number (`signum`).

### `int sigemptyset(sigset_t *set);`
Initializes an empty signal set pointed to by `set`.

### `int sigaddset(sigset_t *set, int signum);`
Adds a signal number (`signum`) to the signal set pointed to by `set`.

### `int kill(pid_t pid, int sig);`
Sends a signal (`sig`) to a specified process (`pid`).

### `void exit(int status);`
Terminates the calling process with an exit status code.

## Header: <unistd.h> (for directory operations)

### `char *getcwd(char *buf, size_t size);`
Gets the current working directory and stores it in the buffer pointed to by `buf`.

### `int chdir(const char *path);`
Changes the current working directory of the calling process to the directory specified by `path`.

## Header: <sys/stat.h>

### `int stat(const char *pathname, struct stat *statbuf);`
Retrieves information about a file specified by pathname and fills in a stat structure with this information.

### `int lstat(const char *pathname, struct stat *statbuf);`
Similar to stat but does not follow symbolic links; it retrieves information about the link itself.

### `int fstat(int fd, struct stat *statbuf);`
Retrieves information about an open file referred to by file descriptor (`fd`) and fills in a stat structure with this information.

## Header: <unistd.h> (for file operations)

### `int unlink(const char *pathname);`
Removes (deletes) a name from the filesystem; if it is the last link to a file and no processes have it open, then it is deleted.

## Header: <sys/types.h> (for exec functions)

### `int execve(const char *filename, char *const argv[], char *const envp[]);`
Executes a program specified by filename with arguments and environment variables provided in argv and envp.

## Header: <unistd.h> (for descriptor operations)

### `int dup(int oldfd);`
Duplicates an existing file descriptor (`oldfd`) and returns a new file descriptor that refers to the same open file description.

### `int dup2(int oldfd, int newfd);`
Duplicates an existing file descriptor (`oldfd`) into another file descriptor (`newfd`), closing newfd if it was open.

## Header: <fcntl.h>

### `int pipe(int pipefd[2]);`
Creates a pair of connected file descriptors (a pipe), which can be used for inter-process communication.

## Header: <dirent.h>

### `DIR *opendir(const char *name);`
Opens a directory stream corresponding to the directory name provided and returns a pointer to it.

### `struct dirent *readdir(DIR *dirp);`
Reads an entry from a directory stream pointed to by dirp and returns it as a pointer to struct dirent.

### `int closedir(DIR *dirp);`
Closes a directory stream opened by opendir.

## Header: <string.h>

### `char *strerror(int errnum);`
Returns a pointer to the textual representation of an error code (`errnum`).

## Header: <stdio.h> (for error handling)

### `void perror(const char *s);`
Prints an error message based on the current value of errno along with an optional custom message provided in s.

## Header: <unistd.h> (for terminal handling)

### `int isatty(int fd);`
Tests whether a given file descriptor refers to a terminal device.

### `char *ttyname(int fd);`
Returns the name of the terminal associated with a given file descriptor (`fd`).

### `int ttyslot(void);`
Returns the slot number of the terminal associated with standard input (stdin).

## Header: <termios.h>

### `int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);`
Sets parameters associated with terminal control for an open terminal referred by fd.

### `int tcgetattr(int fd, struct termios *termios_p);`
Gets parameters associated with terminal control for an open terminal referred by fd.

## Header: <termcap.h>

### `int tgetent(char *bp, const char *name);`
Initializes terminal capability information from database entries based on terminal name provided in name.

### `int tgetflag(const char *id);`
Returns 1 if capability exists; otherwise returns 0 based on capability identifier id provided as input.

### `int tgetnum(const char *id);`
Returns numeric capability value based on capability identifier id provided as input; returns -1 if not found.

### `char* tgetstr(const char* id, char** area);`
Retrieves string capability based on capability identifier id; stores result in area if provided.

### `char* tgoto(const char* cap, int col, int row);`
Constructs cursor addressing string based on capability string cap along with column col and row row values provided as input.

### `int tputs(const char* str, int affcnt, int (*outc)(int));`
Outputs string str using outc function for character output; affcnt indicates how many times this string should be output.
