# Simple Shell

This is a brief introduction to some of the concepts related to the Unix operating system and shell programming. Here are some of the topics that will be covered:

- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

## Who designed and implemented the original Unix operating system

Unix was originally developed in the 1960s by a group of researchers at Bell Labs, including Ken Thompson and Dennis Ritchie.

## Who wrote the first version of the UNIX shell

The first version of the UNIX shell (sh) was written by Ken Thompson in 1971.

## Who invented the B programming language (the direct predecessor to the C programming language)

The B programming language was also invented by Ken Thompson in the early 1970s. B was a simplified version of the earlier BCPL language and was used to write the first version of the Unix operating system.

## Who is Ken Thompson

Ken Thompson is a computer scientist who was one of the original developers of the Unix operating system. He also helped to develop the C programming language and was a co-recipient of the Turing Award in 1983.

## How does a shell work

A shell is a program that provides a command-line interface for interacting with the operating system. When a user types a command into the shell, the shell interprets the command and executes it by calling the appropriate system functions.

## What is a pid and a ppid

A pid (process ID) is a unique identifier for a process in the operating system. A ppid (parent process ID) is the pid of the process that created the current process.

## How to manipulate the environment of the current process

The environment of a process is a set of key-value pairs that can be used to store configuration information. The environment can be manipulated using shell commands like `export` and `unset`.

## What is the difference between a function and a system call

A function is a block of code that can be called from within a program, while a system call is a request made by a program to the operating system to perform some task on its behalf.

## How to create processes

Processes can be created using the `fork` system call. The `fork` call creates a new process by duplicating the existing process, and then the `exec` call is used to replace the new process's memory space with a new program.

## What are the three prototypes of main

The three prototypes of main are:

```c
int main(void);
int main(int argc, char *argv[]);
int main(int argc, char *argv[], char *envp[]);
```

## How does the shell use the PATH to find the programs

The shell uses the PATH environment variable to search for executable programs. The PATH variable contains a list of directories separated by colons, and the shell searches each directory in turn until it finds the requested program.

## How to execute another program with the execve system call

The execve system call can be used to execute another program. The call takes three arguments: the path to the program, an array of command-line arguments, and an array of environment variables.

## How to suspend the execution of a process until one of its children terminates

The `wait` system call can be used to suspend the execution of a process until one of its children terminates.

## What is EOF / “end-of-file”?

EOF (end-of-file) is a special character that indicates the end of a file. When a program reads a file, it will encounter an EOF character when it reaches the end of the file.

