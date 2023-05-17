# Simple Shell Project
This is a simple shell project implemented in C. It provides a basic command-line interface where users can execute commands and interact with the operating system.

## About the project
This project is a simple version of the linux shell made for [ALX Software Engineering Program](https://www.alxafrica.com/software-engineering-2022), It is built using the C programming Language and it can do many functionalities that a real shell does.

## Features
- Command execution: Users can enter commands, and the shell will execute them using the execve system call.
- Basic built-in commands: The shell supports a few built-in commands such as cd (change directory) and exit (exit the shell).
- Environment variable manipulation: Users can set and unset environment variables using the built-in commands setenv and unsetenv.

## Getting Started
To compile the simple shell project, follow these steps:

1. Clone the repository: `git clone https://github.com/sanaeas/simple_shell.git`
2. Navigate to the project directory: `cd simple-shell`
3. Compile the source code: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
4. Run the shell: `./hsh`

## Usage
Once the shell is running, you can enter commands and interact with the shell. Here are a few examples:

- Execute a command: Simply enter the desired command, and press Enter. For example, ls -l will list the files and directories in the current directory in long format.
- Change directory: Use the cd command followed by the directory path. For example, cd /home/user will change the current directory to /home/user.
- Show environment variables: Enter the env command to list the environment variables.
- Exit the shell: Enter the exit command to exit the shell and return to the regular terminal.

## Built-in Commands
The shell provides the following built-in commands:

- cd [directory]: Change the current directory to the specified directory. If no directory is provided, it changes to the home directory.
- env: Print all the environment variables to the standard output.
- setenv [var-name] [value]: Add new variables to enviroment variables list, or update an existing one.
- unsetenv [var-name]: Remove a variable from the environment variables list.
- exit: Exit the shell.

## Project done by:
[Sanae Assim](https://github.com/sanaeas/) and [Hassan Assim](https://github.com/ASSIMv3/)

