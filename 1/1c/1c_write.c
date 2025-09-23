/*
============================================================================
Name : 1c_write.c
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

    mkfifo(fifo_path, 0666);

    fd = open(fifo_path, O_WRONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    char msg[100];
    printf("Enter a message: ");
    fgets(msg, sizeof(msg), stdin);
    write(fd, msg, sizeof(msg));
    printf("Writer: message sent!\n");

    close(fd);
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/1/1c$ gcc 1c_write.c -o write
bhautik@bhautik:~/SS/MT2025029/1/1c$ ./write
Enter a message: Hello!!!
Writer: message sent!
============================================================================
*/
