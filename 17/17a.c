/*
============================================================================
Name : 17a.c
Author : Bhautik Vekariya
Description : Write a program to simulate online ticket reservation. Implement 
              write lock. Write a program to open a file, store a ticket number 
	      and exit. Write a separate program, to open the file, implement 
	      write lock, read the ticket number, increment the number and print 
	      the new ticket number then close the file.
Date: 7th sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd, n, ticket;
    struct flock lock;
    char buf[100];

    fd = open("ticket.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    lock.l_type = F_WRLCK;    
    lock.l_whence = SEEK_SET; 
    lock.l_start = 0;         
    lock.l_len = 0;           

    fcntl(fd, F_SETLKW, &lock);
    	    
    printf("Inside the critical section ...\n");

 
    lseek(fd, 0, SEEK_SET);
    n = read(fd, buf, sizeof(buf) - 1);
    if (n <= 0) {
        perror("read");
        close(fd);
        exit(1);
    }
    buf[n] = '\0';

    ticket = atoi(buf); 
    ticket++;               


    lseek(fd, 0, SEEK_SET);
    dprintf(fd, "%d\n", ticket);           
    ftruncate(fd, lseek(fd, 0, SEEK_CUR)); 

    printf("New ticket reserved: %d\n", ticket);

    printf("Enter to unlock...\n");
    getchar();
    printf("Unlocked\n");

    lock.l_type = F_UNLCK;
    (fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/17$ gcc 17a.c
bhautik@bhautik:~/SS/MT2025029/17$ ./a.out
Inside the critical section ...
New ticket reserved: 6
Enter to unlock...

Unlocked
============================================================================
*/
