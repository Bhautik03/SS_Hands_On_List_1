/*
============================================================================
Name : 1b.c
Author : Bhautik Vekariya
Description : Create the following types of a files using (i) shell command (ii) system call
	      b. hard link (link system call)
Date: 7 Sept, 2025.
============================================================================
*/


#include <unistd.h>  
#include <stdio.h>    

int main() {
    if (link("hardfile.txt", "hlink.txt") == 0) {
        printf("Hard link created!!!\n");
    }

    else{
	 perror("link");
    }

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/1/1b$ gcc 1b.c -o 1b
bhautik@bhautik:~/SS/MT2025029/1/1b$ ./1b
Hard link created!!!
bhautik@bhautik:~/SS/MT2025029/1/1b$ ls -i
3180014 1b  3180033 1b.c  3180166 hardfile.txt  3180166 hlink.txt
============================================================================
*/


