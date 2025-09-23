/*
============================================================================
Name : 12.c
Author : Bhautik Vekariya
Description : Write a program to find out the opening mode of a file. Use fcntl. 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	int fd = open(argv[1], O_RDWR|O_APPEND);
	if(fd < 0){
		perror("open");
		exit(1);
	}

	int flag = fcntl(fd, F_GETFL);
	if(flag==-1){
		perror("fcntl");
		close(fd);
		exit(1);
	}

	int mode = flag & O_ACCMODE;

	if(mode == O_WRONLY) printf("File open in write only mode\n");
	else if(mode == O_RDONLY) printf("File open in read only mode\n");
	else if(mode == O_RDWR) printf("File open in read+write mode\n");

	if(flag & O_APPEND) printf("File has APPEND flag set\n");
	if(flag & O_NONBLOCK) printf("File has non blocking flag set\n");

	close(fd);
	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/12$ gcc 12.c
bhautik@bhautik:~/SS/MT2025029/12$ ./a.out file.txt
File open in read+write mode
File has APPEND flag set
============================================================================
*/
