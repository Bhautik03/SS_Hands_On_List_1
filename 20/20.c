/*
============================================================================
Name : 20.c
Author : Bhautik Vekariya
Description : Find out the priority of your running program. Modify the priority 
              with nice command. 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    int prio;
    prio = getpriority(PRIO_PROCESS, 0);

    printf("Process ID: %d\n", getpid());
    printf("Current nice value: %d\n", prio);

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/20$ gcc 20.c
bhautik@bhautik:~/SS/MT2025029/20$ ./a.out
Process ID: 14641
Current nice value: 0
bhautik@bhautik:~/SS/MT2025029/20$ nice -n 5 ./a.out
Process ID: 14695
Current nice value: 5
============================================================================
*/
