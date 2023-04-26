# Simple Shell

In this project, my partner and I are developing a **UNIX command line interpreter** base in the _sh_ shell

## List of allowed functions

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

### Compilation

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

```

### Template to test output:
=============
$ ./hsh

($) 

hsh main.c shell.c

$ exit
$


## Usage

### Interactive Mode

Execute the shell to start.

> ./hsh

Use the same as _sh_ shell.

#### Example of use

```
$ ./hsh
hsh_shell$ /bin/ls
hsh main.c shell.c
hsh_shell$
```

Error in Interactive Mode

```
$ ./hsh
hsh_shell$ Cisfun
./hsh: 1: Cisfun: not found
hsh_shell$
```

### Non-Interactive Mode

#### Example of use

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
```

Error in Non-Interactive Mode

```
$ echo "Cisfun" | ./hsh
$ ./hsh: 1: Cisfun: not found
$
```
## Features

### Build-in Commands

- exit
- env

Example of use feature (exit)

```
$ ./hsh
hsh_shell$ exit 98
$ echo $?
98
```

### Features

- End of File (Ctrl+d) : Exit Shell
- Accepts arguments for functions
- Check the Path for executable file


The shell implementation is divided into three parts: ​

`The Parser`​
`The Executor`​
`Shell Subsystems`


## Builtin Functions

All built-in functions except printenv are executed by the parent process. The reason for this is that we want setenv, cd etc to modify the state of the parent. If they are executed by the child, the changes will go away when the child exits. For this built in functions, call the function inside execute instead of forking a new process.


## Authors

- Terry Wambui (https://github.com/terryyufei)
- Benson Kaunda (https://github.com/benkivuva)


