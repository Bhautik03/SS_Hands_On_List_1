/*
============================================================================
Name : 1c_read.c
Author : Bhautik Vekariya
Description : Create the following types of a files using (i) shell command (ii) system call
	      c. FIFO (mkfifo Library Function or mknod system call)              
Date: 7 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char *fifo_path = "myfifo";
    char buffer[100];

    mkfifo(fifo_path, 0666);

    fd = open(fifo_path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    read(fd, buffer, sizeof(buffer));
    printf("Reader: received message: %s\n", buffer);

    close(fd);
    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/1/1c$ gcc 1c_read.c -o read
bhautik@bhautik:~/SS/MT2025029/1/1c$ ./read
Reader: received message: Hello!!!
============================================================================
*/

