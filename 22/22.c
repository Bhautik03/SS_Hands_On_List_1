/*
============================================================================
Name :22.c
Author : Bhautik Vekariya
Description : Write a program, open a file, call fork, and then write to the 
	      file by both the child as well as the parent processes. Check 
	      output of the file. 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main() {
    int fd;
    pid_t pid;

    fd = open("file.txt", O_WRONLY | O_CREAT, 0664);
    if (fd < 0) {
        perror("open failed");
        exit(1);
    }

    pid = fork();

    if (pid == 0) {
       	write(fd, "Child process writing to file!!!\n", sizeof("Child process writing to file!!!"));
	printf("Writing is done by child process...\n");
    } 

    else {
	write(fd, "Parent process writing to file!!!\n", sizeof("Parent process writing to file!!!"));
	printf("Writing is done by parent process...\n");	
    }

    close(fd);

    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/22$ gcc 22.c
bhautik@bhautik:~/SS/MT2025029/22$ ./a.out
Writing is done by parent process...
Writing is done by child process...
bhautik@bhautik:~/SS/MT2025029/22$ cat file.txt
Parent process writing to file!!!
Child process writing to file!!!
============================================================================
*/
