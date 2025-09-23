/*
============================================================================
Name : 16a.c
Author : Bhautik Vekariya
Description : Write a program to perform mandatory locking.
		  a. Implement write lock
		  b. Implement read lock 
Date: 7 Sept, 2025.
============================================================================
*/

#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(){
        int fd;
        struct flock lock;

        fd = open("lockFile.txt", O_WRONLY | O_CREAT, 0664);
        if(fd == -1){
                perror("open");
                exit(1);
        }

        lock.l_type = F_WRLCK;    
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;         
        lock.l_len = 0;        	  
	lock.l_pid = getpid();

        printf("Before entering into critical section (write lock)...\n");
        fcntl(fd, F_SETLKW, &lock);
        printf("Inside the critical section with write lock...\n");
        printf("Enter to unlock...\n");
        getchar();
        printf("Unlocked\n");

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);

        close(fd);
        return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/16$ gcc 16a.c
bhautik@bhautik:~/SS/MT2025029/16$ ./a.out
Before entering into critical section (write lock)...
Inside the critical section with write lock...
Enter to unlock...

Unlocked
============================================================================
*/
