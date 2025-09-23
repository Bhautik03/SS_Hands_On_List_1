/*
============================================================================
Name : 26a.c
Author : Bhautik Vekariya
Description : Write a program to execute an executable program.
	      a. use some executable program
	      b. pass some input to an executable program. (for example execute 
	      an executable of $./a.out name) 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) printf("My name is:- %s\n", argv[1]);
    
    else printf("please enter the name...\n");
    
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/26$ gcc 26a.c -o 26a
bhautik@bhautik:~/SS/MT2025029/26$ ./26a bhautik
My name is:- bhautik
============================================================================
*/

