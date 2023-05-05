# 🃏MiniShell :

**                    **The objective of this project is for you to create a simple shell !!**

**With Minishell, you'll be able to travel through time and come back to problems people faced when Windows didn't exist.**

- ***`what is minishell ?`***
    
    *A minishell is a small-scale implementation of a command-line shell, written in C . It provides a basic set of shell functionalities such as executing commands, managing processes, and manipulating files and directories. Unlike a full-fledged Unix shell like bash, zsh or fish, a minishell does not have all the advanced features such as scripting, command substitution, and complex configuration options.*
    
    *A minishell typically implements a subset of the Unix shell syntax and commands. It provides a command prompt where the user can type commands, which are then parsed and executed by the minishell. The basic workflow of a minishell involves reading user input, parsing the input to identify the command and its arguments, and then executing the command using one of the **`exec()`** family of functions.*
    
    *A minishell also typically provides some basic built-in commands such as **`cd`**, **`exit`**, and **`echo`**, which are implemented directly in the minishell code rather than being separate programs. Additionally, a minishell may implement basic features such as command history, job control, and command line editing.*
    
    *Overall, a minishell provides a lightweight and simplified version of a Unix shell that can be useful for learning programming or for situations where a full-featured shell is not needed*
    
- ***`what is shell ?`***
    
    *A shell is a type of computer program called a command-line interpreter that lets Linux and Unix users control their operating systems with command-line interfaces. Shells allow users to communicate efficiently and directly with their operating systems*
    
