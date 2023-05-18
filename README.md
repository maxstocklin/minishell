# MiniShell - A Minimalist Unix Shell

## Description

MiniShell is a lightweight, minimalistic Unix shell implemented in C. Despite its simplicity, it provides a variety of key features found in more complex shells, making it perfect for users who want a no-frills command-line interface or for educational purposes to understand how a Unix shell operates.

## Features
MiniShell includes the following features:

### Redirections: 
The ```<```, ```<<```, ```>``` and ```>>``` redirection operators are fully supported, allowing you to redirect input and output from and to files or commands.

### Pipes: 
Use the ```|``` operator to pipe the output of one command to the input of another.

### Environment Variables: 
Environment variables can be accessed and modified, providing the ability to store user-defined settings.

### Exit Status: 
The special variable $? can be used to retrieve the exit status of the last executed command.

### Signal Handling: 
MiniShell can handle ```ctrl-D```, ```ctrl-C```, and ```ctrl-\``` signals, replicating the functionality of a full-featured shell.

### Builtins: 
MiniShell includes several built-in commands, including ```echo```, ```export```, ```unset```, ```cd```, ```pwd```, ```env```, and ```exit```.

## Installation and Usage

1. Clone the repository:
    ```bash
    git clone git@github.com:maxstocklin/minishell.git minishell
    ```

2. Navigate to the cloned repository:
    ```bash
    cd minishell
    ```

3. Compile the program using the provided Makefile: make
    ```bash
    make
    ```
    
4. Run the shell: ./minishell
    ```bash
    ./minishell
    ```

From here, you can use the shell just like you would use a standard Unix shell.

## Contributing

MiniShell is an open-source project, and contributions are always welcome! If you have any bug reports, feature requests, or questions, please open an issue on this GitHub repository.


