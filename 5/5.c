/*
============================================================================
Name : 5.c
Author : Bhautik Vekariya
Description : Write a program to create five new files with infinite loop. 
	      Execute the program in the background and check the file descriptor 
	      table at /proc/pid/fd.
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd[5];
	char fname[30];

	for(int i=0; i<5; i++){
		sprintf(fname, "file%d.txt", i+1); 
		fd[i] = creat(fname, 0664);
		if(fd[i] == -1){
			perror("creat");
			exit(1);
		}

		printf("Created %s with fd=%d\n", fname, fd[i]);
	}

	while(1){
		sleep(2); 
	}

	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/5$ ./a.out &
[1] 11518
bhautik@bhautik:~/SS/MT2025029/5$ Created file1.txt with fd=3
Created file2.txt with fd=4
Created file3.txt with fd=5
Created file4.txt with fd=6
Created file5.txt with fd=7
bhautik@bhautik:~/SS/MT2025029/5$ ls -l /proc/11518/fd
total 0
lrwx------ 1 bhautik-vekariya bhautik-vekariya 64 Sep  6 16:49 0 -> /dev/pts/1
lrwx------ 1 bhautik-vekariya bhautik-vekariya 64 Sep  6 16:49 1 -> /dev/pts/1
lrwx------ 1 bhautik-vekariya bhautik-vekariya 64 Sep  6 16:49 2 -> /dev/pts/1
l-wx------ 1 bhautik-vekariya bhautik-vekariya 64 Sep  6 16:49 3 -> /home/bhautik-vekariya/SS/MT2025029/5/file1.txt
l-wx------ 1 bhautik-vekariya bhautik-vekariya 64 Sep  6 16:49 4 -> /home/bhautik-vekariya/SS/MT2025029/5/file2.txt
l-wx------ 1 bhautik-vekariya bhautik-vekariya 64 Sep  6 16:49 5 -> /home/bhautik-vekariya/SS/MT2025029/5/file3.txt
l-wx------ 1 bhautik-vekariya bhautik-vekariya 64 Sep  6 16:49 6 -> /home/bhautik-vekariya/SS/MT2025029/5/file4.txt
l-wx------ 1 bhautik-vekariya bhautik-vekariya 64 Sep  6 16:49 7 -> /home/bhautik-vekariya/SS/MT2025029/5/file5.txt
============================================================================
*/
