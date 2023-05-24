THIS SIMPLE SHELL WAS STARTED ON 10 MAY 2023 AND ENDED ON 26 MAY 2023.
It contains all what you may need to know about building and implementing simple shell.

This simple UNIX command interpreter that replicates functionalities of the simple shell (sh). 
All the additional functions are also included. This program was written entirely using C programming language.
### Installation
Clone this repository into local working directory. 
For best results, files should be compiled with GCC and the following flags: Wall -Werror -Wextra -pedantic.
Clone this repository into local working directory. For best results, files should be compiled with 
```sh
gcc -Wall -Werror -Wextra -pedantic *.c
### Usage
After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.
#### Interactive Mode
In interactive mode, simply run the program and wait for the prompt to appear. 
From there, type commands freely, exiting with either the "exit" command or ctrl-D.
#### Non-Interactive Mode
In non-interactive mode, echo desired command and pipe it into the program as following:
```sh
echo "ls" | ./shell
```
In non-interactive mode, the program will exit after finishing desired command(s).
This program entirely will make you understand the functionalities of interactive and non-interactive mode
of the shell build.
 Among all these one will be able to fully understand how all the followings work;

    Who designed and implemented the original Unix operating system
    Who wrote the first version of the UNIX shell
    Who invented the B programming language (the direct predecessor to the C programming language)
    Who is Ken Thompson
    How does a shell work
    What is a pid and a ppid
    How to manipulate the environment of the current process
    What is the difference between a function and a system call
    How to create processes
    What are the three prototypes of main
    How does the shell use the PATH to find the programs
    How to execute another program with the execve system call
    How to suspend the execution of a process until one of its children terminates
    What is EOF / “end-of-file”?

THE FOLLOWINGS ARE THE INCLUDED FILES IN THIS PROJECTS;
builtinfunction1.c  
environment.c  
_exits1.c         
information.c  
main.c         
man_1_Simple_shell         
_string0.c   
variable.c
builtinfunction.c
converter.c    
errors1.c         
_getline.c     
lists1.c        
malloc.c            
shell.h        
storage.c    
tokens01.c
errors0.c      
getEnvironment.c  
list0.c        
make_History.c  
pars.c              
_shell_loop.c  
_strings1.c
AUTHORS


### Credits
All code written by [GATJUAT WICTEAT RIEK](https://github.com/Gatjuat-Wicteat-Riek) 
and [Wahiba](https://github.com/Wahibzd).
