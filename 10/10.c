/*
============================================================================
Name : 10.c
Author : Bhautik Vekariya
Description : Write a program to open a file with read write mode, write 10 
	      bytes, move the file pointer by 10 bytes (use lseek) and write 
	      again 10 bytes.
	      a. check the return value of lseek
	      b. open the file with od and check the empty spaces in between the data. 
Date: 7 Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd;
	char buf1[] = "System!!!!", buf2[] = "Software!!";

	fd = open("file.txt", O_RDWR|O_CREAT|O_TRUNC, 0664);
	if(fd < 0){
		perror("open");
		exit(1);
	}

	write(fd, buf1, 10);
	
	off_t i = lseek(fd, 10, SEEK_CUR);
	printf("After lseek, file pointer at: %ld\n", (long)i);

	write(fd, buf2, 10);

	close(fd);
	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/10$ gcc 10.c
bhautik@bhautik:~/SS/MT2025029/10$ ./a.out
After lseek, file pointer at: 20
bhautik@bhautik:~/SS/MT2025029/10$ od -c file.txt
0000000   S   y   s   t   e   m   !   !   !   !  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   S   o   f   t   w   a   r   e   !   !
0000036
============================================================================
*/