- ***`available functions :`***
    - 📋 functions :
        - ***The GNU Readline Library “*`readline/readline.h”`**
            - $**readline$ :**  *read a line from the terminal and return it / Receives a string, stores it, and returns a memory address, Since it is allocated by malloc, it must be freed.*
            
            ```c
            #include <readline/readline.h>
            
            char *readline(const char *str)
            ```
            
            - ***rl_clear_history** : When you use the **`readline`** function to read input from the user, the library automatically maintains a history of previous commands entered by the user. The **`rl_clear_history`** function allows you to clear this history so that previous commands will no longer be available for recall.*
            
            ```c
            #include <readline/history.h>
            
             void rl_clear_history(void);
            ```
            
            - ***rl_on_new_line*** : *When you use the **`readline`** function to read input from the user, the library automatically handles moving the cursor to the next line when the user presses enter to submit their input. However, in some cases, you may want to explicitly move to a new line before displaying the next prompt. This is where the **`rl_on_new_line`**
             function comes in*
            
            ```c
            int		 rl_on_new_line(void);
            ```
            
            - ***rl_replace_line*** : When you use the **`readline`** function to read input from the user, the library stores the input as a string in a buffer. The **`rl_replace_line`**  function allows you to replace this buffer with a new string.
            
            ```c
            void		 rl_replace_line(char *str, int clear_undo);
            ```
            
            *The first argument **`text`** is a pointer to the new string you want to replace the current input line with.*
            
             *The second argument **`clear_undo`** is a flag that tells the library whether or not to clear the undo history for the current line.*
            
            > *If you set **`clear_undo`** to a non-zero value, the library will clear the undo history for the current line. This means that the user won't be able to use the **`Ctrl+_`**
             or **`Ctrl+U`** key combinations to undo changes to the current line.*
            > 
            
            <aside>
            💡 *`Ctrl+_ and Ctrl+U are keyboard shortcuts that are often used in Unix-like operating systems.`*
            
            *`Ctrl+_ is typically used to undo changes to the current line in a terminal emulator. When you press Ctrl+_, the terminal emulator sends the SIGQUIT signal to the current process. If the process is running the libreadline library and has enabled the undo functionality, libreadline will undo the most recent change to the current line.`*
            
            *`Ctrl+U is typically used to clear the current line in a terminal emulator. When you press Ctrl+U, the terminal emulator sends the SIGINT signal to the current process. If the process is running the libreadline library, libreadline will clear the current input line.`*
            
            *`Note that the behavior of Ctrl+_ and Ctrl+U may vary depending on the terminal emulator and the configuration of the system.`*
            
            </aside>
            
            - **rl_redisplay** : *When you call **`rl_redisplay`**, the library updates the display of the current input line to reflect any changes that have been made since the line was first displayed. This can be useful if you want to update the display of the input line without replacing the entire line using **`rl_replace_line`**.*
                
                ```c
                void		 rl_redisplay(void);
                ```
                
            - ***add_history* :** *When you call **`add_history`** , the library adds a copy of the current input line to the history list, which can be accessed later using the up and down arrow keys. This is similar to the command history feature in many shells and other command-line interfaces.*
            
            ```c
            #include <readline/history.h>
            
            add_history(const char *str)
            ```
            
            <aside>
            💡 `**To compile a program that uses the libreadline library in C, you need to include the library in the compilation command.**`
            
            `**Here's an example of how to compile a program that uses libreadline:**`
            
            ```bash
            gcc -o my_program my_program.c -lreadline
            ```
            
            `**In this example, my_program is the name of the executable file you want to create, and my_program.c is the name of the C file that contains your program code.**`
            
            `**The -lreadline flag tells the compiler to link the libreadline library to your program. When you include this flag, the compiler will look for the libreadline library and add it to the compilation command.**`
            
            `**Make sure you have installed the libreadline library on your system before trying to compile your program. If you are using a Linux-based system, you can install the library using your package manager. For example, on Ubuntu, you can install the libreadline-dev package by running:**`
            
            ```bash
            sudo apt-get install libreadline-dev
            ```
            
            `**Once you have installed the library and compiled your program with the -lreadline flag, you should be able to run the program and use the libreadline functions in your code.**`
            
            </aside>
            
        
        - ***Standard symbolic constants and types “unistd.h “***
            - $**write$ :** *function is used to write data from a buffer to a file descriptor*
            
            ```c
            #include <unistd.h>
            
            ssize_t write(int fd, const void *buf, size_t count);
            ```
            
            *The function takes three arguments:*
            
            1. ***`fd`**: The file descriptor of the file or device to which data is to be written.*
            2. ***`buf**:` A pointer to a buffer containing the data to be written.*
            3. ***`count**:` The number of bytes to write from the buffer.*
            
            *The function returns the number of bytes written on success, or **-1** on failure.*
            
            - **a$ccess$ :** *function is used to check whether a process can access a particular file or directory*
                
                ```c
                #include <unistd.h>
                
                int access(const char *pathname, int mode);
                ```
                
                *The function takes two arguments:*
                
                1. **`*pathname`**: A pointer to a string that contains the path to the file or directory to be checked.*
                2. **`*mode`**: An integer that specifies the type of access to be checked, and can take one of the following values:*
                    - **`*F_OK`**: Check for the existence of the file.*
                    - **`*R_OK`**: Check for read permission.*
                    - **`*W_OK`**: Check for write permission.*
                    - **`*X_OK`**: Check for execute permission.*
                
                *The function returns **`0`** if the access is allowed, or **`-1`** if it is not allowed or if an error occurs.*
                
            
            - $**open$ :** *function is used to open a file or create it if it does not exist.*
                
                ```c
                #include <sys/types.h>
                #include <sys/stat.h>
                #include <fcntl.h>
                
                int open(const char *pathname, int flags);
                int open(const char *pathname, int flags, mode_t mode);
                ```
                
                *The function takes two or three arguments:*
                
                1. **`*pathname`**: A pointer to a string that contains the path to the file to be opened or created.*
                2. **`*flags`**: An integer that specifies the mode in which the file is to be opened. It can be one or a combination of the following flags:*
                    - **`*O_RDONLY`**: Open the file in read-only mode.*
                    - **`*O_WRONLY`**: Open the file in write-only mode.*
                    - **`*O_RDWR`**: Open the file in read-write mode.*
                    - **`*O_APPEND`**: Append to the end of the file on each write.*
                    - **`*O_CREAT`**: Create the file if it does not exist.*
                    - **`*O_TRUNC`**: Truncate the file to zero length if it already exists.*
                    - **`*O_EXCL`**: When used with **`O_CREAT`**, ensure that the file is newly created and return an error if it already exists.*
                3. **`*mode`** (optional): An integer that specifies the permissions to be set on the file if it is created. It is only used when the **`O_CREAT`** flag is present. The value should be specified in octal notation, and can be combined with one or more of the following permission flags:*
                    - **`*S_IRUSR`**: Read permission for the owner.*
                    - **`*S_IWUSR`**: Write permission for the owner.*
                    - **`*S_IXUSR`**: Execute permission for the owner.*
                    - **`*S_IRGRP`**: Read permission for the group.*
                    - **`*S_IWGRP`**: Write permission for the group.*
                    - **`*S_IXGRP`**: Execute permission for the group.*
                    - **`*S_IROTH`**: Read permission for others.*
                    - **`*S_IWOTH`**: Write permission for others.*
                    - **`*S_IXOTH`**: Execute permission for others.*
                    
                    *The function returns a file descriptor, which is a small non-negative integer that is used to refer to the open file in subsequent operations. If an error occurs, the function returns -1*
                    
            - $**read**$ *: is a function in the C programming language that reads data from a file descriptor .*
                
                ```c
                #include <unistd.h>
                ssize_t read(int fd, void *buf, size_t count);
                ```
                
                ```c
                #include <unistd.h>
                
                ssize_t pread(int fd, void *buf, size_t count, off_t offset)
                ```
                
                **`*read`** is a function in the C programming language that reads data from a file descriptor. It takes four arguments:*
                
                1. **`*fd`**: The file descriptor from which to read.*
                2. **`*buf`**: A pointer to the buffer that will hold the data read from the file.*
                3. **`*count`**: The maximum number of bytes to read.*
                4. **`*offset`**: The offset in the file at which to start reading.*
                
                *The **`read`** function returns the number of bytes read from the file, or -1 if an error occurs. It is often used in conjunction with the **`open`** function to read data from a file.*
                
                <aside>
                💡 The **`offset`** parameter in the **`read`** function specifies the position within the file to start reading data from. This parameter is an integer value that represents the number of bytes from the beginning of the file to start reading data from.
                
                For example, if you set the **`offset`** to 0, **`read`** will start reading data from the beginning of the file. If you set the **`offset`** to 10, **`read`** will start reading data from the 11th byte of the file.
                
                Note that the **`offset`** parameter is not always used in every call to **`read`**. In many cases, you can simply pass 0 for the **`offset`** parameter to read from the current position in the file.
                
                </aside>
                
            - $**close$ :** *function is used to close an open file or socket .*
                
                ```c
                #include <unistd.h>
                
                int close(int fd);
                ```
                
                *The **`close`** function returns 0 if the file is closed successfully, and -1 if there is an error. Some common errors include passing an invalid file descriptor, or trying to close a file that is already closed.*
                
                *It's important to note that after calling the **`close`** function, the file descriptor is no longer valid and should not be used again. Attempting to read from or write to a closed file descriptor can lead to undefined behavior*
                
            
            - $*getcwd$ :*  Determines the path name of the working directory and stores it in *buffer*
                
                ```c
                #include <unistd.h>
                char *getcwd(char *buf, size_t size);
                ```
                
            
            <aside>
            💡 `***size**` : The number of characters in the buffer area.*
            
            `***buffer**` : The name of the buffer that will be used to hold the path name of the working directory. buffer must be big enough to hold the working directory name, plus a terminating NULL to mark the end of the name.*
            
            *Returned value :* 
            
            *If successful,   $getcwd()$ returns a pointer to the buffer.*
            
            *If unsuccessful,   $getcwd()$ returns a NULL pointer and sets errno to one of the following values:*
            
            *Error CodeDescription :* 
            
            `*EACCES` : The process did not have read or search permission on some component of the working directory's path name.*
            
            `*EINVAL` : size is less than or equal to zero.*
            
            `*EIO` : An input/output error occurred.*
            
            `*ENOENT` :A component of the working directory's path name does not exist.*
            
            `*ENOTDIR` : A directory component of the working directory's path name is not really a directory.*
            
            `*ERANGE` : size is greater than 0, but less than the length of the working directory's path name, plus 1 for the terminating NULL*
            
            </aside>
            
            - $**chdir$ :** *is used to change the current working directory of the program or process by passing the path to the function as shown in the syntax.*
                
                ```c
                #include <unistd.h>
                
                int chdir(const char *pathname);
                ```
                
                <aside>
                💡 *If successful, chdir() changes the working directory and returns 0.*
                
                *If unsuccessful, chdir() does not change the working directory, returns -1, and sets errno to one of the following values:*
                
                *Error CodeDescription :* 
                
                *`EACCES` : The process does not have search permission on one of the components of pathname.*
                
                *`ELOOP` : A loop exists in symbolic links. This error is issued if the number of symbolic links detected in the resolution of pathname is greater than `POSIX_SYMLOOP` (a value defined in the limits.h header file).*
                
                *`ENAMETOOLONG` : pathname is longer than PATH_MAX characters, or some component of pathname is longer than NAME_MAX characters while _POSIX_NO_TRUNC is in effect. For symbolic links, the length of the pathname string substituted for a symbolic link exceeds PATH_MAX. The PATH_MAX and NAME_MAX values are determined using pathconf().*
                
                *`ENOENT` : pathname is an empty string, or the specified directory does not exist.*
                
                *`ENOTDIR` : Some component of pathname is not a directory.*
                
                </aside>
                
            
            - $**execve$ :**
                
                
            - $**dup$ , $dup2$  , $pipe$  ,** $wait$ , $waitpid$   ****$`fork$ :`
            
            [pipex :](https://www.notion.so/pipex-f3f377eedb644f1a805c6f479d7576c0)
            
            - $ioctl :$ *function can be used to manipulate various device parameters, such as terminal settings or network interfaces, using an ioctl request code and any required arguments. The exact ioctl request codes and arguments depend on the specific device being manipulated.*
                
                
                ```c
                int ioctl(int fd, unsigned long request, ...);
                ```
                
            
            **`fd`** is an integer file descriptor that refers to the device being operated on. 
            
            **`request`** is an unsigned long integer that specifies the particular operation to be performed, 
            
             **`...`** indicates that there may be additional arguments depending on the specific request being made.
            
            <aside>
            💡 `Note that the **ioctl** function is often device-specific and can have many different possible values for **request**, each with their own specific argument requirements and effects. It is important to consult the documentation for the particular device being used in order to determine the appropriate values for **request** and any required arguments.`
            
            </aside>
            
            - $ttyslot$ : *function is used to obtain the index of the user's terminal in the system's terminal table. The index number is used as an identifier for the terminal in other terminal-related functions.*
                
                ```c
                int ttyslot(void);
                ```
                
                - The function takes no arguments.
                - It determines the terminal device associated with the user's login session.
                - It looks up the device in the system's terminal table.
                - It returns the index of the device in the table.
                
                The index returned by **`ttyslot`** is used by other terminal-related functions to retrieve information about the terminal, such as its capabilities, or to send output sequences to the terminal.
                
                <aside>
                💡 However, note that **`ttyslot`** is a legacy function and its use is discouraged in modern programming. In most cases, it is better to use other methods, such as the **`TERM`** environment variable or the **`getenv`** function, to obtain information about the user's terminal.
                
                </aside>
                
            - $ttyname$ : *function is used to obtain the name of the terminal device associated with a given file descriptor.*
                
                ```c
                char *ttyname(int fd);
                ```
                
                The **`ttyname`** function takes an integer file descriptor **`fd`** as its argument and returns a pointer to a string containing the name of the terminal device associated with that file descriptor. If **`fd`** is not a valid file descriptor or is not associated with a terminal device, the function returns a null pointer.
                
                The **`ttyname`** function is typically used to determine the name of the terminal device associated with standard input, output, or error streams, which have file descriptors 0, 1, and 2, respectively. The name of the terminal device can be useful for various purposes, such as for sending output sequences or for determining the terminal's capabilities.
                
                <aside>
                💡 Note that the **`ttyname`** function is not thread-safe and may return different results if called simultaneously from multiple threads. It is also not available on all platforms
                
                </aside>
                
            
            - $isatty$ :*function is used to determine whether a given file descriptor refers to a terminal device.*
                
                ```c
                int isatty(int fd);
                ```
                
                The **`isatty`** function takes an integer file descriptor **`fd`** as its argument and returns a non-zero integer value if the file descriptor refers to a terminal device, or zero if it does not.
                
                The **`isatty`** function is often used to test whether standard input, output, or error streams (which have file descriptors 0, 1, and 2, respectively) are associated with terminal devices. If the function returns a non-zero value, it indicates that the corresponding stream is a terminal device and can be used for interactive I/O operations.
                
                <aside>
                💡 Note that the **`isatty`** function is not guaranteed to work for all types of file descriptors or on all platforms, and its use is not recommended in portable programs. It is often better to use other methods, such as the **`fstat`** function, to obtain information about a file descriptor.
                
                </aside>
                
            - $*wait3 :$ function is a legacy system call used to wait for a child process to terminate and obtain information about its status.*
                
                ```c
                pid_t wait3(int *status, int options, struct rusage *rusage);
                ```
                
                The **`wait3`** function takes three arguments:
                
                - **`status`**: a pointer to an integer variable where the function will store information about the status of the terminated child process.
                - **`options`**: an integer bitmask specifying various options for the **`wait3`** function. This argument is rarely used in modern programming, and its value is typically set to 0.
                - **`rusage`**: a pointer to a **`struct rusage`** variable where the function will store resource usage information about the terminated child process. This argument is also rarely used in modern programming, and its value is typically set to **`NULL`**.
                
                The **`wait3`** function returns the process ID of the terminated child process, or -1 if an error occurs.
                
                <aside>
                💡 Note that the **`wait3`** function is a legacy system call and its use is discouraged in modern programming. It has been superseded by the **`waitpid`** function, which provides similar functionality in a more flexible and portable way.
                
                </aside>
                
            
            - $wait4 :$  *function is a legacy system call used to wait for a specific child process to terminate and obtain information about its status.*
                
                
                ```c
                **pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);**
                ```
                
            
            he **`wait4`** function takes four arguments:
            
            - **`pid`**: the process ID of the child process to wait for. If **`pid`** is -1, the function waits for any child process to terminate.
            - **`status`**: a pointer to an integer variable where the function will store information about the status of the terminated child process.
            - **`options`**: an integer bitmask specifying various options for the **`wait4`** function. This argument is rarely used in modern programming, and its value is typically set to 0.
            - **`rusage`**: a pointer to a **`struct rusage`** variable where the function will store resource usage information about the terminated child process. This argument is also rarely used in modern programming, and its value is typically set to **`NULL`**.
            
            The **`wait4`** function returns the process ID of the terminated child process, or -1 if an error occurs.
            
            <aside>
            💡 *Note that the **`wait4`** function is a legacy system call and its use is discouraged in modern programming. It has been superseded by the **`waitpid`** function, which provides similar functionality in a more flexible and portable way.*
            
            </aside>
            
            ***The main difference between the `wait3` and `wait4` functions in C programming is that `wait3` waits for any child process to terminate, while `wait4` waits for a specific child process to terminate.***
            
            ***The `wait3` function takes no arguments specifying which child process to wait for. It simply waits for any child process to terminate and returns information about its status. In contrast, the `wait4` function takes a `pid` argument that specifies the process ID of the child process to wait for. If `pid` is -1, `wait4` behaves like `wait3` and waits for any child process to terminate.***
            
            ***Another difference is that the `wait4` function takes an additional `options` argument that can be used to specify various options for the function. This argument is rarely used in modern programming, and its value is typically set to 0.***
            
        
        - ***Standard Library Header “stdlib.h”***
            - $**malloc :$** unction is used to dynamically allocate memory at runtime.
                
                ```c
                void *malloc(size_t size);
                ```
                
                The **`malloc`** function takes one argument:
                
                - **`size`**: an unsigned integer value that specifies the size in bytes of the memory block to allocate.
                
                The **`malloc`** function returns a pointer to the first byte of the allocated memory block, or a **`NULL`** pointer if the allocation fails.
                
                The allocated memory block is not initialized and may contain arbitrary values. To initialize the memory block to a specific value, you can use the **`memset`** function, which is also part of the **`string.h`** library.
                
            
            <aside>
            💡 It's important to note that the memory allocated with **`malloc`**
             should be freed when it is no longer needed to avoid memory leaks. This can be done with the **`free`**
             function, which takes a pointer to the memory block as its argument.
            
            </aside>
            
            - $**free$ :** function is used to deallocate memory that was previously allocated with the **`malloc`**
            , **`calloc`** , or **`realloc`**  functions
                
                
                ```c
                void free(void *ptr);
                ```
                
                The **`free`** function takes one argument:
                
                - **`ptr`**: a pointer to the memory block to deallocate.
                
                The **`free`** function does not return a value.
                
                It's important to note that the pointer passed to **`free`** must point to a valid memory block that was previously allocated with **`malloc`**, **`calloc`**, or **`realloc`**. If the pointer is invalid, or if the memory block has already been deallocated, the behavior of the **`free`** function is undefined and may lead to errors or crashes.
                
                <aside>
                💡 In addition, it's a good practice to set the pointer to **`NULL`**
                 after calling **`free`**
                 to avoid using a dangling pointer. This can help to prevent bugs and memory errors in your program.
                
                </aside>
                
            - $**getenv :$** *function is used to retrieve the value of an environment variable*
                
                ```c
                char *getenv(const char *name);
                ```
                
                The **`getenv`** function takes one argument:
                
                - **`name`**: a null-terminated string that specifies the name of the environment variable to retrieve.
                
                The **`getenv`** function returns a pointer to a null-terminated string that contains the value of the environment variable, or a **`NULL`** pointer if the variable is not defined in the current environment
                
                <aside>
                💡 It's important to note that the memory pointed to by the return value is part of the environment and should not be modified. If you need to modify the value of an environment variable, you can use the **`putenv`**
                 or **`setenv`**
                 functions instead.
                
                </aside>
                
        
        - ***Signal Handling and Management Header “signal.h”***
            - $signal :$ function is used to handle software interrupts, also known as signals
                
                ```c
                void (*signal(int sig, void (*handler)(int)))(int);
                ```
                
                The signal function takes two arguments:
                
                `sig`: an integer value that specifies the signal to handle.
                `handler:` a pointer to a function that will be called when the signal is received.
                The signal function returns a pointer to the previous signal handler, or SIG_ERR if an error occurs.
                
                When a signal is received, the specified handler function is called with an integer argument that specifies the signal number. The handler function can perform any necessary action, such as cleaning up resources, setting flags, or taking some other action in response to the signal
                
                <aside>
                💡 *It's important to note that signal handling is a complex topic with many nuances and caveats, and the behavior of signal handling functions can vary depending on the platform, operating system, and other factors. Therefore, it's important to read the documentation carefully and test your code thoroughly to ensure that it behaves as expected in all situations.*
                
                </aside>
                
            - $sigaction :$  function is used to set up a signal handler for a specific signal. It is an alternative to the older **`signal`**  function, and provides more robust and flexible signal handling capabilities.
                
                ```c
                int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
                ```
                
                The **`sigaction`** function takes three arguments:
                
                - **`signum`**: an integer value that specifies the signal to handle.
                - **`act`**: a pointer to a **`sigaction`** structure that specifies the new signal handler to install.
                - **`oldact`**: a pointer to a **`sigaction`** structure that will receive the previous signal handler.
                
                The **`sigaction`** function returns **`0`** on success, or **`-1`** on error.
                
                The **`sigaction`** structure contains several fields that specify the behavior of the signal handler, including:
                
                - **`sa_handler`**: a function pointer that specifies the signal handler function.
                - **`sa_sigaction`**: an alternate signal handler function that can provide additional information about the signal.
                - **`sa_mask`**: a set of signals to block while the signal handler is executing.
                - **`sa_flags`**: additional flags that control the behavior of the signal handler.
                
                <aside>
                💡 Using **`sigaction`**
                 instead of **`signal`**
                 can provide more control over signal handling and can help to avoid certain problems, such as race conditions and unexpected signal behavior. However, it is also more complex and requires more code to set up and u
                
                </aside>
                
            - $sigemptyset:$ function is used to initialize a signal set to be empty
            
            ```c
            	int sigemptyset(sigset_t *set);
            ```
            
            The **`sigemptyset`** function takes one argument:
            
            - **`set`**: a pointer to a **`sigset_t`** structure that represents the signal set to be initialized.
            
            The **`sigemptyset`** function returns **`0`** on success, or **`-1`** on error.
            
            The **`sigset_t`** structure is used to represent a set of signals. The **`sigemptyset`** function initializes the signal set to be empty, so that it does not contain any signals.
            
            After initializing a signal set with **`sigemptyset`**, you can add individual signals to the set using the **`sigaddset`** function, or you can use a convenience function like **`sigfillset`** to initialize the set to contain all signals.
            
            <aside>
            💡 Using signal sets can be useful for blocking or unblocking signals, or for setting up signal handlers to handle specific sets of signals. Signal sets are typically used in conjunction with other signal handling functions like **`sigprocmask`**, **`sigaction`** , and **`sigwait`**
            
            </aside>
            
            - $sigaddset :$ function is used to add a signal to a signal set
                
                ```c
                int sigaddset(sigset_t *set, int signum);
                ```
                
                The **`sigaddset`** function takes two arguments:
                
                - **`set`**: a pointer to a **`sigset_t`** structure that represents the signal set to add the signal to.
                - **`signum`**: an integer value that specifies the signal to add to the signal set.
                
                The **`sigaddset`** function returns **`0`** on success, or **`-1`** on error.
                
                The **`sigset_t`** structure is used to represent a set of signals. The **`sigaddset`** function adds the specified signal to the signal set.
                
                After adding signals to a signal set using **`sigaddset`**, you can use the set in various ways, such as blocking the signals using **`sigprocmask`**, or using the set to specify which signals a signal handler should handle
                
                <aside>
                💡 It's worth noting that signal sets are not arrays, and therefore are not ordered. Adding the same signal to a set multiple times has no effect, and the order in which signals were added to the set is not preserved.
                
                </aside>
                
            - $kill :$  function is used to send a signal to a process or a group of processes
                
                ```c
                int kill(pid_t pid, int sig);
                ```
                
                The **`kill`** function takes two arguments:
                
                - **`pid`**: an integer value that specifies the process ID of the process or process group to send the signal to. If **`pid`** is positive, the signal is sent to the process with the specified ID. If **`pid`** is negative, the signal is sent to the process group with the absolute value of **`pid`**. If **`pid`** is zero, the signal is sent to all processes in the current process group.
                - **`sig`**: an integer value that specifies the signal to send.
                
                The **`kill`** function returns **`0`** on success, or **`-1`** on error.
                
                The **`sig`** argument specifies the signal to send to the specified process or process group. Some common signals include **`SIGTERM`** (terminate), **`SIGINT`** (interrupt), **`SIGKILL`** (kill), and **`SIGSTOP`** (stop). You can also define your own signals using the **`signal`** function.
                
                <aside>
                💡 The **`kill`** function can be useful for controlling other processes from your own program, such as sending signals to terminate a process, interrupt a process, or communicate with a process. However, it's important to use caution when sending signals, as they can cause unintended consequences if not used carefully.
                
                </aside>
                
            - $exit :$ function is used to terminate the current process.
            
            ```c
            void exit(int status);
            ```
            
            The **`exit`** function takes one argument:
            
            - **`status`**: an integer value that specifies the exit status of the process. A zero value usually indicates successful completion, while a nonzero value indicates an error.
            
            The **`exit`** function does not return a value.
            
            When you call the **`exit`** function, the current process is terminated and all open files are closed. The exit status is then returned to the parent process or shell that launched the program.
            
            You can use the exit status to communicate information about the success or failure of the program to the parent process. For example, a shell script can check the exit status of a program to determine whether it succeeded or failed, and take appropriate action based on that result.
            
        
        <aside>
        💡 It's worth noting that the **`exit`**
         function should be used with care, as terminating a process abruptly can cause unintended consequences. You should ensure that any necessary cleanup or resource deallocation is performed before calling **`exit`**.
        
        </aside>
        
        - ***System Data Structure for File Attributes “sys/stat.h”***
            - $stat :$ function is used to obtain information about an open file
                
                ```c
                int fstat(int fd, struct stat *buf);
                ```
                
                The **`fstat`** function takes two arguments:
                
                - **`fd`**: an integer value that specifies the file descriptor of the open file to obtain information about.
                - **`buf`**: a pointer to a **`struct stat`** object that will be filled with information about the file.
                
                The **`fstat`** function returns **`0`** on success, or **`-1`** on error.
                
                <aside>
                💡 The **`struct stat`** object pointed to by **`buf`**  contains various fields that provide information about the file, such as its size, permissions, owner, and modification time .
                
                </aside>
                
            - $lstat :$ function is used to obtain information about a file, symbolic link, or directory. It is similar to the **`stat`**function, but can be used to obtain information about the symbolic link itself rather than the file it points to.
                
                ```c
                int lstat(const char *path, struct stat *buf);
                ```
                
                The **`lstat`** function takes two arguments:
                
                - **`path`**: a string that specifies the path of the file or symbolic link to obtain information about.
                - **`buf`**: a pointer to a **`struct stat`** object that will be filled with information about the file or symbolic link.
                
                The **`lstat`** function returns **`0`** on success, or **`-1`** on error.
                
                <aside>
                💡 The **`struct stat`** object pointed to by **`buf`** contains various fields that provide information about the file or symbolic link, such as its size, permissions, owner, and modification time
                
                </aside>
                
            - $fstat:$  function is used to obtain information about an open file. It is similar to the **`stat`**
             function, but operates on an open file rather than a file specified by its path.
                
                ```c
                int fstat(int fd, struct stat *buf);
                ```
                
                The **`fstat`** function takes two arguments:
                
                - **`fd`**: an integer that specifies the file descriptor of the open file to obtain information about.
                - **`buf`**: a pointer to a **`struct stat`** object that will be filled with information about the file.
                
                The **`fstat`** function returns **`0`** on success, or **`-1`** on error.
                
                <aside>
                💡 The **`struct stat`** object pointed to by **`buf`** contains various fields that provide information about the file, such as its size, permissions, owner, and modification time .
                
                </aside>
                
        
- ***`Execution part** :`*
    
    *To start the execution of a command in Minishell, you first need to parse the user input and convert it into tokens that can be executed by the shell. This involves breaking down the user input into individual words or commands, handling escape characters and quotes, and tokenizing the input.*
    
    *Once you have parsed the user input into tokens, you can then execute the command. The exact steps for executing a command will depend on whether it is a built-in command or an external command.*
    
    *For built-in commands, you can simply call the appropriate function within the shell program to perform the desired action. For example, if the user enters the "cd" command to change the current working directory, you can call a function in your shell program that changes the current working directory using the chdir() system call.*
    
    *For external commands, you need to create a child process to run the command. You can use the fork() system call to create a child process, and then use one of the exec() system calls to replace the child process with the desired command. This will allow the child process to execute the command and then exit, returning control to the parent process.*
    
    *If the user input includes a pipeline or other shell feature, you will need to handle this as well. For pipelines, you can create multiple child processes and set up pipes to connect the output of one command to the input of the next command. For other shell features, you may need to handle input/output redirection, environment variables, and shell expansion.*
    
    *Overall, the key to starting execution in Minishell is to have a clear understanding of the user input, the desired command, and how to execute it in the context of the shell program.*
    
    - ***handling built-in commands** :*
        - what is built-ins:
            
            
            > ***`What is Environment variables :`*** *`are special variables (like $HOME
            ) that contain information about your login session. They're stored for the system shell to use when executing commands. They exist whether you’re using Linux, Mac, or Windows. Many of these variables are set by default during installation or user creation.`*
            > 
            > - *****environment variables :*****
            >     
            >     `*Environment variables can be useful when you want to override default settings, or when you need to manage new settings that your system has no reason to create on its own. For instance, when you type a command, the only reason your computer knows how to find the application corresponding to that command is that the PATH environment variable tells it where to look. This variable lists valid directories for your operating system to search for commands, whether that command is [ls](https://opensource.com/article/19/7/master-ls-command) or [cp](https://opensource.com/article/19/8/copying-files-linux), or a graphical application like Firefox or [Lutris](https://opensource.com/article/18/10/lutris-open-gaming-platform), or anything else.*`
            >     
            >     `*Different environment variables get used by different systems. Your PATH variable is vital to your terminal emulator, for instance, but a lot less significant to, say, Java (which has its own paths, which point to important Java libraries). However, the USER variable is used by several systems as a way to identify who is requesting a service. For example, if you’re on a multiuser system and need to check your local mailbox, your mail command knows which mail spool to retrieve based on the MAIL and USER variables.*`
            >     
            
            ---
            
            `—> ***implement the following builtins:***`
            
            ---
            
            - ***cd:  Changes the current working directory to a specified path.***
                - $*cd-_-command :*$
                    
                    $***chdir$ :*** 
                    
                    function takes a single argument, which is a pointer to a string that contains the path of the directory to change to. The function returns an integer value that indicates whether the change was successful or not.
                    
                    - *If **`chdir()`** successfully changes the current working directory, it returns 0.*
                    - *If **`chdir()`** fails to change the current working directory, it returns -1.*
                    
                    $***getenv$ :***  
                    
                    *function takes a single argument, which is a pointer to a string that contains the name of the environment variable to retrieve. The function returns a pointer to a null-terminated string that contains the value of the environment variable. If the environment variable does not exist, the function returns NULL.*
                    
                    $***stat :***$
                    
                    *function in C is used to obtain information about a file or directory, such as its size, timestamp, owner, permissions, etc. The function takes a filename or path as an argument and fills a **`struct stat`** with information about the file or directory.*
                    
                    ```c
                    int stat(const char *pathname, struct stat *statbuf);
                    ```
                    
                    The first argument is the path to the file or directory that you want to obtain information about, and the second argument is a pointer to a **`struct stat`** that will be filled with the information
                    
                    <aside>
                    💡 `*struct stat` is a structure defined in the C standard library header file `sys/stat.h`. It is used to store information about a file or directory, such as its size, permissions, owner, and modification time.*
                    
                    *The `struct stat` structure has the following members:*
                    
                    - `*dev_t st_dev`: The ID of the device containing the file.*
                    - `*ino_t st_ino`: The inode number of the file.*
                    - `*mode_t st_mode`: The file mode and permissions.*
                    - `*nlink_t st_nlink`: The number of hard links to the file.*
                    - `*uid_t st_uid`: The user ID of the file owner.*
                    - `*gid_t st_gid`: The group ID of the file owner.*
                    - `*dev_t st_rdev`: The device ID (if the file is a special file).*
                    - `*off_t st_size`: The size of the file in bytes.*
                    - `*blksize_t st_blksize`: The block size used for file system I/O.*
                    - `*blkcnt_t st_blocks`: The number of blocks allocated for the file.*
                    - `*time_t st_atime`: The time the file was last accessed.*
                    - `*time_t st_mtime`: The time the file was last modified.*
                    - `*time_t st_ctime`: The time the file status was last changed.*
                    </aside>
                    
                    **`S_ISDIR(mode)`** is a macro defined in the **`sys/stat.h`** header file in C, and it is used to check if a file is a directory.
                    
                    The **`st_mode`** member of the **`struct stat`** structure contains the file mode and permissions. **`S_ISDIR(mode)`** takes the file mode as its argument, and it returns a non-zero value if the file is a directory, and 0 if it is not.
                    
            - ***echo: Prints a message to the terminal.***
                - $echo-_-command :$
                    
                    $-n$ :  option is a flag that can be used with the **`echo`**
                     command to prevent it from appending a newline character at the end of the output.
                    
            - ***exit: Exits the shell program.***
                - $***exit-_-command :***$
                    
                    *The `exit` command is used to exit the current shell, and it is typically used at the end of a script or command sequence to terminate the script or session. Here are some common use cases for the `exit` command in the Bash shell:*
                    
                    1. *Exit with a specific status code: The `exit` command can be used to exit with a specific status code, which can be checked by other programs or scripts that invoke the Bash shell. For example, the command `exit 1` will exit the shell with a status code of 1, indicating that an error occurred.*
                    2. *Exit a loop or function: The `exit` command can also be used to exit a loop or function early. For example, in a `for` loop, the `exit` command can be used to exit the loop early if a certain condition is met.*
                    3. *Terminate a script: When writing Bash scripts, the `exit` command is often used at the end of the script to terminate the session. This ensures that any resources or processes created by the script are properly cleaned up and that the shell returns control to the parent process.*
                    4. *Interrupt a long-running process: If a Bash script is running a long-running process, such as a database query or file download, the `exit` command can be used to interrupt the process and terminate the session. This is often used when a user needs to cancel a running script or command.*
                    5. *Exit a subshell: If a Bash script spawns a subshell, such as a new terminal window, the `exit` command can be used to exit the subshell and return control to the parent process.*
                    
            - ***export: Sets an environment variable.***
                - $export-_-command :$
                    
                    *In Bash shell, the **`export`** command is used to create environment variables. An environment variable is a variable that is made available to any child processes of the current shell, as well as to other programs and scripts running on the system.*
                    
                    *Here are some reasons why we might need to use the **`export`** command:*
                    
                    1. *Making variables available to scripts and programs: When we define a variable using the **`export`** command, it becomes an environment variable that can be accessed by other programs and scripts running on the system. This can be useful if we need to share information between different scripts or programs.*
                    2. *Setting system-wide defaults: Environment variables can be used to set system-wide defaults that affect the behavior of all programs and scripts. For example, the **`PATH`** environment variable is used to specify the directories where the system should look for executable files.*
                    3. *Managing user preferences: Environment variables can also be used to manage user preferences that affect the behavior of individual programs or scripts. For example, a user might define an environment variable named **`EDITOR`** to specify the default text editor to use for editing files.*
                    4. *Overriding default settings: Environment variables can be used to override default settings for individual programs or scripts. For example, a user might set an environment variable named **`PS1`** to change the prompt that is displayed by the Bash shell.*
                    
                    *In summary, the **`export`** command is used to create environment variables, which are variables that are made available to child processes of the current shell and to other programs and scripts running on the system. Environment variables are useful for managing system-wide defaults, user preferences, and program settings.*
                    
                    <aside>
                    💡 The **`declare -x`** prefix indicates that these variables are exported and will be available to any child processes that are spawned from the current shell session.
                    
                    </aside>
                    
            - ***pwd: Prints the current working directory***
                - $**pwd-_-command :**$
                    
                    $**`getcwd :`**$  function is used to get the current working directory of the shell. The *getcwd*  function is part of the standard C library and is available in most Unix-based operating systems, including Linux and macOS.
                    
                    Th*e getcwd* function takes two arguments: a pointer to a character array to store the current working directory and the size of that array. The function returns a pointer to the character array containing the current working directory.
                    
                    > returns a pointer to the character array containing the current working directory on success. If the function fails, it returns a NULL pointer, and the error message is stored in the **`errno`** variable.
                    > 
                    > 
                    > The **`errno`** variable is a global variable that is defined in the **`<errno.h>`** header file. It is used to indicate the type of error that occurred during the execution of a function. In the case of the **`getcwd()`** function, the **`errno`** variable can be used to determine the type of error that caused the function to fail.
                    > 
            - ***unset: Removes an environment variable.***
                - $unset-_-command :$
                    
                    The **`unset`** command is used to remove a variable or function from the current shell environment. There are several reasons why you might need to use **`unset`**:
                    
                    1. Remove unnecessary or obsolete variables: Over time, your shell environment may accumulate variables that are no longer needed or have become obsolete. These variables can clutter your environment and make it harder to find the variables that are actually important. Using **`unset`** to remove these variables can help keep your environment clean and organized.
                    2. Avoid conflicts: Sometimes, two or more variables can have the same name but different values. This can cause confusion and unexpected behavior in scripts and other programs that rely on these variables. By using **`unset`** to remove unwanted variables, you can avoid these conflicts and ensure that your scripts and programs work as expected.
                    3. Protect sensitive information: In some cases, you may have variables that contain sensitive information, such as passwords or access keys. Using **`unset`** to remove these variables when they are no longer needed can help protect this information from being accidentally leaked or disclosed.
                    4. Debugging: When you are debugging a script or program, you may need to remove a variable temporarily to test different scenarios or troubleshoot issues. The **`unset`** command can be useful in this situation.
                    
                    In summary, the **`unset`** command is a useful tool for managing your shell environment, avoiding conflicts, protecting sensitive information, and debugging scripts and programs.
                    
                    <aside>
                    💡 An obsolete variable is a variable that is no longer needed or relevant in the current shell environment. Obsolete variables can accumulate over time as a result of changes in the system or changes in user preferences.
                    
                    For example, an obsolete variable might be one that was used to configure an application that is no longer installed on your system. Another example could be a variable that was used to control an aspect of the system that has since been deprecated or removed.
                    
                    Obsolete variables can clutter your shell environment and make it harder to find the variables that are actually important. They can also cause conflicts with other variables or lead to unexpected behavior in scripts and programs.
                    
                    It's a good practice to periodically review the variables in your shell environment and remove any that are obsolete. The **`unset`** command can be used to remove obsolete variables and keep your environment clean and organized.
                    
                    </aside>
                    
            
            ***exit_cammand : —>***
