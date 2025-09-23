/*
============================================================================
Name : 4.c
Author : Bhautik Vekariya
Description : Write a program to open an existing file with read write mode. 
	      Try O_EXCL flag also.
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>   
#include <unistd.h>  
#include <stdlib.h>  

int main() {
    int fd;

    fd = open("file.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    printf("File opened successfully!!!\n");
    close(fd);

    fd = open("file.txt", O_RDWR | O_CREAT | O_EXCL, 0664);
    if (fd == -1) {
        perror("open with O_EXCL");
    } 
    else {
        printf("File created");
        close(fd);
    }

    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/4$ gcc 4.c
bhautik@bhautik:~/SS/MT2025029/4$ ./a.out
File opened successfully!!!
open with O_EXCL: File exists
============================================================================
*/

