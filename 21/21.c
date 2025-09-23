/*
============================================================================
Name : 21.c
Author : Bhautik Vekariya
Description : Write a program, call fork and print the parent and child process id. 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();  

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    else if (pid == 0) {
        printf("I am the child process!!!   Child PID = %d, Parent PID = %d\n", getpid(), getppid());
    }

    else {
        printf("I am the parent process!!!  Parent PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/21$ gcc 21.c
bhautik@bhautik:~/SS/MT2025029/21$ ./a.out
I am the parent process!!!  Parent PID = 14974, Child PID = 14975
I am the child process!!!   Child PID = 14975, Parent PID = 14974
============================================================================
*/
