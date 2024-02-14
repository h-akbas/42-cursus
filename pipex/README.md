# File I/O Functions in C

## `open` Function
- **Purpose:** Used to open a file or create a new one.
- **Usage:** `int open(const char *pathname, int flags);`
- **Explanation:** Opens a file identified by `pathname` with the specified `flags`, indicating various operations like read-only, write-only, or read-write access.

## `close` Function
- **Purpose:** Closes a file descriptor.
- **Usage:** `int close(int fd);`
- **Explanation:** Closes the file descriptor `fd` to free up system resources and ensure proper handling.

## `read` Function
- **Purpose:** Reads data from a file descriptor into a buffer.
- **Usage:** `ssize_t read(int fd, void *buf, size_t count);`
- **Explanation:** Reads up to `count` bytes from the file descriptor `fd` into the buffer pointed to by `buf`.

## `write` Function
- **Purpose:** Writes data to a file descriptor from a buffer.
- **Usage:** `ssize_t write(int fd, const void *buf, size_t count);`
- **Explanation:** Writes up to `count` bytes from the buffer pointed to by `buf` to the file descriptor `fd`.

# Error Handling and Program Termination Functions in C

## `perror` Function
- **Purpose:** Prints a description for the last error that occurred.
- **Usage:** `void perror(const char *s);`
- **Explanation:** Prints a user-defined string `s` followed by a colon and a space, along with the corresponding error message based on the global variable `errno`.

## `strerror` Function
- **Purpose:** Returns a string describing the error code.
- **Usage:** `char *strerror(int errnum);`
- **Explanation:** Returns a pointer to the corresponding error message string for the given error number.

## `exit` Function
- **Purpose:** Terminates the program.
- **Usage:** `void exit(int status);`
- **Explanation:** Terminates the program and returns the status code to the operating system.

## `access` Function
- **Purpose:** Checks if a file can be accessed with the specified mode.
- **Usage:** `int access(const char *pathname, int mode);`
- **Explanation:** Checks whether the file specified by `pathname` can be accessed using the specified `mode`.

# Process Management Functions in C

## `fork` Function
- **Purpose:** Creates a new process by duplicating the calling process.
- **Usage:** `pid_t fork(void);`
- **Explanation:** Creates a new process (child) that is a copy of the calling process (parent).

## `pipe` Function
- **Purpose:** Creates a unidirectional communication channel (pipe) between two processes.
- **Usage:** `int pipe(int pipefd[2]);`
- **Explanation:** Creates a pipe, and the file descriptors for the read and write ends are stored in the `pipefd` array.

## `unlink` Function
- **Purpose:** Deletes a file name and decrements the link count of the associated file.
- **Usage:** `int unlink(const char *pathname);`
- **Explanation:** Removes the specified file name, and if it was the last link to the associated file, the file itself is deleted.

## `wait` Function
- **Purpose:** Waits for any child process to terminate and retrieves its termination status.
- **Usage:** `pid_t wait(int *status);`
- **Explanation:** Suspends the calling process until any of its child processes terminate and retrieves the termination status.

## `waitpid` Function
- **Purpose:** Waits for a specific child process to terminate and retrieves its termination status.
- **Usage:** `pid_t waitpid(pid_t pid, int *status, int options);`
- **Explanation:** Similar to `wait` but allows you to specify which child process to wait for using the `pid` parameter.

These functions are crucial for managing processes, communication between them, and handling file operations in C programs.
