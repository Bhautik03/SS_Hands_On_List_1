/*
============================================================================
Name : 1a.c
Author : Bhautik Vekariya
Description : Create the following types of a files using (i) shell command (ii) system call
	      a. soft link (symlink system call)
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    if (symlink("softfile.txt", "slink.txt") == 0) {
        printf("Soft link created successfully.\n");
    } 
    
    else {
        perror("symlink");
    }
    
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/1/1a$ gcc 1a.c -o 1a
bhautik@bhautik:~/SS/MT2025029/1/1a$ ./1a
Soft link created successfully.

bhautik@bhautik:~/SS/MT2025029/1/1a$ ls -l
total 24
-rwxrwxr-x 1 bhautik-vekariya bhautik-vekariya 16048 Sep  6 15:54 1a
-rw-rw-r-- 1 bhautik-vekariya bhautik-vekariya   934 Sep  6 15:54 1a.c
lrwxrwxrwx 1 bhautik-vekariya bhautik-vekariya    12 Sep  6 15:54 slink.txt -> softfile.txt
-rw-rw-r-- 1 bhautik-vekariya bhautik-vekariya    38 Aug 24 12:10 softfile.txt
============================================================================
*/

