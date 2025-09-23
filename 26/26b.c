/*
============================================================================
Name : 26b.c
Author : Bhautik Vekariya
Description : Write a program to execute an executable program.
              a. use some executable program
              b. pass some input to an executable program. (for example execute 
	      an executable of $./a.out name) 
Date: 7 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Running './26a' from C program!!!\n");

    execl("./26a", "26a", "Bhautik", NULL);

    perror("execl failed...");

    return 1;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/26$ gcc 26b.c
bhautik@bhautik:~/SS/MT2025029/26$ ./a.out
Running './26a' from C program!!!
My name is:- Bhautik
============================================================================
*/
