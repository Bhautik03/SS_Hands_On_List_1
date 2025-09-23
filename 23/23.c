/*
============================================================================
Name : 23.c
Author : Bhautik Vekariya
Description : Write a program to create a Zombie state of the running program. 
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

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        printf("Child PID=%d exiting immediately...\n\n", getpid());
	exit(0);
    } 
    
    else {
        printf("Parent PID=%d sleeping...\n", getpid());
	sleep(60);
    }

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/23$ gcc 23.c
bhautik@bhautik:~/SS/MT2025029/23$ ./a.out
Parent PID=15431 sleeping...
Child PID=15432 exiting immediately...
bhautik@bhautik:~/SS/MT2025029/23$ ps aux | grep defunct
bhautik+   15432  0.0  0.0      0     0 pts/1    Z+   17:51   0:00 [a.out] <defunct>
bhautik+   15482  0.0  0.0   9144  2248 pts/2    S+   17:51   0:00 grep --color=auto defunct
============================================================================
*/
