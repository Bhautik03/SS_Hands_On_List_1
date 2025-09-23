/*
============================================================================
Name : 9.c
Author : Bhautik Vekariya
Description : Write a program to print the following information about a given file.
		 a. inode
		 b. number of hard links
		 c. uid
		 d. gid
		 e. size
		 f. block size
		 g. number of blocks
		 h. time of last access
		 i. time of last modification
		 j. time of last change 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat Stat;

    if (stat(argv[1], &Stat) < 0) {
        perror("Error gettinig file information");
        exit(1);
    }

    printf("File: %s\n", argv[1]);
    printf("a. Inode: %lu\n", Stat.st_ino);
    printf("b. Number of hard links: %lu\n", Stat.st_nlink);
    printf("c. UID: %u\n", Stat.st_uid);
    printf("d. GID: %u\n", Stat.st_gid);
    printf("e. Size: %ld bytes\n", Stat.st_size);
    printf("f. Block size: %ld bytes\n", Stat.st_blksize);
    printf("g. Number of blocks: %ld\n", Stat.st_blocks);
    printf("h. Time of last access: %s", ctime(&Stat.st_atime));
    printf("i. Time of last modification: %s", ctime(&Stat.st_mtime));
    printf("j. Time of last change: %s", ctime(&Stat.st_ctime));

    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/9$ gcc 9.c
bhautik@bhautik:~/SS/MT2025029/9$ ./a.out file.txt
File: file.txt
a. Inode: 3180087
b. Number of hard links: 1
c. UID: 1000
d. GID: 1000
e. Size: 32 bytes
f. Block size: 4096 bytes
g. Number of blocks: 8
h. Time of last access: Sat Sep  6 15:34:36 2025
i. Time of last modification: Tue Aug 26 17:16:37 2025
j. Time of last change: Sat Sep  6 15:34:36 2025
============================================================================
*/
