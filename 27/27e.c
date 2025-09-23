/*
============================================================================
Name : 27e.c
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
    char *argv[] = { "ls", "-Rl", NULL };

    printf("Using execvp:\n");
    execvp("ls", argv);

    perror("execvp failed");
    return 1;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/27$ gcc 27e.c
bhautik@bhautik:~/SS/MT2025029/27$ ./a.out
Using execvp:
.:
total 36
-rw-rw-rw- 1 bhautik-vekariya bhautik-vekariya  1255 Sep  6 19:37 27a.c
-rw-rw-rw- 1 bhautik-vekariya bhautik-vekariya  1379 Sep  6 19:38 27b.c
-rw-rw-rw- 1 bhautik-vekariya bhautik-vekariya  1325 Sep  6 19:40 27c.c
-rw-rw-rw- 1 bhautik-vekariya bhautik-vekariya  1348 Sep  6 19:41 27d.c
-rw-rw-rw- 1 bhautik-vekariya bhautik-vekariya   640 Sep  6 19:31 27e.c
-rwxrwxr-x 1 bhautik-vekariya bhautik-vekariya 16096 Sep  6 19:41 a.out
============================================================================
*/
