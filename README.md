# MiniShell - A Minimalist Unix Shell

## Description

MiniShell is a lightweight, minimalistic Unix shell implemented in C. Despite its simplicity, it provides a variety of key features found in more complex shells, making it perfect for users who want a no-frills command-line interface or for educational purposes to understand how a Unix shell operates.

## Features
MiniShell includes the following features:

### Redirections: 
The <, <<, > and >> redirection operators are fully supported, allowing you to redirect input and output from and to files or commands.

### Pipes: 
Use the | operator to pipe the output of one command to the input of another.

### Environment Variables: 
Environment variables can be accessed and modified, providing the ability to store user-defined settings.

### Exit Status: 
The special variable $? can be used to retrieve the exit status of the last executed command.

### Signal Handling: 
MiniShell can handle ctrl-D, ctrl-C, and ctrl-\ signals, replicating the functionality of a full-featured shell.

### Builtins: 
MiniShell includes several built-in commands, including echo, export, unset, cd, pwd, env, and exit.

