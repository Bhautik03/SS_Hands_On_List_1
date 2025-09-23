/*
============================================================================
Name : 3.c
Author : Bhautik Vekariya
Description : Write a program to create a file and print the file descriptor 
	      value. Use creat ( ) system call
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 

int main(){
	int fd;
	fd = creat("file.txt", 0664);
	if(fd == -1){
		perror("creat");
		exit(1);
	}

	printf("File created!!!\n");
	printf("File Descriptor Value: %d", fd);

	close(fd);
	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/3$ gcc 3.c
bhautik@bhautik:~/SS/MT2025029/3$ ./a.out
File created!!!
File Descriptor Value: 3
============================================================================
*/
