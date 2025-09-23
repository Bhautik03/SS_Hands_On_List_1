/*
============================================================================
Name : 24.c
Author : Bhautik Vekariya
Description : Write a program to create an orphan process. 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        printf("I am the orphan child...\n");
        printf("I am child having PID = %d\n", getpid());
        printf("My parent's PID = %d\n", getppid());

	sleep(15);
	printf("New parent's PID = %d\n", getppid());
    }
   
    else {
        printf("I am parent having PID = %d\n", getpid());
	printf("My child's PID = %d\n", pid);
        printf("Parent exiting now...\n\n");
        exit(0);  
    }

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/24$ gcc 24.c
bhautik@bhautik:~/SS/MT2025029/24$ ./a.out
I am parent having PID = 21708
My child's PID = 21709
Parent exiting now...

I am the orphan child...
I am child having PID = 21709
My parent's PID = 21708
New parent's PID = 2087
============================================================================
*/
