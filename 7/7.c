/*
============================================================================
Name : 7.c
Author : Bhautik Vekariya
Description : Write a program to copy file1 into file2 ($cp file1 file2). 
Date: 7 Sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int sfd, dfd, n;
	char buf[50];

	if(argc != 3){ 
		printf("Usage: %s <source_file> <desti file>\n", argv[0]);
		exit(1);
	}

	sfd = open(argv[1], O_RDONLY);
	dfd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0664);

	while(n = read(sfd, buf, sizeof(buf))){
		if(!write(dfd, buf, n)){
			perror("Error writing to destination file");
			close(sfd);
			close(dfd);
			exit(1);
		}		
	}

	close(sfd);
	close(dfd);

	printf("File copied!!!\n");

	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/7$ gcc 7.c
bhautik@bhautik:~/SS/MT2025029/7$ ./a.out file1.txt file2.txt
File copied!!!
============================================================================
*/
