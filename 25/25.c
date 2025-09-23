/*
============================================================================
Name : 25.c
Author : Bhautik Vekariya
Description : Write a program to create three child processes. The parent 
	      should wait for a particular child (use waitpid system call). 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;

    pid1 = fork();
    if(pid1 == 0){
	    printf("Child 1 PID = %d is running,  Parent PID = %d\n", getpid(), getppid());
	    sleep(4);
	    printf("Child 1 PID=%d existing...\n", getpid());
	    exit(2);
    }

    pid2 = fork();
    if(pid2 == 0){
            printf("Child 2 PID = %d is running,  Parent PID = %d\n", getpid(), getppid());
            sleep(8);
            printf("Child 2 PID=%d existing...\n", getpid());
            exit(4);
    }

    pid3 = fork();
    if(pid3 == 0){
            printf("Child 3 PID = %d is running,  Parent PID = %d\n", getpid(), getppid());
            sleep(10);
            printf("Child 3 PID=%d existing...\n", getpid());
            exit(6);
    }


    pid_t waited = waitpid(pid2, &status, 0);
    if (waited > 0 && WIFEXITED(status)) {
        printf("Parent: Child with PID=%d exited with status=%d\n", waited, WEXITSTATUS(status));
    }

    while(wait(NULL) > 0);

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/25$ gcc 25.c
bhautik@bhautik:~/SS/MT2025029/25$ ./a.out
Child 1 PID = 15741 is running,  Parent PID = 15740
Child 2 PID = 15742 is running,  Parent PID = 15740
Child 3 PID = 15743 is running,  Parent PID = 15740
Child 1 PID=15741 existing...
Child 2 PID=15742 existing...
Parent: Child with PID=15742 exited with status=4
Child 3 PID=15743 existing...
============================================================================
*/
