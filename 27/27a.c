/*
============================================================================
Name : 27a.c
Author : Bhautik Vekariya
Description : Write a program to execute ls -Rl by the following system calls
		  a. execl
		  b. execlp
		  c. execle
		  d. execv
		  e. execvp 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Using execl:\n");
    execl("/bin/ls", "ls", "-Rl", NULL);

    perror("execl failed");
    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/27$ gcc 27a.c
bhautik@bhautik:~/SS/MT2025029/27$ ./a.out
Using execl:
.:
total 36
-rw-rw-rw- 1 bhautik-vekariya bhautik-vekariya   549 Sep  6 19:30 27a.c
-rw-rw-rw- 1 bhautik-vekariya bhautik-vekariya   695 Sep  6 19:30 27b.c
-rw-rw-rw- 1 bhautik-vekariya bhautik-vekariya   618 Sep  6 19:30 27c.c
-rw-rw-rw- 1 bhautik-vekariya bhautik-vekariya   642 Sep  6 19:31 27d.c
-rw-rw-rw- 1 bhautik-vekariya bhautik-vekariya   640 Sep  6 19:31 27e.c
-rwxrwxr-x 1 bhautik-vekariya bhautik-vekariya 16040 Sep  6 19:37 a.out
============================================================================
*/

